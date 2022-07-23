cmake_minimum_required(VERSION 3.17)
project(Project)

set(CMAKE_CXX_STANDARD 20)
add_executable(
    Project src/main.cpp
    src/TradeArea.cpp src/include/TradeArea.h
    src/Hand.cpp src/include/Hand.h
    src/Player.cpp src/include/Player.h
    src/Table.cpp src/include/Table.h
    src/CardFactory.cpp src/include/CardFactory.h
    src/include/Chain.h src/Chain.cpp
    src/include/Deck.h src/Deck.cpp
    src/include/Card.h src/Card.cpp
    src/DiscardPile.cpp src/include/DiscardPile.h
    src/exceptions/Exception.cpp src/exceptions/include/Exception.h
    src/exceptions/GameException.cpp src/exceptions/include/GameException.h
    src/exceptions/NotEnoughCoinsException.cpp src/exceptions/include/NotEnoughCoinsException.h
    src/exceptions/MaxedChainsException.cpp src/exceptions/include/MaxedChainsException.h
    src/exceptions/MixedCardException.cpp src/exceptions/include/MixedCardException.h
    src/exceptions/NullPointerException.cpp src/exceptions/include/NullPointerException.h
    src/exceptions/ArrayIndexOutOfBoundsException.cpp src/exceptions/include/ArrayIndexOutOfBoundsException.h
    src/exceptions/EmptyContainerException.cpp src/exceptions/include/EmptyContainerException.h
    src/UIUtils.cpp src/include/UIUtils.h
    src/Utils.cpp src/include/Utils.h)
