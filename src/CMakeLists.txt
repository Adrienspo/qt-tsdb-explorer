# Copyright (c) 2025-2026 Adrien Sporrer
# SPDX-License-Identifier: GPL-3.0-or-later

qt_add_executable(qt-tsdb-explorer
        datasource.cpp
        channel.cpp
        newdatasourcedialog.cpp
        newchanneldialog.cpp
        mainwindow.ui
        mainwindow.cpp
        main.cpp
)

target_link_libraries(qt-tsdb-explorer PRIVATE Qt6::Core Qt6::Widgets Qt6::Sql)
target_include_directories(qt-tsdb-explorer PRIVATE "${CMAKE_BINARY_DIR}/generated")