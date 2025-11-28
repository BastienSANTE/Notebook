#include "mainwindow.h"
#include "noteeditor.h"
#include "documentlist.h"

#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Editor* ed = nullptr;

    //Create the list of documents
    DocumentList* documentList = new DocumentList;

    // If no file is given, start app with blank file.
    // Create the list of documents nevertheless.
    if (argc <= 1){
        ed =  new Editor(&w, documentList);
        qDebug() << "Started application without file" ;

    } else {
        ed = new Editor(&w, documentList, QCoreApplication::arguments().at(1));
        qDebug() << "Started application with" << QCoreApplication::arguments().at(1);
    }
    w.show();
    qDebug() << "Use this line to add graphical breakpoints";
    return a.exec();
}
