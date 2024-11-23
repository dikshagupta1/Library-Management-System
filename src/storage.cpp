#include "storage.h"
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
namespace fs = std::filesystem;

std::string Storage::getDataDirectory() {
    // Get the environment variable LIBRARY_DATA_DIR
    const char* envPath = std::getenv("LIBRARY_DATA_DIR");

    // Use the environment variable if set, otherwise use default
    if (envPath) {
        return std::string(envPath);
    } else {
        return "/home/libraryDir";
    }
}

void Storage::saveData(const std::vector<Book> &books) {
    // Get filePath
    std::string filePath = formFilePath(getDataDirectory());

    // Read from File
    json j;
    for (const auto &book : books) {
        j.push_back({{"id", book.getId()},
                     {"title", book.getTitle()},
                     {"author", book.getAuthor()},
                     {"year", book.getYear()},
                     {"available", book.isAvailable()}});
    }
    std::ofstream file(filePath);
    if (file.is_open()) {
        // Pretty print with 4 spaces
        file << j.dump(4);
    }
}

std::vector<Book> Storage::loadData() {
    // Get filePath
    std::string filePath = formFilePath(getDataDirectory());

    // Write to file
    std::vector<Book> books;
    std::ifstream file(filePath);
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

std::string formFilePath(std::string dataDir) {
    // IF directory doesnt exist, create one
    if (!fs::exists(dataDir)) {
        fs::create_directories(dataDir);
    }

    return dataDiry + "/" + LIBRARY_FILE;
}