cmake_minimum_required(VERSION 3.22)
project(curse_IO VERSION 0.0.1 LANGUAGES CXX C ASM_NASM)

# Set C standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find NASM
enable_language(ASM_NASM)
if(NOT CMAKE_ASM_NASM_COMPILER_LOADED)
    message(FATAL_ERROR "NASM compiler not found")
endif()

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add NASM source files
file(GLOB_RECURSE ASM_SOURCES "src/*.asm")

# Add source files excluding main.c
file(GLOB_RECURSE SOURCES "src/*.c")
list(FILTER SOURCES EXCLUDE REGEX ".*main\\.c$")

# Add source files excluding main.cpp
file(GLOB_RECURSE CPP_SOURCES "src/*.cpp")
list(FILTER CPP_SOURCES EXCLUDE REGEX ".*main\\.cpp$")


# Option to enable or disable CFLAGS
option(ENABLE_CFLAGS "Enable CFLAGS" OFF)

# Create an object library from the source files
add_library(curse_IO_obj OBJECT ${ASM_SOURCES} ${SOURCES} ${CPP_SOURCES}   )



find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(curse_IO_obj PRIVATE ${CURSES_LIBRARIES})

if(ENABLE_CFLAGS)
    target_compile_options(curse_IO_obj PRIVATE 
    $<$<COMPILE_LANGUAGE:C>:-fsanitize=address -Wall -Wextra -Werror>
    $<$<COMPILE_LANGUAGE:CXX>:-fsanitize=address -Wall -Wextra -Werror>
    )
    # Link with sanitizer library for C and C++ targets
    target_link_libraries(curse_IO_obj PRIVATE -fsanitize=address)
endif()


# Create the main executable with main.cpp
add_executable(curse_IO src/main.cpp)
target_link_libraries(curse_IO PRIVATE curse_IO_obj)

# Option to enable or disable GoogleTest
option(ENABLE_GTEST "Enable Google Test" OFF)


if(ENABLE_GTEST)
    enable_testing()
    find_package(GTest REQUIRED)

    # Add test executable
    add_executable(curse_io_test tests/curse_IO_test.cc)
    target_link_libraries(curse_io_test PRIVATE GTest::gtest_main curse_IO_obj)

    include(GoogleTest)
    gtest_discover_tests(curse_io_test)
endif()

# Install a pkg-config file.
CONFIGURE_FILE(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/pkg-config.pc.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc"
)