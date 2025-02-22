//
// Created by Enzo Renard on 19/11/2024.
//
/**
 * @file Character.hpp
 * @brief Defines the Character class, representing a game character with health, capabilities, and items.
 *
 * The Character class encapsulates attributes and functionalities for managing a character's health,
 * attacks, movements, items, and other abilities like JetPack usage. It also includes methods for
 * handling damage, animation states, and interactions with buffs.
 */
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Animation.hpp"

#include "Capabilities.hpp"
#include "Health.hpp"
#include "Item.hpp"
#include "Items.hpp"
#include <vector>
#include <memory>

/**
 * @class Character
 * @brief Represents a character in the game, with health, capabilities, and items.
 */
class Character {
protected:
    static int nextId; ///< Static counter to generate unique IDs for characters.
    std::string type; ///< The type or class of the character.
    int id; ///< Unique identifier for the character.
    std::map<std::string, int> items; ///< List of buffs or items the character possesses.
    Health health; ///< The health object representing the character's health.
    Capabilities capabilities; ///< The capabilities (attacks, movements, jetpack) of the character.
    bool onGround; ///< Indicates whether the character is on the ground.
    Animation hurtAnimation; ///< Animation triggered when the character is hurt.

    /**
     * @brief Virtual method to handle character death. Must be implemented by derived classes.
     * @see Player::die()
     */
    virtual void die() = 0;

    /**
 * @brief Increases the character's current health.
 * @param amount The amount to increase the health by.
 */
    void increaseHealth(int amount);

public:
    static constexpr double DEF_HURT_TIME = 0.5; ///< Default duration of the hurt animation.
    static constexpr double DEF_RUN_FORCE = 4.0; ///< Default force for running movements.
    static constexpr double DEF_JUMP_FORCE = 5.0; ///< Default force for jumping movements.

    /**
     * @brief Constructs a Character with specified attributes.
     * @param type The type or class of the character.
     * @param max_health The maximum health of the character.
     * @param hurtTime The duration of the hurt animation.
     * @param capabilities The capabilities assigned to the character.
     */
    Character(std::string type, int max_health, double hurtTime, Capabilities capabilities);

    /**
     * @brief Constructs a Character with default capabilities and hurt animation time.
     * @param type The type or class of the character.
     * @param max_health The maximum health of the character.
     */
    Character(const std::string&type, int max_health);

    virtual ~Character() = default;

    /**
     * @brief Retrieves the character's health.
     * @return The Health object.
     */
    [[nodiscard]] Health getHealth() const;

    /**
     * @brief Retrieves a specific attack by its name.
     * @param name The name of the attack.
     * @return The corresponding Attack object.
     */
    [[nodiscard]] Attack getAttack(std::string) const;

    /**
     * @brief Retrieves a specific attack by its index.
     * @param attackIndex The index of the attack.
     * @return The corresponding Attack object.
     */
    Attack getAttackAt(int attackIndex) const;

    /**
     * @brief Retrieves a specific movement by its name.
     * @param name The name of the movement.
     * @return The corresponding Movement object.
     */
    [[nodiscard]] std::shared_ptr<Movement> getMovement(const std::string&) const;

    /**
     * @brief Retrieves the JetPack assigned to the character.
     * @return The JetPack object.
     */

    [[nodiscard]] JetPack getJetPack() const;

    /**
     * @brief Retrieves the character's unique ID.
     * @return The ID of the character.
     */
    [[nodiscard]] int getId() const;

    /**
     * @brief Checks if the character has a JetPack.
     * @return True if the character has a JetPack, otherwise false.
     */
    [[nodiscard]] bool hasJetPack() const;

    /**
     * @brief Executes an attack by its name.
     * @param attackName The name of the attack.
     * @return The damage dealt by the attack.
     * @throws std::invalid_argument If the attack cannot be used.
     */
    int attack(const std::string& attackName);

    /**
     * @brief Executes a movement by its name.
     * @param movementName The name of the movement.
     * @throws std::invalid_argument If the movement cannot be used.
     */
    void move(const std::string& movementName);

    /**
     * @brief Checks if the JetPack can be used.
     * @return True if the JetPack can be activated, otherwise false.
     */
    [[nodiscard]] bool canUseJetpack() const;

    /**
     * @brief Activates the JetPack.
     * @throws std::invalid_argument If the JetPack cannot be used.
     */
    void useJetpack() const; // TODO why never used?

    /**
     * @brief Checks if an attack can be used by its name.
     * @param attackName The name of the attack.
     * @return True if the attack can be used, otherwise false.
     */
    [[nodiscard]] bool canUse(const std::string&attackName) const;

    /**
     * @brief Checks if a movement can be used by its name.
     * @param movementName The name of the movement.
     * @return True if the movement can be used, otherwise false.
     */
    [[nodiscard]] bool canMove(const std::string& movementName) const;

    /**
     * @brief Marks the character as landed.
     */
    void land();

    /**
     * @brief Checks if the character is on the ground.
     * @return True if the character is landed, otherwise false.
     */
    [[nodiscard]] bool isLanded() const;

    /**
     * @brief Checks if an item is in the character's inventory.
     * if it is, we increment the number of this item in the inventory.
     * if it is not, we add the item to the inventory.
     * @param buff The item to add.
     */
    virtual void addItem(const Item&item);



    /**
     * @brief Checks if the character is currently using a blocking movement,
     * making him busy
     * @return True if the character is busy, otherwise false.
     */
    [[nodiscard]] bool isBusy() const; // TODO The attacks are not involved in this method ?

    /**
     * @brief Applies damage to the character.
     * @param damage The amount of damage to apply.
     * @throws std::invalid_argument If the damage is negative.
     */
    void hurt(int damage);

    /**
     * @brief Retrieves the type of the character.
     * @return The type as a string.
     */
    [[nodiscard]] std::string getType() const;

    /**
     * @brief Retrieves the hurt animation object.
     * @return The Animation object representing the hurt animation.
     */
    [[nodiscard]] Animation getHurtAnimation() const;

    /**
     * @brief Changes the onGround status of the character.
     */
    void takeOff();

    /**
     * @brief Checks if the character is doing a movement.
     * @return The movement index
     */
    int isMoving() const;

    /**
     * @brief Manually stops a movement. Designed for the JetPack.
     * @param movementName The name of the movement to stop.
     */
    void stopMoving(const std::string& movementName);

    /**
     * @brief Increases the character's Maximum health
     * by a specified amount and sets the current health to the new maximum.
     * @param amount The amount to increase the health by.
     * @throws std::invalid_argument If the amount is negative.
     */
    void increaseMaxHealth(int amount);

    /**
     * @brief Increases a character's movement force by a specified amount.
     * @param movementName The movement to increase the force of.
     * @param amount The amount to increase the force by.
     */
    void increaseMovementForce(const std::string&movementName, double amount);

    /**
     * @brief Increases the damage of a character's attacks by a specified amount.
     * @param amount The amount to increase the damage by.
     * @param attackName The list of the character's attacks to increase the damage of.
     */
    void increaseAttackDamage(double amount, const std::vector<std::string>& attackName);

    /**
     * @brief Retrieves the names of all character attacks.
     * @return A vector of attack names.
     */
    std::vector<std::string> getAllAttackName() const;

    /**
     * @brief Retrieves the amount of a specific item in the character's inventory.
     * @param item_id The ID of the item to check.
     * @return The amount of the item in the inventory.
     */
    int getNumberOfItem(int item_id) const;
};
#endif //CHARACTER_HPP
