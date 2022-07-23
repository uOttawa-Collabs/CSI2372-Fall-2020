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

#ifndef PROJECT_GAMEEXCEPTION_H
#define PROJECT_GAMEEXCEPTION_H

#include <string>

#include "Exception.h"

class GameException : public Exception
{
public:
    explicit GameException(std::string message = "");
    GameException(GameException &&e) = default;
};


#endif //PROJECT_GAMEEXCEPTION_H
