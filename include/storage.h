#ifndef STORAGE_H
#define STORAGE_H

#include "book.h"
#include <vector>

const std::string LIBRARY_FILE = "library-db.json";

class Storage {
private:
    std::string getDataDirectory() const;    
public:
    static void saveData(const std::vector<Book> &books);
    static std::vector<Book> loadData();
};

#endif // STORAGE_H
