// Copyright (c) 2025-2026 Adrien Sporrer
// SPDX-License-Identifier: GPL-3.0-or-later

#include "channel.h"

#include <utility>

Channel::Channel(QString name, const QWeakPointer<const DataSource>& data_source, QString monitored_table_name, QString monitored_column_name) :
    m_name(std::move(name)),
    m_data_source(data_source),
    m_monitored_table_name(std::move(monitored_table_name)),
    m_monitored_column_name(std::move(monitored_column_name)) {}