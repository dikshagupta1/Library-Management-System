#include "cliHandler.h"
#include "menuHandler.h"
#include "library.h"
#include <iostream>
#include <vector>
#include <string>


int main(int argc, char* argv[]) {
    Library library;

    // Load existing data
    library.loadFromDb();

    if (argc > 1) {
        // Use CLI approach
        CLIHandler cli(library);
        std::vector<std::string> args(argv + 1, argv + argc);
        cli.handleCommand(args);
    } else {
        // Use menu-driven approach
        MenuHandler menu(library);
        menu.start();
    }

    return 0;
}



/*int main() {
    Library library;

    // Load existing data
    library.loadData();

    int choice;
    do {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Add a Book\n";
        std::cout << "2. Borrow a Book\n";
        std::cout << "3. Return a Book\n";
        std::cout << "4. Search a Book by ID\n";
        std::cout << "5. List All Books\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.borrowBook();
                break;
            case 3:
                library.returnBook();
                break;
            case 4:
                library.searchBook();
                break;
            case 5:
                library.listBooks();
                break;
            case 6:
                library.saveData();
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}*/
