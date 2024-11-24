-- Создаём таблицу users
CREATE TABLE IF NOT EXISTS user (
    login TEXT PRIMARY KEY,
    password TEXT NOT NULL,
    phone TEXT DEFAULT "+7123453",
    file_count INTEGER DEFAULT 0
);

-- Вставляем тестовые данные
INSERT INTO user (login, password) VALUES 
('user1', '1234567890'),
('user2', '0987654321'),
('user3', '5555555555'),
('user4', '1112223333'),
('user5', '4445556666');