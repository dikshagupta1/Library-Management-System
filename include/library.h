#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Database.h"
#include <vector>
#include <string>

class Library {
private:
    std::vector<Book> books;

public:
    void addBook();
    void borrowBook();
    void returnBook();
    void listBooks() const;
    void searchBookById() const;
    void searchBookByTitle() const;
    void searchBookByAuthor() const;
    void saveData() const;
    void loadData();
};

#endif // LIBRARY_H
