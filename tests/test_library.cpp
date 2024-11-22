//#define CATCH_CONFIG_MAIN
#include "catch2/catch_test_macros.hpp"
#include "library.h"
#include "book.h"
#include "database.h"
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
    REQUIRE(lib.borrowBook("Borrowable Book") == true);
    // Book is no longer available
    REQUIRE(lib.borrowBook("Borrowable Book") == false);
}

TEST_CASE("Library: Return Book") {
    Library lib;
    Book book(1, "Returnable Book", "Author1", 2021, true);

    lib.addBook(book);
    REQUIRE(lib.borrowBook("Returnable Book") == true);

    // Return the book
    REQUIRE(lib.returnBook("Returnable Book") == true);
    // Cannot return an already returned book
    REQUIRE(lib.returnBook("Returnable Book") == false);
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

    std::cout.rdbuf(oldCout); // Reset std::cout to its original state

    std::string expectedOutput = "Id: 1, Title: Title1, Author: Author1, Year: 2021, Available: true\n"
                                 "Id: 2, Title: Title2, Author: Author2, Year: 2022, Available: true\n";

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
    lib.findBookById(2); // Non-existent ID

    std::cout.rdbuf(oldCout); // Reset std::cout

    std::string expectedOutput = "Id: 1, Title: Unique Title, Author: Author1, Year: 2021, Available: true\n"
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

    std::cout.rdbuf(oldCout); // Reset std::cout

    std::string expectedOutput = "Id: 1, Title: Searchable Title, Author: Author1, Year: 2021, Available: true\n"
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

    std::cout.rdbuf(oldCout); // Reset std::cout

    std::string expectedOutput = "Id: 1, Title: Title1, Author: Common Author, Year: 2021, Available: true\n"
                                 "Id: 2, Title: Title2, Author: Common Author, Year: 2022, Available: true\n";

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


/* Test for adding a book
TEST_CASE("Add a book to the library") {
    Library library;
    library.loadFromDb;

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
    library.loadFromDb();

    // Simulate adding a test book
    Book testBook(1, "Test Title", "Test Author", 2024, true);
    library.addBook(testBook);

    library.borrowBook();
    REQUIRE(testBook.isAvailable() == false);
}

// Test for returning a book
TEST_CASE("Return a book to the library") {
    Library library;
    library.loadFromDb();

    Book testBook(2, "Test Title 2", "Test Author 2", 2023, false);
    library.addBook(testBook);

    library.returnBook();
    REQUIRE(testBook.isAvailable() == true);
}

// Test for searching a book by ID
TEST_CASE("Search for a book by ID") {
    Library library;
    library.loadFromDb();

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
    library.loadFromDb();

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
    library.loadFromDb();

    Book testBook(5, "Another Search Book", "Some Author", 2020, true);
    library.addBook(testBook);

    std::streambuf *oldCout = std::cout.rdbuf();
    std::ostringstream captureOutput;
    std::cout.rdbuf(captureOutput.rdbuf());

    library.searchBookByAuthor();
    REQUIRE(captureOutput.str().find("Some Author") != std::string::npos);

    std::cout.rdbuf(oldCout);
}*/
