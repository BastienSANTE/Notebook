 #include "documentlist.h"

DocumentList::DocumentList() {};

DocumentList::~DocumentList() {};

void DocumentList::AddDocument(QTextDocument*& doc) {
    qDebug() << this;
    documents.append(doc);
    qDebug() << "Document at " << doc << " added to list. List now " << documents.size() << " items long";
}
