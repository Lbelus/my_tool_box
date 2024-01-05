cmake_minimum_required(VERSION 3.22)
project(parakalo VERSION 0.0.1 LANGUAGES C ASM_NASM)

# Set C standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

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


# Option to enable or disable CFLAGS
option(ENABLE_CFLAGS "Enable CFLAGS" OFF)

# Create an object library from the source files
add_library(parakaloObj OBJECT ${ASM_SOURCES} ${SOURCES})



find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(parakaloObj PRIVATE ${CURSES_LIBRARIES})

if(ENABLE_CFLAGS)
    target_compile_options(parakaloObj PRIVATE 
    $<$<COMPILE_LANGUAGE:C>:-fsanitize=address -Wall -Wextra -Werror>
    )
    target_link_libraries(parakaloObj PRIVATE -fsanitize=address)
endif()


# Create the main executable with main.cpp
add_executable(parakalo src/main.c)
target_link_libraries(parakalo PRIVATE parakaloObj)

# Option to enable or disable GoogleTest
option(ENABLE_GTEST "Enable Google Test" OFF)


if(ENABLE_GTEST)
    enable_testing()
    find_package(GTest REQUIRED)

    # Add test executable
    add_executable(redis_api_test tests/redis_api_test.cc)
    target_link_libraries(redis_api_test PRIVATE GTest::gtest_main parakaloObj)

    include(GoogleTest)
    gtest_discover_tests(redis_api_test)
endif()

# # Install a pkg-config file.
# CONFIGURE_FILE(
#     "${CMAKE_CURRENT_SOURCE_DIR}/cmake/pkg-config.pc.in"
#     "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc"
# )