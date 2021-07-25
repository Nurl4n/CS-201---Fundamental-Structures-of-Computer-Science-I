#ifndef THEATER_H_INCLUDED
#define THEATER_H_INCLUDED
#include <string>

using namespace std;

class Theater
{
public:
    Theater();
    ~Theater();
    void operator=(const Theater &);
    void setTheaterID( int id);
    int getTheaterID();
    void setMovieName( string name);
    string getMovieName();
    void resetNumOfSeats( int n);
    int getNumOfSeats();
    void createRoom( int rows, int column);
    void printRoom();
    int reserve( int numAudiences, char* seatRow, int* seatCol);
    int findReservation( int resCode);
    void addNumOfAudiences(int audiences);
    void showReserve( int code);
    int* getNumOfAudiences();
    string** getReservedSeats();
    void cancelReserv( int code);
    char** getRoom();
private:
    int theaterID;
    string movieName;
    int numOfSeats;
    int rows;
    int columns;
    char** room;
    int totalNumOfReservations;
    string** reservedSeats;
    int* numOfAudiences;
    int* reservationCodes;
};

#endif // THEATER_H_INCLUDED
