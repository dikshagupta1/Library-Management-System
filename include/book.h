#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
private:
    unsigned int id;
    std::string title;
    std::string author;
    int year;
    bool available;

public:
    // Constructors
    Book(unsigned int id, const std::string title, const std::string author, int year, bool available);

    // Member functions
    void display() const;
    void borrow();
    void returnBook();

    const std::string& getTitle() const;
    const std::string& getAuthor() const;
    int getYear() const;
    unsigned int getId() const;
    bool isAvailable() const;

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

#endif // BOOK_H
