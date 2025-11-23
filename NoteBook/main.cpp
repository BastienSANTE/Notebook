#include "mainwindow.h"
#include "noteeditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    
    if (argv[0] == NULL) {
      NoteEditor ne(&w);
    } else {
      NoteEditor ne(&w, argv[0]);
    }
    
    w.show();
    return a.exec();
}
