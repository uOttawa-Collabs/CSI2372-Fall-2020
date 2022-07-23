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

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "include/Table.h"
#include "include/Chain.h"
#include "include/UIUtils.h"
#include "exceptions/include/Exception.h"

static const char *saveFilePath = "save.txt";
static const char *saveFilePath2 = "save2.txt";

void newGame();

void loadGame();

void saveGame(std::array<std::string, Table::PLAYER_NUMBER>, Table&);

int main()
{
    
    try
    {
        UIUtils::printWelcomeMessage(std::cout);

        std::cout << "Please choose:" << std::endl;
        std::cout << "1.\tNew game" << std::endl;
        std::cout << "2.\tLoad game" << std::endl;
        std::cout << "3.\tQuit" << std::endl;

        switch (UIUtils::choice(std::cin, std::cout, 3))
        {
            case 1:
                newGame();
                break;
            case 2:
                loadGame();
                break;
            case 3:
                return 0;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
    
}

void newGame()
{
    bool toContinue = true;
    std::array<std::string, Table::PLAYER_NUMBER> names;
    for (int i = 0; i < Table::PLAYER_NUMBER; ++i)
        names[i] =
            std::move(UIUtils::getNonEmptyLine(std::cin,
                                               std::cout,
                                               "Please enter the name of player " + std::to_string(i + 1) + ": "));

    std::cout << "Initializing game..." << std::endl;
    Table table(CardFactory::getFactory(), names);
    int counter = 0;
    while (!table.isGameOver() && toContinue)
    {
        std::cout << "Current table:" << std::endl;
        std::cout << table << std::endl;
        table.play(std::cin, std::cout);

        //Counter used to only ask on every other turn.
        if (counter == 1) {
            counter = 0;
            std::cout << "Would you like to save game? (1/2) 1 = save, 2 = continue" << std::endl;
            switch (UIUtils::choice(std::cin, std::cout, 2))
            {
            case 1:
                toContinue = false;
                saveGame(names, table);
                break;
            default:
                break;
            }
        }
        else {
            counter = 1;
        }
        
    }
    //Only output winner status if game is not saved
    if (toContinue) {
        std::cout << "Game over" << std::endl;
        for (std::string& name : names)
            std::cout << "Player " << name << " won: " << table.win(name) << std::endl;
    }
}

void loadGame()
{
    std::cout << "Initializing save game..." << std::endl;
    std::ifstream inStr(saveFilePath);

    //Getting the two names of the players
    char one[256], two[256];
    inStr.getline(one, 256);
    inStr.getline(two, 256);
    std::array<std::string, Table::PLAYER_NUMBER> names; 
    names[0] = one;
    names[1] = two;

    //Initializing table 
    Table table(inStr, CardFactory::getFactory());

    //Same play game function as before
    bool counter = 0;
    bool toContinue = true;
    while (!table.isGameOver() && toContinue)
    {
        std::cout << "Current table:" << std::endl;
        std::cout << table << std::endl;
        table.play(std::cin, std::cout);

        //Counter used to only ask on every other turn.
        if (counter == 1) {
            counter = 0;
            std::cout << "Would you like to save game? (1/2) 1 = save, 2 = continue" << std::endl;
            switch (UIUtils::choice(std::cin, std::cout, 2))
            {
            case 1:
                toContinue = false;
                saveGame(names, table);
                break;
            default:
                break;
            }
        }
        else {
            counter = 1;
        }
    }

    //Only output winner status if game is not saved
    if (toContinue) {
        std::cout << "Game over" << std::endl;
        for (std::string& name : names)
            std::cout << "Player " << name << " won: " << table.win(name) << std::endl;
    }
}

void saveGame(std::array<std::string, Table::PLAYER_NUMBER> names, Table &table) {

    std::cout << "Saving game to: " << *saveFilePath << std::endl;
    
    //Initiating File Stream 
    std::ofstream oStream;
    oStream.open(saveFilePath);

    //inputting names
    oStream << names[0] << std::endl;
    oStream << names[1] << std::endl;
    
    //Inputting deck
    oStream << table.deck << std::endl;

    //Inputting table (excluding deck)
    oStream << table << std::endl;

    oStream.close();

    std::cout << "Save Complete. Terminating Instance" << std::endl;
}