import React, { useState } from 'react';

const ChatInput = ({ onSend, isLoading }) => {
    const [input, setInput] = useState('');
  
    const handleSubmit = () => {
      if (input.trim() !== '' && !isLoading) {
        onSend(input);
        setInput('');
      }
    };
  
    return (
      <div className="chat-input">
        <input
          type="text"
          placeholder="Введите сообщение..."
          value={input}
          onChange={(e) => setInput(e.target.value)}
          onKeyDown={(e) => e.key === 'Enter' && handleSubmit()}
          disabled={isLoading} // блокировка во время запроса
        />
        <button onClick={handleSubmit} disabled={isLoading}>
          {isLoading ? '...' : 'Отправить'}
        </button>
      </div>
    );
  };

export default ChatInput;
