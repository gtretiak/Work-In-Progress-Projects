import React, { useState } from 'react';
import ChatWindow from './components/ChatWindow';
import ChatInput from './components/ChatInput';
import axios from 'axios';
import './styles.css';

function App() {
  const [messages, setMessages] = useState([]);
  const [isLoading, setIsLoading] = useState(false);
  const [sessionId, setSessionId] = useState(generateSessionId());

  // Генерация уникального ID сессии
  function generateSessionId() {
    return Math.random().toString(36).substr(2, 9);
  }

  // Сброс сессии
  const resetSession = async () => {
    try {
      await axios.post('/reset-session', { session_id: sessionId });
      setMessages([]);
      setSessionId(generateSessionId());
    } catch (err) {
      console.error('Ошибка сброса сессии:', err);
    }
  };

  // Отправка сообщения
  const sendMessage = async (text) => {
    if (isLoading) return;

    // Обработка команды сброса
    if (text.toLowerCase().includes('новая схема')) {
      await resetSession();
      setMessages([{ sender: 'system', text: '🔄 Начинаем новую сессию!' }]);
      return;
    }

    const userMsg = { sender: 'user', text };
    setMessages((prev) => [...prev, userMsg]);
    setIsLoading(true);

    try {
      const res = await axios.post('/generate-schema', {
        session_id: sessionId,
        user_input: text
      });

      const aiResponse = res.data.schema;
      const aiMsg = { sender: 'ai', text: aiResponse };

      setMessages((prev) => [...prev, aiMsg]);

    } catch (err) {
      console.error(err);
      const errorText = err.response?.data?.detail || 'Ошибка сервера';
      setMessages((prev) => [
        ...prev,
        { sender: 'ai-error', text: `⚠️ Ошибка: ${errorText}` },
      ]);
    } finally {
      setIsLoading(false);
    }
  };

  return (
    <div className="app-container">
      <div className="chat-header">
        <h1 className="chat-title">AI Schema Builder</h1>
        <button
          className="reset-button"
          onClick={resetSession}
          title="Начать новую сессию"
        >
          ⟳
        </button>
      </div>
      <ChatWindow messages={messages} />
      <ChatInput
        onSend={sendMessage}
        isLoading={isLoading}
        placeholder="Введите описание интеграции или 'Новая схема'..."
      />
    </div>
  );
}

export default App;
