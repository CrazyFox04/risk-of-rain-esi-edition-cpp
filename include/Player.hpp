//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>
#include "Character.hpp"

class Player : public Character {
    std::shared_ptr<Weapon> activeWeapon;
    std::vector<std::shared_ptr<Weapon>> weapons;

    float attack1Cooldown;
    float attack2Cooldown;
    float attack3Cooldown;
    float dashCooldown;

    float jetpackFuel;
    int maxJumps;

    int remainingJumps;
    std::chrono::time_point<std::chrono::system_clock> lastAttackTime;
    std::chrono::time_point<std::chrono::system_clock> lastShootTime;

public:
    static constexpr int DEF_HEALTH = 100;
    static constexpr int DEF_SPEED = 1;
    static constexpr int DEF_DAMAGE = 10;
    static constexpr float DEF_ATTACK_COOLDOWN = 1.0f;
    static constexpr float DEF_DASH_COOLDOWN = 3.0f;
    static constexpr float DEF_JETPACK_FUEL = 5.0f;
    static constexpr int DEF_MAX_JUMPS = 1;

    Player();
    Player(int health, int speed, int damage);
    ~Player() override = default;

    // Cooldown-related methods
    float getAttack1Cooldown() const;
    float getAttack2Cooldown() const;
    float getAttack3Cooldown() const;
    float getDashCooldown() const;

    void reduceAttackCooldowns(const std::shared_ptr<Buff> &item);
    void reduceDashCooldown(const std::shared_ptr<Buff> &item);

    // Jetpack and jump methods
    float getJetpackFuel() const;
    int getMaxJumps() const;
    int getRemainingJumps() const;

    void increaseJetpackFuel(const std::shared_ptr<Buff> &item);
    void increaseMaxJumps(const std::shared_ptr<Buff> &item);
    void resetJumps();

    // Combat methods
    bool canShoot() const;
    void useItem(const std::shared_ptr<Buff> &item);
    void switchWeapons();
    void addItem(const std::shared_ptr<Buff> &item);

    std::shared_ptr<Weapon> getActiveWeapon() const;
    std::shared_ptr<Buff> getItem(size_t index) const;

    void attack() override;
    void shoot() override;

    void increaseHealth(int amount);
    void increaseMaxHealth(int amount);
    void increaseSpeed(int amount);
    void increaseDamage(int amount);
};
#endif //PLAYER_HPP
