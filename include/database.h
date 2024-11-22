#ifndef DATABASE_H
#define DATABASE_H

#include "Book.h"
#include <vector>

class Database {
public:
    static void saveData(const std::vector<Book> &books);
    static std::vector<Book> loadData();
};

#endif // DATABASE_H
