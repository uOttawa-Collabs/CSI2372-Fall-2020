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

#include <random>
#include <chrono>

#include "include/CardFactory.h"
#include "include/Card.h"
#include "include/Deck.h"

CardFactory *CardFactory::cardFactory = nullptr;

CardFactory *CardFactory::getFactory() noexcept
{
    if (cardFactory == nullptr)
        cardFactory = new CardFactory();

    return cardFactory;
}

Deck CardFactory::getDeck()
{
    Deck deck(this);

    for (int i = 0; i < Blue::CARD_NUMBER; i++)
        deck.cards.push_back(new Blue());

    for (int i = 0; i < Chili::CARD_NUMBER; i++)
        deck.cards.push_back(new Chili());

    for (int i = 0; i < Stink::CARD_NUMBER; i++)
        deck.cards.push_back(new Stink());

    for (int i = 0; i < Green::CARD_NUMBER; i++)
        deck.cards.push_back(new Green());

    for (int i = 0; i < Soy::CARD_NUMBER; i++)
        deck.cards.push_back(new Soy());

    for (int i = 0; i < Black::CARD_NUMBER; i++)
        deck.cards.push_back(new Black());

    for (int i = 0; i < Red::CARD_NUMBER; i++)
        deck.cards.push_back(new Red());

    for (int i = 0; i < Garden::CARD_NUMBER; i++)
        deck.cards.push_back(new Garden());

    deck.top = deck.cards.size();

    std::shuffle(deck.cards.begin(),
                 deck.cards.end(),
                 std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));

    return deck;
}
