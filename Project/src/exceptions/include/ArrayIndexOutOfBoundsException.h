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

#ifndef PROJECT_ARRAYINDEXOUTOFBOUNDSEXCEPTION_H
#define PROJECT_ARRAYINDEXOUTOFBOUNDSEXCEPTION_H

#include "Exception.h"

class ArrayIndexOutOfBoundsException : public Exception
{
public:
    explicit ArrayIndexOutOfBoundsException(
        std::string message = "",
        std::string fileName = "<Unknown File Name>",
        int lineNumber = -1,
        std::string functionName = "<Unknown Function>",
        const std::exception *cause = nullptr);

    ArrayIndexOutOfBoundsException(ArrayIndexOutOfBoundsException &&e) = default;
};


#endif //PROJECT_ARRAYINDEXOUTOFBOUNDSEXCEPTION_H
