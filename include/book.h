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
    Book() = default;
    Book(int id, const std::string &title, const std::string &author, int year, bool available)
        : id(id), title(title), author(author), year(year), available(available) {}

    // Member functions
    void inputDetails();
    void display() const;
    void borrow();
    void returnBook();

    // Getters
    int getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getYear() const { return year; }
    bool isAvailable() const { return available; }

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

#endif // BOOK_H
