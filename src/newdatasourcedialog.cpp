#include "newdatasourcedialog.h"

#include <QDialogButtonBox>
#include <QFormLayout>

NewDataSourceDialog::NewDataSourceDialog(QWidget* parent) : QDialog(parent) {
    this->setWindowTitle("New Data Source");
    this->setMinimumSize(400, 300);

    auto* main_layout = new QVBoxLayout(this);
    main_layout->setContentsMargins(20, 10, 20, 10);

    // Setup form widget
    {
        auto* form_widget = new QWidget(this);
        auto* form_layout = new QFormLayout(form_widget);
        form_layout->setSpacing(10);

        m_name_field = new QLineEdit(this);
        m_name_field->setPlaceholderText("e.g. \"Production TSDB\"");
        form_layout->addRow("Name:", m_name_field);

        m_hostname_field = new QLineEdit(this);
        m_hostname_field->setPlaceholderText("\"localhost\" or any IP address");
        form_layout->addRow("Host:", m_hostname_field);

        m_port_field = new QSpinBox(this);
        m_port_field->setRange(0, 65'535);
        form_layout->addRow("Port:", m_port_field);

        m_username_field = new QLineEdit(this);
        form_layout->addRow("Username:", m_username_field);

        m_password_field = new QLineEdit(this);
        m_password_field->setEchoMode(QLineEdit::Password);
        form_layout->addRow("Password:", m_password_field);

        main_layout->addWidget(form_widget);
    }

    auto* button_box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, this);
    main_layout->addWidget(button_box);
    connect(button_box, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(button_box, &QDialogButtonBox::rejected, this, &QDialog::reject);
}