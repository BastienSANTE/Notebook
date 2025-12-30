#ifndef NOTEBROWSER_H
#define NOTEBROWSER_H

#include <QTextBrowser>
#include <QWheelEvent>

class NoteBrowser : public QTextBrowser
{


public:
    Q_OBJECT

public:
    explicit NoteBrowser(QWidget* parent = nullptr);
    virtual ~NoteBrowser();

signals:
    void zoomFactorIncreased();
    void zoomFactorDecreased();

protected:
    //Overriding zoom to enable image resizing
    void wheelEvent(QWheelEvent* event) override;
};



#endif // NOTEBROWSER_H
