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

#include "include/UIUtils.h"
#include "include/Utils.h"

#include <iostream>
#include <string>

void UIUtils::printWelcomeMessage(std::ostream &outputStream)
{
    outputStream << "Bohnanza - CSI2372 F2020 Final Project" << std::endl << std::endl;
    outputStream << "----------Designed by:----------" << std::endl;
    outputStream << "Morris (Jun Yi) Cai:\t*" << std::endl;
    outputStream << "Jake Wang:\t\t*" << std::endl << std::endl;
}

int UIUtils::choice(std::istream &inputStream, std::ostream &outputStream, int choices)
{
    if (choices > 0)
    {
        int c;

        outputStream << "Your choice (1";
        for (int i = 2; i <= choices; ++i)
            outputStream << '/' << i;
        outputStream << "): ";

        while (!(inputStream >> c) || c < 1 || c > choices)
        {
            outputStream << "Invalid input. Please try again." << std::endl;
            if (!inputStream)
            {
                inputStream.clear();
                while (inputStream.get() != '\n');
            }
        }

        UIUtils::flush(inputStream);
        return c;
    }
    else
        return -1;
}

int UIUtils::choice(std::istream &inputStream, std::ostream &outputStream, const std::vector<int> &choices)
{
    if (!choices.empty())
    {
        int c;

        outputStream << "Your choice (" << choices[0];
        for (int i = 1; i < choices.size(); ++i)
            outputStream << '/' << choices[i];
        outputStream << "): ";

        while (!(inputStream >> c) || std::find(choices.begin(), choices.end(), c) == choices.end())
        {
            outputStream << "Invalid input. Please try again." << std::endl;
            if (!inputStream)
            {
                inputStream.clear();
                while (inputStream.get() != '\n');
            }
        }

        UIUtils::flush(inputStream);
        return c;
    }
    else
        return -1;
}

void UIUtils::flush(std::istream &inputStream)
{
    char c;
    while ((c = inputStream.get()) != '\n' && c != EOF);
}

std::string
UIUtils::getNonEmptyLine(std::istream &inputStream, std::ostream &outputStream, const std::string &hint, bool flush)
{
    if (flush)
        UIUtils::flush(inputStream);

    std::string line;

    outputStream << hint;

    while (line.empty())
    {
        std::getline(inputStream, line);
        Utils::trim(line);

        if (line.empty())
            outputStream << "Empty input, please try again." << std::endl;
    }

    return line;
}
