#ifndef CLIHANDLER_H
#define CLIHANDLER_H

#include "library.h"
#include <vector>
#include <string>

class CLIHandler {
public:
    explicit CLIHandler(Library& library);
    void handleCommand(const std::vector<std::string>& args);

private:
    Library& library;

    void addBook(const std::vector<std::string>& args);
    void searchBook(const std::vector<std::string>& args);
    void borrowBook(const std::vector<std::string>& args);
    void returnBook(const std::vector<std::string>& args);
    void listBooks();
    void CLIHandler::displayHelp() const;
};

#endif // CLIHANDLER_H
