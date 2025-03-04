-- Создание таблицы пользователей
CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT NOT NULL UNIQUE,
    password TEXT NOT NULL,
    is_admin BOOLEAN DEFAULT FALSE
);

-- Добавление тестовых пользователей
INSERT INTO users (username, password, is_admin) VALUES ('admin', 'password', TRUE);
INSERT INTO users (username, password, is_admin) VALUES ('user', '12345', FALSE);
