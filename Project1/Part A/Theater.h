#ifndef THEATER_H_INCLUDED
#define THEATER_H_INCLUDED
#include <string>

using namespace std;

class Theater
{
public:
    Theater();
    ~Theater();
    void setTheaterID(int id);
    int getTheaterID();
    void setMovieName(string name);
    string getMovieName();
    void resetNumOfSeats(int n);
    int getNumOfSeats();
    void createRoom(int rows, int column);
private:
    int theaterID;
    string movieName;
    int numOfSeats;
    char** room;
};

#endif // THEATER_H_INCLUDED
