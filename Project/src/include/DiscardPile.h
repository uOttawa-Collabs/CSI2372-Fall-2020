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

#ifndef PROJECT_DISCARDPILE_H
#define PROJECT_DISCARDPILE_H

#include <iostream>
#include <vector>

class Card;

class CardFactory;

class DiscardPile
{
public:
    explicit DiscardPile(const CardFactory *cardFactory) : cardFactory(cardFactory) {}

    DiscardPile(std::istream &inputStream, const CardFactory *cardFactory);

    DiscardPile &operator+=(const Card *card) noexcept(false);

    const Card *pickUp() noexcept(false);

    [[nodiscard]] const Card *top() const noexcept;

    void print(std::ostream &outputStream) const noexcept;

    void printTop(std::ostream &outputStream) const noexcept(false);

    friend std::ostream &operator<<(std::ostream &outputStream, const DiscardPile &discardPile) noexcept;

private:
    const CardFactory         *cardFactory;
    std::vector<const Card *> discardPile;
};


#endif //PROJECT_DISCARDPILE_H
