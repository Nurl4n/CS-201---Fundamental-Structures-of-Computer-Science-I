#ifndef PAPER_H_INCLUDED
#define PAPER_H_INCLUDED
#include <iostream>
using namespace std;

class Paper
{
    public:
        Paper();
        ~Paper();
        void setPaperTitle( string pTitle );
        void setJournalName( string jName );
        void setPublictionYear( int puYear );
        void setNumOfCoauthors( int numOfCoau );
        string getPaperTitle();
        string getJournalName();
        int getPublictionYear();
        int getNumOfCoauthors();
        void addCoauthorToPaper( const string& paperTitle, const string& coauthorFirstName, const string& coauthorLastName, const string& coauthorInstitution );
        void removeCoauthorFromPaper( const string& coauthorFirstName, const string& coauthorLastName, int& numOfDeletions );
        void showCoauthorOfPaper( const string& coauthorFirstName, const string& coauthorLastName , int& numOfPapersOfCoauthor );
        void showJournalWithPapers( const string& journalTitle , int& numOfPapersInJournal );

    private:
        struct Node{
            Node* next;
            string firstName;
            string lastName;
            string istitution;
        };
        Node* head;

        int numOfCoauthors;
        string paperTitle;
        string journalName;
        int publictionYear;
        bool findCoauther( string coauthorFirstName );
        bool findCoautherFullName( string coauthorFirstName, string coauthorLastName);
};

#endif // PAPER_H_INCLUDED
