#include "mainwindow.h"

#include "newdatasourcedialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->actionNewDataSource, &QAction::triggered, this, &MainWindow::onActionNewDataSourceTriggered);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onActionNewDataSourceTriggered() {
    NewDataSourceDialog dialog(this);
    if (dialog.exec()) {
        qInfo() << "Data source created";
        return;
    }
    qInfo() << "Data source creation cancelled";
}