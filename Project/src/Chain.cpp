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

#include "include/Chain.h"
#include "include/Card.h"
#include "include/CardFactory.h"

#include "exceptions/include/MixedCardException.h"
#include "exceptions/include/NullPointerException.h"

Chain::Chain(std::istream &inputStream, const CardFactory *cardFactory) : Chain(cardFactory)
{
    char c[256];

    //Getting the singular chain line from the save file
    inputStream.getline(c, 256);

    int i = 1;
    while (c[i] != NULL) {

        switch (c[i]) {
        case 'B':
            chain.push_back(new Blue());
            break;
        case 'C':
            chain.push_back(new Chili());
            break;
        case 'S':
            chain.push_back(new Stink());
            break;
        case 'G':
            chain.push_back(new Green());
            break;
        case 's':
            chain.push_back(new Soy());
            break;
        case 'b':
            chain.push_back(new Black());
            break;
        case 'R':
            chain.push_back(new Red());
            break;
        case 'g':
            chain.push_back(new Garden());
            break;
        }
        i++;

    }
    std::cout << "________________" << std::endl;
}


Chain &Chain::operator+=(const Card *card)
{
    if (card != nullptr)
    {
        // Perform RTTI check
        if (!chain.empty())
        {
            const Card        *firstCard = chain[0];
            const std::string typeName   = typeid(*firstCard).name();

            if (typeName != typeid(*card).name())
                throw MixedCardException("A chain can only store cards of the same type");
        }
        chain.push_back(card);
    }
    else
    {
        throw NullPointerException("card cannot be nullptr",
                                   __FILE__,
                                   __LINE__,
                                   __FUNCTION__);
    }
    return *this;
}


bool Chain::isReadyToSell() const noexcept
{
    if (chain.empty())
        return false;
    else
        return chain.size() >= chain[0]->getCardsPerCoin(1);
}

int Chain::sell()
{
    int remainder = static_cast<int>(chain.size());
    int    coin      = 0;

    for (const Card *card : chain)
    {
        // For each situation of coin combo
        for (int i = 4; i > 0; --i)
        {
            int requiredCardNumber = card->getCardsPerCoin(i);    // The required card number for the coin combo

            // Check if there is enough cards to sell in the chain, in the situation of getting i coins at one time
            if (requiredCardNumber != -1 && requiredCardNumber <= remainder)
            {
                int sold = remainder % requiredCardNumber;
                coin += sold * i;
                remainder -= sold * requiredCardNumber;
            }
        }
    }

    /*
     * The chain is cleared after selling
     *
     * This behavior may change by requirement.
     */
    if (coin != 0)
        chain.clear();

    return coin;
}


std::ostream &operator<<(std::ostream &outputStream, const Chain &chain)
{
    if (!chain.chain.empty())
    {
        //outputStream << chain.chain[0]->getName();
        for (const Card *card : chain.chain)
            outputStream << *card << ' ';
    }
    else
        outputStream << "Empty";

    return outputStream;
}
