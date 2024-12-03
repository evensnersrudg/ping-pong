// This test checks if the Ball resets correctly when it passes either paddle.
// It ensures the ball returns to its starting position and velocity after being reset.

#include <catch2/catch_test_macros.hpp>
#include "ting_man_kan_justere_i_spillet/Ball.hpp"

TEST_CASE("Ball resets after passing paddle", "[Ball]") {
    Ball ball;

    SECTION("Resets after passing left paddle") {
        // Simulate ball going out of bounds on the left
        ball.getMesh()->position.x = -21.0f; // Beyond the left boundary
        ball.reset();

        // Verify ball reset: position at origin, default velocity
        REQUIRE(ball.getMesh()->position.x == 0.0f);
        REQUIRE(ball.getMesh()->position.y == 0.0f);
        REQUIRE(ball.getVelocity().x == 15.0f); // Assuming default speed
        REQUIRE(ball.getVelocity().y == 15.0f);
    }

    SECTION("Resets after passing right paddle") {
        // Simulate ball going out of bounds on the right
        ball.getMesh()->position.x = 21.0f; // Beyond the right boundary
        ball.reset();

        // Verify ball reset: position at origin, default velocity
        REQUIRE(ball.getMesh()->position.x == 0.0f);
        REQUIRE(ball.getMesh()->position.y == 0.0f);
        REQUIRE(ball.getVelocity().x == 15.0f);
        REQUIRE(ball.getVelocity().y == 15.0f);
    }
}
