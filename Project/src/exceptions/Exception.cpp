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

#include "include/Exception.h"
#include <typeinfo>

Exception::~Exception() noexcept
{
    delete cause;
}

const char *Exception::what() const
{
    whatMessage =
        exceptionName
        + (message.empty() ? "" : ": " + message)
        + '\n'
        + "\tat " + functionName + "(" + fileName + ": "
        + (lineNumber == -1 ? "<Unknown Line>" : std::to_string(lineNumber))
        + ")"
        + '\n';

    if (cause != nullptr)
    {
        whatMessage += "Caused by: ";

        try
        {
            const auto &e = dynamic_cast<const Exception &>(*cause);
            whatMessage += e.what();
        }
        catch (const std::bad_cast &e)
        {
            whatMessage += cause->what();
        }
    }

    return whatMessage.c_str();
}

const std::string &Exception::getMessage() const
{
    return message;
}

const std::string &Exception::getExceptionName() const
{
    return exceptionName;
}

const std::string &Exception::getFileName() const
{
    return fileName;
}

int Exception::getLineNumber() const
{
    return lineNumber;
}

const std::string &Exception::getFunctionName() const
{
    return functionName;
}

const std::exception *Exception::getCause() const
{
    return cause;
}

void Exception::setExceptionName(std::string name) const
{
    exceptionName = std::move(name);
}
