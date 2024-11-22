#include "library.h"
#include "book.h"
#include "database.h"
#include <iostream>
#include <algorithm>

// Add a book to the library
void Library::addBook(const Book& book) {
    books.push_back(book);
    saveToDb();
}

// Borrow a book
bool Library::borrowBook(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title && book.isAvailable()) {
            book.borrow();
            saveToDb();
            return true;
        }
    }
    return false;
}

// Return a borrowed book
bool Library::returnBook(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title && !book.isAvailable()) {
            book.returnBook();
            saveToDb();
            return true;
        }
    }
    return false;
}

// List all books
void Library::listBooks() const {
   for (const auto& book : books) {
        std::cout << book << "\n";
    }
}

// Search book by ID
void Library::findBookById(int id) const {
     for (const auto& book : books) {
        if (book.getId() == id) {
            std::cout << book << "\n";
            return;
        }
    }
    std::cout << "No book found with ID: " << id << "\n";
}

// Search book by Title
void Library::findBookByTitle(const std::string& query) const {
    for (const auto& book : books) {
        if (book.getTitle() == query) {
            std::cout << book << "\n";
            return;
        }
    }
    std::cout << "No book found with title: " << query << "\n";
}

// Search book by Author
void Library::findBookByAuthor(const std::string& author) const {
     for (const auto& book : books) {
        if (book.getAuthor() == author) {
            std::cout << book << "\n";
        }
    }
}

// Save the current state of the library to a file
void Library::saveToDb() const {
    Database::saveData(books);
}

// Load the data from the file
void Library::loadFromDb() {
    books = Database::loadData();
}
