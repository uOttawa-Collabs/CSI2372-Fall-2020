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

#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#include <iostream>
#include <string>
#include <utility>
#include <array>
#include <sstream>
#include "Hand.h"

class CardFactory;

class Chain;

class Player
{
public:
    const static int NUMBER_START_CHAINS = 2;
    const static int NUMBER_MAX_CHAINS   = 3;

    explicit Player(std::string name, const CardFactory *cardFactory);

    Player(std::istream &inputStream, const CardFactory *cardFactory);

    [[nodiscard]] const std::string &getName() const noexcept;

    [[nodiscard]] int getNumCoins() const noexcept;

    Player &operator+=(int coins) noexcept;

    Player &operator+=(const Card *card) noexcept(false);

    [[nodiscard]] int getMaxNumChains() const noexcept;

    [[nodiscard]] int getNumChains() const noexcept;

    [[nodiscard]] int getHandCardNumber() const noexcept;

    Chain &operator[](int index) const noexcept(false);

    void buyThirdChain() noexcept(false);

    void printHand(std::ostream &outputStream, bool printAll) const noexcept(false);

    const Card *play() noexcept(false);

    const Card *discard(int index) noexcept(false);

    friend std::ostream &operator<<(std::ostream &outputStream, const Player &player) noexcept;

private:
    const CardFactory                      *cardFactory;
    std::string                            name;
    int                                    numCoins;
    int                                    maxNumChains;
    int                                    numChains;
    std::array<Chain *, NUMBER_MAX_CHAINS> chains;
    Hand                                   hand;
};


#endif //PROJECT_PLAYER_H
