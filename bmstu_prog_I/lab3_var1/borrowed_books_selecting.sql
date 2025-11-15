SELECT users.name, books.title, borrowed_books.borrow_date, borrowed_books.return_date
    FROM borrowed_books 
        INNER JOIN users ON borrowed_books.user_id = users.id 
        INNER JOIN books ON borrowed_books.book_id = books.id
WHERE borrowed_books.return_date >= CURRENT_DATE;
