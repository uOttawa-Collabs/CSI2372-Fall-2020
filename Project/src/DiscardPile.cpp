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

#include "include/DiscardPile.h"
#include "include/Card.h"
#include "include/CardFactory.h"
#include "exceptions/include/NullPointerException.h"
#include "exceptions/include/EmptyContainerException.h"

DiscardPile::DiscardPile(std::istream &inputStream, const CardFactory *cardFactory) : DiscardPile(cardFactory)
{
    char c[256];

    //Skipping line to filter out "----Discard Pile----"
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
            discardPile.push_back(new Blue());
            break;
        case 'C':
            discardPile.push_back(new Chili());
            break;
        case 'S':
            discardPile.push_back(new Stink());
            break;
        case 'G':
            discardPile.push_back(new Green());
            break;
        case 's':
            discardPile.push_back(new Soy());
            break;
        case 'b':
            discardPile.push_back(new Black());
            break;
        case 'R':
            discardPile.push_back(new Red());
            break;
        case 'g':
            discardPile.push_back(new Garden());
            break;
        }
        i++;
    }


        
}

DiscardPile &DiscardPile::operator+=(const Card *card) noexcept(false)
{
    if (card != nullptr)
        discardPile.push_back(card);
    else
        throw NullPointerException("card cannot be nullptr",
                                   __FILE__,
                                   __LINE__,
                                   __FUNCTION__);
    return *this;
}

const Card *DiscardPile::pickUp() noexcept(false)
{
    const Card *topCard = top();
    if (topCard == nullptr)
    {
        throw EmptyContainerException("Discard pile is empty",
                                      __FILE__,
                                      __LINE__,
                                      __FUNCTION__);
    }
    else
    {
        discardPile.pop_back();
        return topCard;
    }
}

const Card *DiscardPile::top() const noexcept
{
    if (discardPile.empty())
        return nullptr;
    else
        return discardPile.back();
}

void DiscardPile::print(std::ostream &outputStream) const noexcept
{
    if (discardPile.empty())
        outputStream << "Empty";
    else
        for (const Card *card : discardPile)
            outputStream << *card;
}

void DiscardPile::printTop(std::ostream &outputStream) const noexcept(false)
{
    const Card *topCard = top();
    if (topCard == nullptr)
    {
        throw EmptyContainerException("Discard pile is empty",
                                      __FILE__,
                                      __LINE__,
                                      __FUNCTION__);
    }
    else
        outputStream << *top();
}

std::ostream &operator<<(std::ostream &outputStream, const DiscardPile &discardPile) noexcept
{
    if (discardPile.top() == nullptr)
        outputStream << "Empty";
    else
        discardPile.print(outputStream);
    return outputStream;
}
