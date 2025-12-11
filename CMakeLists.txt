# Copyright (c) 2025 Adrien Sporrer
# SPDX-License-Identifier: GPL-3.0-or-later

cmake_minimum_required(VERSION 3.16)
project(qt-tsdb-explorer
        VERSION 0.1.0
        DESCRIPTION "A Qt-based data acquisition, visualization, and analysis tool for time series databases, inspired by oscilloscope UX."
        HOMEPAGE_URL "https://github.com/Adrienspo/qt-tsdb-explorer"
        LANGUAGES CXX
)

# C++ specific variables setup
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt-specific variables setup
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Project metadata headers generation
configure_file("src/version.h.in" "generated/version.h" @ONLY)
configure_file("src/metadata.h.in" "generated/metadata.h" @ONLY)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Sql)

add_subdirectory(src bin)