// Copyright (c) 2025 Adrien Sporrer
// SPDX-License-Identifier: GPL-3.0-or-later

#include "mainwindow.h"

#include "newdatasourcedialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->actionNewDataSource, &QAction::triggered, this, &MainWindow::onActionNewDataSourceTriggered);
}

MainWindow::~MainWindow() = default;

void MainWindow::onActionNewDataSourceTriggered() {
    NewDataSourceDialog dialog(this);
    if (dialog.exec()) {
        m_data_sources.append(dialog.dataSource());
        qInfo("Data source \"%s\" created", qUtf8Printable(dialog.dataSource().name()));
        return;
    }
    qInfo() << "Data source creation cancelled";
}