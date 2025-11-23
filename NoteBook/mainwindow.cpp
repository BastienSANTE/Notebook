#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new MainWindow)
{}

MainWindow::~MainWindow()
{
    delete ui;
}
