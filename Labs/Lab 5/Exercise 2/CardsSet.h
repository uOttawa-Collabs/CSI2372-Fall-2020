#ifndef EXERCISE_2_CARDSSET_H
#define EXERCISE_2_CARDSSET_H

#include "Card.h"

class CardsSet
{
public:
    CardsSet() : number(0) {}

    void novSet()
    {
        for (int i = 0; i < 13; ++i)
            for (int j = 0; j < 4; ++j)
                set[i * 4 + j] = Card(static_cast<color>(j), i);
        number = 52;
    }

    void shuffle()
    {
        srand(time(nullptr));

        for (int i = 0; i < number; ++i)
            swap(set[0], set[rand() % number]);
    }

    int numCards() { return number; }

    Card take()
    {
        if (number > 0)
            return set[--number];
        else
            throw range_error("No card in the card set");
    }

    void put(Card k)
    {
        if (number < 52)
            set[number++] = k;
        else
            throw range_error("Maximum card set size is 52");
    }

    Card lookIn(int no)
    {
        if (no >= 1 && no <= number)
            return set[number - no];
        else
            throw out_of_range("Card index out of range");
    }

    void empty() { number = 0; }

private :
    Card set[52];
    int  number;
};

#endif //EXERCISE_2_CARDSSET_H
