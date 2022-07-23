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

#ifndef PROJECT_CHAIN_H
#define PROJECT_CHAIN_H

#include <iostream>
#include <type_traits>
#include <vector>

class Card;

class CardFactory;

class Chain
{
public:
    explicit Chain(const CardFactory *cardFactory) : cardFactory(cardFactory) {};

    Chain(std::istream &inputStream, const CardFactory *cardFactory);

    Chain &operator+=(const Card *card);

    [[nodiscard]] bool isReadyToSell() const noexcept;

    int sell();

    friend std::ostream &operator<<(std::ostream &outputStream, const Chain &chain);

private:
    const CardFactory         *cardFactory;
    std::vector<const Card *> chain;
};

#endif //PROJECT_CHAIN_H
