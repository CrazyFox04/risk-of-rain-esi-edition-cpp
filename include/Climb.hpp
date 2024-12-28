//
// Created by Enzo Renard on 28/12/2024.
//

#ifndef CLIMB_HPP
#define CLIMB_HPP
#include "Movement.hpp"

class Climb : public Movement {
    bool climbing = false;
public:
    explicit Climb(double force);
    void use() override;
    void stop() override;
    bool isUsing() const override;
    bool canUse() const override;
};
#endif //CLIMB_HPP
