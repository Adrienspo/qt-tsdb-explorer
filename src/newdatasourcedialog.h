#pragma once

#include <QComboBox>
#include <QDialog>
#include <QLabel>
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