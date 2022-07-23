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

#ifndef PROJECT_CARDFACTORY_H
#define PROJECT_CARDFACTORY_H

class Deck;

class CardFactory
{
public:
    
    static CardFactory *getFactory() noexcept;

    Deck getDeck();

private:
    static CardFactory *cardFactory;

    CardFactory() = default;
};

#endif //PROJECT_CARDFACTORY_H
