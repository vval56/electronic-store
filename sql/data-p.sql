CREATE TABLE IF NOT EXISTS products (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    brand TEXT NOT NULL,
    other_name TEXT NOT NULL,
    price INT NOT NULL,
    quantity TEXT NOT NULL,
    category TEXT NOT NULL,
    size  TEXT NOT NULL,
    diagonal  TEXT NOT NULL,
    processor TEXT NOT NULL,
    ram TEXT NOT NULL,
    storage TEXT NOT NULL,
    camera TEXT NOT NULL
);


