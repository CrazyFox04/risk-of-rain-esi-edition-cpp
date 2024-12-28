//
// Created by Enzo Renard on 28/12/2024.
//

#ifndef MOVEMENTS_HPP
#define MOVEMENTS_HPP
#include <set>
#include "magic_enum/magic_enum.hpp"

enum Movements {
    RUN,
    JUMP,
    DASH,
    JETPACK,
    CLIMB
};

struct DefinedMovements {
    static std::string getMovementName(int movementIndex) {
        if (movementIndex < 0 || movementIndex >= size()) {
            throw std::out_of_range("Invalid movement enum value.");
        }
        return magic_enum::enum_name(static_cast<Movements>(movementIndex)).data();
    }

    static int size() {
        return magic_enum::enum_count<Movements>();
    }

    static Movements get(Movements movement) {
        return movement;
    }

    static std::set<Movements> getAllMovements() {
        std::set<Movements> movements;
        for (int i = 0; i < size(); ++i) {
            movements.insert(get(static_cast<Movements>(i)));
        }
        return movements;
    }

    static std::set<std::string> getCharacterMovementsName() {
        auto movements = getAllMovements();
        auto names = std::set<std::string>();
        for (const auto&movement: movements) {
            names.insert(getMovementName(movement));
        }
        return names;
    }


    static bool isAValidMovementName(const std::string&move) {
        return getCharacterMovementsName().contains(move);
    }

    static int getMovementIndex(const std::string& movementName) {
        for (int i = 0; i < size(); ++i) {
            if (getMovementName(i) == movementName) {
                return i;
            }
        }
        return -1;
    }
};
#endif //MOVEMENTS_HPP
