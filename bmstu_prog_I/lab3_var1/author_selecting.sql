SELECT books.title, books.publication_year, authors.name 
    FROM books INNER JOIN authors ON books.author_id = authors.id
WHERE authors.name == 'А.С.Пушкин';
