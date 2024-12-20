//
// Created by Julien Delcombel on 24/11/2024.
//

#ifndef FLOOD_IT_WEAPON_H
#define FLOOD_IT_WEAPON_H

enum class Weapon {
    GUN, // default
    MACHINE_GUN,
    LASER_GUN,
};

struct WeaponProperties {
    int damage;
    float fireRate;
    float reloadTime;

    static WeaponProperties getProperties(Weapon weapon) {
        switch (weapon) {
            case Weapon::GUN:
                return {10, 1.0f, 1.0f};
            case Weapon::MACHINE_GUN:
                return {5, 0.5f, 2.0f};
            case Weapon::LASER_GUN:
                return {15, 1.5f, 0.5f};
        }
        return {0, 0.0f, 0.0f};
    }
};

#endif //FLOOD_IT_WEAPON_H
