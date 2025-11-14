import sys
from PySide6 import QtCore, QtWidgets, QtGui

class MyApp(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()
        self.window_width, self.window_height = 800, 600
        self.setMinimumSize(self.window_width, self.window_height)

        self.main_window = QtWidgets.QWidget()
        
        self.main_layout = QtWidgets.QVBoxLayout(self.main_window)
        self.mdlayout = QtWidgets.QStackedLayout()
        self.setCentralWidget(self.main_window)

        
        self.init_ui()
        self.init_config_signals()
        
    def init_ui(self):
        self.mdview = QtWidgets.QTextEdit()
        self.rawview = QtWidgets.QTextEdit("$$I = \int \rho R^{2} dV$$")
        self.switchbutton = QtWidgets.QPushButton(self.main_window)

        self.mdlayout.insertWidget(0, self.rawview)
        self.mdlayout.insertWidget(1, self.mdview)
        self.is_md_view = 0

        self.main_layout.addLayout(self.mdlayout)
        self.main_layout.addWidget(self.switchbutton)

        
    def init_config_signals(self):
        self.rawview.textChanged.connect(self.updatemd)
        self.switchbutton.clicked.connect(self.switchview)
        

    def updatemd(self):
        self.mdview.setMarkdown(self.rawview.toPlainText())


    def switchview(self):
        if self.is_md_view == 0:
            self.mdlayout.setCurrentIndex(1)
            self.updatemd()
            self.is_md_view = 1;
        elif self.is_md_view == 1:
            self.mdlayout.setCurrentIndex(0)
            self.is_md_view = 0;
        
            
if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    myApp = MyApp()
    myApp.show()

    try:
        sys.exit(app.exec())
    except SystemExit:
        print("Process ended")
