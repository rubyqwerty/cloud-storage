-- Создаём таблицу users
CREATE TABLE IF NOT EXISTS user (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    login TEXT NOT NULL,
    phone TEXT,
    file_count INTEGER DEFAULT 0
);

-- Вставляем тестовые данные
INSERT INTO user (login, phone, file_count) VALUES 
('user1', '1234567890', 3),
('user2', '0987654321', 5),
('user3', '5555555555', 1),
('user4', '1112223333', 0),
('user5', '4445556666', 2);