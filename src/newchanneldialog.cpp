// Copyright (c) 2025-2026 Adrien Sporrer
// SPDX-License-Identifier: GPL-3.0-or-later

#include "newchanneldialog.h"

#include <QDialogButtonBox>
#include <QFormLayout>

NewChannelDialog::NewChannelDialog(const QList<QWeakPointer<const DataSource>>& available_data_sources, QWidget* parent) : QDialog(parent), m_available_data_sources(available_data_sources) {
    this->setWindowTitle("New Channel");
    this->setMinimumSize(400, 300);

    auto* main_layout = new QVBoxLayout(this);
    main_layout->setContentsMargins(20, 10, 20, 10);

    // Setup form widget
    {
        auto* form_widget = new QWidget(this);
        auto* form_layout = new QFormLayout(form_widget);
        form_layout->setSpacing(10);

        m_name_field = new QLineEdit(this);
        form_layout->addRow("Name:", m_name_field);

        m_data_source_field = new QComboBox(this);
        m_data_source_field->setEnabled(available_data_sources.size() > 1);
        for (const auto& data_source_weak_ref : available_data_sources) {
            if (const auto data_source = data_source_weak_ref.toStrongRef()) {
                m_data_source_field->addItem(data_source->name());
            }
        }
        form_layout->addRow("Datasource:", m_data_source_field);

        m_monitored_table_name_field = new QLineEdit(this);
        form_layout->addRow("Table name:", m_monitored_table_name_field);

        m_monitored_column_name_field = new QLineEdit(this);
        form_layout->addRow("Column name:", m_monitored_column_name_field);

        main_layout->addWidget(form_widget);
    }

    auto* button_box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, this);
    main_layout->addWidget(button_box);
    connect(button_box, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(button_box, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

Channel NewChannelDialog::channel() const {
    const int current_index = m_data_source_field->currentIndex();
    QWeakPointer<const DataSource> data_source_weak_ref;
    if (current_index >= 0 && current_index < m_available_data_sources.size()) {
        data_source_weak_ref = m_available_data_sources.at(m_data_source_field->currentIndex());
    }
    return {m_name_field->text(), data_source_weak_ref, m_monitored_table_name_field->text(), m_monitored_column_name_field->text()};
}