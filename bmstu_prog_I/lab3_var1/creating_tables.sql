CREATE TABLE authors (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name VARCHAR (20),
    birth_year INTEGER
);

CREATE TABLE books (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title VARCHAR (50),
    author_id INT,
    publication_year INTEGER,
    genre VARCHAR (20) ,
    FOREIGN KEY (author_id) REFERENCES authors (id) ON UPDATE SET NULL ON DELETE CASCADE
);

CREATE TABLE users (
    id  INTEGER PRIMARY KEY AUTOINCREMENT,
    name VARCHAR (20),
    registration_date DATE
);

CREATE TABLE borrowed_books (
    user_id INT,
    book_id INT,
    borrow_date DATE,
    return_date DATE,
    FOREIGN KEY (user_id)          REFERENCES users (id) ON UPDATE CASCADE,
    FOREIGN KEY (book_id)          REFERENCES books (id) ON UPDATE CASCADE
);
