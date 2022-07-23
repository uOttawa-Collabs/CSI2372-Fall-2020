#ifndef EXERCISE_2_CARD_H
#define EXERCISE_2_CARD_H

/*Card.h*/
#include <iostream>

using namespace std;

#include <cassert> //for assert()

#include <string>
#define ENUM_STRINGIFY(x) #x

enum color
{
    club, diamond, heart, spade
};

const char *colorString[] =
{
    "club", "diamond", "heart", "spade"
};

class Card
{
public :
    Card(color c = club, int v = 1);

    int value() { return val; }

    void write()
    {
        string value;
        switch (val)
        {
            case 11:
                value = "jack";
                break;
            case 12:
                value = "queen";
                break;
            case 13:
                value = "king";
                break;
            default:
                value = to_string(val);
                break;
        }
        cout << '(' << colorString[col] << ", " << value << ')';
    }

private :
    color col;
    int   val;
};

/*Constructor*/
Card::Card(color c, int v)
{
    assert (v >= 1 && v <= 13); //we use a standard function void assert (int expression)
    // which indicates an error message if the expression is false.
    col = c;
    val = v;
}

#endif
