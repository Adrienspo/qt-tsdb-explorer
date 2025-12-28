// Copyright (c) 2025 Adrien Sporrer
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QMainWindow>

#include "datasource.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow final : public QMainWindow {
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(MainWindow)

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private slots:
    void onActionNewDataSourceTriggered();

private:
    QScopedPointer<Ui::MainWindow> ui;
    QList<DataSource> m_data_sources;
};