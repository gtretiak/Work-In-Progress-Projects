# ================= Stage 1: Backend =================
FROM python:3.10-slim AS backend

WORKDIR /app

# Копируем зависимости и устанавливаем
COPY backend/requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

# Копируем весь бэкенд код
COPY backend .

# ================= Stage 2: Frontend =================
FROM node:18-slim AS frontend

WORKDIR /frontend

# Копируем package.json и ставим зависимости
COPY frontend/package*.json ./
RUN npm install

# Копируем весь фронтенд код и билдим
COPY frontend .
RUN npm run build

# ================= Stage 3: Final Image =================
FROM python:3.10-slim

WORKDIR /app

# Копируем готовый бэкенд
COPY --from=backend /app /app

# Копируем собранный фронтенд
COPY --from=frontend /frontend/build /app/static

# Установка зависимостей ещё раз для чистоты
RUN pip install --no-cache-dir -r requirements.txt

# Открываем порт
EXPOSE 8000

# Запуск Uvicorn
CMD ["uvicorn", "app:app", "--host", "0.0.0.0", "--port", "8000"]
