cmake_minimum_required(VERSION 3.16)
project(qt-tsdb-explorer VERSION 0.1.0 LANGUAGES CXX)

# C++ specific variables setup
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt-specific variables setup
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Generate version header file
configure_file("src/version.h.in" "generated/version.h" @ONLY)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Sql)

add_subdirectory(src bin)