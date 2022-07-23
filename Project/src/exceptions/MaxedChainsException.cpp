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

#include "include/MaxedChainsException.h"

MaxedChainsException::MaxedChainsException(std::string message) : GameException(std::move(message))
{
    setExceptionName("MaxedChainsException");
}
