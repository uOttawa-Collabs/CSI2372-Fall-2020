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

#ifndef PROJECT_MIXEDCARDEXCEPTION_H
#define PROJECT_MIXEDCARDEXCEPTION_H

#include "GameException.h"

class MixedCardException : public GameException
{
public:
    explicit MixedCardException(std::string message = "");

    MixedCardException(MixedCardException &&e) = default;
};


#endif //PROJECT_MIXEDCARDEXCEPTION_H
