#include "storage.h"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void Storage::saveData(const std::vector<Book> &books) {
    json j;
    for (const auto &book : books) {
        j.push_back({{"id", book.getId()},
                     {"title", book.getTitle()},
                     {"author", book.getAuthor()},
                     {"year", book.getYear()},
                     {"available", book.isAvailable()}});
    }
    std::ofstream file(LIBRARY_FILE);
    if (file.is_open()) {
        // Pretty print with 4 spaces
        file << j.dump(4);
    }
}

std::vector<Book> Storage::loadData() {
    std::vector<Book> books;
    std::ifstream file(LIBRARY_FILE);
    if (file.is_open()) {
        json j;
        file >> j;
        books.clear();
        for (const auto &item : j) {
            Book book(item["id"], item["title"], item["author"], item["year"], item["available"]);
            books.push_back(book);
        }
    }
    return books;
}
