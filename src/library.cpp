#include "library.h"
#include "book.h"
#include "database.h"
#include <iostream>
#include <algorithm>

// Add a book to the library
void Library::addBook(const Book& book) {
    books.push_back(book);
    saveData();
}

// Borrow a book
bool Library::borrowBook(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title && book.isAvailable()) {
            book.borrow();
            saveData();
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
            saveData();
            return true;
        }
    }
    return false;
}

// List all books
void Library::listBooks() const {
    for (const auto &book : books) {
        book.display();
    }
}

// Search book by ID
void Library::searchBookById(int id) const {
     for (const auto& book : books) {
        if (book.getID() == id) {
            std::cout << book << "\n";
            return;
        }
    }
    std::cout << "No book found with ID: " << id << "\n";
}

// Search book by Title
void Library::searchBookByTitle(const std::string& query) const {
    for (const auto& book : books) {
        if (book.getTitle() == query) {
            std::cout << book << "\n";
            return;
        }
    }
    std::cout << "No book found with title: " << query << "\n";
}

// Search book by Author
void Library::searchBookByAuthor(const std::string& author) const {
     for (const auto& book : books) {
        if (book.getAuthor() == author) {
            std::cout << book << "\n";
        }
    }
}

// Save the current state of the library to a file
void Library::saveData() const {
    Database::saveData(books);
}

// Load the data from the file
void Library::loadData() {
    books = Database::loadData();
}
