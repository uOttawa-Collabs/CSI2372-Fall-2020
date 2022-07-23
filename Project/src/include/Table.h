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

#ifndef PROJECT_TABLE_H
#define PROJECT_TABLE_H

#include <iostream>
#include <array>

#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"

class Table
{
public:
    //Deck made public in order to allow saveGame to access it
    Deck deck;
    const static int PLAYER_NUMBER = 2;

    explicit Table(const CardFactory *cardFactory, const std::array<std::string, PLAYER_NUMBER> &playerNames);

    Table(std::istream &inputStream, const CardFactory *cardFactory);

    virtual ~Table();

    void play(std::istream &inputStream, std::ostream &outputStream) noexcept(false);

    [[nodiscard]] bool isGameOver() const noexcept;

    bool win(const std::string &playerName) noexcept;

    void printHand(bool printAll) const noexcept(false);

    //Function needed to allow saves to see the deck
    Deck getTableDeck();

    friend std::ostream &operator<<(std::ostream &outputStream, Table &table) noexcept;

private:
    const CardFactory                   *cardFactory;
    std::array<Player *, PLAYER_NUMBER> players;

    DiscardPile                         discardPile;
    TradeArea                           tradeArea;
    int                                 currentPlayer;

    bool procAddToChain(std::istream &inputStream, std::ostream &outputStream, const Card *card);

    void
    procPlayTopmostCard(std::istream &inputStream, std::ostream &outputStream, const Card *card);

    void
    procProcessTradeArea(std::istream &inputStream, std::ostream &outputStream, const Card *&card);

    void procSellChains(std::istream &inputStream, std::ostream &outputStream);

    void procDiscardCards(std::istream &inputStream, std::ostream &outputStream);

    void procChainTradeAreaCards(std::istream &inputStream, std::ostream &outputStream);
};

#endif //PROJECT_TABLE_H
