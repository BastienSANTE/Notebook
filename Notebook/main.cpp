#include "mainwindow.h"
#include "noteeditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    NoteEditor ed(&w, QCoreApplication::arguments().at(1));

    w.show();
    return a.exec();
}
