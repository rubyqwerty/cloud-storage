-- Создаём таблицу files
CREATE TABLE IF NOT EXISTS file (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    file_name TEXT NOT NULL,
    file_path TEXT NOT NULL,
    verification_status TEXT DEFAULT "not confirmed"
);

-- Вставляем тестовые данные
INSERT INTO file (file_name, file_path) VALUES 
('file1.txt', '/path/to/file1.txt'),
('file2.txt', '/path/to/file2.txt'),
('file3.pdf', '/path/to/file3.pdf'),
('file4.docx', '/path/to/file4.docx'),
('file5.jpg', '/path/to/file5.jpg');