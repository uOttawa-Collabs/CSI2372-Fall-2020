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


#include "include/Hand.h"
#include "include/Card.h"
#include "include/CardFactory.h"
#include "exceptions/include/NullPointerException.h"
#include "exceptions/include/EmptyContainerException.h"
#include "exceptions/include/ArrayIndexOutOfBoundsException.h"

Hand::Hand(std::istream &inputStream, const CardFactory *cardFactory)
{
    char c[256];
    std::cout << "Hand:" << std::endl;

    inputStream.getline(c, 256);
    std::cout << c << std::endl;

    if (c[0] == '4') {
        std::cout << "Starting String(Hand):" << c << std::endl;
        int i = 1;
        while (c[i] != NULL) {
            switch (c[i]) {
            case 'B':
                hand.push_back(new Blue());
                break;
            case 'C':
                hand.push_back(new Chili());
                break;
            case 'S':
                hand.push_back(new Stink());
                break;
            case 'G':
                hand.push_back(new Green());
                break;
            case 's':
                hand.push_back(new Soy());
                break;
            case 'b':
                hand.push_back(new Black());
                break;
            case 'R':
                hand.push_back(new Red());
                break;
            case 'g':
                hand.push_back(new Garden());
                break;
            }
            i++;
            std::cout << "han" << std::endl;
        }
    }
}

Hand &Hand::operator+=(const Card *card) noexcept(false)
{
    if (card != nullptr)
        hand.push_back(card);
    else
    {
        throw NullPointerException("card cannot be nullptr",
                                   __FILE__,
                                   __LINE__,
                                   __FUNCTION__);
    }
    return *this;
}

const Card *Hand::play() noexcept(false)
{
    const Card *topCard = top();
    if (topCard == nullptr)
    {
        throw EmptyContainerException("Hand is empty",
                                      __FILE__,
                                      __LINE__,
                                      __FUNCTION__);
    }
    else
    {
        hand.pop_front();
        return topCard;
    }
}

const Card *Hand::top() const noexcept
{
    if (hand.empty())
        return nullptr;
    else
        return hand.front();
}

const Card *Hand::operator[](int index) noexcept(false)
{
    try
    {
        const Card *card = hand.at(index);
        hand.erase(hand.begin() + index);
        return card;
    }
    catch (std::out_of_range &e)
    {
        throw ArrayIndexOutOfBoundsException("Invalid card index",
                                             __FILE__,
                                             __LINE__,
                                             __FUNCTION__,
                                             new std::out_of_range(std::move(e)));
    }
}

std::ostream &operator<<(std::ostream &outputStream, const Hand &hand) noexcept
{
    if (hand.top() == nullptr)
        outputStream << "Empty";
    else
        for (const Card *card : hand.hand)
            outputStream << *card;

    return outputStream;
}
