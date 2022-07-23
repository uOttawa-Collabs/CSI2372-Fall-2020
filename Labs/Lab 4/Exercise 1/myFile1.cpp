#include <iostream>

#include "myFile1a.h"
#include "myFile1b.h"

using namespace std;

int main()
{
    Course  *Math = new Course(100, 60);
    Course  *ITI  = new Course(200, 120);
    Student *Yan  = new Student(1, 35);
    Student *Jane = new Student(2, 35);
    Yan->addCourse(Math, 15);
    Yan->addCourse(ITI, 12);
    Jane->addCourse(Math, 8);
    Jane->addCourse(ITI, 5);
    cout << "The total hours of Yan is " << Yan->totalHours() << endl;
    cout << "The average of Yan is " << Yan->average() << endl;
    cout << "The total hours of Jane is " << Jane->totalHours() << endl;
    cout << " The average of Jane is " << Jane->average() << endl;
    delete Math;
    delete ITI;
    delete Yan;
    delete Jane;
    cout << "Enter a number to exit..." << endl;
    return 0;
}
