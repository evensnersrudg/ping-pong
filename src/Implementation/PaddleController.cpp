#include "GameObjects/PaddleController.hpp"

using namespace threepp;

// Connects the controller to the left and right paddles
PaddleController::PaddleController(Paddle& leftPaddle, Paddle& rightPaddle)
    : leftPaddle_(leftPaddle), rightPaddle_(rightPaddle) {}

// Updates paddle directions based on the current key states
void PaddleController::update(float deltaTime) {
    // Move the left paddle
    if (moveLeftUp_) leftPaddle_.setDirection(1);
    else if (moveLeftDown_) leftPaddle_.setDirection(-1);
    else leftPaddle_.setDirection(0);

    // Move the right paddle
    if (moveRightUp_) rightPaddle_.setDirection(1);
    else if (moveRightDown_) rightPaddle_.setDirection(-1);
    else rightPaddle_.setDirection(0);
}

// Handles key press events to start paddle movement
void PaddleController::onKeyPressed(KeyEvent evt) {
    if (evt.key == Key::W) moveLeftUp_ = true;
    if (evt.key == Key::S) moveLeftDown_ = true;
    if (evt.key == Key::O) moveRightUp_ = true;
    if (evt.key == Key::L) moveRightDown_ = true;
}
// Handles key release events to stop paddle movement
void PaddleController::onKeyReleased(KeyEvent evt) {
    if (evt.key == Key::W) moveLeftUp_ = false;
    if (evt.key == Key::S) moveLeftDown_ = false;
    if (evt.key == Key::O) moveRightUp_ = false;
    if (evt.key == Key::L) moveRightDown_ = false;
}
