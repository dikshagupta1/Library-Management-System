#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "database.h"
#include <vector>
#include <string>

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book);
    void findBookByTitle(const std::string& query) const;
    void findBookById(int id) const;
    void findBookByAuthor(const std::string& author) const;
    bool borrowBook(const std::string& title);
    bool returnBook(const std::string& title);
    void listBooks() const;;
    void saveToDb() const;
    void loadFromDb();
};

#endif // LIBRARY_H
