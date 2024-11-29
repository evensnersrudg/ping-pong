#ifndef RACKET_H
#define RACKET_H

#include "threepp/threepp.hpp"

using namespace threepp;

class Racket {
public:
    Racket(const Vector3& position, float width, float height, int keyUp, int keyDown);

    // Oppdater racketens posisjon basert på tastetrykk
    void update(float dt, bool moveUp, bool moveDown);

    // Legg racketen til scenen
    void addToScene(Scene& scene) const;

private:
    std::shared_ptr<Mesh> mesh_; // Racketens grafiske representasjon
    float speed_ = 300.0f;       // Racketens bevegelseshastighet
    int keyUp_;                  // Tast for oppover-bevegelse
    int keyDown_;                // Tast for nedover-bevegelse
    float height_;               // Racketens høyde
};

#endif // RACKET_H
