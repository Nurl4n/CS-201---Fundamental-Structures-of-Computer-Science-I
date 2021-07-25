#include <iostream>
#include "PaperRepository.h"

using namespace std;

int main()
{
    PaperRepository pr;

    cout << endl;
    pr.showAllPapers();
    cout << endl;

    pr.addPaper("A", "jo", 2010);
    pr.addPaper("B", "jo", 2010);
    pr.addPaper("C", "j", 2010);
    pr.addPaper("D", "jo", 2012);
    pr.addPaper("E", "jo", 2012);
    pr.addPaper("D", "jo", 2012);
    pr.addPaper("F", "jo", 2012);


    cout << endl;
    pr.showAllPapers();
    cout << endl;

    pr.removePaper("E");
    pr.removePaper("b");
    pr.removePaper("A");
    pr.removePaper("C");

    cout << endl;
    pr.showAllPapers();
    cout << endl;




    return 0;
}
