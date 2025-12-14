// Copyright (c) 2025 Adrien Sporrer
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>

#include "datasource.h"

class NewDataSourceDialog final : public QDialog {
    Q_OBJECT

public:
    explicit NewDataSourceDialog(QWidget* parent = nullptr);

    [[nodiscard]] DataSource dataSource() const;

private:
    QLineEdit* m_name_field = nullptr;
    QLineEdit* m_hostname_field = nullptr;
    QSpinBox* m_port_field = nullptr;
    QLineEdit* m_username_field = nullptr;
    QLineEdit* m_password_field = nullptr;
};