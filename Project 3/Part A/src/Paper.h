#ifndef PAPER_H_INCLUDED
#define PAPER_H_INCLUDED
#include <iostream>
//#include <string>
using namespace std;

class Paper
{
    public:
        Paper();
        void setPaperTitle(string pTitle);
        void setJournalName(string jName);
        void setPublictionYear(int puYear);
        string getPaperTitle();
        string getJournalName();
        int getPublictionYear();

    private:
        string paperTitle;
        string journalName;
        int publictionYear;

};

#endif // PAPER_H_INCLUDED
