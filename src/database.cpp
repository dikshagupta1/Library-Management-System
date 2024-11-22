#include "database.h"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void Database::saveData(const std::vector<Book> &books) {
    json j;
    for (const auto &book : books) {
        j.push_back({{"id", book.getId()},
                     {"title", book.getTitle()},
                     {"author", book.getAuthor()},
                     {"year", book.getYear()},
                     {"available", book.isAvailable()}});
    }
    std::ofstream file("books.json");
    file << j.dump(4);
}

std::vector<Book> Database::loadData() {
    std::vector<Book> books;
    std::ifstream file("books.json");
    if (file) {
        json j;
        file >> j;
        for (const auto &item : j) {
            Book book(item["id"], item["title"], item["author"], item["year"], item["available"]);
            books.push_back(book);
        }
    }
    return books;
}
