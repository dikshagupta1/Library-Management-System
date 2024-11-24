#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include "library.h"

class MenuHandler {
public:
    explicit MenuHandler(Library& library);
    void start();

private:
    Library& library;

    void addBook();
    void searchBook();
    void borrowBook();
    void returnBook();
    void listBooks();
};

unsigned int readAndValidateId();
int readAndValidateYear();

#endif // MENUHANDLER_H
