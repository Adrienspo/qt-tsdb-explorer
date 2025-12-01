#pragma once

#include <QString>

class DataSource {
public:
    DataSource(QString name, QString hostname, int port, QString username, QString password);

    [[nodiscard]] const QString& name() const { return m_name; }
    [[nodiscard]] const QString& hostname() const { return m_hostname; }
    [[nodiscard]] int port() const { return m_port; }
    [[nodiscard]] const QString& username() const { return m_username; }

private:
    DataSource() = default;

    QString m_name;
    QString m_hostname;
    int m_port = -1;
    QString m_username;
    QString m_password;
};