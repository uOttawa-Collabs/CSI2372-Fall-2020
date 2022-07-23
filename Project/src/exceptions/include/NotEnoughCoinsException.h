/**
 * CSI2372A - Fall 2020
 * File for Final Project
 * December 5th, 2020
 *
 * @author Morris (Jun Yi) Cai: *
 * @author Jake Wang: *
 *
 * Using instructions from "Project_CSI2372_F20.pdf"
*/

#ifndef PROJECT_NOTENOUGHCOINSEXCEPTION_H
#define PROJECT_NOTENOUGHCOINSEXCEPTION_H

#include "GameException.h"

class NotEnoughCoinsException : public GameException
{
public:
    explicit NotEnoughCoinsException(int coins, std::string message = "");

    NotEnoughCoinsException(NotEnoughCoinsException &&e) = default;

    int getCoins() const;

private:
    int coins;
};


#endif //PROJECT_NOTENOUGHCOINSEXCEPTION_H
