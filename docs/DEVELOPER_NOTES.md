
## Developer Notes

### Design Principles
1. **Single Responsibility Principle (SRP)**:
   - Definition: A class should have only one reason to change, meaning it should have only one responsibility or job.
   - Each class has a single responsibility: `Book` represents data, `Library` handles operations, and `Storage` manages persistence.

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

### Key Design Decisions
- **Use of Include Guards:** Prevents multiple inclusions of header files.

- **Modular Design:** Ensures separation of concerns, making the system maintainable.

- **Validation Functions:** Centralized validation improves code reuse.

### Design Focus
1. **Modularity**:
   - Code is divided into reusable components for better maintainability.

2. **DRY (Don't Repeat Yourself)**:
   - Avoid redundant code by abstracting common behaviors.

3. **Persistence**:
   - Data is saved and loaded using JSON to maintain state across runs.

### Standards and Practices
- **C++17 Features:** Leverages modern C++ features like `std::optional`, `std::filesystem`, and `constexpr`.

- **Error Handling:** Consistent use of exceptions for error reporting.

- **Documentation:** Inline comments and meaningful function names for readability.

### Time Complexity
|Operation|Time Complexity|
|---------|:-------------:|
|Add a Book	     | O(n) |
|Borrow a Book	  | O(n) |
|Return a Book	  | O(n) |
|Search a Book	  | O(n) |
|List All Books  | O(n) |
