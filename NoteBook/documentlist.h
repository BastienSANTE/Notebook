#ifndef DOCUMENTLIST_H
#define DOCUMENTLIST_H

#include <QList>
#include <QTextDocument>

/**
 *  A document list, cannot be created more than once
 *  So that there aren't several document lists.
 *  Disappears at application closure.
*/

class DocumentList
{
public:
    DocumentList() {
        qDebug() << "Document list intialized" ;
    };
    ~DocumentList() {};

    QList<QTextDocument*> documents;

    void AddDocumentToList(QTextDocument* doc){
        documents.append(doc);
        qDebug() << "Document at " << &doc << " added to list.";
    }

};

#endif // DOCUMENTLIST_H
