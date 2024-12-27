//
// Created by Enzo Renard on 19/11/2024.
//
/**
 * @file Area.hpp
 * @brief Defines the Area class, representing a region in the game world.
 *
 * The Area class is responsible for handling specific game regions, their properties,
 * and interactions. It supports gateways, spawns, and compatibility checks between areas.
 */
#ifndef AREA_HPP
#define AREA_HPP
#include "Direction.hpp"
#include "Spawn.hpp"
#include <set>

/**
 * @class Area
 * @brief Represents a region within the game world with specific properties and spawns.
 */
class Area {
    static constexpr int FILLED_ID = 0; ///< Constant representing a filled area ID.
    int type; ///< The type of the area.
    int id; ///< The unique identifier of the area.
    std::set<Direction2D> gatewayPositions; ///< Set of gateway positions for connecting areas.
    std::vector<Spawn> spawns; ///< List of spawns within the area.

    /**
     * @brief Retrieves a spawn by its ID.
     * @param spawn_id The ID of the spawn to retrieve.
     * @return A reference to the spawn.
     */
    Spawn& get_spawn(int spawn_id);

public:
    /**
     * @brief Default constructor for the Area class.
     */
    Area();

    /**
     * @brief Constructs an Area object with specified properties.
     * @param type The type of the area.
     * @param max_id The maximum allowable ID for the area.
     * @param gatewayPositions Set of gateway positions for the area.
     */
    Area(int type, int max_id, std::set<Direction2D> gatewayPositions);

    /**
     * @brief Constructs an Area object with spawns.
     * @param type The type of the area.
     * @param max_id The maximum allowable ID for the area.
     * @param gatewayPositions Set of gateway positions for the area.
     * @param spawns A list of spawns for the area.
     */
    Area(int type, int max_id, std::set<Direction2D> gatewayPositions, std::vector<Spawn> spawns);

    /**
     * @brief Generates a random Area object.
     * @return A randomly generated Area object.
     */
    static Area getRandomArea();

    /**
     * @brief Checks compatibility between this area and another based on direction.
     * @param sourceDirection The direction of the source gateway.
     * @param otherArea The other area to compare compatibility with.
     * @return True if the areas are compatible, otherwise false.
     */
    bool isCompatible(Direction2D sourceDirection, const Area&otherArea);

    /**
     * @brief Retrieves the type of the area.
     * @return The type of the area.
     */
    [[nodiscard]] int get_type() const;

    /**
     * @brief Retrieves the ID of the area.
     * @return The ID of the area.
     */
    [[nodiscard]] int get_id() const;

    /**
     * @brief Retrieves a globally unique identifier for the area.
     * @return The globally unique identifier.
     */
    [[nodiscard]] int get_guid() const;

    /**
     * @brief Retrieves the gateway positions for the area.
     * @return A set of gateway positions.
     */
    [[nodiscard]] std::set<Direction2D> get_gateway_positions() const;

    /**
     * @brief Generates a random area ID within a maximum range.
     * @param max_id The maximum allowable ID.
     * @return A randomly generated area ID.
     */
    static int get_random_area_id(int max_id) ;

    /**
     * @brief Checks if a specific spawn is available.
     * @param spawd_id The ID of the spawn to check.
     * @return True if the spawn is available, otherwise false.
     */
    bool can_spawn(int spawd_id);

    /**
     * @brief Activates a spawn in the area.
     * @param spawd_id The ID of the spawn to activate.
     */
    void spawn(int spawd_id);

    /**
     * @brief Retrieves the IDs of all spawns in the area.
     * @return A vector containing all spawn IDs.
     */
    [[nodiscard]] std::vector<int> get_spawn_ids() const;
};
#endif //AREA_HPP
