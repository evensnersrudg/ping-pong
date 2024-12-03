#ifndef PADDLE_H
#define PADDLE_H

#include <threepp/threepp.hpp>

// This class is for the paddles in the game
class Paddle {
public:
  Paddle(const threepp::Vector3& position, float height); // Sets up the paddle at a position with a height

  void move(float delta, float topBoundary, float bottomBoundary); // Moves the paddle up or down, but keeps it within bounds
  void setDirection(float direction); // Tells the paddle to move up (1), down (-1), or stay still (0)

  std::shared_ptr<threepp::Mesh> getMesh() const; // Gets the paddle's 3D model so it can show up on screen

private:
  std::shared_ptr<threepp::Mesh> paddleMesh_; // The visual part of the paddle
  float direction_ = 0.0f; // This is which way the paddle moves: 1 = up, -1 = down
  float speed_ = 15.0f; // How fast the paddle moves
};

#endif // PADDLE_H
