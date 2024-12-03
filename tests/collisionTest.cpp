// This test verifies the collision logic of the Ball class in a ping-pong game.
// It ensures that the Ball inverts its velocity correctly when colliding with vertical or horizontal walls,
// simulating realistic bounce behavior during gameplay.

#include <catch2/catch_test_macros.hpp>
#include "ting_man_kan_justere_i_spillet/Ball.hpp"

TEST_CASE("Collision testing for Ball", "[Ball]") {
    Ball ball;
    ball.reset();

    SECTION("Inverts x-velocity on collision with a vertical wall") {
        // Test initial velocity
        float initialVelocityX = ball.getVelocity().x;
        ball.invertVelocityX();


        // Verify velocity inversion
        REQUIRE(ball.getVelocity().x == -initialVelocityX);
    }

    SECTION("Inverts y-velocity on collision with a horizontal wall") {
        // Test initial velocity
        float initialVelocityY = ball.getVelocity().y;
        ball.invertVelocityY();

        // Verify velocity inversion
        REQUIRE(ball.getVelocity().y == -initialVelocityY);
    }
}
