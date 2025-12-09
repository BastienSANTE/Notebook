#include "noteeditor.h"
#include "documentlist.h"

#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::unique_ptr<Editor> editor;

    //Create the list of documents (DEPRECATED)
    //DocumentList documentList;

    // If no file is given, start app with blank file.
    // Create the list of documents nevertheless.
    if (argc <= 1){
        editor = std::make_unique<Editor>();
        qDebug() << "Started application without file" ;

    } else {
        editor = std::make_unique<Editor>(QCoreApplication::arguments().at(1));
        qDebug() << "Started application with" << QCoreApplication::arguments().at(1);
    }

    editor->mainWindow->show();
    qDebug() << "Use this line to add graphical breakpoints";
    return a.exec();
}
