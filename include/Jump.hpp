//
// Created by Enzo Renard on 26/12/2024.
//

#ifndef JUMP_HPP
#define JUMP_HPP
#include "Movement.hpp"

class Jump : public Movement {
    int maxUsage;
    int currentUsage;

public:
    Jump(double force, int maxUsage);

    bool canUse() const override;
    
    void use() override;

    void reset();
};
#endif //JUMP_HPP
