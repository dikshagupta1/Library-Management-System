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
    void displayHelp() const;
};

unsigned int validateId(const std::string& input);
int validateYear(const std::string& input);

#endif // CLIHANDLER_H
