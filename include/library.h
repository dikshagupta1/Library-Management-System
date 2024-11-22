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
    void searchBookByTitle(const std::string& query) const;
    void searchBookById(int id) const;
    void searchBookByAuthor(const std::string& author) const;
    bool borrowBook(const std::string& title);
    bool returnBook(const std::string& title);
    void displayBooks() const;;
    void saveData() const;
    void loadData();
};

#endif // LIBRARY_H
