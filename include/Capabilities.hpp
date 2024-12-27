//
// Created by Enzo Renard on 26/12/2024.
//

#ifndef CAPABILITIES_HPP
#define CAPABILITIES_HPP
#include <set>
#include <map>
#include "Attacks.hpp"
#include "Attack.hpp"
#include "Movement.hpp"
#include "JetPack.hpp"

class Capabilities {
    std::map<std::string, Attack> attacks;
    std::map<std::string, Movement> movements;
    JetPack jetPack;

    bool hasThisAttack(std::string& name) const;

    bool hasThisMovement(std::string& name) const;
public:
    Capabilities(std::set<Attack> attacks, std::set<std::shared_ptr<Movement>> movements, bool hasJetPack);

    bool canUse(std::string) const;

    Attack getAttack(std::string) const;

    Movement getMovement(std::string) const;

    JetPack getJetPack() const;
    
    std::chrono::time_point<std::chrono::steady_clock> getLastAttackTime() const;

    void use(std::string);

    bool isBusy() const;
};
#endif //CAPABILITIES_HPP
