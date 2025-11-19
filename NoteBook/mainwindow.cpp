#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->switchButton, &QPushButton::clicked, this, &MainWindow::SwitchViews);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SwitchViews()
{
    if(ui->viewSwitcher->currentIndex() == 0){
        ui->viewSwitcher->setCurrentIndex(1);
        ui->MDView->setMarkdown(ui->plainView->document()->toPlainText());
        ui->switchButton->setText("Plain View");
    } else {
        ui->viewSwitcher->setCurrentIndex(0);
        ui->switchButton->setText("MD view");
    }
}
