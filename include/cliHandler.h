#ifndef CLIHANDLER_H
#define CLIHANDLER_H

#include "Library.h"
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
};

#endif // CLIHANDLER_H
