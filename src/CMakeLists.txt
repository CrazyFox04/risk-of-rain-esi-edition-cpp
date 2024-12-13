# ===========================================
#          Sources model CMakeLists
# ===========================================
project(risk-of-rain-esi-edition-cpp)

# C++ sources files of the Risk of rain game
set(SOURCES
        Character.cpp
        Enemy.cpp
        Player.cpp
        Game.cpp
        Level.cpp
        Area.cpp
        Tile.cpp
        InteractiveObject.cpp
        Direction.cpp
)

# Create the model library that public can use
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Include the headers folder for linker
# Note : If needed, we can split headers declaration in multiple child folder in the include folder.
target_include_directories(${PROJECT_NAME} PUBLIC
        ../include
        # If more folder or more specific you can add it here
)
