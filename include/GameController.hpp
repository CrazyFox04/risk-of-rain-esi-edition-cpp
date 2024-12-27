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

    void takePlayerDamage(int damage);

    int getAreaGuidCurrentLevel(int, int) const;

    int ifCanSpawnCurrentLevelSpawnAt(int, int, int);

    std::string getType(int) const;

    int getCharacterSpeed(int) const;

    double getCharacterJumpForce(int) const;

    double getEnemyFollowRange(int) const;

    double getEnemyAttackRange(int) const;

    bool canCharacterAttack(int, std::string) const;

    double getDamage(int, std::string) const;

    double getChargeTime(int, std::string) const;

    double getCharacterHurtTime(int) const;

    int getCharacterHealth(int) const;

    int getCharacterMaxHealth(int) const;

    double getPlayerDashForce() const;

    double getJetPackForce() const;

    double getJetPackMaxTime() const;

    double getPlayerLandingTime() const;

    double getPlayerDashTime() const;

    double getCharacterAttackTime(int, std::string) const;

    bool isPlayerDashing() const;

    bool isPlayerUsingJetpack() const;

    bool canCharacterMove(int, std::string) const;

    double getCharacterCoolDownAttackTime(int, std::string) const;

    bool isAValidId(int) const;

    int getPlayerId() const;

    void attack(int, std::string, int);

    void move(int, std::string);
};

MY_API GameController* newGame();

MY_API void destroyGame(const GameController*);

MY_API int getPlayerMaxHealth(const GameController*);

MY_API int getPlayerCurrentHealth(GameController*);

MY_API void takePlayerDamage(GameController*, int);

MY_API int getAreaGuidCurrentLevel(const GameController*, int, int);

MY_API int ifCanSpawnCurrentLevelSpawnAt(GameController*, int, int, int);

MY_API const char* getType(const GameController*, int);

MY_API int getCharacterSpeed(const GameController*, int);

MY_API double getCharacterJumpForce(const GameController*, int);

MY_API double getEnemyFollowRange(const GameController*, int);

MY_API double getEnemyAttackRange(const GameController*, int);

MY_API bool canCharacterAttack(const GameController*, int, const char*);

MY_API double getDamage(const GameController*, int, const char*);

MY_API double getChargeTime(const GameController*, int, const char*);

MY_API double getCharacterHurtTime(const GameController*, int);

MY_API int getCharacterHealth(const GameController*, int);

MY_API int getCharacterMaxHealth(const GameController*, int);

MY_API double getPlayerDashForce(const GameController*);

MY_API double getJetPackForce(const GameController*);

MY_API double getJetPackMaxTime(const GameController*);

MY_API double getPlayerLandingTime(const GameController*);

MY_API double getPlayerDashTime(const GameController*);

MY_API double getCharacterAttackTime(const GameController*, int, const char*);

MY_API bool isPlayerDashing(const GameController*);

MY_API bool isPlayerUsingJetpack(const GameController*);

MY_API bool canCharatcerMove(const GameController*, int, const char*);

MY_API double getCharacterCoolDownAttackTime(const GameController*, int, const char*);

MY_API bool isAValidId(const GameController*, int);

MY_API int getPlayerId(const GameController*);

MY_API void attack(GameController*, int, const char*, int);

MY_API void move(GameController*, int, const char*);

#endif
