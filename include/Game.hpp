//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef GAME_HPP
#define GAME_HPP
#include <unordered_set>

#include "Player.hpp"

#include "Level.hpp"

#include <vector>

class Game {
    int activeLevel;
    std::vector<Level> levels;
    Player player;

    void add_level(const Level&level);

    void next_level();

public:
    Game();

    Level getActiveLevel();

    int get_area_guid_current_level(int x, int y) const;

    int getPlayerMaxHealth() const;

    int getPlayerCurrentHealth() const;

    void takePlayerDamage(int damage);

    int if_can_spawn_current_level_spawn_at(int areaX, int areaY, int spawdId);

    std::string getType(int id) const;

    int getCharacterSpeed(int id) const;

    double getCharacterJumpForce(int id) const;

    double getEnemyFollowRange(int id) const;

    double getEnemyAttackRange(int id) const;

    bool canCharacterAttack(int id, std::string attackName) const;

    double getDamage(int id, std::string attackName) const;

    double getChargeTime(int id, std::string attackName) const;

    double getCharacterHurtTime(int id) const;

    bool isCharacterBusy(int id);

    int getCharacterHealth(int id) const;

    int getCharacterMaxHealth(int id) const;

    double getPlayerDashForce() const;

    double getJetPackForce() const;

    double getJetPackMaxTime() const;

    double getPlayerLandingTime() const;

    double getPlayerDashTime() const;

    double getCharacterAttackTime(int id, std::string attackName) const;

    bool isPlayerDashing() const;

    bool isPlayerUsingJetpack() const;

    bool canCaracterMove(int id, std::string movementName) const;

    double getCharacterCoolDownAttack(int id, std::string attackName) const;
};
#endif //GAME_HPP
