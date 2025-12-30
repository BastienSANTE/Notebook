#include "notebrowser.h"

NoteBrowser::NoteBrowser(QWidget* parent) {}

NoteBrowser::~NoteBrowser(){}

void NoteBrowser::wheelEvent(QWheelEvent* event){
    bool _isCtrlHeld = QGuiApplication::keyboardModifiers().testFlag(Qt::ControlModifier);

    if (event->angleDelta().y() > 0 && _isCtrlHeld) {
        zoomIn();
        emit zoomFactorIncreased();
    } else if (event->angleDelta().y() < 0 && _isCtrlHeld) {
        zoomOut();
        emit zoomFactorDecreased();
    }
}
