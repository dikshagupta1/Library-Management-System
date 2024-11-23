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
    int id,year;
    std::cout << "Enter id: ";
    std::cin >> id;
    std::cout << "Enter title: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "Enter author: ";
    std::getline(std::cin, author);
    std::cout << "Enter year: ";
    std::cin >> year;

    library.addBook(Book(id, title, author, year, true));
    std::cout << "Book added successfully.\n";
}

void MenuHandler::searchBook() {
    int searchType;
    std::cout << "Search by:\n";
    std::cout << "1. ID\n";
    std::cout << "2. Title\n";
    std::cout << "3. Author\n";
    std::cout << "Enter your choice: ";
    std::cin >> searchType;

    // Clear input buffer
    std::cin.ignore(); 

    if (searchType == 1) {
        int id;
        std::cout << "Enter Book ID: ";
        std::cin >> id;
        library.findBookById(id);
    } else if (searchType == 2) {
        std::string title;
        std::cout << "Enter Title: ";
        std::getline(std::cin, title);
        library.findBookByTitle(title);
    } else if (searchType == 3) {
        std::string author;
        std::cout << "Enter Author Name: ";
        std::getline(std::cin, author);
        library.findBookByAuthor(author);
    } else {
        std::cout << "Invalid choice.\n";
    }
}

void MenuHandler::borrowBook() {
    int id;
    std::cout << "Enter id to borrow: ";
    std::cin >> id;

    if (!library.borrowBook(id)) {
        std::cout << "Book not available or doesn't exist.\n";
    } else {
        std::cout << "Book borrowed successfully.\n";
    }
}

void MenuHandler::returnBook() {
    int id;
    std::cout << "Enter id to return: ";
    std::cin >> id;

    if (!library.returnBook(id)) {
        std::cout << "Book not found in borrowed list.\n";
    } else {
        std::cout << "Book returned successfully.\n";
    }
}

void MenuHandler::listBooks() {
    library.listBooks();
}
