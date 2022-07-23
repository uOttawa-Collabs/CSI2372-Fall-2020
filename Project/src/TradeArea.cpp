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

#include <stdexcept>
#include <iterator>
#include <ranges>
#include <algorithm>

#include "include/TradeArea.h"
#include "exceptions/include/NullPointerException.h"

TradeArea::TradeArea(std::istream &inputStream, const CardFactory *cardFactory) : cardFactory(cardFactory)
{
    char c[256];

    //Skipping line to filter out "----Trading Area----"
    inputStream.getline(c, 256);
    inputStream.getline(c, 256);


    int i = 0;
    bool empty = false;
    while (c[i] != NULL && !empty) {

        switch (c[i]) {
        case'E':
            empty = true;
            break;
        case 'B':
            cardList.push_back(new Blue());
            break;
        case 'C':
            cardList.push_back(new Chili());
            break;
        case 'S':
            cardList.push_back(new Stink());
            break;
        case 'G':
            cardList.push_back(new Green());
            break;
        case 's':
            cardList.push_back(new Soy());
            break;
        case 'b':
            cardList.push_back(new Black());
            break;
        case 'R':
            cardList.push_back(new Red());
            break;
        case 'g':
            cardList.push_back(new Garden());
            break;
        }
        i++;
    } 
}

bool TradeArea::legal(const Card *card) const noexcept(false)
{
    if (card != nullptr)
    {
        return std::ranges::all_of(
            cardList,
            [card](const Card *cardInList) { return cardInList->getName() == card->getName(); });
    }
    else
        throw NullPointerException("card cannot be nullptr",
                                   __FILE__,
                                   __LINE__,
                                   __FUNCTION__);
}

const Card *TradeArea::trade(const std::string &beanName) noexcept
{
    for (auto iterator = cardList.begin(); iterator != cardList.end(); ++iterator)
    {
        if ((*iterator)->getName() == beanName)
        {
            const Card *tradeCard = *iterator;
            cardList.erase(iterator);
            return tradeCard;
        }
    }

    return nullptr;
}

void TradeArea::erase(std::list<const Card *>::const_iterator &position) noexcept
{
    cardList.erase(position);
}

int TradeArea::numCards() const noexcept
{
    return cardList.size();
}

int TradeArea::discard(DiscardPile &discardPile)
{
    int i = 0;

    for (const Card *card : cardList)
    {
        discardPile += card;
        ++i;
    }

    cardList.clear();

    return i;
}

bool TradeArea::match(const Card *card) const noexcept
{
    if (card != nullptr)
    {
        return std::ranges::any_of(
            cardList.cbegin(),
            cardList.cend(),
            [card](const Card *tradeAreaCard) -> bool
            {
                return tradeAreaCard->getName() == card->getName();
            });
    }
    else
        return false;
}

std::list<const Card *>::const_iterator TradeArea::begin() const noexcept
{
    return cardList.cbegin();
}

std::list<const Card *>::const_iterator TradeArea::end() const noexcept
{
    return cardList.cend();
}

TradeArea &TradeArea::operator+=(const Card *card) noexcept(false)
{
    if (card != nullptr)
        cardList.push_back(card);
    else
        throw NullPointerException("card cannot be nullptr",
                                   __FILE__,
                                   __LINE__,
                                   __FUNCTION__);
    return *this;
}

std::ostream &operator<<(std::ostream &outputStream, const TradeArea &tradeArea) noexcept
{
    if (tradeArea.cardList.empty())
        outputStream << "Empty";
    else
        for (const Card *card : tradeArea.cardList)
            outputStream << *card;

    return outputStream;
}


