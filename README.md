# Library Management System

## Overview
This Library Management System is a comprehensive solution for managing books and library operations. The system is implemented in C++17 and includes both menu-based and Command-Line Interface (CLI)-based approaches, offering flexibility and ease of use.

### Key Features
- **Menu-Based Approach**: User-friendly, interactive menu for navigating library operations.
- **CLI-Based Approach**: Enables advanced users to execute specific commands directly.
- **Persistent Storage**: Book data is stored in a JSON file, ensuring data is saved between sessions.
- **Validation**: Robust validation for inputs like book ID, publication year, and duplicate entries.
- **Extensible Architecture**: The project uses a modular design, making it easy to add new features.

---

## Table of Contents
1. [Project Structure](#project-structure)
2. [Installation](#installation)
3. [Configuration](#configuration)
4. [Usage](#usage)
5. [Validation Mechanisms](#validation-mechanisms)
6. [Testing](#testing)
7. [Extending the System](#extending-the-system)
8. [Known Issues and Limitations](#known-issues-and-limitations)
9. [Future Enhancements](#future-enhancements)
10. [Architecture Overview](#architecture-overview)

---

## Project Structure
```
LibraryManagementSystem/
|├── src/
|   |├── CLIHandler.cpp   # Implementation for CLI handling
|   |├── MenuHandler.cpp  # Implementation for menu-driven handling
|   |├── Storage.cpp      # Handles JSON data storage and retrieval
|   |├── Library.cpp      # Core library logic
|   └── main.cpp          # Entry point of the program
|├── include/
|   |├── CLIHandler.h     # Header for CLI handling
|   |├── MenuHandler.h    # Header for menu-driven handling
|   |├── Storage.h        # Header for JSON storage
|   |├── Library.h        # Header for library logic
|├── data/
|   └── library_data.json # Persistent JSON data file stored in the directory provided by ENV. Check [configuration](#configuration)
|├── tests/
|   └── test_library.cpp  # Unit tests for library functions
│   └── CMakeLists.txt    # Build test
|├── CMakeLists.txt       # Build configuration file
|└── README.md            # Documentation
```

---

## Installation

### Prerequisites
- **C++17 Compiler**: Ensure your environment supports C++17.
- **CMake**: For building the project.
- **JSON Library**: Integrated using nlohmann/json.
- **Docker**: Optional, for containerization.

### Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/dikshagupta1/Library-Management-System.git
   cd Library-Management-System
   ```
2. Build and run the project: 
    #### **Using CMake**
    Build:
   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```
    The executable gets generated in the build directory.
    
    #### **Using Docker**
    Build the Docker image:
    ```bash
    docker build -t library-management-system .
    ```

    Run the container:
    ```bash
    docker run --rm library-management-system
    ```
---

## Configuration
### Persistent Storage Directory
The JSON file storing library data is configured via an environment variable for flexibility.
1. Set the environment variable:
    - Linux/macOS:
   ```bash
   export LIBRARY_DATA_DIR=/path/to/data
   ```

   - Windows (Command Prompt):
   ```bash
   set LIBRARY_DATA_DIR=C:\absolute\path\to\data
    ```
2. The system will store `library-db.json` in the specified directory.

---
## Usage

### CLI-Based Approach
1. Goto the build directory and run the cli command to access the help doc:
    ```bash
   ./LibraryManagementSystem help
    ```

2. Enter specific commands:
   - `add <id> <title> <author> <year>`: Add a new book.
   - `list`: Display all books.
   - `borrow <id>`: Borrow a book by its ID.
   - `return <id>`: Return a book by its ID.
   - `search <mode> <query>`: Search for a book using the modes - id, title or author.
   
### Menu-Based Approach
1. Goto the build directory and run the application:
    ```bash
   ./LibraryManagementSystem
    ```
2. Use the numbered menu options displayed to navigate through the system.
3. Perform operations such as adding, borrowing, returning, listing, or searching for books.

### Example
**CLI Interaction:**
```
$ ./LibraryManagementSystem add 1 "Midnight's Children" "Salman Rushdie" 1981
Book added successfully.
```
```
$ ./LibraryManagementSystem list
Id: 1, Title: Midnight's Children, Author: Salman Rushdie, Year:1981, Available: Yes
```
```
$ ./LibraryManagementSystem borrow 1
Book borrowed successfully.
```
```
$ ./LibraryManagementSystem list
Id: 1, Title: Midnight's Children, Author: Salman Rushdie, Year: 1981, Available: No
```

**Menu-Based Interaction:**
```
$ ./LibraryManagementSystem
--- Library Management System ---
1. Add Book
2. Search Book
3. Borrow Book
4. Return Book
5. List All Books
0. Exit
Enter your choice: 1
Enter Book id: 11
Enter title: Midnight's Children
Enter author: Salman Rushdie
Enter year of publishing: 1981
Book added successfully.
```

---

## Validation Mechanisms
- **Book ID**: Ensures IDs are unique and numeric.
- **Year**: Validates that the year is within a realistic range (e.g., 1000 to the current year).
- **Duplicate Entries**: Prevents books with identical IDs from being added.

---

## Testing
Unit tests are included to ensure the correctness of the system.

### Running the Tests
1. Build the project with the test target:
   ```bash
   mkdir build 
   cd build
   cmake -DENABLE_TESTS=ON ..
   make
   ```
2. Execute the test binary:
   ```bash
   ./tests/tests
   ```

---
## Extending the System
To add new features:
1. Define new functionality in `Library.h` and `Library.cpp`.
2. Extend CLI commands in `CLIHandler.cpp` or menu options in `MenuHandler.cpp`.
3. Update `Storage` for persistent data handling if required.

---

## Known Issues and Limitations
- User needs to enter the Book Id manually while adding a book.
- The system currently supports basic library operations only.
- Limited to a single JSON file for storage.
- No user authentication or multi-user capabilities.

---

## Future Enhancements 

#### This is an initial MVP of the Library Management System. Please read the planned future enhancements [here](docs/FUTURE_ENHANCEMENTS.md).
---

## Architecture Overview
#### For architecture overview and developer notes about the design principles and decisions read [Architecture Overview](docs/ARCHITECTURAL_OVERVIEW.md).
---