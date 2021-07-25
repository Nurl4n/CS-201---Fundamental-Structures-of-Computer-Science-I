#include <iostream>
#include "Paper.h"

using namespace std;

Paper::Paper()
{
    setPaperTitle("NULL");
    setJournalName("NULL");
    setPublictionYear(0);
    setNumOfCoauthors(0);
    head = NULL;
}

Paper::~Paper()
{
    while(head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
    }
}

void Paper::setPaperTitle( string pTitle )
{
    paperTitle = pTitle;
}

void Paper::setJournalName( string jName )
{
    journalName = jName;
}

void Paper::setPublictionYear( int puYear )
{
    publictionYear = puYear;
}

void Paper::setNumOfCoauthors( int numOfCoau )
{
    numOfCoauthors = numOfCoau;
}

int Paper::getNumOfCoauthors()
{
    numOfCoauthors;
}

string Paper::getPaperTitle()
{
    return paperTitle;
}

string Paper::getJournalName()
{
    return journalName;
}

int Paper::getPublictionYear()
{
    return publictionYear;
}

bool Paper::findCoauther( string coauthorFirstName )
{
    Node* cur = head;
    for(int i = 0; i < numOfCoauthors; i++)
    {
        if(cur->firstName == coauthorFirstName)
            return true;
        else
            cur = cur->next;
    }
    return false;
}

bool Paper::findCoautherFullName( string coauthorFirstName, string coauthorLastName)
{
    Node* cur = head;
    for(int i = 0; i < numOfCoauthors; i++)
    {
        if(cur->firstName == coauthorFirstName && cur->lastName == coauthorLastName)
            return true;
        else
            cur = cur->next;
    }
    return false;
}

void Paper::addCoauthorToPaper( const string& paperTitle, const string& coauthorFirstName, const string& coauthorLastName, const string& coauthorInstitution )
{
    if( findCoauther(coauthorFirstName) )
        cout << "ERROR: Coauthor " << coauthorFirstName << " " << coauthorLastName << " already is in Paper " << paperTitle << endl;
    else
    {
        if( numOfCoauthors == 0 )
        {
            head = new Node;
            head->firstName = coauthorFirstName;
            head->lastName = coauthorLastName;
            head->istitution = coauthorInstitution;
            head->next = NULL;
            numOfCoauthors++;
        }
        else
        {
            string newCoauthor = coauthorLastName + coauthorFirstName;
            Node* cur = head;
            Node* prev = head;
            for(int i = 0; i < numOfCoauthors; i++)
            {
                string existingCoauthor = cur->lastName + cur->firstName;
                if(existingCoauthor < newCoauthor)
                {
                    prev = cur;
                    cur = cur->next;
                }
                else
                {
                    if(cur == head)
                    {
                        Node* temp = new Node;
                        temp->firstName = coauthorFirstName;
                        temp->lastName = coauthorLastName;
                        temp->istitution = coauthorInstitution;
                        temp->next = head;
                        head = temp;
                    }
                    else
                    {
                        Node* temp = new Node;
                        temp->firstName = coauthorFirstName;
                        temp->lastName = coauthorLastName;
                        temp->istitution = coauthorInstitution;
                        temp->next = cur;
                        prev->next = temp;
                        i = numOfCoauthors;
                    }
                }
            }
            if(cur == NULL)
            {
                Node* temp = new Node;
                temp->firstName = coauthorFirstName;
                temp->lastName = coauthorLastName;
                temp->istitution = coauthorInstitution;
                temp->next = NULL;
                prev->next = temp;
            }
            numOfCoauthors++;
        }
    }
}

void Paper::removeCoauthorFromPaper( const string& coauthorFirstName, const string& coauthorLastName , int& numOfDeletions)
{
    if( findCoautherFullName(coauthorFirstName, coauthorLastName) )
        {
            bool flag = false;
            if(head->firstName == coauthorFirstName && head->lastName == coauthorLastName)
            {
                Node* temp = head;
                head = head->next;
                delete temp;
                temp = NULL;
                flag = true;
                numOfCoauthors--;
                numOfDeletions++;
            }
            else
            {
                //cout << "was here" << endl;
                Node* cur = head->next;
                Node* prev = head;
                for(int i = 1; i < numOfCoauthors; i++)
                {
                    if(cur->firstName == coauthorFirstName && cur->lastName == coauthorLastName)
                    {
                        Node* temp = cur;
                        prev->next = cur->next;
                        cur->next = NULL;
                        delete temp;
                        temp = NULL;
                        flag = true;
                        numOfCoauthors--;
                        numOfDeletions++;
                        i = numOfCoauthors;
                    }
                    else
                    {
                        prev = cur;
                        cur = cur->next;
                    }
                }
            }
            if(flag)
                cout << "INFO: Coauther " << coauthorFirstName + " " + coauthorLastName << " has been deleted from Paper " << paperTitle << endl;
        }
}

void Paper::showCoauthorOfPaper( const string& coauthorFirstName, const string& coauthorLastName , int& numOfPapersOfCoauthor )
{
    Node* cur = head;
    for(int i = 0; i < numOfCoauthors; i++)
    {
        if(cur->firstName == coauthorFirstName && cur->lastName == coauthorLastName)
        {
            cout << cur->istitution << ", " << paperTitle << ", " << publictionYear << endl;
            numOfPapersOfCoauthor++;
            i = numOfCoauthors;
        }
        else
            cur = cur->next;
    }
}

void Paper::showJournalWithPapers( const string& journalTitle , int& numOfPapersInJournal )
{
    if(journalName == journalTitle)
    {
        cout << paperTitle << ", " << publictionYear << endl;
        numOfPapersInJournal++;
    }
}





