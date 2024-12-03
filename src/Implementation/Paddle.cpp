#include "GameObjects/Paddle.hpp"

using namespace threepp;

// Sets up the paddle with a given position and height
Paddle::Paddle(const Vector3& position, float height) {
    // Make the paddle a simple box
    auto geometry = BoxGeometry::create(1, height, 1);
    auto material = MeshBasicMaterial::create();
    material->color = Color::black;

    // Combine the box and material to create the paddle's visual model
    paddleMesh_ = Mesh::create(geometry, material);

    // Place the paddle at the specified position
    paddleMesh_->position.set(position.x, position.y, position.z);
}

// Moves the paddle up or down, but keeps it within the game area
void Paddle::move(float delta, float topBoundary, float bottomBoundary) {
    // Update the paddle's position based on its direction and speed
    paddleMesh_->position.y += direction_ * speed_ * delta;

    // Prevent the paddle from moving outside the boundaries
    paddleMesh_->position.y = std::clamp(paddleMesh_->position.y, bottomBoundary, topBoundary);
}

// Changes the direction the paddle moves (1 = up, -1 = down, 0 = still)
void Paddle::setDirection(float direction) {
    direction_ = direction;
}

// Returns the paddle's 3D model so it can be drawn on the screen
std::shared_ptr<Mesh> Paddle::getMesh() const {
    return paddleMesh_;
}
