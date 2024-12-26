//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Animation.hpp"

#include "Capabilities.hpp"
#include "Health.hpp"
#include "Buff.h"
#include <vector>
#include <memory>

class Character {
    bool canUse(Attack attack) const;

    void increaseHealth(int amount);

    void increaseMaxHealth(int amount);

protected:
    static int nextId;
    std::string type;
    int id;
    std::vector<std::shared_ptr<Buff>> items;
    Health health;
    Capabilities capabilities;
    bool onGround;
    Animation hurtAnimation;

public:
    static constexpr double DEF_HURT_TIME = 0.5;
    static constexpr double DEF_RUN_FORCE = 4.0;
    static constexpr double DEF_JUMP_FORCE = 5.0;

    Character(const std::string& type, int max_health, double hurtTime, Capabilities capabilities);

    Character(const std::string& type, int max_health);

    virtual ~Character() = default;

    Health getHealth() const;

    Attack getAttack(std::string) const;

    Movement getMovement(std::string) const;

    JetPack getJetPack() const;

    int getId() const;

    bool hasJetPack() const;

    const std::vector<std::shared_ptr<Buff>>& getItems() const;

    int attack(std::string attackName);

    void move(std::string movementName);

    bool canUseJetpack() const;

    void useJetpack();

    bool canUse(std::string attackName) const;

    bool canMove(std::string movementName) const;

    void land();

    bool isLanded() const;

    virtual void addItem(std::shared_ptr<Buff> buff) = 0;

    void useItem(const std::shared_ptr<Buff>&item);

    bool isBusy() const;

    void hurt(int damage);

    std::string getType() const;

    Animation getHurtAnimation() const;
};
#endif //CHARACTER_HPP
