#ifndef PADDLECONTROLLER_H
#define PADDLECONTROLLER_H

#include "ting_man_kan_justere_i_spillet/Paddle.hpp"
#include <threepp/threepp.hpp>

// This class handles paddle movement based on player input
class PaddleController : public threepp::KeyListener { // Listens to keyboard events
public:
  PaddleController(Paddle& leftPaddle, Paddle& rightPaddle); // Links the controller to both paddles

  void update(float deltaTime); // Updates paddle movement based on the current input

  void onKeyPressed(threepp::KeyEvent evt) override; // Called when a key is pressed
  void onKeyReleased(threepp::KeyEvent evt) override; // Called when a key is released

private:
  Paddle& leftPaddle_; // Reference to the left paddle
  Paddle& rightPaddle_; // Reference to the right paddle

  // Booleans to track which keys are currently pressed for both paddles
  bool moveLeftUp_ = false;
  bool moveLeftDown_ = false;
  bool moveRightUp_ = false;
  bool moveRightDown_ = false;
};

#endif // PADDLECONTROLLER_H
