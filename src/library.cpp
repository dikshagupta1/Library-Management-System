#include "library.h"
#include "book.h"
#include "database.h"
#include <iostream>
#include <algorithm>

// Add a book to the library
void Library::addBook() {
    Book newBook;
    newBook.inputDetails();
    books.push_back(newBook);
    saveData();
    std::cout << "Book added successfully!" << std::endl;
}

// Borrow a book
void Library::borrowBook() {
    int id;
    std::cout << "Enter the book ID to borrow: ";
    std::cin >> id;

    auto it = std::find_if(books.begin(), books.end(), [id](const Book &book) {
        return book.getId() == id && book.isAvailable();
    });

    if (it != books.end()) {
        it->borrow();
        saveData();
        std::cout << "Book borrowed successfully!" << std::endl;
    } else {
        std::cout << "Book not available or invalid ID." << std::endl;
    }
}

// Return a borrowed book
void Library::returnBook() {
    int id;
    std::cout << "Enter the book ID to return: ";
    std::cin >> id;

    auto it = std::find_if(books.begin(), books.end(), [id](const Book &book) {
        return book.getId() == id && !book.isAvailable();
    });

    if (it != books.end()) {
        it->returnBook();
        saveData();
        std::cout << "Book returned successfully!" << std::endl;
    } else {
        std::cout << "Invalid ID or the book was not borrowed." << std::endl;
    }
}

// List all books
void Library::listBooks() const {
    std::cout << "Library Books List:" << std::endl;
    for (const auto &book : books) {
        book.display();
    }
}

// Search book by ID
void Library::searchBookById() const {
    int id;
    std::cout << "Enter book ID: ";
    std::cin >> id;

    auto it = std::find_if(books.begin(), books.end(), [id](const Book &book) {
        return book.getId() == id;
    });

    if (it != books.end()) {
        it->display();
    } else {
        std::cout << "No book found with ID " << id << std::endl;
    }
}

// Search book by Title
void Library::searchBookByTitle() const {
    std::string title;
    std::cout << "Enter book title: ";
    std::cin.ignore();  // To handle any leftover newline character
    std::getline(std::cin, title);

    auto it = std::find_if(books.begin(), books.end(), [&title](const Book &book) {
        return book.getTitle() == title;
    });

    if (it != books.end()) {
        it->display();
    } else {
        std::cout << "No book found with title " << title << std::endl;
    }
}

// Search book by Author
void Library::searchBookByAuthor() const {
    std::string author;
    std::cout << "Enter author name: ";
    std::cin.ignore();
    std::getline(std::cin, author);

    auto it = std::find_if(books.begin(), books.end(), [&author](const Book &book) {
        return book.getAuthor() == author;
    });

    if (it != books.end()) {
        it->display();
    } else {
        std::cout << "No books found by author " << author << std::endl;
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
