cmake_minimum_required(VERSION 3.14)
project(LibraryManagementSystem)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
    src/main.cpp
    src/library.cpp
    src/book.cpp
    src/database.cpp
    src/cliHandler.cpp
    src/menuHandler.cpp
)

# Include directories
include_directories(include)



# Add the nlohmann/json header-only library
include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)
FetchContent_MakeAvailable(Catch2)


# Add executable target
add_executable(LibraryManagementSystem ${SOURCES})
add_executable(tests tests/test_library.cpp)

# Link external libraries if needed (e.g., JSON library)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(LibraryManagementSystem PRIVATE nlohmann_json::nlohmann_json)
