#include <QApplication>
#include <QtWidgets>
#include <QMainWindow>

class editorApp {

public:
  editorApp(int width, int height) {
    window.setMinimumWidth(width);
    window.setMinimumHeight(height);
    window.setCentralWidget(testbtn);
  }

  ~editorApp() {}

  QString btn = "Hello";

  QMainWindow window;
  QPushButton* testbtn = new QPushButton(btn, nullptr);

};


int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	editorApp ed(400, 500);
	ed.window.show();
	return app.exec();

}
