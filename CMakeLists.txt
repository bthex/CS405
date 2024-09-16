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