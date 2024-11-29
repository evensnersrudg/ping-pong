#ifndef BALL_H
#define BALL_H

#include "threepp/threepp.hpp"

using namespace threepp;

class Ball {
public:
    Ball(float radius, const Vector2& initialVelocity, float speed);

    void update(float dt, float leftBorder, float rightBorder, float bottomBorder, float topBorder);

    std::shared_ptr<Mesh> getMesh() const;

    float getRadius() const;

private:
    float radius_;
    Vector2 velocity_;
    float speed_;
    std::shared_ptr<Mesh> mesh_;
};


#endif //BALL_H
