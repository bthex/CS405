cmake_minimum_required(VERSION 3.23)
project(CS405)

set(CMAKE_CXX_STANDARD 14)

add_executable(NumericOverflow
        module1/NumericOverflow/NumericOverflow.cpp)

add_executable(SQLInjection
        module2/SQLInjection/sqlite3.c
        module2/SQLInjection/sqlite3.h
        module2/SQLInjection/SQLInjection.cpp)