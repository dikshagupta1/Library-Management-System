#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "library.h"
#include "book.h"

// Test for adding a book
TEST_CASE("Add a book to the library") {
    Library library;
    library.loadData();

    std::streambuf *oldCout = std::cout.rdbuf();
    std::ostringstream captureOutput;
    std::cout.rdbuf(captureOutput.rdbuf());

    library.addBook();
    REQUIRE(captureOutput.str().find("Book added successfully") != std::string::npos);

    std::cout.rdbuf(oldCout);
}

// Test for borrowing a book
TEST_CASE("Borrow a book from the library") {
    Library library;
    library.loadData();

    // Simulate adding a test book
    Book testBook(1, "Test Title", "Test Author", 2024, true);
    library.addBook(testBook);

    library.borrowBook();
    REQUIRE(testBook.isAvailable() == false);
}

// Test for returning a book
TEST_CASE("Return a book to the library") {
    Library library;
    library.loadData();

    Book testBook(2, "Test Title 2", "Test Author 2", 2023, false);
    library.addBook(testBook);

    library.returnBook();
    REQUIRE(testBook.isAvailable() == true);
}

// Test for searching a book by ID
TEST_CASE("Search for a book by ID") {
    Library library;
    library.loadData();

    Book testBook(3, "Searchable Book", "Author Search", 2022, true);
    library.addBook(testBook);

    std::streambuf *oldCout = std::cout.rdbuf();
    std::ostringstream captureOutput;
    std::cout.rdbuf(captureOutput.rdbuf());

    library.searchBookById();
    REQUIRE(captureOutput.str().find("Searchable Book") != std::string::npos);

    std::cout.rdbuf(oldCout);
}

// Test for searching a book by Title
TEST_CASE("Search for a book by Title") {
    Library library;
    library.loadData();

    Book testBook(4, "Title Search Book", "Another Author", 2021, true);
    library.addBook(testBook);

    std::streambuf *oldCout = std::cout.rdbuf();
    std::ostringstream captureOutput;
    std::cout.rdbuf(captureOutput.rdbuf());

    library.searchBookByTitle();
    REQUIRE(captureOutput.str().find("Title Search Book") != std::string::npos);

    std::cout.rdbuf(oldCout);
}

// Test for searching a book by Author
TEST_CASE("Search for a book by Author") {
    Library library;
    library.loadData();

    Book testBook(5, "Another Search Book", "Some Author", 2020, true);
    library.addBook(testBook);

    std::streambuf *oldCout = std::cout.rdbuf();
    std::ostringstream captureOutput;
    std::cout.rdbuf(captureOutput.rdbuf());

    library.searchBookByAuthor();
    REQUIRE(captureOutput.str().find("Some Author") != std::string::npos);

    std::cout.rdbuf(oldCout);
}
