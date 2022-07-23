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

#include "include/Player.h"
#include "include/Chain.h"
#include "include/CardFactory.h"
#include "include/Card.h"
#include <iostream>
#include <stdio.h>
#include "exceptions/include/NotEnoughCoinsException.h"
#include "exceptions/include/MaxedChainsException.h"
#include "exceptions/include/ArrayIndexOutOfBoundsException.h"
#include "exceptions/include/EmptyContainerException.h"

Player::Player(std::string name, const CardFactory *cardFactory) :
    name(std::move(name)),
    cardFactory(cardFactory),
    numCoins(0),
    maxNumChains(Player::NUMBER_MAX_CHAINS),
    numChains(Player::NUMBER_START_CHAINS),
    hand(cardFactory)
{
    chains.fill(nullptr);

    for (int i = 0; i < NUMBER_START_CHAINS; ++i)
        chains[i] = new Chain(cardFactory);
}

Player::Player(std::istream& inputStream, const CardFactory* cardFactory) :
    cardFactory(cardFactory),
    hand(inputStream, cardFactory)
{
    char c[256];

    //Skipping space line before each player (or "----Players----" line)
    inputStream.getline(c, 256);


    //Getting Name
    //inputStream.getline(c, 256);
    inputStream.getline(c, 256);
    name = c;
    std::remove_if(name.begin(), name.end(), isspace);
    std::cout << "Name:" << name << std::endl;

    //Getting numCoins
    inputStream.getline(c, 256);
    inputStream.getline(c, 256);
    sscanf_s(c, "%d", &numCoins);
    std::cout << "Coins:" << numCoins << std::endl;

    //Getting maxNumChains
    inputStream.getline(c, 256);
    inputStream.getline(c, 256);
    sscanf_s(c, "%d", &maxNumChains);
    std::cout << "Max Chains:" << maxNumChains << std::endl;

    //Getting numChains;
    inputStream.getline(c, 256);
    inputStream.getline(c, 256);
    sscanf_s(c, "%d", &numChains);
    std::cout << "Num Chains:" << numChains << std::endl;

    
    for (int i = 0; i < numChains; ++i) 
        chains[i] = new Chain(inputStream, cardFactory);

    
}

const std::string &Player::getName() const noexcept
{
    return name;
}

int Player::getNumCoins() const noexcept
{
    return numCoins;
}

Player &Player::operator+=(int coins) noexcept
{
    numCoins += coins;
    return *this;
}

Player &Player::operator+=(const Card *card) noexcept(false)
{
    hand += card;
    return *this;
}

int Player::getMaxNumChains() const noexcept
{
    return maxNumChains;
}

int Player::getNumChains() const noexcept
{
    return numChains;
}

int Player::getHandCardNumber() const noexcept
{
    return hand.hand.size();
}

Chain &Player::operator[](int index) const noexcept(false)
{
    if (index < numChains || index > 0)
        return *chains[index];
    else
        throw ArrayIndexOutOfBoundsException("Chain index (" + std::to_string(index) + ") is out of bounds",
                                             __FILE__,
                                             __LINE__,
                                             __FUNCTION__);
}

void Player::buyThirdChain() noexcept(false)
{
    if (numCoins < 3)
        throw NotEnoughCoinsException(numCoins, "Need at least 3 coins to buy a chain");
    else if (numChains >= 3)
        throw MaxedChainsException("A player can have " + std::to_string(NUMBER_MAX_CHAINS) + " chains at most");
    else
    {
        chains[numChains++] = new Chain(cardFactory);
        numCoins -= 3;
    }
}

void Player::printHand(std::ostream &outputStream, bool printAll) const noexcept(false)
{
    if (printAll)
        outputStream << hand;
    else
    {
        if (hand.top() == nullptr)
            throw EmptyContainerException("Player's hand is empty",
                                          __FILE__,
                                          __LINE__,
                                          __FUNCTION__);
        else
            outputStream << *hand.top();
    }
}

const Card *Player::play() noexcept(false)
{
    return hand.play();
}

const Card *Player::discard(int index) noexcept(false)
{
    return hand[index];
}

std::ostream &operator<<(std::ostream &outputStream, const Player &player) noexcept
{
    //Output Name
    outputStream << "--Name: " << std::endl;
    outputStream << player.name << std::endl;

    //Output numCoins
    outputStream << "--Coins" << std::endl;
    outputStream << player.numCoins << std::endl;

    //Output Max Chains:
    outputStream << "--Maxchains:" << std::endl;
    outputStream << player.maxNumChains << std::endl;

    //Output NumChains
    outputStream <<"--NumChains:" << std::endl;
    outputStream << player.numChains << std::endl;

    //Output Chains
    for (int i = 0; i < player.numChains; ++i)
        outputStream << *player.chains[i] << std::endl;

    return outputStream;
}
