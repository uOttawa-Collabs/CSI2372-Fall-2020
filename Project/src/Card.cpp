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

#include "include/Card.h"

#include "exceptions/include/ArrayIndexOutOfBoundsException.h"

const std::string &Card::getName() const noexcept
{
    return name;
}

void Card::print(std::ostream &outputStream) const
{
    if (!name.empty())
        outputStream << name[0];
}

int Card::getCardsPerCoin(int coins) const noexcept(false)
{
    try
    {
        return prices.at(coins - 1);
    }
    catch (std::out_of_range &e)
    {
        throw ArrayIndexOutOfBoundsException("Unexpected query of coin number",
                                             __FILE__,
                                             __LINE__,
                                             __FUNCTION__,
                                             new std::out_of_range(move(e)));
    }
}

std::ostream &operator<<(std::ostream &outputStream, const Card &card)
{
    card.print(outputStream);
    return outputStream;
}
