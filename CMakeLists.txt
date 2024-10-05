cmake_minimum_required(VERSION 3.23)
project(CS405)

set(CMAKE_CXX_STANDARD 14)

# Module 1 Numeric Overflow
add_executable(NumericOverflow
        module1/NumericOverflow/NumericOverflow.cpp)

# Module 2 SQL Injection
add_executable(SQLInjection
        module2/SQLInjection/sqlite3.c
        module2/SQLInjection/sqlite3.h
        module2/SQLInjection/SQLInjection.cpp)

# Module 2 Buffer Overflow
add_executable(BufferOverflow
        module2/BufferOverflow/PythonWithExploit.py
        module2/BufferOverflow/PythonWithoutExploit.py
        module2/BufferOverflow/BufferOverflow.cpp)

# Module 4 Exceptions
add_executable(Exceptions
        module4/Exceptions/Exceptions.cpp
)

# Module 4 Unit Test

# 'lib' is the folder with Google Test sources
add_subdirectory(module4/UnitTest/lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(Google_Tests_run
        module4/UnitTest/UnitTest.cpp
)
# 'Google_Tests_run' is the target name
target_link_libraries(Google_Tests_run gtest gtest_main)