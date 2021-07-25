#include <iostream>
#include <string>
#include "BoxOffice.h"

using namespace std;

BoxOffice::BoxOffice()
{
    numOfTheaters = 0;
    theaters = NULL;
}

BoxOffice::~BoxOffice()
{
    delete[] theaters;
}

int BoxOffice::getNumOfTheaters()
{
    return numOfTheaters;
}

void BoxOffice::resetNumOfTheaters( int n)
{
    numOfTheaters += n;
}

int BoxOffice::findTheater( int theaterID)
{
    for(int i = 0; i < numOfTheaters; i++)
        if(theaters[i].getTheaterID() == theaterID)
            return i+1;
    return 0;
}
void BoxOffice::addTheater( int theaterId, string movieName, int numRows, int numSeatsPerRow)
{
    int existIndex = findTheater(theaterId);
    if(existIndex != 0)
        cout << "Theater " << theaterId << "(" << movieName << ")" << " already exists" << endl;
    else
    {
        resetNumOfTheaters(1);
        Theater* temp = theaters;
        theaters = new Theater[getNumOfTheaters()];
        if(temp != NULL)
            for(int i = 0; i < getNumOfTheaters() - 1; i++)
                theaters[i] = temp[i];
        theaters[getNumOfTheaters() - 1].setTheaterID(theaterId);
        theaters[getNumOfTheaters() - 1].setMovieName(movieName);
        theaters[getNumOfTheaters() - 1].createRoom(numRows, numSeatsPerRow);
        cout << "Theater " << theaterId << "(" << movieName << ")" << " has been added" << endl;

        /*for(int i = 0; i < getNumOfTheaters() - 1; i++)
            if(temp[i] != NULL)
                delete[] temp[i];*/
        if(temp != NULL)
            delete[] temp;
    }
}

void BoxOffice::removeTheater( int theaterId)
{
    int existIndex = findTheater(theaterId);

    if(!existIndex)
        cout << "Theater " << theaterId << " does not exist" <<endl;
    else
    {
        resetNumOfTheaters(-1);
        Theater* temp = theaters;
        theaters = new Theater[getNumOfTheaters()];
        for(int i = 0; i < existIndex - 1; i++)
            theaters[i] = temp[i];
        for(int i = existIndex; i < getNumOfTheaters() + 1; i++)
            theaters[i - 1] = temp[i];
        cout << "Theater " << theaterId << " has been deleted" << endl;
        delete[] temp;
    }
}

void BoxOffice::showAllTheaters()
{
    if(getNumOfTheaters() == 0)
        cout << "No movie theaters in the system!" << endl;
    else
    {
        cout << "Theaters currently in the system:" << endl;
        for(int i = 0; i < getNumOfTheaters(); i++)
            cout << "Theater " << theaters[i].getTheaterID() << "(" << theaters[i].getMovieName() << "): " << theaters[i].getNumOfSeats() << " available seats" << endl;
    }
}







