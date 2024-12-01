#include "ting_man_kan_justere_i_spillet/Ball.h"
using namespace threepp;

Ball::Ball() {
    auto geometry = SphereGeometry::create(0.5f, 32, 32);
    auto material = MeshBasicMaterial::create();
    material->color = Color::darkred;

    ballMesh_ = Mesh::create(geometry, material);
    reset();
}

void Ball::update(float delta) {
    ballMesh_->position.x += velocity_.x * delta;
    ballMesh_->position.y += velocity_.y * delta;
}

void Ball::reset() {
    ballMesh_->position.set(0, 0, 0);
    velocity_.set(speed_, speed_);
}

void Ball::invertVelocityX() {
    velocity_.x = -velocity_.x;
}

void Ball::invertVelocityY() {
    velocity_.y = -velocity_.y;
}

std::shared_ptr<Mesh> Ball::getMesh() const {
    return ballMesh_;
}
