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

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private slots:
    void onActionNewDataSourceTriggered();

private:
    Ui::MainWindow* ui;
    QList<DataSource> m_data_sources;
};