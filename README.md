# Library-Management-System

## Overview
The Library Management System is a C++17-based project that provides functionality for managing a library of books, including adding, searching, borrowing, and returning books. 
Data is persistently stored in JSON format.

## Features
- Add books with details like title, author, year, and availability.
- Search books by title, author, or ID.
- Borrow and return books.
- List all books.
- Persistent JSON-based data storage.

## Requirements
- C++17
- CMake 3.10 or higher
- Docker (optional for containerized execution)
- JSON library: [nlohmann/json](https://github.com/nlohmann/json)

## Build Instructions

### Using CMake
1. Clone the repository:
   ```bash
   git clone https://github.com/dikshagupta1/Library-Management-System.git
   cd LibraryManagementSystem

2. Build the project
    ```bash
    mkdir build && cd build #Create a build directory
    cmake .. #Run CMake
    cmake --build . #Build the project

3. Run the program:
    ```bash
    ./LibraryManagementSystem

### Using Docker
1. Build the Docker image:
   ```bash
   docker build -t library-management-system .

2. Run the container:
    ```bash
    docker run --rm library-management-system

## Test Instructions
1. Install Catch2:
   ```bash
  sudo apt install catch2

2. Compile and run tests:
    ```bash
    cd tests
    mkdir build && cd build
    cmake ..
    make
    ./run_tests

