#include <iostream>
#include <string>
#include "Theater.h"
using namespace std;

Theater::Theater()
{
    theaterID = 0;
    numOfSeats = 0;
    movieName = "NULL";
}

Theater::~Theater(){}

void Theater::setTheaterID( int id)
{
    theaterID = id;
}

void Theater::setMovieName(string name)
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

void Theater::createRoom(int rows, int column)
{
    resetNumOfSeats(rows * column);
    room = new char*[rows];
    for(int i = 0; i < rows; i++)
        room[i] = new char[column];
}

void Theater::resetNumOfSeats(int n)
{
    numOfSeats = n;
}

int Theater::getNumOfSeats()
{
    return numOfSeats;
}

