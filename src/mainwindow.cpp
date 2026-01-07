// Copyright (c) 2025-2026 Adrien Sporrer
// SPDX-License-Identifier: GPL-3.0-or-later

#include "mainwindow.h"

#include "newchanneldialog.h"
#include "newdatasourcedialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->actionNewChannel->setEnabled(false);
    connect(ui->actionNewDataSource, &QAction::triggered, this, &MainWindow::onActionNewDataSourceTriggered);
    connect(ui->actionNewChannel, &QAction::triggered, this, &MainWindow::onActionNewChannelTriggered);
}

MainWindow::~MainWindow() = default;

QList<QWeakPointer<const DataSource>> MainWindow::availableDataSources() const {
    return {m_data_sources.begin(), m_data_sources.end()};
}

void MainWindow::onActionNewDataSourceTriggered() {
    if (NewDataSourceDialog dialog(this); dialog.exec()) {
        m_data_sources.append(QSharedPointer<DataSource>::create(dialog.dataSource())); // Reminder: The QSharedPointer internals and the object are allocated in one single memory allocation, which
                                                                                        // could help reduce memory fragmentation in a long-running application.
        ui->actionNewChannel->setEnabled(true);
        qInfo(R"(Data source "%s" created)", qUtf8Printable(dialog.dataSource().name()));
        return;
    }
    qInfo() << "Data source creation cancelled";
}

void MainWindow::onActionNewChannelTriggered() {
    if (NewChannelDialog dialog(this->availableDataSources(), this); dialog.exec()) {
        qInfo(R"(Channel "%s" created (from "%s" data source))", qUtf8Printable(dialog.channel().name()), qUtf8Printable(dialog.channel().dataSourceWeakRef().toStrongRef()->name()));
        return;
    }
    qInfo() << "Channel creation cancelled";
}