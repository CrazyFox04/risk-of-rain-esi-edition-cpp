# ===========================================
#            Tests CMakeLists
# ===========================================
include(FetchContent)
include(GoogleTest)
project(risk-of-rain_test)

# Define test source files
set(TEST_SOURCES
        testMain.cpp
        testArea.cpp
        testDefinedAreas.cpp
)

# Create the tests main executable
add_executable(${PROJECT_NAME} ${TEST_SOURCES})
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
# Prevent overriding the parent project's compiler/linker settings for Windows target
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable test in every child directory
enable_testing()

# Link required libraries
target_link_libraries(
        ${PROJECT_NAME} PRIVATE
        GTest::gtest
        GTest::gtest_main
        risk-of-rain-esi-edition-cpp 
)

# Discover tests using Google Test
gtest_discover_tests(${PROJECT_NAME})
