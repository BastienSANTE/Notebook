#include "mainwindow.h"
#include "noteeditorfixed.h"
#include "documentlist.h"

#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //Create the list of documents
    DocumentList* documentList = new DocumentList;

    // If no file is given, start app with blank file.
    // Create the list of documents nevertheless.
    if (argc <= 1){
        NoteEditorFixed ed(&w, documentList);
        qDebug() << "Started application without file" ;

    } else {
        NoteEditorFixed ed(&w, documentList, QCoreApplication::arguments().at(1));
        qDebug() << "Started application with" << QCoreApplication::arguments().at(1);
    }
    w.show();
    return a.exec();
}
