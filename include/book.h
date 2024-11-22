#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    int year;
    bool available;

public:
    // Constructors
    Book(int id, const std::string title, const std::string author, int year, bool available);

    // Member functions
    void display() const;
    void borrow();
    void returnBook();

    const std::string& getTitle() const;
    const std::string& getAuthor() const;
    int getYear() const;
    int getId() const;
    bool isAvailable() const;

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

#endif // BOOK_H
