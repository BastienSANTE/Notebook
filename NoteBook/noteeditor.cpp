#include "noteeditor.h"
#include "documentlist.h"
#include <QFile>

NoteEditor::NoteEditor(QWidget* parent) {
  stack = new QStackedWidget(parent);
  editor = new QPlainTextEdit(parent);
  viewer = new QTextBrowser(parent);

  stack->addWidget(editor);
  stack->addWidget(viewer);
}

NoteEditor::NoteEditor(QWidget* parent, char* fn){
  stack = new QStackedWidget(parent);
  editor = new QPlainTextEdit(parent);
  viewer = new QTextBrowser(parent);

  stack->addWidget(editor);
  stack->addWidget(viewer);

  QFile argumentFile(fn);
  
  if (argumentFile.open(QIODeviceBase::ReadWrite))
  {
    editor->setPlainText(argumentFile.readAll());
  }
  argumentFile.close();
}

void NoteEditor::SwitchViews()
{
    if(stack->currentIndex() == 0)
    {
        stack->setCurrentIndex(1);
        viewer->setMarkdown(editor->document()->toPlainText());
        switchBtn->setText("Plain View");
    } else
    {
        stack->setCurrentIndex(0);
        switchBtn->setText("MD view");
    }
}
