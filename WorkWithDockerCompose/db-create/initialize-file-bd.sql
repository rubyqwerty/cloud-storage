-- Создаём таблицу files
CREATE TABLE IF NOT EXISTS file (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    file_name TEXT NOT NULL,
    file_path TEXT NOT NULL,
    verified_user TEXT DEFAULT NULL,
    verification_status TEXT DEFAULT "not confirmed"
);