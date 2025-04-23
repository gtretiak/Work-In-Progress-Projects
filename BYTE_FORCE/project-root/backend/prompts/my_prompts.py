PROMPTS = {
    "ПРАВИЛО ПРОВЕРКИ обязательных параметров подключения"
    "missing_fields_instruction": """
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
""",
    "required_fields_by_type": """
- Для RabbitMQ: userName, userPass, addresses, virtualHost  
- Для Kafka: bootstrapServers, username, password  
- Для SAP: jco.client.user, jco.client.passwd, jco.client.ashost  
- Для Mail: username, password, host, port  
- Для REST: host, port, access_key (если требуется)  
- Для Scheduler: не требуется  
- Для SAP inbound: jco.client.user, jco.client.passwd, jco.client.ashost, jco.server.gwhost, jco.server.progid

1. Проверь описание пользователя на наличие обязательных параметров подключения.

ВАЖНО: если в пользовательском описании отсутствуют обязательные параметры подключения из списка выше — НЕ СТРОЙ JSON.

Вместо этого верни СТРОГО СООБЩЕНИЕ такого вида:
"❗️Уточните недостающие параметры подключения: [список полей] (missing_fields_instruction)"

2. Если пользователь указал все необходимые поля:

Ты строишь ответ исходя из описания пользователя, по структуре global_definition_prompt и используешь список промптов для определения стартера и активити. Затем строишь только JSON-схему по структуре global_definition_prompt.

Иначе: верни СТРОГО СООБЩЕНИЕ такого вида:
"❗️Уточните недостающие параметры подключения: [список полей] (missing_fields_instruction)"
""",
    "global_definition_prompt": """
Структура корня wf/definition:
- Обязательные поля:
  - "type": строка, определяет тип процесса (чаще всего "complex") Составной тип примитива, используется для создания БП из нескольких действий. Выполняется и обрабатывается последовательность действий (activity).
    Так же может быть
    await_for_message. Ожидание вызова от внешней системы/внешнего БП с заранее заданным текстом.
    rest_call. Вызов МС (REST API).
    db_call. Вызов функции или выборки из БД.
    send_to_rabbitmq. Отправка сообщения в очередь rabbitmq
    send_to_sap. Отправка idoc в sap
    transform. трансформация.
  - "name": имя бизнес-процесса
  - "compiled": указывается, если type = "complex"
    - Обязательные внутри:
      - "start": ID стартовой activity
      - "activities": список всех действий процесса
    - Необязательное внутри:
      - "outputTemplate": Фильтр всех данных запуска по завершению процесса. Если старт схемы будет производится с помощью синхронного REST-запроса и в ответ необходимо получить только определенные параметры, для более удобной их обработки, то необходимо указать необходимые для фильтрации параметры.
  - "details": 
    - Обязательные внутри:
      - "starters": Описание параметров старта
        - Обязательные внутри:
          - "type": Тип старта:
            kafka_consumer - старт схемы производится при вычитывании сообщения из очереди кафка
            sap_inbound - старт схемы производится при получении idoc в указанный канал SAP
            rest_call - старт схемы производится при вызове low-code с id схемы. Если не указан стартер, то по умолчанию присваивается rest_call 
            scheduler - старт схемы по расписанию
            rabbitmq_consumer - старт схемы производится при вычитывании сообщения из очереди rabbitmq
            mail_consumer - старт схемы производится при вычитывании всех непрочитанных писем почтового ящика
          - "name": Имя стартера
          -Обязательное, если стартер rabbitmq:
            - "rabbitmqConsumer": Описание деталей стартера подключения rabbitmq
          -Обязательное, если стартер kafka:
            - "kafkaConsumer": Описание деталей подключения стартера kafka
          -Обязательное, если стартер SAP:
            - "sapInbound": Описание деталей подключения стартера SAP
          -Обязательное, если стартер по расписанию:
            - "shedulerStarter": Описание деталей работы стартера по расписанию
      -Обязательное, если FlowDefinition.type = 'send_to_kafka':
        - "sendToKafkaConfig": Описание деталей вызова
      -Обязательное, если FlowDefinition.type = 'xslt_transform':
        - "xsltTransformConfig": Описание xslt-трансформации
      -Обязательное, если FlowDefinition.type = 'db_call':
        - "databaseCallConfig": Описание вызова БД (select или function)
      -Обязательное, если FlowDefinition.type = 'send_to_rabbitmq'
        - "sendToRabbitmqConfig": Описание отправки сообщения в Rabbitmq
      -Обязательное, если FlowDefinition.type = 'await_for_message'
        - "awaitForMessageConfig": Описание ожидаемого сообщения от внешней системы
- Необязательные поля процесса:
  - "tenantId": ID системы (по умолчанию "default")
  - "version": необязательное, значение по умолчанию 1, при каждом редактировании WF увеличивается на 1
  - "description": описание процесса
  - "flowEditorConfig": настройки отображения схемы для UI

Общие требования:
- Строить JSON строго по данной структуре.
- Если указаны дополнительные конфигурации (например, "sendToKafkaConfig") — заполняй их только если тип процесса требует.
- Строго соблюдать вложенность и типы данных.
- Проверять итоговый JSON на валидность.
""",
    "starter_rabbitmq_consumer": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON интеграции. Верни ТОЛЬКО JSON SCHEME — без пояснений, без комментариев.

Пользователь хочет: "{USER_INPUT}"

Правила:
- Стартер должен быть типа "RabbitMQ Consumer"
- Обязательные поля стартера:
  - "type": "rabbitmq_consumer"
  - "name": имя стартера
  - "rabbitmqConsumer": Описание деталей подключения:
  - Обязательные поля "rabbitmqConsumer": 
    - "queue": название очереди
    - "connectionDef": параметры подключения (userName, userPass, addresses, virtualHost) - запрашивать у пользователя
    - "payloadValidateSchema": JSON Schema валидации сообщений
    - "outputTemplate": объявление переменных на основе полученного сообщения
- Проверь схему на валидность.

Пример:
{
  "details": {
    "inputValidateSchema": {
      "type": "object",
      "required": ["payload"],
      "properties": {
        "payload": {
          "type": "object"
        }
      }
    },
    "starters": [
      {
        "name": "starter_name",
        "type": "rabbitmq_consumer",
        "description": "",
        "rabbitmqConsumer": {
          "queue": "queue_name",
          "connectionDef": {
            "userName": запрашивать у пользователя,
            "userPass": запрашивать у пользователя,
            "addresses": ["localhost:5672"],
            "virtualHost": "/"
          },
          "payloadValidateSchema": {},
          "outputTemplate": {
            "order": "jp{payload}"
          }
        }
      }
    ]
  }
}
""",
    "starter_kafka_consumer": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON интеграции. Верни ТОЛЬКО JSON SCHEME — без пояснений, без комментариев.

Пользователь хочет: "{USER_INPUT}"

Правила:
- Стартер должен быть типа "kafka_consumer".
- Обязательные поля стартера:
  - "type": "kafka_consumer"
  - "name": имя стартера
  - "kafkaConsumer": детали подключения к Kafka:
  - Обязательные поля "kafkaConsumer":
    - "topic": название топика
    - "connectionDef": параметры подключения (bootstrapServers, authDef при необходимости)
- Проверь схему на валидность.

Пример:
{
  "details": {
    "starters": [
      {
        "name": "starter_name",
        "type": "kafka_consumer",
        "kafkaConsumer": {
          "topic": "topic_name",
          "connectionDef": {
            "bootstrapServers": "kafka:9092",
            "authDef": {
              "type": "SASL_SSL",
              "sasl": {
                "username": запрашивать у пользователя,
                "password": запрашивать у пользователя
              }
            }
          }
        }
      }
    ]
  }
}
""",
    "starter_rest_call": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON интеграции. Верни ТОЛЬКО JSON SCHEME — без пояснений, без комментариев.

Пользователь хочет: "{USER_INPUT}"

Правила:
- Стартер должен быть типа "rest_call".
- Обязательные поля стартера:
  - "type": "rest_call"
  - details.inputValidateSchema: если нужно принимать параметры на старте
- Если inputValidateSchema не указан — спроси у пользователя.
- Проверь схему на валидность.

Пример:
{
  "details": {
    "inputValidateSchema": {
      "type": "object",
      "properties": {
        "apiId": {"type": "string"},
        "revisionId": {"type": "string"}
      },
      "required": ["apiId", "revisionId"]
    },
    "starters": [
      {"type": "rest_call"}
    ]
  }
}
""",
    "starter_sapInbound": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON интеграции. Верни ТОЛЬКО JSON SCHEME — без пояснений, без комментариев.

Пользователь хочет: "{USER_INPUT}"

Правила:
- Стартер должен быть типа "sapInbound".
- Обязательные поля стартера:
  - "type": "sapInbound"
  - "inboundDef": Описание деталей стартера подключения inboundDef
    - Обязательные поля "inboundDef":
    - "name": Имя стартера
    - "connectionDef": Параметры подключения
    - Обязательные поля "connectionDef":
        - "jco.client.lang": Язык клиента
        - "jco.client.passwd": Пароль
        - "jco.client.user": Логин
        - "jco.client.sysnr": номер SAP-системы
        - "jco.destination.pool_capacity": максимальное количество подключений, которые могут находиться в пуле подключений для destination
        - "jco.destination.peak_limit": максимальное количество одновременных подключений для destionation
        - "jco.client.client": номер клиента в SAP-системе
        - "jco.client.ashost": Хост
    - "props":
    - Обязательные поля "props":
        - "jco.server.gwhost": gwhost
        - "jco.server.progid": progid
        - "jco.server.gwserv": gwserv
        - "jco.server.connection_count": Количество подключений
- Проверь схему на валидность.

Пример:
{
  "details": {
        "inputValidateSchema": {},
        "starters": [
            {
                "type": "sap_inbound",
                "sapInbound": {
                    "inboundDef": {
                        "name": "sapInbound-SAP-LP",
                        "connectionDef": {
                            "name": "sapConnection-SAP-LP",
                            "props": {
                                "jco.client.lang": "EN",
                                "jco.destination.peak_limit": 10,
                                "jco.client.client": 400,
                                "jco.client.sysnr": 10,
                                "jco.destination.pool_capacity": 3,
                                "jco.client.ashost": "m-1.teat.ru",
                                "jco.client.user": "user",
                                "jco.client.passwd": "passwd"
                            }
                        },
                        "props": {
                            "jco.server.gwhost": "/H/test.ru/S/3310",
                            "jco.server.progid": "L_1",
                            "jco.server.gwserv": "sap",
                            "jco.server.connection_count": 2
                        }
                    }
                }
            }
        ]
    }
}
""",
    "starter_scheduler": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON интеграции. Верни ТОЛЬКО JSON SCHEME — без пояснений, без комментариев.

Пользователь хочет: "{USER_INPUT}"

Правила:
- Стартер должен быть типа "scheduler".
- Обязательные поля стартера:
  - "type": "scheduler"
  - "name": Имя стартера
  - "scheduler": Описание деталей стартера по расписанию
  - Обязательные поля "scheduler":
    - "type": "cron"
    - "cron": описание расписания
    - Обязательные поля "cron":
        - "dayOfWeek": День недели
        - "month": Количество месяцев, через которое повторять запуск
        - "dayOfMonth": День месяца
        - "hour": Количество месяцев, через которое повторять запуск
        - "minute": Количество месяцев, через которое повторять запуск
    - "startDateTime": Дата начала работы стартера
    - "outputTemplate": Дата окончания работы стартера
- Проверь схему на валидность.

Пример:
{
  At 00:00, on day 1 of the month, every 2 months
    "details": {
        "starters": [
            {
                "name": "scheduler_name",
                "type":"scheduler",
                "description": "Тестовый стартер",
                "scheduler": {
                    "type": "cron",
                    "cron": {
                      "dayOfWeek": "0",
                      "month": "*/2",
                      "dayOfMonth": "1",
                      "hour": "0",
                      "minute": "0"
                    },
                    "startDateTime": "2025-03-06T08:39:30.446Z",
                    "endDateTime": "2025-03-06T08:39:30.446Z"
                  }
            }
        ]
    }
}
""",
    "starter_mail_consumer": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON интеграции. Верни ТОЛЬКО JSON SCHEME — без пояснений, без комментариев.

Пользователь хочет: "{USER_INPUT}"

Правила:
- Стартер должен быть типа "mail_consumer".
- Обязательные поля стартера:
  - "type": "mail_consumer"
  - "name": Имя стартера
  - "mail_consumer": Описание деталей стартера
  - Обязательные поля "mail_consumer":
    - "connectionDef": описание расписания
    - Обязательные поля "connectionDef":
        - "protocol": imap
        - "host": Хост подключения
        - "port": Порт
        - "mailAuth": Параметры авторизации
        - Обязательные поля "mailAuth":
            - "username": Почта. запрашивать у пользователя.
            - "password": Пароль. запрашивать у пользователя.
    - "mailFilter": Дата начала работы стартера
    - Обязательные поля "mailFilter":
        - "senders": Почта отправителя письма
        - "subjects":Тема письма. Важно! Полное совпадение
        - "startMailDateTime": Дата, с которой необходимо начать вычитывать непрочитанные сообщения.Если параметр не указан, то будут вычитываться все непрочитанные письма.

- Проверь схему на валидность.

Пример:
{
   "details": {
        "starters": [
            {
                "name": "mail_starter",
                "type": "mail_consumer",
                "description": "Тестовый стартер",
                "tenantId": "default",
                "mailConsumer": {
                    "connectionDef": {
                        "protocol": "imap",
                        "host": "imap.yandex.ru",
                        "port": 993,
                        "mailAuth": {
                            "username": "test@test.test",
                            "password": "test"
                        }
                    },
                    "mailFilter": {
                        "senders": ["mymail@mail.ru"],
                        "subjects": ["topic1", "topic2"],
                        "startMailDateTime": "2025-01-01T10:01:23.000+03:00"
                    }
                }
            }
        ]
    }
}
""",
    "activity_rest_call": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON активности "rest_call". Верни ТОЛЬКО JSON без пояснений.

Пользователь хочет добавить шаг: "{USER_INPUT}"

Правила:
- Тип активности: "workflow_call" с workflowDef типа "rest_call".
- Обязательные поля:
  - "id": уникальный идентификатор активности
  - "type": "workflow_call"
  - "workflowCall": описание вызова:
    - "workflowDef":
      - "type": "rest_call"
      - "details":
        - "restCallConfig": с полями "url" и "method".
- Проверь схему на валидность.

Пример:
{
  "id": "call_api",
  "type": "workflow_call",
  "workflowCall": {
    "workflowDef": {
      "type": "rest_call",
      "details": {
        "restCallConfig": {
          "url": "https://example.com/api",
          "method": "POST"
        }
      }
    }
  }
}
""",
    "activity_db_call": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON активности "db_call". Верни ТОЛЬКО JSON без пояснений.

Пользователь хочет добавить шаг: "{USER_INPUT}"

Правила:
- Тип активности: "workflow_call" с workflowDef типа "db_call".
- Обязательные поля:
  - "id"
  - "type": "workflow_call"
  - "workflowCall":
    - "workflowDef":
      - "type": "db_call"
      - "details":
        - "query": SQL-запрос
        - "connection": параметры подключения
- Проверь схему на валидность.

Пример:
{
  "id": "query_db",
  "type": "workflow_call",
  "workflowCall": {
    "workflowDef": {
      "type": "db_call",
      "details": {
        "query": "SELECT * FROM orders",
        "connection": {
          "database": "main_db"
        }
      }
    }
  }
}
""",
    "activity_send_to_rabbitmq": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON активности "send_to_rabbitmq". Верни ТОЛЬКО JSON без пояснений.

Пользователь хочет добавить шаг: "{USER_INPUT}"

Правила:
- Тип активности: "workflow_call" с workflowDef типа "send_to_rabbitmq".
- Обязательные поля:
  - "id"
  - "type": "workflow_call"
  - "workflowCall":
    - "workflowDef":
      - "type": "send_to_rabbitmq"
      - "details":
        - "queue": название очереди
        - "connectionDef": параметры подключения
- Проверь схему на валидность.

Пример:
{
  "id": "send_to_queue",
  "type": "workflow_call",
  "workflowCall": {
    "workflowDef": {
      "type": "send_to_rabbitmq",
      "details": {
        "queue": "queue_name",
        "connectionDef": {
          "userName": "guest",
          "userPass": "guest",
          "addresses": ["localhost:5672"],
          "virtualHost": "/"
        }
      }
    }
  }
}
""",
    "activity_send_to_kafka": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON активности "send_to_kafka". Верни ТОЛЬКО JSON без пояснений.

Пользователь хочет добавить шаг: "{USER_INPUT}"

Правила:
- Тип активности: "workflow_call" с workflowDef типа "send_to_kafka".
- Обязательные поля:
  - "id"
  - "type": "workflow_call"
  - "workflowCall":
    - "workflowDef":
      - "type": "send_to_kafka"
      - "details":
        - "topic": название топика
        - "connectionDef": параметры подключения
- Проверь схему на валидность.

Пример:
{
  "id": "send_to_kafka",
  "type": "workflow_call",
  "workflowCall": {
    "workflowDef": {
      "type": "send_to_kafka",
      "details": {
        "topic": "event_topic",
        "connectionDef": {
          "bootstrapServers": "kafka:9092"
        }
      }
    }
  }
}
""",
    "activity_send_to_s3": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON активности "send_to_s3". Верни ТОЛЬКО JSON без пояснений.

Пользователь хочет добавить шаг: "{USER_INPUT}"

Правила:
- Тип активности: "workflow_call" с workflowDef типа "send_to_s3".
- Обязательные поля:
  - "id"
  - "type": "workflow_call"
  - "workflowCall":
    - "workflowDef":
      - "type": "send_to_s3"
      - "details":
        - "bucket": имя бакета
        - "key": ключ объекта. запрашивать у пользователя.
        - "connectionDef": параметры подключения к S3
- Проверь схему на валидность.

Пример:
{
  "id": "upload_to_s3",
  "type": "workflow_call",
  "workflowCall": {
    "workflowDef": {
      "type": "send_to_s3",
      "details": {
        "bucket": "bucket_name",
        "key": "path/to/file.json",
        "connectionDef": {
          "accessKey": "ACCESS_KEY",
          "secretKey": "SECRET_KEY",
          "region": "us-east-1"
        }
      }
    }
  }
}
""",
    "activity_send_to_sap": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON активности "send_to_sap". Верни ТОЛЬКО JSON без пояснений.

Пользователь хочет добавить шаг: "{USER_INPUT}"

Правила:
- Тип активности: "workflow_call" с workflowDef типа "send_to_sap".
- Обязательные поля:
  - "id"
  - "type": "workflow_call"
  - "workflowCall":
    - "workflowDef":
      - "type": "send_to_sap"
      - "details":
        - "sendToSapConfig": описание подключения
          - "connectionDef" или "connectionRef"
        - "idoc": тело документа (XML)
- Проверь схему на валидность.

Пример:
{
  "id": "send_to_sap",
  "type": "workflow_call",
  "workflowCall": {
    "workflowDef": {
      "type": "send_to_sap",
      "details": {
        "sendToSapConfig": {
          "connectionDef": {
            "props": {
              "jco.client.lang": "EN",
              "jco.client.user": запрашивать у пользователя,
              "jco.client.passwd": запрашивать у пользователя,
              "jco.client.ashost": запрашивать у пользователя,
              "jco.client.client": "100",
              "jco.client.sysnr": "00"
            }
          },
          "idoc": {
            "xml": "jp{sap_xml}"
          }
        }
      }
    }
  }
}
""",
    "activity_xslt_transform": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON активности "xslt_transform". Верни ТОЛЬКО JSON без пояснений.

Пользователь хочет добавить шаг: "{USER_INPUT}"

Правила:
- Тип активности: "workflow_call" с workflowDef типа "xslt_transform".
- Обязательные поля:
  - "id"
  - "type": "workflow_call"
  - "workflowCall":
    - "workflowDef":
      - "type": "xslt_transform"
      - "details":
        - "xsltTemplate": XSLT шаблон
- Проверь схему на валидность.

Пример:
{
  "id": "xslt_conversion",
  "type": "workflow_call",
  "workflowCall": {
    "workflowDef": {
      "type": "xslt_transform",
      "details": {
        "xsltTemplate": "<xsl:stylesheet>...</xsl:stylesheet>"
      }
    }
  }
}
""",
    "activity_transform": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON активности "transform". Верни ТОЛЬКО JSON без пояснений.

Пользователь хочет добавить шаг: "{USER_INPUT}"

Правила:
- Тип активности: "workflow_call" с workflowDef типа "transform".
- Обязательные поля:
  - "id"
  - "type": "workflow_call"
  - "workflowCall":
    - "workflowDef":
      - "type": "transform"
      - "details":
        - "inputVariable": входная переменная
        - "outputVariable": выходная переменная
        - "mapping": схема преобразования полей
- Проверь схему на валидность.

Пример:
{
  "id": "transform_data",
  "type": "workflow_call",
  "workflowCall": {
    "workflowDef": {
      "type": "transform",
      "details": {
        "inputVariable": "input_var",
        "outputVariable": "output_var",
        "mapping": {
          "newField": "oldField"
        }
      }
    }
  }
}
""",
    "activity_inject": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON активности "inject". Верни ТОЛЬКО JSON без пояснений.

Пользователь хочет добавить шаг: "{USER_INPUT}"

Правила:
- Тип активности: "workflow_call" с workflowDef типа "inject".
- Обязательные поля:
  - "id"
  - "type": "workflow_call"
  - "workflowCall":
    - "workflowDef":
      - "type": "inject"
      - "details":
        - "variables": словарь переменных, которые нужно внедрить
- Проверь схему на валидность.

Пример:
{
  "id": "inject_constants",
  "type": "workflow_call",
  "workflowCall": {
    "workflowDef": {
      "type": "inject",
      "details": {
        "variables": {
          "country": "RU",
          "currency": "RUB"
        }
      }
    }
  }
}
""",
    "activity_switch": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON активности "switch". Верни ТОЛЬКО JSON без пояснений.

Пользователь хочет добавить шаг: "{USER_INPUT}"

Правила:
- Тип активности: "workflow_call" с workflowDef типа "switch".
- Обязательные поля:
  - "id"
  - "type": "workflow_call"
  - "workflowCall":
    - "workflowDef":
      - "type": "switch"
      - "details":
        - "switchConfig": список условий (cases и default)
- Проверь схему на валидность.

Пример:
{
  "id": "switch_case",
  "type": "workflow_call",
  "workflowCall": {
    "workflowDef": {
      "type": "switch",
      "details": {
        "switchConfig": {
          "cases": [
            {"condition": "${var} == 'A'", "transition": "stepA"},
            {"condition": "${var} == 'B'", "transition": "stepB"}
          ],
          "default": "defaultStep"
        }
      }
    }
  }
}
""",
    "activity_parallel": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON активности "parallel". Верни ТОЛЬКО JSON без пояснений.

Пользователь хочет добавить шаг: "{USER_INPUT}"

Правила:
- Тип активности: "workflow_call" с workflowDef типа "parallel".
- Обязательные поля:
  - "id"
  - "type": "workflow_call"
  - "workflowCall":
    - "workflowDef":
      - "type": "parallel"
      - "details":
        - "branches": список параллельных веток
- Проверь схему на валидность.

Пример:
{
  "id": "parallel_exec",
  "type": "workflow_call",
  "workflowCall": {
    "workflowDef": {
      "type": "parallel",
      "details": {
        "branches": ["branchA", "branchB"]
      }
    }
  }
}
""",
    "activity_timer": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON активности "timer". Верни ТОЛЬКО JSON без пояснений.

Пользователь хочет добавить шаг: "{USER_INPUT}"

Правила:
- Тип активности: "workflow_call" с workflowDef типа "timer".
- Обязательные поля:
  - "id"
  - "type": "workflow_call"
  - "workflowCall":
    - "workflowDef":
      - "type": "timer"
      - "details":
        - "delay": задержка в миллисекундах
- Проверь схему на валидность.

Пример:
{
  "id": "wait_timer",
  "type": "workflow_call",
  "workflowCall": {
    "workflowDef": {
      "type": "timer",
      "details": {
        "delay": 5000
      }
    }
  }
}
""",
    "activity_await_for_message": """
Ты — системный аналитик. Твоя задача — строго по описанию ниже сгенерировать JSON активности "await_for_message". Верни ТОЛЬКО JSON без пояснений.

Пользователь хочет добавить шаг: "{USER_INPUT}"

Правила:
- Тип активности: "await_for_message".
- Обязательные поля:
  - "id"
  - "type": "await_for_message"
  - "messageName": название ожидаемого сообщения
- Проверь схему на валидность.

Пример:
{
  "id": "wait_for_message",
  "type": "await_for_message",
  "messageName": "EventReceived"
}
""",
}
