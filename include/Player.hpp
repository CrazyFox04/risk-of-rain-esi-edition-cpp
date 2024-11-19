//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Character.hpp"
class Player final : Character {
public:
    Player(int health, int speed, int damage);
};
#endif //PLAYER_HPP
