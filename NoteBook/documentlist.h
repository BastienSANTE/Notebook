#ifndef DOCUMENTLIST_H
#define DOCUMENTLIST_H

#include <vector>
#include <QTextDocument>

/**
 *  A document list, cannot be created more than once
 *  So that there aren't several document lists
*/

class DocumentList
{
public:
    DocumentList();
    ~DocumentList() {};

    std::vector<QTextDocument> documents;

    // Give list of all documents to the function
    std::vector<QTextDocument>& GetDocumentList() {
        return documents;
    };
};

#endif // DOCUMENTLIST_H
