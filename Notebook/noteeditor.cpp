#include "noteeditor.h"
#include <QFile>

NoteEditor::NoteEditor(QMainWindow* w, QString fn) {

    //Create the holder to have everything
    holder = new QWidget(w);

    //Set the editor to be at the center of the window.
    // Remove margins to make editor fill the entire window
    w->setCentralWidget(holder);
    w->centralWidget()->setContentsMargins(0, 0, 0, 0);
    layout =  new QVBoxLayout(holder);
    stack = new QStackedWidget(holder);
    editor = new QPlainTextEdit(stack);
    viewer = new QTextBrowser(stack);

    switchBtn = new QPushButton("A", w);

    stack->addWidget(editor);
    stack->addWidget(viewer);

    layout->addWidget(stack, 1, Qt::AlignCenter);
    layout->addWidget(switchBtn, 0, Qt::AlignCenter);

    if (fn.isEmpty()){

    } else {
    QFile argumentFile(fn);

    if (argumentFile.open(QIODeviceBase::ReadWrite)) {
        editor->setPlainText(argumentFile.readAll());
    }
    argumentFile.close();
    }

    QObject::connect(switchBtn, SIGNAL(clicked()), this, SLOT(SwitchViews()));
}

void NoteEditor::SwitchViews()
{
    if(stack->currentIndex() == 0) {
        stack->setCurrentIndex(1);
        viewer->setMarkdown(editor->document()->toPlainText());
        switchBtn->setText("Plain View");
    } else {
        stack->setCurrentIndex(0);
        switchBtn->setText("MD view");
    }
}
