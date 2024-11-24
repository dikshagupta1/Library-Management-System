cmake_minimum_required(VERSION 3.14)
project(LibraryManagementSystem)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message(STATUS "Building Project: ${PROJECT_NAME}")

# Add source files
set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/library.cpp
    ${CMAKE_SOURCE_DIR}/src/book.cpp
    ${CMAKE_SOURCE_DIR}/src/storage.cpp
    ${CMAKE_SOURCE_DIR}/src/cliHandler.cpp
    ${CMAKE_SOURCE_DIR}/src/menuHandler.cpp
)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the nlohmann/json header-only library
include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

# Add the tests directory
option(ENABLE_TESTS "Enable or disable building tests" OFF)
message(STATUS "Building with Unit tests: ${ENABLE_TESTS}")
if (ENABLE_TESTS)
    add_subdirectory(${CMAKE_SOURCE_DIR}/tests)
endif()

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Link external libraries
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)