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
#include <map>
#include "Attacks.hpp"
#include "Attack.hpp"
#include "Movement.hpp"
#include "JetPack.hpp"

/**
 * @class Capabilities
 * @brief Represents a collection of abilities (attacks, movements, and tools) for a character.
 */
class Capabilities {
    std::map<std::string, Attack> attacks; ///< Map of attacks identified by their names.
    std::map<std::string, Movement> movements; ///< Map of movements identified by their names.
    JetPack jetPack; ///< JetPack capability, if available.

    /**
     * @brief Checks if a specific attack exists.
     * @param name The name of the attack.
     * @return True if the attack exists, otherwise false.
     */
    bool hasThisAttack(std::string& name) const;

    /**
     * @brief Checks if a specific movement exists.
     * @param name The name of the movement.
     * @return True if the movement exists, otherwise false.
     */
    bool hasThisMovement(std::string& name) const;
public:
    /**
     * @brief Constructs a Capabilities object with the specified attacks, movements, and JetPack.
     * @param attacks A set of available attacks.
     * @param movements A set of available movements.
     * @param hasJetPack Whether the JetPack capability is available.
     */
    Capabilities(std::set<Attack> attacks, std::set<std::shared_ptr<Movement>> movements, bool hasJetPack);

    bool canUse(std::string) const;

    Attack getAttack(std::string) const;

    Movement getMovement(std::string) const;

    JetPack getJetPack() const;
    
    std::chrono::time_point<std::chrono::steady_clock> getLastAttackTime() const;

    int use(std::string);

    bool isBusy() const;
};
#endif //CAPABILITIES_HPP
