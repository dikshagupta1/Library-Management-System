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