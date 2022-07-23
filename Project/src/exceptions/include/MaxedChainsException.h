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

#ifndef PROJECT_MAXEDCHAINSEXCEPTION_H
#define PROJECT_MAXEDCHAINSEXCEPTION_H

#include "GameException.h"

class MaxedChainsException : public GameException
{
public:
    explicit MaxedChainsException(std::string message = "");

    MaxedChainsException(MaxedChainsException &&e) = default;
};


#endif //PROJECT_MAXEDCHAINSEXCEPTION_H
