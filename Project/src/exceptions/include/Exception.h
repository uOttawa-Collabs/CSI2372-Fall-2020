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

#ifndef PROJECT_EXCEPTION_H
#define PROJECT_EXCEPTION_H

#include <stdexcept>
#include <string>
#include <utility>

class Exception : public std::exception
{
public:
    explicit Exception(std::string message = "",
                       std::string fileName = "<Unknown File Name>",
                       int lineNumber = -1,
                       std::string functionName = "<Unknown Function>",
                       const std::exception *cause = nullptr) :
        message(move(message)),
        exceptionName("Exception"),
        fileName(move(fileName)),
        lineNumber(lineNumber),
        functionName(move(functionName)),
        cause(cause) {}

    Exception(Exception &&e) = default;

    ~Exception() noexcept override;

    [[nodiscard]] const char *what() const override;

    const std::string &getMessage() const;

    const std::string &getExceptionName() const;

    const std::string &getFileName() const;

    int getLineNumber() const;

    const std::string &getFunctionName() const;

    const std::exception *getCause() const;

protected:
    void setExceptionName(std::string name) const;

private:
    const std::string message;

    const std::string    fileName;
    const int            lineNumber;
    const std::string    functionName;
    const std::exception *cause;

    mutable std::string exceptionName;
    mutable std::string whatMessage;
};

#endif //PROJECT_EXCEPTION_H
