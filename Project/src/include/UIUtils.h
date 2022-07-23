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

#ifndef PROJECT_UIUTILS_H
#define PROJECT_UIUTILS_H

#include <string>
#include <vector>

namespace UIUtils
{
    void printWelcomeMessage(std::ostream &outputStream);

    int choice(std::istream &inputStream, std::ostream &outputStream, int choices);

    int choice(std::istream &inputStream, std::ostream &outputStream, const std::vector<int> &choices);

    void flush(std::istream &inputStream);

    std::string
    getNonEmptyLine(std::istream &inputStream, std::ostream &outputStream, const std::string &hint, bool flush = false);
}

#endif //PROJECT_UIUTILS_H
