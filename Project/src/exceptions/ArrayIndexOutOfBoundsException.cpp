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

#include "include/ArrayIndexOutOfBoundsException.h"

ArrayIndexOutOfBoundsException::ArrayIndexOutOfBoundsException(std::string message,
                                           std::string fileName,
                                           int lineNumber,
                                           std::string functionName,
                                           const std::exception *cause) :
    Exception(std::move(message), std::move(fileName), lineNumber, std::move(functionName), cause)
{
    setExceptionName("ArrayIndexOutOfBoundsException");
}
