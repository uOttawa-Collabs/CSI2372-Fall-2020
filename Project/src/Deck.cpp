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

#include "include/Deck.h"
#include "include/Card.h"

#include <random>

Deck::Deck(const CardFactory *cardFactory) : cardFactory(cardFactory)
{
    top = cards.size();
}

Deck::Deck(std::istream &inputStream, const CardFactory *cardFactory) : Deck(cardFactory)
{   
    char c[512];

    //Skipping line to filter out "----Deck----"
    inputStream.getline(c, 512);
    inputStream.getline(c, 512);

    int i = 0;
    while (c[i] != NULL) {

        switch (c[i]) {
        case 'B':
            cards.push_back(new Blue());
            break;
        case 'C':
            cards.push_back(new Chili());
            break;
        case 'S':
            cards.push_back(new Stink());
            break;
        case 'G':
            cards.push_back(new Green());
            break;
        case 's':
            cards.push_back(new Soy());
            break;
        case 'b':
            cards.push_back(new Black());
            break;
        case 'R':
            cards.push_back(new Red());
            break;
        case 'g':
            cards.push_back(new Garden());
            break;
        default:
            top--;
        }
        i++;
        top++;
    }
}

Deck::Deck(Deck &&deck) noexcept : cardFactory(deck.cardFactory), cards(std::move(deck.cards)), top(deck.top)
{
    deck.cards.clear();
}

Deck::~Deck() noexcept
{
    for (const Card *card : cards)
        delete card;
}

const Card *Deck::draw()
{
    if (top > 0)
        return cards[--top];
    else
        return nullptr;
}

bool Deck::empty() const noexcept
{
    return cards.empty();
}

std::ostream &operator<<(std::ostream &outputStream, const Deck &deck)
{
    outputStream << "----Deck----" << std::endl;
    for (int i = 0; i < deck.top; ++i)
        outputStream << *deck.cards.at(i) << " ";
    return outputStream;
}
