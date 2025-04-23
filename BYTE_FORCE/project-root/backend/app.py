from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
from typing import Dict, List
import requests
import os
import re
from dotenv import load_dotenv
from prompts.my_prompts import PROMPTS
from fastapi.staticfiles import StaticFiles

load_dotenv()
app = FastAPI()

API_KEY = os.getenv("API_KEY")
session_memory: Dict[str, List[str]] = {}


class ResetRequest(BaseModel):
    session_id: str


class SchemaRequest(BaseModel):
    session_id: str
    user_input: str


def remove_think_block(response_text: str) -> str:
    return re.sub(r"<think>.*?</think>", "", response_text, flags=re.DOTALL).strip()


@app.post("/generate-schema")
def generate_schema(request: SchemaRequest):
    try:
        if request.session_id not in session_memory:
            session_memory[request.session_id] = []

        session_memory[request.session_id].append(f"Пользователь: {request.user_input}")
        user_history = "\n".join(session_memory[request.session_id])

        formatted_prompts = ""
        for name, prompt in PROMPTS.items():
            formatted_prompts += f"\n### Шаблон: {name} ###\n{prompt.strip()}\n"

        missing_fields_instruction = """
            - userName — имя пользователя для подключения (например, к очереди или брокеру)
            - userPass — пароль пользователя
            - addresses — список адресов брокеров (например, ["localhost:5672"])
            - virtualHost — виртуальный хост в RabbitMQ
            - bootstrapServers — адреса Kafka-брокеров (например, "kafka:9092")
            - topic — название топика в Kafka
            - queue — имя очереди в RabbitMQ
            - accessKey — ключ доступа (например, к API или облаку)
            - secretKey — секретный ключ доступа
            - region — регион облачного провайдера
            - protocol — протокол подключения (например, IMAP)
            - host — хост сервиса (например, "imap.yandex.ru")
            - port — порт подключения
            - mailAuth — данные авторизации для доступа к почтовому ящику
            - senders — список допустимых отправителей (email-адреса)
            - subjects — список тем писем
            - startMailDateTime — дата, с которой начинаем читать почту
            - jco.client.user — логин для SAP
            - jco.client.passwd — пароль для SAP
            - jco.client.ashost — адрес SAP-хоста
            - jco.client.sysnr — номер системы SAP
            - jco.client.client — номер клиента SAP
            - jco.client.lang — язык SAP-подключения
            - jco.destination.pool_capacity — макс. подключений в пуле
            - jco.destination.peak_limit — макс. одновременных подключений
            - jco.server.gwhost — SAP Gateway Host
            - jco.server.progid — Program ID для подключения к SAP
            - idoc — структура сообщения для SAP
            - connectionDef — блок с параметрами подключения
            - url — адрес для REST-запроса
            - method — HTTP-метод (GET, POST и т.д.)
            - database — имя базы данных
            - inputVariable — входная переменная
            - outputVariable — переменная, которую вернёт активность
            - mapping — сопоставление данных (source → target)
            - branchA / branchB — ответвления в логике (if/else)
            - delay — задержка перед выполнением следующего действия
            - messageName — название сообщения в сценарии
        """

        master_prompt = f"""
Ты — специалист по генерации JSON-конфигураций интеграций для low-code платформы.

Соблюдай ПРАВИЛО ПРОВЕРКИ обязательных параметров подключения!

Список "обязательные параметры подключения по типам":
    - Для RabbitMQ: userName, userPass, addresses, virtualHost  
    - Для Kafka: bootstrapServers, username, password  
    - Для SAP: jco.client.user, jco.client.passwd, jco.client.ashost  
    - Для Mail: username, password, host, port  
    - Для REST: host, port, access_key (если требуется)  
    - Для Scheduler: не требуется  
    - Для SAP inbound: jco.client.user, jco.client.passwd, jco.client.ashost, jco.server.gwhost, jco.server.progid

Если в пользовательском описании отсутствуют обязательные параметры подключения:
- Попроси пользователя ввести их.
- Если пользователь не знает (пишет "не знаю", "нет информации", "пока не знаю"):
  - Вставь заглушки вида "TO_BE_FILLED" в соответствующие поля.
  - Построй схему с заглушками.
  - В отдельном сообщении предупреди:
    "Внимание: некоторые поля заполнены временными заглушками. Обязательно замените их на реальные значения перед использованием!"

Если обязательные поля указаны, но необязательные отсутствуют:
- Спроси про необязательные поля одним сообщением.
- Если пользователь не заполнил их — автоматически укажи "нет информации".

Если пользователь указал все необходимые поля:
- Строй финальный JSON по структуре global_definition_prompt.

Если пользователь описывает тип интеграции, которого нет в шаблонах:
- Верни сообщение:
  "Тип интеграции не поддерживается: "[название]". Но предлагаю вам "[название]". Желаете?"

Если пользователь спрашивает что-то не по теме:
- Ответь в шуточной форме и попроси вернуться к теме.

Вот список шаблонов и примеров и правило обязательных параметров подключения:

{formatted_prompts}

Пожалуйста, выбери подходящий шаблон и действуй строго по инструкции. 

Если пользователь допустил ошибку — подскажи ему.
"""

        response = requests.post(
            "https://api.gpt.mws.ru/v1/chat/completions",
            headers={
                "Authorization": f"Bearer {API_KEY}",
                "Content-Type": "application/json",
            },
            json={
                "model": "deepseek-r1-distill-qwen-32b",
                "messages": [
                    {"role": "system", "content": master_prompt},
                    {"role": "user", "content": user_history},
                ],
                "temperature": 0.4,
                "max_tokens": 5000,
            },
        )

        if response.ok:
            raw_response = response.json()["choices"][0]["message"]["content"]
            cleaned_response = remove_think_block(raw_response)
            return {"schema": cleaned_response}
        else:
            raise HTTPException(status_code=response.status_code, detail=response.text)

    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))


@app.post("/reset-session")
def reset_session(request: ResetRequest):
    if request.session_id in session_memory:
        del session_memory[request.session_id]
    return {"message": f"Сессия {request.session_id} сброшена"}


# Отдаём фронтенд через статику
app.mount("/", StaticFiles(directory="static", html=True), name="static")
