#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "dragon2/core/hello.hpp"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setWindowTitle(QString("DRAGON2 GUI - v%1")
        .arg(QString::fromStdString(dragon2::core::version())));
    ui->labelVersion->setText(
        QString("Core version: %1").arg(QString::fromStdString(dragon2::core::version()))
    );

    connect(ui->btnHello, &QPushButton::clicked, this, &MainWindow::onHello);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onHello() {
    const auto msg = QString::fromStdString(dragon2::core::hello("Qt"));
    QMessageBox::information(this, "Hello", msg);
}
