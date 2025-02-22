//
// Created by Enzo Renard on 26/12/2024.
//
/**
 * @file Capabilities.hpp
 * @brief Defines the Capabilities class for managing a character's attacks, movements, and abilities.
 *
 * The Capabilities class encapsulates the logic for handling attacks, movements,
 * and special tools like the JetPack. It provides methods to check, retrieve, and use these capabilities.
 */
#ifndef CAPABILITIES_HPP
#define CAPABILITIES_HPP
#include <set>
#include <memory>
#include <map>
#include <algorithm>
#include "Attacks.hpp"
#include "Attack.hpp"
#include "Movement.hpp"
#include "JetPack.hpp"

/**
 * @class Capabilities
 * @brief Represents a collection of abilities (attacks, movements, and tools) for a character.
 */
class Capabilities {
    std::vector<Attack> attacks; ///< Map of attacks identified by their names.
    std::map<std::string, std::shared_ptr<Movement>> movements; ///< Map of movements identified by their names.
    JetPack jetPack; ///< JetPack capability, if available.

    /**
     * @brief Retrieves an attack by its name.
     * @param name The name of the attack.
     * @return The corresponding Attack object reference.
     */
    Attack& getAttack(const std::string&name);
public:
    /**
     * @brief Constructs a Capabilities object with the specified attacks, movements, and JetPack.
     * @param attacks A set of available attacks.
     * @param movements A set of available movements.
     * @param hasJetPack Whether the JetPack capability is available.
     */
    Capabilities(std::vector<Attack> attacks, std::set<std::shared_ptr<Movement>> movements, bool hasJetPack);

    /**
     * @brief Checks if a capability (attack, movement, or JetPack) can be used.
     * @param name The name of the capability.
     * @return True if the capability can be used, otherwise false.
     * @throws std::invalid_argument If the capability does not exist.
     */
    [[nodiscard]] bool canUse(std::string) const;

    /**
     * @brief Retrieves an attack by its name.
     * @param name The name of the attack.
     * @return The corresponding Attack object copy.
     * @throws std::invalid_argument If the attack does not exist.
     */
    [[nodiscard]] Attack getCopyAttack(std::string&) const;

    /**
     * @brief Retrieves a movement by its name.
     * @param name The name of the movement.
     * @return The corresponding Movement object.
     * @throws std::invalid_argument If the movement does not exist.
     */
    [[nodiscard]] std::shared_ptr<Movement> getMovement(std::string) const;

    /**
     * @brief Retrieves the JetPack capability.
     * @return The JetPack object.
     */
    [[nodiscard]] JetPack getJetPack() const;

    /**
     * @brief Retrieves the last time any attack was used.
     * @return The time point of the most recent attack usage.
     */
    [[nodiscard]] std::chrono::time_point<std::chrono::steady_clock> getLastAttackTime() const;

    /**
     * @brief Uses a specific capability (attack, movement, or JetPack).
     * @param name The name of the capability to use.
     * @return The damage dealt if the capability is an attack, otherwise 0.
     * @throws std::invalid_argument If the capability cannot be used or does not exist.
     */
    int use(std::string);

    /**
     * @brief Checks if any capability is currently in use.
     * @return True if any attack, movement, or the JetPack is in use, otherwise false.
     */
    [[nodiscard]] bool isBusy() const;

    /**
     * @brief Checks if any movement is currently in use and gets it's index.
     * @return The index of the movement that is currently in use, -1 if no movement is in use.
     */
    int isMoving() const;

    /**
 * @brief Checks if a specific attack exists.
 * @param name The name of the attack.
 * @return True if the attack exists, otherwise false.
 */
    bool hasThisAttack(std::string name) const;

    /**
     * @brief Checks if a specific movement exists.
     * @param name The name of the movement.
     * @return True if the movement exists, otherwise false.
     */
    bool hasThisMovement(std::string name) const;

    /**
     * @brief Increases the force of a specific movement by a given amount.
     * @param string The movement to increase the force of.
     * @param amount The amount to increase the force by.
     */
    void increaseMovementForce(const std::string& string, double amount);

    /**
     * @brief Increases the damage of a specific attack by a given amount.
     * @param amount The amount to increase the damage by.
     * @param attacksName The attack to increase the damage of.
     */
    void increaseAttackDamage(double amount, std::string&attacksName);

    /**
     * @brief Retrieves all of character's attacks names.
     * @return A vector of all the character's attacks names.
     */
    std::vector<std::string> getCharacterAttacksName() const;

    /**
     * @brief Manually stops a specific movement. Designed for jetpack.
     * @param name The movement to stop.
     */
    void stop(std::string name);

    /**
     * @brief Retreives an attack at a specific index.
     * @param attack_index The index of the attack to retrieve.
     * @return The attack object at the specified index.
     */
    const Attack& getAttackAt(int attack_index) const;
};
#endif //CAPABILITIES_HPP
