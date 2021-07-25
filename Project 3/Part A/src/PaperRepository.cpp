#include <iostream>
#include "PaperRepository.h"

using namespace std;

PaperRepository::PaperRepository()
{
    head = NULL;
    tail = NULL;
    numOfPapers = 0;
}

PaperRepository::~PaperRepository()
{
    for(int i = 0; i < numOfPapers; i++)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

bool PaperRepository::findPaper( string paperT )
{
    Node* cur = head;
    for(int i = 0; i < numOfPapers; i++)
    {
        if(cur->paper.getPaperTitle() == paperT)
            return true;
        else
            cur = cur->next;
    }
    return false;
}

void PaperRepository::addPaper( const string& paperTitle, const string& journalTitle, const int publictionYear )
{
    if(findPaper(paperTitle))
        cout << "ERROR: Paper " << paperTitle << " already exists" << endl;
    else
    {
        if(head == NULL)
        {
            head = new Node;
            head->next = head;
            head->prev = head;
            head->paper.setPaperTitle(paperTitle);
            head->paper.setJournalName(journalTitle);
            head->paper.setPublictionYear(publictionYear);
            tail = head;
            numOfPapers++;
        }
        else
        {
            tail->next = new Node;
            tail->next->paper.setPaperTitle(paperTitle);
            tail->next->paper.setJournalName(journalTitle);
            tail->next->paper.setPublictionYear(publictionYear);
            tail->next->next = head;
            tail->next->prev = tail;
            tail = tail->next;
            head->prev = tail;
            numOfPapers++;
        }
        cout << "INFO: Paper " << paperTitle << " has been added" << endl;
    }
}

void PaperRepository::removePaper( const string& paperTitle )
{
    if(!findPaper(paperTitle))
        cout << "ERROR: Paper " << paperTitle << " does not exist" << endl;
    else
    {
        if(numOfPapers == 1)
        {
            delete head;
            head = NULL;
            tail = head;
            numOfPapers--;
        }
        else
        {
            Node* cur = head;
            for(int i = 0; i < numOfPapers; i++)
            {
                if(cur->paper.getPaperTitle() == paperTitle)
                    i = numOfPapers;
                else
                    cur = cur->next;
            }
            if(cur == head)
                head = head->next;
            if(cur->next == head)
                tail = cur->prev;
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;

            delete cur;
            cur = NULL;
            numOfPapers--;
        }
        cout << "INFO: Paper " << paperTitle << " has been deleted" << endl;
    }
}

void PaperRepository::showAllPapers()
{
    if(numOfPapers == 0)
        cout << "--none--" << endl;

    Node* cur = head;
    for(int i = 1; i <= numOfPapers; i++)
    {
        if( i == 1)
            cout << cur->paper.getPaperTitle() << ", " << cur->paper.getJournalName() << ", " << cur->paper.getPublictionYear() <<
            " for the 1st paper" << endl;
        else if( i == 2)
            cout << cur->paper.getPaperTitle() << ", " << cur->paper.getJournalName() << ", " << cur->paper.getPublictionYear() <<
            " for the 2nd paper" << endl;
        else if( i == 3)
            cout << cur->paper.getPaperTitle() << ", " << cur->paper.getJournalName() << ", " << cur->paper.getPublictionYear() <<
            " for the 3rd paper" << endl;
        else
            cout << cur->paper.getPaperTitle() << ", " << cur->paper.getJournalName() << ", " << cur->paper.getPublictionYear() <<
            " for the " << i << "th paper" << endl;
        cur = cur->next;
    }
}





