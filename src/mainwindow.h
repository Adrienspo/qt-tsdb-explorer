// Copyright (c) 2025-2026 Adrien Sporrer
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

    [[nodiscard]] QList<QWeakPointer<const DataSource>> availableDataSources() const;

private slots:
    void onActionNewDataSourceTriggered();
    void onActionNewChannelTriggered();

private:
    QScopedPointer<Ui::MainWindow> ui;
    QList<QSharedPointer<DataSource>>
        m_data_sources; // Note: this collection could have its own resource manager (e.g., DataSourceManager) to decouple data source lifecycle management from the UI layer.
};