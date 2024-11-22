
### Design Principles
1. **Single Responsibility Principle (SRP)**:
   - Definition: A class should have only one reason to change, meaning it should have only one responsibility or job.
   - Each class has a single responsibility: `Book` represents data, `Library` handles operations, and `Database` manages persistence.

2. **Open/Closed Principle (OCP)**:
   - Definition: Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification.
   - The design allows the addition of new book types or library management features without modifying the existing code. 
      For instance, we can extend the project by adding new types of books (e.g., EBook, AudioBook) without modifying the core Book or Library classes.

3. **Liskov Substitution Principle (LSP)**:
   - Definition: Subtypes must be substitutable for their base types without altering the correctness of the program.
   - If we extend the Book class to create new types (e.g. EBook), the new class should be substitutable for Book in any context without breaking the code.
      For example, the Library class should be able to store both Book and EBook objects without issue.
   
4. **Dependency Inversion Principle (DIP)**:
   - Definition: High-level modules should not depend on low-level modules. Both should depend on abstractions (e.g. interfaces).
   - In this project if we later replace file storage with a database system, the library management logic would not need to change, only the data persistence class.


### Design Focus
   
1. **Modularity**:
   - Code is divided into reusable components for better maintainability.

2. **DRY (Don't Repeat Yourself)**:
   - Avoid redundant code by abstracting common behaviors.

3. **Persistence**:
   - Data is saved and loaded using JSON to maintain state across runs.


### Time Complexity
|Operation|Time Complexity|
|---------|:-------------:|
|Add a Book	     | O(1) |
|Borrow a Book	  | O(n) |
|Return a Book	  | O(n) |
|Search a Book	  | O(n) |
|List All Books  | O(n) |


Project Files Checklist
Source Code:

CMakeLists.txt (for CMake build system)
Dockerfile (for containerization)
Source files (main.cpp, Library.cpp, Book.cpp, Database.cpp)
Header files (Library.h, Book.h, Database.h)
Test Cases:

A test suite using a framework like Google Test or Catch2.
Persistence Files:

JSON or text file for storing book data (books.json).
Documentation:

README.md (with build instructions, usage, and design principles)
UML diagrams and explanations (already provided)
Time complexity analysis.