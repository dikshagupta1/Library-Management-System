# Set the test source files
set(TEST_SOURCES
    test_library.cpp
    ${CMAKE_SOURCE_DIR}/src/library.cpp
    ${CMAKE_SOURCE_DIR}/src/book.cpp
    ${CMAKE_SOURCE_DIR}/src/storage.cpp
    ${CMAKE_SOURCE_DIR}/src/cliHandler.cpp
    ${CMAKE_SOURCE_DIR}/src/menuHandler.cpp
)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Fetch Catch2
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)
FetchContent_MakeAvailable(Catch2)

# Add the test executable
add_executable(tests ${TEST_SOURCES})

# Link libraries
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain nlohmann_json::nlohmann_json)
