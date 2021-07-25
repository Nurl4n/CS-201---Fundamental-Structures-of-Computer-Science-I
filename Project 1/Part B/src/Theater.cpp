#include <iostream>
#include <string>
#include "Theater.h"
#include <iomanip>
#include <locale>
#include <sstream>
#include <cstring>
#include <cstdio>

using namespace std;

Theater::Theater()
{
    theaterID = 0;
    numOfSeats = 0;
    rows = 0;
    columns = 0;
    movieName = "NULL";
    numOfAudiences = 0;
    totalNumOfReservations = 0;
    reservedSeats = NULL;
    reservationCodes = 0;
}

Theater::~Theater()
{
    for(int i = 0; i < rows; i++)
        delete[] room[i];
    delete[] room;

    for(int i = 0; i < totalNumOfReservations; i++)
        delete[] reservedSeats[i];
    delete[] reservedSeats;

    delete[] numOfAudiences;

    delete[] reservationCodes;
}

void Theater::operator=(const Theater & theaterToCopy)
{
    if( &theaterToCopy != this)
    {
        theaterID = theaterToCopy.theaterID;
        movieName = theaterToCopy.movieName;
        numOfSeats = theaterToCopy.numOfSeats;
        rows = theaterToCopy.rows;
        columns = theaterToCopy.columns;
        totalNumOfReservations = theaterToCopy.totalNumOfReservations;

        room = new char*[theaterToCopy.rows];
        for(int i = 0; i < theaterToCopy.rows; i++)
            room[i] = new char[theaterToCopy.columns];

        for( int i = 0; i < theaterToCopy.rows; i++)
            for( int j = 0; j < theaterToCopy.columns; j++)
                room[i][j] = theaterToCopy.room[i][j];


        numOfAudiences = new int[theaterToCopy.totalNumOfReservations];
        for(int i = 0; i < theaterToCopy.totalNumOfReservations; i++)
            numOfAudiences[i] = theaterToCopy.numOfAudiences[i];


        reservedSeats = new string*[theaterToCopy.totalNumOfReservations];
        for(int i = 0; i < theaterToCopy.totalNumOfReservations; i++)
            reservedSeats[i] = new string[theaterToCopy.numOfAudiences[i] * 2];

        for( int i = 0; i < theaterToCopy.totalNumOfReservations; i++)
            for( int j = 0; j < theaterToCopy.numOfAudiences[i] * 2; j++)
                reservedSeats[i][j] = theaterToCopy.reservedSeats[i][j];

        reservationCodes = new int[theaterToCopy.totalNumOfReservations];
        for(int i = 0; i < theaterToCopy.totalNumOfReservations; i++)
            reservationCodes[i] = theaterToCopy.reservationCodes[i];
    }
}

void Theater::setTheaterID( int id)
{
    theaterID = id;
}

void Theater::setMovieName( string name)
{
    movieName = name;
}

int Theater::getTheaterID()
{
    return theaterID;
}

string Theater::getMovieName()
{
    return movieName;
}

void Theater::createRoom( int row, int column)
{
    resetNumOfSeats(row * column);
    rows = row;
    columns = column;
    room = new char*[row];
    for(int i = 0; i < row; i++)
        room[i] = new char[column];
    for(int i = 0; i < row; i++)
        for(int j = 0; j < column; j++)
            room[i][j] = 'o';
}

void Theater::resetNumOfSeats( int n)
{
    numOfSeats = n;
}

int Theater::getNumOfSeats()
{
    return numOfSeats;
}

void Theater::printRoom()
{
    cout << "Theater " << getTheaterID() << "(" << getMovieName()
         << ") has " << getNumOfSeats() << " available seats" << endl;

    cout << " ";
    for(int i = 0; i < columns; i++)
        cout << "  " << i+1;
    cout << endl;
    char row = 'A';
    for(int i = 0; i < rows; i++)
    {
        cout << row;
        for(int j = 0; j < columns; j++)
            cout << "  " << room[i][j];
        row++;
        cout << endl;
    }
}

void Theater::addNumOfAudiences(int audiences)
{
    int* temp = numOfAudiences;
    numOfAudiences = new int[totalNumOfReservations];
    for(int i = 0; i < totalNumOfReservations - 1; i++)
        numOfAudiences[i] = temp[i];
    numOfAudiences[totalNumOfReservations - 1] = audiences;
    if(temp != NULL)
        delete [] temp;
}

int Theater::reserve( int numAudiences, char* seatRow, int* seatCol)
{
    int codeReserve = 1;
    int arr[2*numAudiences]; // to keep indexes of seats in order to reserve
    int arrIndex = 0;
    int notPossible = 0;
    int rowNum;
    int colNum;
    char rowLetter;
    string takenSeat [2];
    for(int i = 0; i < numAudiences; i++)
    {
        rowLetter = 'A';
        rowNum = 0;
        for(int j = 0; j < rows; j++)
            if(seatRow[i] != rowLetter)
            {
                rowLetter++;
                rowNum++;
            }
        colNum = 1;
        for(int j = 0; j < columns; j++)
            if(seatCol[i] != colNum)
                colNum++; // colNum - 1's index in room array

        if(room[rowNum][colNum - 1] == 'x')
        {
            notPossible = 1;
            takenSeat[0] = rowLetter;
            int n = colNum;
            string String = static_cast<ostringstream*>( &(ostringstream() << n) )->str();
            takenSeat[1] = String;
        }
        else
        {
            arr[arrIndex] = rowNum;
            arr[arrIndex+1] = colNum - 1;
            arrIndex += 2;
            codeReserve = codeReserve * (rowNum+1) * colNum;
        }
    }

    if(notPossible)
        cout << "Seat " << takenSeat[0] << takenSeat[1] << " has already been taken" << endl << endl;
    else
    {
        totalNumOfReservations++;
        for(int i = 0; i < 2 * numAudiences; i += 2)
            room[arr[i]][arr[i+1]] = 'x';
        codeReserve = codeReserve * numAudiences * 100;

        int* tempCodes = reservationCodes;
        reservationCodes = new int[totalNumOfReservations];
        for(int i = 0; i < totalNumOfReservations - 1; i++)
            reservationCodes[i] = tempCodes[i];
        reservationCodes[totalNumOfReservations - 1] = codeReserve;
        if(tempCodes != NULL)
            delete[] tempCodes;

        /*keeping reserved seats*/
        addNumOfAudiences(numAudiences);

        string** temp = reservedSeats;
        reservedSeats = new string* [totalNumOfReservations];
        for(int i = 0; i < totalNumOfReservations; i++)
            reservedSeats[i] = new string[numOfAudiences[i] * 2];

        for(int i = 0; i < totalNumOfReservations - 1; i++)
            for(int j = 0; j < numOfAudiences[i] * 2; j++)
                reservedSeats[i][j] = temp[i][j];

        int indexForReservedSeats = 0;
        for(int i = 0; i < numAudiences; i++)
        {
            reservedSeats[totalNumOfReservations - 1][indexForReservedSeats] = seatRow[i];
            int Number = seatCol[i];
            string String = static_cast<ostringstream*>( &(ostringstream() << Number) )->str();
            reservedSeats[totalNumOfReservations - 1][indexForReservedSeats + 1] = String;
            indexForReservedSeats += 2;
        }

        resetNumOfSeats(getNumOfSeats() - numAudiences);

        /* deleting temp*/
        if(temp != NULL){
            for(int j = 0; j < totalNumOfReservations - 1; j++)
                delete [] temp[j];
            delete [] temp;
        }
    }
    return codeReserve;
}

int Theater::findReservation( int resCode)
{
    int existIndex = 0;
    for(int i = 0; i < totalNumOfReservations; i++)
        if(reservationCodes[i] == resCode)
            existIndex = i+1;
    return existIndex;
}


void Theater::cancelReserv( int code)
{
    int existIndex = findReservation(code);

    const char* arrRow; // to keep indexes of seats in order to reserve
    int rowNum;
    int colNum;
    char rowLetter;
    for(int i = 0; i < numOfAudiences[existIndex - 1] * 2; i += 2)
    {
        rowLetter = 'A';
        rowNum = 0;
        arrRow = reservedSeats[existIndex - 1][i].c_str();
        for(int j = 0; j < rows; j++)
            if(arrRow[0] != rowLetter)
            {
                rowLetter++;
                rowNum++;
            }

        colNum = 1;
        for(int j = 0; j < columns; j++)
        {
            int z;
            sscanf(reservedSeats[existIndex - 1][i + 1].c_str(), "%d", &z);
            if(z != colNum)
                colNum++; // colNum - 1's index in room array
        }
        room[rowNum][colNum - 1] = 'o';
    }
    resetNumOfSeats(getNumOfSeats() + numOfAudiences[existIndex - 1]); // after canceling reservation under reservation code

    string seatsdeleted = "";
    for(int i = 0; i < numOfAudiences[existIndex - 1] * 2; i += 2)
        seatsdeleted += reservedSeats[existIndex  -1][i] + reservedSeats[existIndex  -1][i + 1] + " ";
    cout << "Reservation for seats " << seatsdeleted << "is cancelled in Theater " << theaterID << " (" << movieName << ") " << endl;

    // reset reserved seats array
    string** temp = reservedSeats;
    reservedSeats = new string*[totalNumOfReservations - 1];
    for(int i = 0; i < existIndex - 1; i++)
        reservedSeats[i] = new string[numOfAudiences[i] * 2];
    for(int i = existIndex; i < totalNumOfReservations; i++)
        reservedSeats[i - 1] = new string[numOfAudiences[i] * 2];

    for(int i = 0; i < existIndex - 1; i++)
        for(int j = 0; j < numOfAudiences[i] * 2; j++)
            reservedSeats[i][j] = temp[i][j];
    for(int i = existIndex; i < totalNumOfReservations; i++)
        for(int j = 0; j < numOfAudiences[i] * 2; j++)
            reservedSeats[i - 1][j] = temp[i][j];

    delete[] temp;

    // reset reservation codes array
    int* tempForResCodes = reservationCodes;
    reservationCodes = new int[totalNumOfReservations - 1];
    for(int i = 0; i < existIndex - 1; i++)
        reservationCodes[i] = tempForResCodes[i];
    for(int i = existIndex; i < totalNumOfReservations; i++)
        reservationCodes[i - 1] = tempForResCodes[i];

    delete[] tempForResCodes;

    // reset number of audiences array
    int* tempForNumAud = numOfAudiences;
    numOfAudiences = new int[totalNumOfReservations - 1];
    for(int i = 0; i < existIndex - 1; i++)
        numOfAudiences[i] = tempForNumAud[i];
    for(int i = existIndex; i < totalNumOfReservations; i++)
        numOfAudiences[i - 1] = tempForNumAud[i];

    delete[] tempForNumAud;

    totalNumOfReservations--;
}

int* Theater::getNumOfAudiences()
{
    return numOfAudiences;
}

string** Theater::getReservedSeats()
{
    return reservedSeats;
}

char** Theater::getRoom()
{
    return room;
}
