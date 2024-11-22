#include "menuHandler.h"
#include <iostream>
#include <string>

MenuHandler::MenuHandler(Library& library) : library(library) {}

void MenuHandler::start() {
    int choice;
    do {
        std::cout << "\n--- Library Management System ---\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Search Book\n";
        std::cout << "3. Borrow Book\n";
        std::cout << "4. Return Book\n";
        std::cout << "5. List All Books\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: borrowBook(); break;
            case 4: returnBook(); break;
            case 5: listBooks(); break;
            case 0: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

void MenuHandler::addBook() {
    std::string title, author;
    int year;
    std::cout << "Enter title: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "Enter author: ";
    std::getline(std::cin, author);
    std::cout << "Enter year: ";
    std::cin >> year;

    library.addBook(Book(title, author, year));
    std::cout << "Book added successfully.\n";
}

void MenuHandler::searchBook() {
    std::string query;
    std::cout << "Enter title or author to search: ";
    std::cin.ignore();
    std::getline(std::cin, query);

    library.searchBooks(query);
}

void MenuHandler::borrowBook() {
    std::string title;
    std::cout << "Enter title to borrow: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    if (!library.borrowBook(title)) {
        std::cout << "Book not available or doesn't exist.\n";
    } else {
        std::cout << "Book borrowed successfully.\n";
    }
}

void MenuHandler::returnBook() {
    std::string title;
    std::cout << "Enter title to return: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    if (!library.returnBook(title)) {
        std::cout << "Book not found in borrowed list.\n";
    } else {
        std::cout << "Book returned successfully.\n";
    }
}

void MenuHandler::listBooks() {
    library.listBooks();
}
