#include "ting_man_kan_justere_i_spillet/Racket.h"

Racket::Racket(const Vector3& position, float width, float height, int keyUp, int keyDown)
    : keyUp_(keyUp), keyDown_(keyDown), height_(height) {
    // Opprett racketens geometri og materiale
    auto geometry = PlaneGeometry::create(width, height);
    auto material = MeshBasicMaterial::create({{"color", Color::white}});
    mesh_ = Mesh::create(geometry, material);

    // Sett startposisjonen for racketen
    mesh_->position.set(position.x, position.y, position.z);
}

void Racket::update(float dt, bool moveUp, bool moveDown) {
    // Beveg racketen basert på tastetrykk
    if (moveUp) {
        mesh_->position.y += speed_ * dt;
    }
    if (moveDown) {
        mesh_->position.y -= speed_ * dt;
    }

    // Begrens racketens bevegelse til en maks høyde
    float limit = 300.0f; // Maksimal Y-bevegelse
    if (mesh_->position.y > limit) {
        mesh_->position.y = limit;
    } else if (mesh_->position.y < -limit) {
        mesh_->position.y = -limit;
    }
}

void Racket::addToScene(Scene& scene) const {
    // Legg racketen til scenen
    scene.add(mesh_);
}
