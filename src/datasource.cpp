// Copyright (c) 2025 Adrien Sporrer
// SPDX-License-Identifier: GPL-3.0-or-later

#include "datasource.h"

DataSource::DataSource(QString name, QString hostname, const int port, QString username, QString password) : m_name(std::move(name)), m_hostname(std::move(hostname)), m_port(port), m_username(std::move(username)), m_password(std::move(password)) {}