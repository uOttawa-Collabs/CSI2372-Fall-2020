#include "myfile2.h"

/*
 * Exercise 2 1)
 * 
 * The main() function first obtain the radius and height from user's input,
 * then output the latest corresponding calculation result of surface or volume when exiting the program.
 */
int main()
{
    char choice;
    int nvolume = 0;
    int nsurface = 0;
    double radius, height;

    while (1)
    {
        choice = menu();
        switch (choice)
        {
            case '1':
                cout << endl << "Surface calculation" << endl;
                cout << "Enter the radius:";
                cin >> radius;
                nsurface = surface(radius);
                break;
            case '2':
                cout << endl << "Volume calculation" << endl;
                cout << " Enter the radius:";
                cin >> radius;
                cout << " Enter the height:";
                cin >> height;
                nvolume = volume(radius, height);
                break;
            case '3':
                cout << endl << "Exit the program" << endl;
                cout << "The volume function has been executed" << nvolume << "times" << endl;
                cout << "The surface function has been executed" << nsurface << "times" << endl;
                exit(0);
            default:
                break;
        }
    }
}

char menu()
{
    char choice;

    cout << "What do you want to do?:" << endl << endl;
    cout << "\t-Calculate the area of a disk from a radius (Press 1)" << endl << endl;
    cout << "\t-Calculate the volume of a cylinder from a radius and a height (Press 2)" << endl << endl; cout << "\t-Exit the program (press 3)" << endl << endl;
    cout << "Your choice:";
    cin >> choice;

    return choice;
}

double surface(double r)
{
    return Pi * r * r;
}

double volume(double r, double h)
{
    return Pi * r * r * h;
}
