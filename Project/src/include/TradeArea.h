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


#ifndef PROJECT_TRADEAREA_H
#define PROJECT_TRADEAREA_H

#include <iostream>
#include <string>
#include <list>

#include "CardFactory.h"
#include "Card.h"
#include "DiscardPile.h"

class TradeArea
{
public:
    explicit TradeArea(const CardFactory *cardFactory) : cardFactory(cardFactory) {}

    TradeArea(std::istream &inputStream, const CardFactory *cardFactory);

    bool legal(const Card *) const noexcept(false);

    const Card *trade(const std::string &beanName) noexcept;

    void erase(std::list<const Card *>::const_iterator &position) noexcept;

    [[nodiscard]] int numCards() const noexcept;

    int discard(DiscardPile &discardPile);

    bool match(const Card *card) const noexcept;

    [[nodiscard]] std::list<const Card *>::const_iterator begin() const noexcept;

    [[nodiscard]] std::list<const Card *>::const_iterator end() const noexcept;

    TradeArea &operator+=(const Card *card) noexcept(false);

    friend std::ostream &operator<<(std::ostream &outputStream, const TradeArea &tradeArea) noexcept;

private:
    const CardFactory       *cardFactory;
    std::list<const Card *> cardList;
};


#endif //PROJECT_TRADEAREA_H
