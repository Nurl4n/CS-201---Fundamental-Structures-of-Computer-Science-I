#ifndef PAPERREPOSITORY_H_INCLUDED
#define PAPERREPOSITORY_H_INCLUDED

#include "Paper.h"

class PaperRepository
{
    public:
        PaperRepository();
        ~PaperRepository();
        void addPaper( const string& paperTitle, const string& journalTitle, const int publictionYear );
        void removePaper( const string& paperTitle );
        void addCoauthor( const string& paperTitle, const string& coauthorFirstName,
                         const string& coauthorLastName, const string& coauthorInstitution );
        void removeCoauthor( const string& coauthorFirstName, const string& coauthorLastName );
        void showAllPapers();
        void showCoauthor( const string& coauthorFirstName, const string& coauthorLastName );
        void showJournal( const string& journalTitle );

    private:
        struct Node{
            Node* next;
            Node* prev;
            Paper paper;
        };
        Node* head;
        Node* tail;
        int numOfPapers;
        bool findPaper( string paperT );
};

#endif // PAPERREPOSITORY_H_INCLUDED
