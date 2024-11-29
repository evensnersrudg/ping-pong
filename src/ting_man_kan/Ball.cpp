#include "ting_man_kan_justere_i_spillet/Ball.h"

Ball::Ball(float radius, const Vector2& initialVelocity, float speed)
    : radius_(radius), velocity_(initialVelocity), speed_(speed) {

    const auto geometry = CircleGeometry::create(radius);
    const auto material = MeshBasicMaterial::create();
    material->color = Color::green;

    mesh_ = Mesh::create(geometry, material);
}

void Ball::update(float dt, float leftBorder, float rightBorder, float bottomBorder, float topBorder) {
    mesh_->position.x += velocity_.x * dt * speed_;
    mesh_->position.y += velocity_.y * dt * speed_;

    // Kollisjonssjekk og oppdatering av retning
    if (mesh_->position.x <= leftBorder) {
        mesh_->position.x = leftBorder;
        velocity_.x = -velocity_.x;
    }
    if (mesh_->position.x >= rightBorder) {
        mesh_->position.x = rightBorder;
        velocity_.x = -velocity_.x;
    }
    if (mesh_->position.y <= bottomBorder) {
        mesh_->position.y = bottomBorder;
        velocity_.y = -velocity_.y;
    }
    if (mesh_->position.y >= topBorder) {
        mesh_->position.y = topBorder;
        velocity_.y = -velocity_.y;
    }
}

std::shared_ptr<Mesh> Ball::getMesh() const {
    return mesh_;
}

float Ball::getRadius() const {
    return radius_;
}
