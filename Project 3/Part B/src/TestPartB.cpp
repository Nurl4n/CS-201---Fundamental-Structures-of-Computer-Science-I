#include <iostream>
#include "PaperRepository.h"

using namespace std;

int main()
{
    PaperRepository pr;

    cout << endl;
    pr.showAllPapers();
    cout << endl;

    pr.addPaper("Smoke Simulation", "SIGGRAPH", 2010);
    pr.addPaper("3D Thumbnail", "Algorithms and Technologies", 2011);
    pr.addPaper("Dynamic Clustering", "SIGR", 1999);
    pr.addPaper("Efficient SVMs", "IEEE", 1999);
    pr.addPaper("Neural Networks", "IEEE", 2002);
    pr.addPaper("Neural Networks", "ICML", 2005);

    cout << endl;
    pr.showAllPapers();
    cout << endl;

    pr.addCoauthor("Smoke Simulation", "Okan", "Arikan", "Bilkent");
    pr.addCoauthor("3D Thumbnail", "Funda", "Atik", "AYESAS");
    pr.addCoauthor("3D Thumbnail", "Sena", "Atik", "AYESAS");
    pr.addCoauthor("Dynamic Clustering", "Gokhan", "Akcay", "Bilkent");
    pr.addCoauthor("Neural Networks", "Aynur", "Dayanik", "Bilkent");
    pr.addCoauthor("Neural Networks", "Funda", "Atik", "Bilkent");
    pr.addCoauthor("Explosion Simulation", "Aynur", "Dayanik", "Bilkent");
    pr.addCoauthor("Neural Networks", "Aynur", "Dayanik", "Bilkent");
    pr.addCoauthor("3D Thumbnail", "Yeliz", "Yigit", "Yogurt Tech");
    pr.addCoauthor("Efficient SVMs", "Cigdem", "Gunduz Demir", "Bilkent");
    pr.addCoauthor("Efficient SVMs", "Funda", "Atik", "Bilkent");

    cout << endl;
    pr.showCoauthor("Funda", "Atik");
    cout << endl;
    pr.showCoauthor("Aynur", "Dayanik");
    cout << endl;

    pr.removeCoauthor("Funda", "Atik");
    pr.removeCoauthor("Aynur", "Dayanik");
    pr.removeCoauthor("Can", "Koyuncu");

    cout << endl;
    pr.showCoauthor("Funda", "Atik");
    cout << endl;
    pr.showCoauthor("Aynur", "Dayanik");
    cout << endl;

    pr.showJournal("Algorithms and Technologies");
    cout << endl;
    pr.showJournal("IEEE");
    cout << endl;

    pr.removePaper("Neural Networks");
    pr.removePaper("3D Thumbnail");
    pr.removePaper("Explosion Simulation");

    cout << endl;
    pr.showJournal("Algorithms and Technologies");
    cout << endl;
    pr.showJournal("IEEE");

    cout << endl;
    pr.showAllPapers();
    cout << endl;


    /*
    string a = "Nalrun";
    string b = "Nurlan";
    int c = 0;

    if(a.length() > b.length() )
        c = a.length();
    else
        c = b.length();
    string con = "big";

    int d = 0;
    d = a.length() >= b.length() ? a.length() : b.length();
    cout << d <<endl;
    if(a < b)
        con = "small";
    cout << con;
    //for(int i = 0 ; i < a. > )
    */
    /*
    int b = 5;
    cout << b << endl;
    fun(b);
    cout << b << endl;
    */



    return 0;
}
