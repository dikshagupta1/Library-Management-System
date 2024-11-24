//#define CATCH_CONFIG_MAIN
#include "catch2/catch_test_macros.hpp"
#include "library.h"
#include "book.h"
#include "storage.h"
#include <sstream>

TEST_CASE("Library: Add Book") {
    Library lib;
    Book book1(1, "Title1", "Author1", 2021, true);
    Book book2(2, "Title2", "Author2", 2022, true);

    lib.addBook(book1);
    lib.addBook(book2);

    // Check if the books were added successfully
    REQUIRE_NOTHROW(lib.findBookById(1));
    REQUIRE_NOTHROW(lib.findBookById(2));
}

TEST_CASE("Library: Borrow Book") {
    Library lib;
    Book book(1, "Borrowable Book", "Author1", 2021, true);

    lib.addBook(book);

    // Book is available initially
    REQUIRE(lib.borrowBook(1) == true);
    // Book is no longer available
    REQUIRE(lib.borrowBook(1) == false);
}

TEST_CASE("Library: Return Book") {
    Library lib;
    Book book(1, "Returnable Book", "Author1", 2021, true);

    lib.addBook(book);
    REQUIRE(lib.borrowBook(1) == true);

    // Return the book
    REQUIRE(lib.returnBook(1) == true);
    // Cannot return an already returned book
    REQUIRE(lib.returnBook(1) == false);
}

TEST_CASE("Library: List Books") {
    Library lib;
    Book book1(1, "Title1", "Author1", 2021, true);
    Book book2(2, "Title2", "Author2", 2022, true);

    lib.addBook(book1);
    lib.addBook(book2);

    // Redirect output to test
    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    lib.listBooks();

    // Reset std::cout to its original state
    std::cout.rdbuf(oldCout);
    std::string expectedOutput = "Id: 1, Title: Title1, Author: Author1, Year: 2021, Available: Yes\n"
                                 "Id: 2, Title: Title2, Author: Author2, Year: 2022, Available: Yes\n";

    REQUIRE(output.str() == expectedOutput);
}

TEST_CASE("Library: Find Book by ID") {
    Library lib;
    Book book(1, "Unique Title", "Author1", 2021, true);
    lib.addBook(book);

    // Redirect output to test
    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    lib.findBookById(1);
    // Non-existent ID
    lib.findBookById(2);

    std::cout.rdbuf(oldCout);

    std::string expectedOutput = "Id: 1, Title: Unique Title, Author: Author1, Year: 2021, Available: Yes\n"
                                 "No book found with ID: 2\n";

    REQUIRE(output.str() == expectedOutput);
}

TEST_CASE("Library: Find Book by Title") {
    Library lib;
    Book book(1, "Searchable Title", "Author1", 2021, true);
    lib.addBook(book);

    // Redirect output to test
    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    lib.findBookByTitle("Searchable Title");
    lib.findBookByTitle("Non-Existent Title");

    // Reset std::cout
    std::cout.rdbuf(oldCout);

    std::string expectedOutput = "Id: 1, Title: Searchable Title, Author: Author1, Year: 2021, Available: Yes\n"
                                 "No book found with title: Non-Existent Title\n";

    REQUIRE(output.str() == expectedOutput);
}

TEST_CASE("Library: Find Book by Author") {
    Library lib;
    Book book1(1, "Title1", "Common Author", 2021, true);
    Book book2(2, "Title2", "Common Author", 2022, true);
    lib.addBook(book1);
    lib.addBook(book2);

    // Redirect output to test
    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    lib.findBookByAuthor("Common Author");
    lib.findBookByAuthor("Non-Existent Author");

    // Reset std::cout
    std::cout.rdbuf(oldCout); 

    std::string expectedOutput = "Id: 1, Title: Title1, Author: Common Author, Year: 2021, Available: Yes\n"
                                 "Id: 2, Title: Title2, Author: Common Author, Year: 2022, Available: Yes\n";

    REQUIRE(output.str() == expectedOutput);
}

TEST_CASE("Library: Save and Load Data") {
    Library lib;
    Book book1(1, "Title1", "Author1", 2021, true);
    Book book2(2, "Title2", "Author2", 2022, true);

    lib.addBook(book1);
    lib.addBook(book2);

    // Save data to DB
    REQUIRE_NOTHROW(lib.saveToDb());

    // Load data from DB
    Library newLib;
    REQUIRE_NOTHROW(newLib.loadFromDb());

    // Verify data loaded correctly
    REQUIRE_NOTHROW(newLib.findBookById(1));
    REQUIRE_NOTHROW(newLib.findBookById(2));
}