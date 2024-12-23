//
// Created by Enzo Renard on 05/12/2024.
//
#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#ifdef _WIN64
#define MY_API extern "C" __declspec(dllexport)
#else
#define MY_API extern "C"
#endif

#include "Game.hpp"


class GameController {
    Game game_;

public:
    int getPlayerMaxHealth() const;

    int getPlayerCurrentHealth() const;

    void addPlayerMaxHealth(int health);

    void addPlayerHealth(int health);

    void takePlayerDamage(int damage);
};

MY_API GameController* newGame();

MY_API void destroyGame(const GameController*);

MY_API int getPlayerMaxHealth(const GameController*);

MY_API int getPlayerCurrentHealth(GameController*);

MY_API void addPlayerMaxHealth(GameController*, int);

MY_API void addPlayerHealth(GameController*, int);

MY_API void takePlayerDamage(GameController*, int);

#endif
