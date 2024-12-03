#ifndef BALL_H
#define BALL_H

#include <threepp/threepp.hpp>

// Represents the ball in the game
class Ball {
public:
  Ball();
  void createBall(); // Sets up the ball's 3D model
  void update(float delta); // Updates the ball's position
  void reset(); // Resets the ball's position and velocity

  void invertVelocityX(); // Reverses horizontal velocity
  void invertVelocityY(); // Reverses vertical velocity

  threepp::Vector2 getVelocity() const; // Returns the ball's velocity
  std::shared_ptr<threepp::Mesh> getMesh() const; // Returns the ball's 3D mesh

private:
  std::shared_ptr<threepp::Mesh> ballMesh_; // 3D model of the ball
  threepp::Vector2 velocity_; // Current velocity of the ball
  float speed_ = 15.0f; // Ball's speed
};

#endif // BALL_H
