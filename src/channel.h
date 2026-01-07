// Copyright (c) 2025-2026 Adrien Sporrer
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QWeakPointer>

class DataSource;

class Channel {
public:
    Channel(QString name, const QWeakPointer<const DataSource>& data_source, QString monitored_table_name, QString monitored_column_name);

    [[nodiscard]] const QString& name() const { return m_name; }
    [[nodiscard]] QWeakPointer<const DataSource> dataSource() const { return m_data_source; }
    [[nodiscard]] const QString& monitoredTableName() const { return m_monitored_table_name; }
    [[nodiscard]] const QString& monitoredColumnName() const { return m_monitored_column_name; }

private:
    Channel() = default;

    QString m_name;
    QWeakPointer<const DataSource> m_data_source;
    QString m_monitored_table_name;
    QString m_monitored_column_name;
};