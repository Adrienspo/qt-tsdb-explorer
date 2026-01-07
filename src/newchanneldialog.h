// Copyright (c) 2025-2026 Adrien Sporrer
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QComboBox>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>

#include "channel.h"
#include "datasource.h"

class NewChannelDialog final : public QDialog {
    Q_OBJECT

public:
    explicit NewChannelDialog(const QList<QWeakPointer<const DataSource>>& available_data_sources, QWidget* parent = nullptr);

    [[nodiscard]] Channel channel() const;

private:
    QList<QWeakPointer<const DataSource>> m_available_data_sources;
    QLineEdit* m_name_field = nullptr;
    QComboBox* m_data_source_field = nullptr;
    QLineEdit* m_monitored_table_name_field = nullptr;
    QLineEdit* m_monitored_column_name_field = nullptr;
};