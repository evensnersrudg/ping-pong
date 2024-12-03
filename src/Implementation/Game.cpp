#include "GameObjects/Game.hpp"
#include <threepp/threepp.hpp>
#include <iostream> // For printing the scores

using namespace threepp;

// Constructor initializes paddles, ball, and rendering components
Game::Game()
    : leftPaddle(Vector3(-15, 0, 0), 4),
      rightPaddle(Vector3(15, 0, 0), 4),
      controller(leftPaddle, rightPaddle) { // Connect paddles to controller
    canvas = std::make_shared<threepp::Canvas>("Pong Game");
    camera = std::make_shared<threepp::PerspectiveCamera>(75, canvas->aspect(), 0.1f, 1000.f);
    camera->position.z = 20;

    scene = std::make_shared<threepp::Scene>();

    renderer = std::make_shared<threepp::GLRenderer>(canvas->size());
    renderer->setClearColor(Color::white);

    // Add game elements to the scene
    scene->add(leftPaddle.getMesh());
    scene->add(rightPaddle.getMesh());
    scene->add(ball.getMesh());

    // Add key listeners for paddle control and game start
    canvas->addKeyListener(controller);
    canvas->addKeyListener(*this);

    createWalls(); //ceiling and floor
    displayScore(); // Show initial score
}

// Main game loop
void Game::run() {
    Clock clock;

    // Continuous update and rendering
    canvas->animate([&]() {
        float deltaTime = clock.getDelta();

        if (gameStarted) { // Only update game elements when the game has started
            controller.update(deltaTime);
            leftPaddle.move(deltaTime, 9, -9);
            rightPaddle.move(deltaTime, 9, -9);
            ball.update(deltaTime);
            checkCollisions();
        }

        renderer->render(*scene, *camera);
    });
}

// Handle key presses
void Game::onKeyPressed(KeyEvent evt) {
    if (evt.key == Key::B && !gameStarted) { // Start the game on B key press
        gameStarted = true;
    }
}

// Detect and respond to collisions
void Game::checkCollisions() {
    // Ball bounces off top and bottom walls
    if (ball.getMesh()->position.y >= 9.5f || ball.getMesh()->position.y <= -9.5f) {
        ball.invertVelocityY();
    }

    // Ball hits the left paddle
    if (ball.getMesh()->position.x <= leftPaddle.getMesh()->position.x + 0.5f &&
        ball.getMesh()->position.y <= leftPaddle.getMesh()->position.y + 2.0f &&
        ball.getMesh()->position.y >= leftPaddle.getMesh()->position.y - 2.0f) {
        ball.invertVelocityX();
    }

    // Ball hits the right paddle
    if (ball.getMesh()->position.x >= rightPaddle.getMesh()->position.x - 0.5f &&
        ball.getMesh()->position.y <= rightPaddle.getMesh()->position.y + 2.0f &&
        ball.getMesh()->position.y >= rightPaddle.getMesh()->position.y - 2.0f) {
        ball.invertVelocityX();
    }

    // Ball goes out of bounds on the left side
    if (ball.getMesh()->position.x <= -20.0f) {
        rightScore++; // Increment right player's score
        displayScore(); // Update score
        ball.reset(); // Reset ball position and velocity
        gameStarted = false; // Stop the game
    }

    // Ball goes out of bounds on the right side
    if (ball.getMesh()->position.x >= 20.0f) {
        leftScore++; // Increment left player's score
        displayScore(); // Update score
        ball.reset(); // Reset ball position and velocity
        gameStarted = false; // Stop the game
    }
}

// Create ceiling and floor walls
void Game::createWalls() {
    auto wallGeometry = PlaneGeometry::create(40, 1); // Wall dimensions
    auto wallMaterial = MeshBasicMaterial::create();
    wallMaterial->color = Color::gray;

    // Ceiling
    auto ceiling = Mesh::create(wallGeometry, wallMaterial);
    ceiling->position.set(0, 10, 0);
    scene->add(ceiling);

    // Floor
    auto floor = Mesh::create(wallGeometry, wallMaterial);
    floor->position.set(0, -10, 0);
    scene->add(floor);
}

// Print scores to the console
void Game::displayScore() {
    std::cout << "Left Player: " << leftScore << " | Right Player: " << rightScore << std::endl;
}