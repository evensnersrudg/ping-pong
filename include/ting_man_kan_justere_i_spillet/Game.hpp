#ifndef GAME_H
#define GAME_H

#include "Paddle.hpp"
#include "Ball.hpp"
#include "PaddleController.hpp"
#include <threepp/threepp.hpp>


// Game class handles the main logic of the Pong game
class Game : public threepp::KeyListener { // Inherits from KeyListener to handle key inputs
public:
    Game();
    void run();// Starts the main game loop
    void onKeyPressed(threepp::KeyEvent evt) override; // Handles key press events

private:
    // Rendering and game objects
    std::shared_ptr<threepp::Canvas> canvas;
    std::shared_ptr<threepp::PerspectiveCamera> camera;
    std::shared_ptr<threepp::Scene> scene;
    std::shared_ptr<threepp::GLRenderer> renderer;

    // Game elements
    Paddle leftPaddle;
    Paddle rightPaddle;
    Ball ball;
    PaddleController controller;

    // Game state
    bool gameStarted = false;
    int leftScore = 0; // Track left player's score
    int rightScore = 0;

    // Private methods for game logic
    void checkCollisions(); // Handles collision detection
    void createWalls(); // Creates ceiling and floor walls
    void displayScore(); // Displays the current scores
};

#endif // GAME_H
