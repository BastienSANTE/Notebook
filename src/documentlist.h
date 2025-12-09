#ifndef DOCUMENTLIST_H
#define DOCUMENTLIST_H

#include <QObject>
#include <QList>
#include <QTextDocument>

/**
 *  A document list, cannot be created more than once
 *  So that there aren't several document lists.
 *  Disappears at application closure.
*/

class DocumentList : public QObject {
public:
    Q_OBJECT

public:
    QList<QTextDocument*> documents;

    DocumentList();
    ~DocumentList();
    void AddDocument(QTextDocument*& doc);
};

#endif // DOCUMENTLIST_H
