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
    /**
     * @brief Increases the character's current health.
     * @param amount The amount to increase the health by.
     */
    void increaseHealth(int amount);

protected:
    static int nextId; ///< Static counter to generate unique IDs for characters.
    std::string type; ///< The type or class of the character.
    int id; ///< Unique identifier for the character.
    std::map<std::string, int> items; ///< List of buffs or items the character possesses.
    Health health; ///< The health object representing the character's health.
    Capabilities capabilities; ///< The capabilities (attacks, movements, jetpack) of the character.
    bool onGround; ///< Indicates whether the character is on the ground.
    Animation hurtAnimation; ///< Animation triggered when the character is hurt.

    virtual void die() = 0;
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
    Character(const std::string&type, int max_health, double hurtTime, Capabilities capabilities);

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
     * @brief Retrieves a specific movement by its name.
     * @param name The name of the movement.
     * @return The corresponding Movement object.
     */
    [[nodiscard]] std::shared_ptr<Movement> getMovement(std::string) const;

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
     * @brief Retrieves the items (buffs) assigned to the character.
     * @return A vector of shared pointers to Buff objects.
     */
    [[nodiscard]] const std::vector<std::shared_ptr<Items>>& getItems() const;

    /**
     * @brief Executes an attack by its name.
     * @param attackName The name of the attack.
     * @return The damage dealt by the attack.
     * @throws std::invalid_argument If the attack cannot be used.
     */
    int attack(std::string attackName);

    /**
     * @brief Executes a movement by its name.
     * @param movementName The name of the movement.
     * @throws std::invalid_argument If the movement cannot be used.
     */
    void move(std::string movementName);

    /**
     * @brief Checks if the JetPack can be used.
     * @return True if the JetPack can be activated, otherwise false.
     */
    [[nodiscard]] bool canUseJetpack() const;

    /**
     * @brief Activates the JetPack.
     * @throws std::invalid_argument If the JetPack cannot be used.
     */
    void useJetpack();

    /**
     * @brief Checks if an attack can be used by its name.
     * @param attackName The name of the attack.
     * @return True if the attack can be used, otherwise false.
     */
    [[nodiscard]] bool canUse(std::string attackName) const;

    /**
     * @brief Checks if a movement can be used by its name.
     * @param movementName The name of the movement.
     * @return True if the movement can be used, otherwise false.
     */
    [[nodiscard]] bool canMove(std::string movementName) const;

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
     * @brief Adds a buff to the character's inventory.
     * @param buff The buff to add.
     */
    virtual void addItem(Item buff);

    /**
     * @brief Uses a specific item (buff).
     * @param item The buff to use.
     */
    void useItem(const std::shared_ptr<Items>&item);

    /**
     * @brief Checks if the character is currently busy.
     * @return True if the character is busy, otherwise false.
     */
    [[nodiscard]] bool isBusy() const;

    /**
     * @brief Applies damage to the character.
     * @param damage The amount of damage to apply.
     */
    void hurt(int damage);

    /**
     * @brief Retrieves the type or class of the character.
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

    int isMoving() const;

    void stopMoving(std::string movementName);

    void increaseMaxHealth(int amount);

    void increaseMovementForce(const std::string&movementName, double amount);

    void increaseAttackDamage(double amount, std::vector<std::string> attackName);

    std::vector<std::string> getAllAttackName();

    int getNumberOfItem(int item_id) const;
};
#endif //CHARACTER_HPP
