//
// Created by Julien Delcombel on 24/11/2024.
//

#ifndef FLOOD_IT_CHARACTERMODIFIER_H
#define FLOOD_IT_CHARACTERMODIFIER_H

enum class Buff {
    HEALTH_POTION,
    SPEED_BOOST,
    DAMAGE_BOOST
};

struct BuffValue {
    static int getValue(Buff buff) {
        switch (buff) {
            case Buff::HEALTH_POTION:
                return 50;
            case Buff::SPEED_BOOST:
                return 10;
            case Buff::DAMAGE_BOOST:
                return 15;
            default:
                return 0;
        }
    }
};


#endif //FLOOD_IT_CHARACTERMODIFIER_H
