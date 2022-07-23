//
// Created by wxx9248 on 2020-11-05.
//

#ifndef EXERCISE_2_PLAYER_H
#define EXERCISE_2_PLAYER_H

#include "CardsSet.h"

class Player
{
public:
    Player(CardsSet &cardPacket, bool isComputer) : packet(cardPacket), computer(isComputer) {}

    int play();

private:
    CardsSet inHand;
    CardsSet &packet;
    const bool computer;

    int countPoints();
};


#endif //EXERCISE_2_PLAYER_H
