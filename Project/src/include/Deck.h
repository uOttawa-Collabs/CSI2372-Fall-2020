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

#ifndef PROJECT_DECK_H
#define PROJECT_DECK_H

#include <iostream>
#include <vector>

#include "CardFactory.h"

class Card;

class Deck
{
public:
    explicit Deck(const CardFactory *cardFactory);

    Deck(std::istream &inputStream, const CardFactory *cardFactory);

    Deck(const Deck &deck) = delete;

    Deck(Deck &&deck) noexcept;

    virtual ~Deck() noexcept;

    const Card *draw();

    [[nodiscard]] bool empty() const noexcept;

    friend std::ostream &operator<<(std::ostream &outputStream, const Deck &deck);

    friend Deck CardFactory::getDeck();

private:
    std::vector<Card *> cards;
    size_t              top;
    const CardFactory   *cardFactory;
};


#endif //PROJECT_DECK_H
