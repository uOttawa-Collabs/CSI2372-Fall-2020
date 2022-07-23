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


#ifndef PROJECT_HAND_H
#define PROJECT_HAND_H

#include <iostream>
#include <deque>

class CardFactory;

class Card;

class Hand
{
public:
    explicit Hand(const CardFactory *cardFactory) : cardFactory(cardFactory) {}

    Hand(std::istream &inputStream, const CardFactory *cardFactory);

    Hand &operator+=(const Card *card) noexcept(false);

    const Card *play() noexcept(false);

    [[nodiscard]] const Card *top() const noexcept;

    const Card *operator[](int index) noexcept(false);

    friend std::ostream &operator<<(std::ostream &outputStream, const Hand &hand) noexcept;

    friend class Player;

private:
    const CardFactory        *cardFactory;
    std::deque<const Card *> hand;
};


#endif //PROJECT_HAND_H
