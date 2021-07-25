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
        cout << "Theater " << theaterId << "(" << movieName << ")" << " already exists (You cannot add)" << endl;
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

        if(temp != NULL)
            delete[] temp;
    }
}

void BoxOffice::removeTheater( int theaterId)
{
    int existIndex = findTheater(theaterId);

    if(!existIndex)
        cout << "Theater " << theaterId << " does not exist (You cannot remove)" <<endl;
    else
    {
        cout << endl;
        cout << "Theater " << theaterId << "(" << theaters[existIndex - 1].getMovieName() << ")"
        <<" and all of its reservations are cancelled" << endl;
        resetNumOfTheaters(-1);
        Theater* temp = theaters;
        theaters = new Theater[getNumOfTheaters()];
        for(int i = 0; i < existIndex - 1; i++)
            theaters[i] = temp[i];
        for(int i = existIndex; i < getNumOfTheaters() + 1; i++)
            theaters[i - 1] = temp[i];
        delete[] temp;
    }
}

void BoxOffice::showAllTheaters()
{
    if(getNumOfTheaters() == 0)
        cout << "No movie theaters in the system!" << endl;
    else
    {
        cout << endl;
        cout << "Theaters currently in the system:" << endl;
        for(int i = 0; i < getNumOfTheaters(); i++)
            cout << "Theater " << theaters[i].getTheaterID() << "(" << theaters[i].getMovieName() << "): "
                 << theaters[i].getNumOfSeats() << " available seats" << endl;
        cout << endl;
    }
}

void BoxOffice::showTheater( int theaterId)
{
    int existIndex = findTheater(theaterId);

    if(!existIndex)
        cout << "Theater " << theaterId << " does not exist (You cannot show theater)" <<endl;
    else
    {
        cout << endl;
        theaters[existIndex-1].printRoom();
        cout << endl;
    }
}

int BoxOffice::makeReservation( int theaterId, int numAudiences, char* seatRow, int* seatCol)
{
    int reservationCode = -1;
    int existIndex = findTheater(theaterId);

    if(!existIndex)
        cout << "Theater " << theaterId << " does not exist (You cannot make reservation)" << endl;
    else
    {
        if(theaters[existIndex - 1].getNumOfSeats() < numAudiences)
            cout << "Theater " << theaters[existIndex - 1].getTheaterID()
                 << " does not have enough space for " << numAudiences << " audiences (You couldn't make reservation)" <<endl;
        else
            reservationCode = theaters[existIndex - 1].reserve( numAudiences, seatRow, seatCol);
    }
    return reservationCode;
}

void BoxOffice::showReservation(int resCode)
{
    int existIndex = 0;
    int whichTheater = 0;
    for(int i = 0; i < numOfTheaters; i++)
    {
        int n = theaters[i].findReservation(resCode);
        if(n != 0)
        {
            existIndex = n;
            whichTheater = i;
        }
    }

    if(!existIndex)
        cout << "No reservations found under code " << resCode << endl;
    else
    {
        cout << "Reservations under code " << resCode << " in Theater " << theaters[whichTheater].getTheaterID()
             << " (" << theaters[whichTheater].getMovieName() << "): ";
        int index = 0;
        for(int i = 0; i < theaters[whichTheater].getNumOfAudiences()[existIndex - 1]; i++)
        {
            cout << theaters[whichTheater].getReservedSeats()[existIndex - 1][index]
                 << theaters[whichTheater].getReservedSeats()[existIndex - 1][index + 1] << " ";
            index += 2;
        }
        cout << endl;

    }
}

void BoxOffice::cancelReservation(int resCode)
{
    int existIndex = 0; // index of code inside reservation code array
    int whichTheater = 0;
    for(int i = 0; i < numOfTheaters; i++)
    {
        int n = theaters[i].findReservation(resCode);
        if(n != 0)
        {
            existIndex = n;
            whichTheater = i;
        }
    }

    if(!existIndex)
        cout << "No reservations found under code " << resCode << endl;
    else
        theaters[whichTheater].cancelReserv(resCode);
}

