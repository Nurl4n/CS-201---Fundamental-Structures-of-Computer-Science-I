#include <iostream>
#include "Paper.h"

using namespace std;

Paper::Paper()
{
    setPaperTitle("NULL");
    setJournalName("NULL");
    setPublictionYear(0);
}

void Paper::setPaperTitle(string pTitle)
{
    paperTitle = pTitle;
}

void Paper::setJournalName(string jName)
{
    journalName = jName;
}

void Paper::setPublictionYear(int puYear)
{
    publictionYear = puYear;
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
