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

#include <algorithm>
#include <string>
#include <sstream>
#include "include/Table.h"
#include "include/Chain.h"
#include "include/UIUtils.h"
#include "exceptions/include/GameException.h"
#include "exceptions/include/ArrayIndexOutOfBoundsException.h"
#include "exceptions/include/NullPointerException.h"

Table::Table(const CardFactory *cardFactory, const std::array<std::string, PLAYER_NUMBER> &playerNames) :
    cardFactory(cardFactory),
    deck(std::move(CardFactory::getFactory()->getDeck())),
    discardPile(cardFactory),
    tradeArea(cardFactory),
    currentPlayer(0)
{
    for (int i = 0; i < PLAYER_NUMBER; ++i)
    {
        players[i] = new Player(playerNames[i], cardFactory);

        // Draw 5 cards for each player
        for (int j = 0; j < 5; ++j)
            *players[i] += deck.draw();
    }
}


Table::Table(std::istream &inputStream, const CardFactory *cardFactory) : 
        cardFactory(cardFactory),
        deck(inputStream, cardFactory),
        discardPile(inputStream, cardFactory),
        tradeArea(inputStream, cardFactory),
        currentPlayer(0)
{
    for (int i = 0; i < PLAYER_NUMBER; ++i)
        players[i] = new Player(inputStream, cardFactory);
}


Table::~Table()
{
    for (Player *&player : players)
        delete player;
}

void Table::play(std::istream &inputStream, std::ostream &outputStream) noexcept(false)
{
    const Card *card;

    outputStream << "Player " << currentPlayer << " (" << players[currentPlayer]->getName() << "): " << std::endl;

    // Player draws top card from deck
    *players[currentPlayer] += deck.draw();

    // Trade area is not empty
    procProcessTradeArea(inputStream, outputStream, card);

    // Play the topmost card
    procPlayTopmostCard(inputStream, outputStream, card);

    // Detect mature chains and probably sell them
    procSellChains(inputStream, outputStream);

    // Play the topmost card again
    if (toupper(UIUtils::getNonEmptyLine(inputStream,
                                         outputStream,
                                         "Would you like to play you topmost card? (y/N): ")[0]) == 'Y')
        procPlayTopmostCard(inputStream, outputStream, card);

    // Detect mature chains and probably sell them again
    procSellChains(inputStream, outputStream);

    // Discard cards
    if (toupper(UIUtils::getNonEmptyLine(inputStream,
                                         outputStream,
                                         "Would you like to discard a card? (y/N): ")[0]) == 'Y')
        procDiscardCards(inputStream, outputStream);

    // Draw 3 cards from deck and place cards in the trade area
    try
    {
        for (int i = 0; i < 3; ++i)
            tradeArea += deck.draw();
    }
    catch (const NullPointerException &e)
    {
        // Out of cards. Game over.
        return;
    }

    // Match the top card of discard pile with cards in the trade area
    if (tradeArea.numCards())
        while (tradeArea.match(discardPile.top()))
            tradeArea += discardPile.pickUp();

    // Ask if player wants to chain the card in the trade area
    procChainTradeAreaCards(inputStream, outputStream);

    // Draw 2 cards from deck and add the cards to the player's hand
    try
    {
        for (int i = 0; i < 2; ++i)
            *players[currentPlayer] += deck.draw();
    }
    catch (const NullPointerException &e)
    {
        // Out of cards. Game over.
        return;
    }

    currentPlayer = (currentPlayer + 1) % PLAYER_NUMBER;
}

bool Table::isGameOver() const noexcept
{
    return deck.empty();
}

bool Table::win(const std::string &playerName) noexcept
{
    if (isGameOver())
    {
        std::sort(
            players.begin(),
            players.end(),
            [](Player *&a, Player *&b) -> bool
            {
                return a->getNumCoins() > b->getNumCoins();
            });

        if (players[0]->getName() == playerName)
            return true;
        else
            return false;
    }
    else
        return false;
}

void Table::printHand(bool printAll) const noexcept(false)
{
    for (Player *const &player : players)
        player->printHand(std::cout, printAll);
}


std::ostream &operator<<(std::ostream &outputStream, Table &table) noexcept
{
    outputStream << "----Discard Pile----" << std::endl;
    outputStream << table.discardPile << std::endl;

    outputStream << "----Trading Area----" << std::endl;
    outputStream << table.tradeArea << std::endl;

    outputStream << "----Players----" << std::endl;
    for (Player *&player : table.players)
        outputStream << *player << std::endl;



    return outputStream;
}

// Private methods
bool Table::procAddToChain(std::istream &inputStream, std::ostream &outputStream, const Card *card)
{
    for (;;)
    {
        outputStream << "Please enter the target chain index." << std::endl;
        int chain = UIUtils::choice(inputStream, outputStream, players[currentPlayer]->getNumChains()) - 1;

        try
        {
            (*players[currentPlayer])[chain] += card;
            outputStream << "Card is added to the chain." << std::endl;
            return true;
        }
        catch (const GameException &e)
        {
            outputStream << e.getMessage() << std::endl;
            return false;
        }
    }
}

void Table::procProcessTradeArea(std::istream &inputStream, std::ostream &outputStream, const Card *&card)
{
    std::string input;

    while (tradeArea.numCards())
    {
        outputStream << "Trade area is not empty." << std::endl;
        input = std::move(UIUtils::getNonEmptyLine(inputStream,
                                                   outputStream,
                                                   "Please enter a bean name to add to a chain"
                                                   " or type \"discard\" to discard all of them: "));

        if (input == "discard")
        {
            tradeArea.discard(discardPile);
            break;
        }

        card = tradeArea.trade(input);
        if (card == nullptr)
        {
            input.clear();
            outputStream << "No specified bean name found in trade area, please try again." << std::endl;
            continue;
        }

        for (;;)
        {
            if (procAddToChain(inputStream, outputStream, card))
                break;
            else if (toupper(UIUtils::getNonEmptyLine(inputStream,
                                                      outputStream,
                                                      "Would you like to discard the card (y/N): ")[0]) == 'Y')
            {
                discardPile += card;
                break;
            }
        }
    }
}

void
Table::procPlayTopmostCard(std::istream &inputStream, std::ostream &outputStream, const Card *card)
{
    std::string input;

    outputStream << "The topmost card in your hand is: ";
    players[currentPlayer]->printHand(outputStream, false);
    outputStream << std::endl << "Please select where you want to place the top most card in your hand." << std::endl;
    outputStream << "Available choices: Chain, TradeArea, DiscardPile" << std::endl;

    card = players[currentPlayer]->play();

    for (;;)
    {
        input = std::move(UIUtils::getNonEmptyLine(inputStream,
                                                   outputStream,
                                                   "Your choice: "));

        if (input == "Chain")
        {
            if (procAddToChain(inputStream, outputStream, card))
                break;
        }
        else if (input == "TradeArea")
        {
            if (tradeArea.legal(card))
            {
                tradeArea += card;
                outputStream << "Your card has been placed in the trade area" << std::endl;
                break;
            }
            else
                outputStream << "This card is not legal to place into the trade area" << std::endl;
        }
        else if (input == "DiscardPile")
        {
            discardPile += card;
            outputStream << "Your card has been placed in the discard pile" << std::endl;
            break;
        }
        else
            outputStream << "Invalid choice, please try again." << std::endl;
    }
}

void Table::procSellChains(std::istream &inputStream, std::ostream &outputStream)
{
    std::vector<int> matureChainIndex;
    for (int         i = 0; i < players[currentPlayer]->getNumChains(); ++i)
    {
        if ((*players[currentPlayer])[i].isReadyToSell())
            matureChainIndex.push_back(i + 1);
    }

    if (!matureChainIndex.empty())
    {
        outputStream << "You have chains that are ready to sell." << std::endl;
        outputStream << "Available index: ";

        for (const int &i : matureChainIndex)
            outputStream << i << ' ';

        outputStream << std::endl;

        if (toupper(UIUtils::getNonEmptyLine(inputStream,
                                             outputStream,
                                             "Would you like to sell any? (y/N): ")[0]) == 'Y')
        {
            while (!matureChainIndex.empty())
            {
                int i     = UIUtils::choice(inputStream, outputStream, matureChainIndex) - 1;
                int coins = (*players[currentPlayer])[i].sell();
                *players[currentPlayer] += coins;
                matureChainIndex.erase(std::find(matureChainIndex.begin(), matureChainIndex.end(), i));
                outputStream << "You have sold chain " << i + 1 << " and got " << coins << " coin(s)." << std::endl;

                if (matureChainIndex.empty()
                    || toupper(UIUtils::getNonEmptyLine(inputStream,
                                                        outputStream,
                                                        "Would you like to sell more? (y/N): ")[0]) != 'Y')
                    break;
            }
        }
    }
    else
        outputStream << "All chains are not mature yet." << std::endl;
}

void Table::procDiscardCards(std::istream &inputStream, std::ostream &outputStream)
{
    outputStream << "You have these cards in your hand: " << std::endl;
    players[currentPlayer]->printHand(outputStream, true);
    outputStream << std::endl;

    for (;;)
    {
        outputStream << "Please enter the card index, starting with 1: " << std::endl;
        int cardIndex = UIUtils::choice(inputStream, outputStream, players[currentPlayer]->getHandCardNumber()) - 1;

        try
        {
            discardPile += players[currentPlayer]->discard(cardIndex);
            break;
        }
        catch (const ArrayIndexOutOfBoundsException &e)
        {
            outputStream << e.getMessage() << std::endl;
        }
    }
}

void Table::procChainTradeAreaCards(std::istream &inputStream, std::ostream &outputStream)
{
    if (tradeArea.numCards())
    {
        outputStream << "The trade area has the following cards: " << std::endl;
        outputStream << tradeArea << std::endl;
        if (toupper(UIUtils::getNonEmptyLine(inputStream,
                                             outputStream,
                                             "Would you like to chain any card? (y/N): ")[0]) == 'Y')
        {
            for (auto tradeCard : tradeArea)
            {
                if (toupper(UIUtils::getNonEmptyLine(inputStream,
                                                     outputStream,
                                                     tradeCard->getName() + " (y/N): ")[0]) == 'Y')
                {
                    while (!procAddToChain(inputStream, outputStream, tradeCard))
                    {
                        if (toupper(UIUtils::getNonEmptyLine(inputStream,
                                                             outputStream,
                                                             "Would you like to try again? (Y/n): ")[0]) == 'N')
                            break;
                    }
                }
            }
        }
    }
}
