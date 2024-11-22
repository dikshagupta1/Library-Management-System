#ifndef DATABASE_H
#define DATABASE_H

#include "book.h"
#include <vector>

const std::string LIBRARY_FILE = "library-db.json";

class Database {
public:
    static void saveData(const std::vector<Book> &books);
    static std::vector<Book> loadData();
};

#endif // DATABASE_H
