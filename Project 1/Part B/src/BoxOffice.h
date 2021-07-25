#ifndef BOXOFFICE_H_INCLUDED
#define BOXOFFICE_H_INCLUDED
#include "Theater.h"
#include <string>

using namespace std;
class BoxOffice
{
public:
    BoxOffice();
    ~BoxOffice();
    void addTheater( int theaterId, string movieName, int numRows, int numSeatsPerRow);
    void removeTheater( int theaterId);
    void showAllTheaters();
    void showTheater(int theaterId);
    int makeReservation( int theaterId, int numAudiences, char* seatRow, int* seatCol);
    void showReservation ( int resCode);
    void cancelReservation( int resCode);
    void resetNumOfTheaters( int n);
    int getNumOfTheaters();
    int findTheater( int theaterID);
private:
    Theater* theaters;
    int numOfTheaters;
};

#endif // BOXOFFICE_H_INCLUDED
