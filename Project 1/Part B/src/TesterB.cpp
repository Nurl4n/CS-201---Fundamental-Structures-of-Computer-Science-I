#include <iostream>
#include <string>
#include "BoxOffice.h"
using namespace std;

int main()
{
    BoxOffice R;
    R.showAllTheaters();
    R.addTheater(10425, "Ted", 4, 3);
    R.addTheater(8234, "Cloud Atlas", 8, 3);
    R.addTheater(9176, "Hope Springs", 6, 2);
    R.showAllTheaters();
    R.addTheater(10425, "Skyfall", 8, 6);
    R.showAllTheaters();
    R.showTheater(10425);

    char rowRes1[4] = {'A', 'B', 'B', 'C'};
    int colRes1[4] = {3, 3, 1, 1};
    int code1 = R.makeReservation(10425, 4, rowRes1, colRes1);
    if(code1 != -1)
        cout << "Your reservation code is " << code1 << endl;
    R.showTheater(10425);

    char rowRes2[2] = {'A','D'};
    int colRes2[2] = {2,3};
    int code2 = R.makeReservation(10425, 2, rowRes2, colRes2);
    if(code2 != -1)
        cout << "Your reservation code is " << code2 << endl;
    R.showTheater(10425);

    char rowRes3[2] = {'B','A'};
    int colRes3[2] = {2,3};
    int code3 = R.makeReservation(10425, 2, rowRes3, colRes3);
    if(code3 != -1)
        cout << "Your reservation code is " << code3 << endl;
    R.showTheater(10425);

    char rowRes4[7] = {'A','B','C','C','A','B','D'};
    int colRes4[7] = {1,2,2,3,2,1,2};
    int code4 = R.makeReservation(10425, 7, rowRes4, colRes4);
    if(code4 != -1)
        cout << "Your reservation code is " << code4 << endl;
    R.showTheater(10425);

    R.showAllTheaters();
    R.showReservation(code1);
    R.showReservation(100);
    R.cancelReservation(code2);
    R.showTheater(10425);
    R.showAllTheaters();
    R.cancelReservation(300);

    R.removeTheater(8234);
    R.showTheater(8234);
    R.showAllTheaters();
    R.removeTheater(674);
    R.showAllTheaters();

    R.removeTheater(10425);
    R.showReservation(code1);
    R.showAllTheaters();

    BoxOffice R2;
    R2.showAllTheaters();
    R2.addTheater(9176, "Skyfall", 3, 3);
    R2.showAllTheaters();

    /*
    string a = "Nurlan";
    a += " Farzali";
    cout << a << endl;


    int Number = 123;
    string String = static_cast<ostringstream*>( &(ostringstream() << Number) )->str();

    cout << String;



    //R.theaters[0].findReservation(code1);


    char** reserv = 0;
    reserv = new char*[4];
    for(int i = 0; i < 4; i++)
        reserv[i] = new char[4];

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            reserv[i][j] = '1';
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
            cout << reserv[i][j];
        cout <<endl;
    }
    cout << sizeof reserv[2] / sizeof (char);

    cout << " ";
    for(int i = 0; i < 4; i++)
        cout << "  " << i+1;
    cout << endl;

    cout << "alma";
    char a = 'A';
    for(int i = 0; i < 26; i++)
        cout << a++ << endl;

    char** a;
    a = new char* [6];
    for(int i =0; i < 6; i++)
        a[i] = new char [9];

    cout << "Size of array is " ;*/

    return 0;
}
