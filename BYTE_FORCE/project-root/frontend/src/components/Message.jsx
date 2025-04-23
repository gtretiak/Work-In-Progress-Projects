import React from 'react';

const Message = ({ sender, text }) => {
  return (
    <div className={`message ${sender === 'user' ? 'user' : 'ai'}`}>
      <div className="bubble">
        <strong>{sender === 'user' ? 'You' : 'AI'}:</strong> {text}
      </div>
    </div>
  );
};

export default Message;
