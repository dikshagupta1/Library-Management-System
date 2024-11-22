#include "cliHandler.h"
#include <iostream>
#include <sstream>

CLIHandler::CLIHandler(Library& library) : library(library) {}

void CLIHandler::handleCommand(const std::vector<std::string>& args) {
    if (args.empty()) {
        displayHelp();
        return;
    }

    const std::string& command = args[0];
    if (command == "help") {
        displayHelp();
    } else if (command == "add") {
        addBook(args);
    } else if (command == "search") {
        searchBook(args);
    } else if (command == "borrow") {
        borrowBook(args);
    } else if (command == "return") {
        returnBook(args);
    } else if (command == "list") {
        listBooks();
    } else {
        std::cerr << "Error: Unknown command '" << command << "'.\n";
        displayHelp();
    }
}

void CLIHandler::addBook(const std::vector<std::string>& args) {
    if (args.size() < 5) {
        std::cerr << "Usage: add <id> <title> <author> <year>\n";
        return;
    }

    int id = std::stoi(args[1]);
    std::string title = args[2];
    std::string author = args[3];
    int year = std::stoi(args[4]);

    Book book(id, title, author, year, true);
    library.addBook(book);

    std::cout << "Book added successfully.\n";
}

void CLIHandler::searchBook(const std::vector<std::string>& args) {
    if (args.size() < 3) {
        std::cerr << "Usage: search <title|author|id> <query>\n";
        return;
    }

    const std::string& mode = args[1];
    const std::string& query = args[2];

    if (mode == "title") {
        library.findBookByTitle(query);
    } else if (mode == "author") {
        library.findBookByAuthor(query);
    } else if (mode == "id") {
        library.findBookById(std::stoi(query));
    } else {
        std::cerr << "Error: Invalid search mode. Use 'title', 'author', or 'id'.\n";
    }
}

void CLIHandler::borrowBook(const std::vector<std::string>& args) {
    if (args.size() < 2) {
        std::cerr << "Usage: borrow <title>\n";
        return;
    }

    const std::string& title = args[1];

    if (library.borrowBook(title)) {
        std::cout << "Book borrowed successfully.\n";
    } else {
        std::cerr << "Error: Book is unavailable or not found.\n";
    }
}

void CLIHandler::returnBook(const std::vector<std::string>& args) {
    if (args.size() < 2) {
        std::cerr << "Usage: return <title>\n";
        return;
    }

    const std::string& title = args[1];

    if (library.returnBook(title)) {
        std::cout << "Book returned successfully.\n";
    } else {
        std::cerr << "Error: Book was not borrowed or not found.\n";
    }
}

void CLIHandler::listBooks() {
    library.listBooks();
}

void CLIHandler::displayHelp() const {
    std::cout << "Available commands:\n"
              << "  help           Show this help message\n"
              << "  add            Add a new book (title, author, year)\n"
              << "  search         Search for a book using the modes - id, title or author \n"
              << "  borrow         Borrow a book (title)\n"
              << "  return         Return a borrowed book (title)\n"
              << "  list           List all books in the library\n";
}