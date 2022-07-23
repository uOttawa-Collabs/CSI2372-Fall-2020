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
#ifndef PROJECT_EMPTYCONTAINEREXCEPTION_H
#define PROJECT_EMPTYCONTAINEREXCEPTION_H

#include "Exception.h"
#include <string>

class EmptyContainerException : public Exception
{
public:
    explicit EmptyContainerException(
        std::string message = "",
        std::string fileName = "<Unknown File Name>",
        int lineNumber = -1,
        std::string functionName = "<Unknown Function>",
        const std::exception *cause = nullptr);

    EmptyContainerException(EmptyContainerException &&e) = default;
};


#endif //PROJECT_EMPTYCONTAINEREXCEPTION_H
