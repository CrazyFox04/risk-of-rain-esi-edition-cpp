//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <chrono>
#include <string>
#include <array>
#include "Character.hpp"

class Player : public Character {
    std::array<float, 5> attackDamages;
    std::array<float, 5> attackCooldowns;
    std::array<float, 5> attackAnimTimes;
    std::vector<int> selectedAttacks;
    std::vector<std::shared_ptr<Buff>> items;

    // Movement properties
    float moveSpeed;
    float jumpForce;
    float dashForce;
    float jetPackSpeed;

    // Jetpack flight time and jump properties
    float jetpackFuel;
    float maxJetpackFuel;
    float jetpackCooldown;
    std::chrono::time_point<std::chrono::steady_clock> lastJetpackUse;
    std::chrono::time_point<std::chrono::steady_clock> jetpackRechargeStart;
    int maxJumps;

    // Animation times
    float hurtAnimTime;
    float landingAnimTime;
    float dashAnimTime;

    // Player states
    bool isDashing;
    bool isJetPacking;
    bool isBusy;
    bool isJetpackRecharging;

    // Health
    int maxHealth;
    int currentHealth;

    // Current state
    int remainingJumps;
    std::chrono::time_point<std::chrono::steady_clock> lastDashTime;
    std::chrono::time_point<std::chrono::steady_clock> lastAttackTime;

    std::string id;

public:
    static constexpr int DEF_HEALTH = 100;
    static constexpr int DEF_SPEED = 4;
    static constexpr float DEF_JUMP_FORCE = 5.0f;
    static constexpr float DEF_DASH_FORCE = 1000.0f;
    static constexpr float DEF_JETPACK_SPEED = 5.0f;
    static constexpr float DEF_JETPACK_TIME = 5.0f;
    static constexpr float DEF_JETPACK_COOLDOWN = 3.0f;

    Player(const std::string& playerId);
    ~Player() override = default;

    // Attack methods
    void selectAttacks(const std::vector<int> &attackIndices);
    bool canAttack(int attackIndex) const;
    void attack(int attackIndex);

    // Dash
    bool canDash() const;
    void dash();

    // Jetpack
    bool canUseJetpack() const;
    void useJetpack();
    void rechargeJetpack();

    // State setters and getters
    bool getIsDashing() const;
    bool getIsJetPacking() const;
    bool getIsBusy() const;
    bool getIsJetpackRecharging() const;
    void setIsBusy(bool state);
    void setIsDashing(bool state);

    // Movement and jetpack
    float getMoveSpeed() const;
    float getJumpForce() const;
    float getDashForce() const;
    float getJetPackSpeed() const;
    float getJetpackFuel() const;
    float getMaxJetpackFuel() const;
    float getJetpackCooldown() const;

    // Health
    int getMaxHealth() const;
    int getCurrentHealth() const;
    void increaseHealth(int amount);
    void increaseMaxHealth(int amount);


    std::shared_ptr<Buff> getItem(size_t index) const;

    const std::string& getId() const;

    // Cooldown-related methods
    float getDashCooldown() const;

    void reduceAttackCooldowns(const std::shared_ptr<Buff> &item);
    void reduceDashCooldown(const std::shared_ptr<Buff> &item);

    void increaseJetpackFuel(const std::shared_ptr<Buff> &item);
    void increaseMaxJumps(const std::shared_ptr<Buff> &item);
    void resetJumps();

    void useItem(const std::shared_ptr<Buff> &item);
    void addItem(const std::shared_ptr<Buff> &item);
};
#endif //PLAYER_HPP
