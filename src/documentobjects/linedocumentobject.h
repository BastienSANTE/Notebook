#ifndef LINEDOCUMENTOBJECT_H
#define LINEDOCUMENTOBJECT_H

#include <QObject>
#include <QTextObjectInterface>

class LineDocumentObject : public QTextObjectInterface
{
    Q_OBJECT
    Q_INTERFACES(QTextObjectInterface)

public:
    LineDocumentObject();

};

#endif // LINEDOCUMENTOBJECT_H
