cmake_minimum_required(VERSION 3.14)
project(LibraryManagementSystem)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
    src/main.cpp
    src/Library.cpp
    src/Book.cpp
    src/Database.cpp
    src/CLIHandler.cpp
    src/MenuHandler.cpp
)

# Include directories
include_directories(include)

# Add the nlohmann/json header-only library
find_package(nlohmann_json REQUIRED)
include_directories(${nlohmann_json_INCLUDE_DIRS})

# Add executable target
add_executable(LibraryManagementSystem ${SOURCES})
add_executable(tests test_library.cpp)
target_link_libraries(tests PRIVATE nlohmann_json::nlohmann_json)

# Link external libraries if needed (e.g., JSON library)

target_link_libraries(LibraryManagementSystem PRIVATE nlohmann_json::nlohmann_json)
