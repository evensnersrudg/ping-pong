#include "GameObjects/Ball.hpp"
using namespace threepp;

Ball::Ball() {
    createBall(); // Initialize the ball's 3D model
    reset(); // Set initial position and velocity
}

void Ball::createBall() {
    auto geometry = SphereGeometry::create(0.5f, 32, 32);
    auto material = MeshBasicMaterial::create();
    material->color = Color::darkred;
    ballMesh_ = Mesh::create(geometry, material);
}

void Ball::update(float delta) {
    // Move the ball based on velocity and elapsed time
    ballMesh_->position.x += velocity_.x * delta;
    ballMesh_->position.y += velocity_.y * delta;
}

void Ball::reset() {
    ballMesh_->position.set(0, 0, 0); // Reset position to the center
    velocity_.set(speed_, speed_); // Set initial velocity
}

void Ball::invertVelocityX() {
    velocity_.x = -velocity_.x; // Reverse horizontal velocity
}

void Ball::invertVelocityY() {
    velocity_.y = -velocity_.y; // Reverse vertical velocity
}

Vector2 Ball::getVelocity() const {
    return velocity_; // Return current velocity
}

std::shared_ptr<Mesh> Ball::getMesh() const {
    return ballMesh_; // Return 3D model of the ball
}
