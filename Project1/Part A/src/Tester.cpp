#include <iostream>
#include <string>
#include "BoxOffice.h"

using namespace std;

int main()
{
    BoxOffice R;
    R.showAllTheaters();
    R.addTheater(10425, "Ted", 4, 3);
    R.addTheater(10425, "Ted", 5, 3);
    R.addTheater(1045, "Ted", 7, 2);
    R.addTheater(1045, "Ted", 4, 6);
    R.addTheater(145, "Ted", 9, 3);
    R.addTheater(105, "Ted", 10, 3);
    R.addTheater(45, "Ted", 11, 3);
    cout << "Number of theaters: " <<R.getNumOfTheaters() << endl;
    R.showAllTheaters();

    R.removeTheater(10425);
    cout << "Number of theaters: " <<R.getNumOfTheaters() << endl;
    R.showAllTheaters();
    return 0;


}
