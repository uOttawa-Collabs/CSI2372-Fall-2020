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

#ifndef PROJECT_CARD_H
#define PROJECT_CARD_H

#include <ostream>
#include <string>
#include <utility>
#include <array>

class Card
{
public:
    explicit Card(std::string name, const std::array<int, 4> &prices) :
        name(std::move(name)), prices(prices) {};

    [[nodiscard]] const std::string &getName() const noexcept;

    void print(std::ostream &outputStream) const;

    [[nodiscard]] virtual int getCardsPerCoin(int coins) const noexcept(false);

    friend std::ostream &operator<<(std::ostream &outputStream, const Card &card);

private:
    std::string        name;
    std::array<int, 4> prices;
};

class Blue : public Card
{
public:
    static const int CARD_NUMBER = 20;

    Blue() : Card("Blue", { 4, 6, 8, 10 }) {}
};

class Chili : public Card
{
public:
    static const int CARD_NUMBER = 18;

    Chili() : Card("Chili", { 3, 6, 8, 9 }) {}
};

class Stink : public Card
{
public:
    static const int CARD_NUMBER = 16;

    Stink() : Card("Stink", { 3, 5, 7, 8 }) {}
};

class Green : public Card
{
public:
    static const int CARD_NUMBER = 14;

    Green() : Card("Green", { 3, 5, 6, 7 }) {}
};

class Soy : public Card
{
public:
    static const int CARD_NUMBER = 12;

    Soy() : Card("soy", { 2, 4, 6, 7 }) {}
};

class Black : public Card
{
public:
    static const int CARD_NUMBER = 10;

    Black() : Card("black", { 2, 4, 5, 6 }) {}
};

class Red : public Card
{
public:
    static const int CARD_NUMBER = 8;

    Red() : Card("Red", { 2, 3, 4, 5 }) {}
};

class Garden : public Card
{
public:
    static const int CARD_NUMBER = 6;

    Garden() : Card("garden", { -1, 2, 3, -1 }) {}
};


#endif //PROJECT_CARD_H
