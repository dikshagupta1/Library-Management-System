#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "storage.h"
#include <vector>
#include <string>

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book);
    void findBookByTitle(const std::string& query) const;
    void findBookById(unsigned int id) const;
    void findBookByAuthor(const std::string& author) const;
    bool borrowBook(unsigned int id);
    bool returnBook(unsigned int id);
    void listBooks() const;
    void saveToDb() const;
    void loadFromDb();
};

#endif // LIBRARY_H
