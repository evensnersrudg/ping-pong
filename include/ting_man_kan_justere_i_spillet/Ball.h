#ifndef BALL_H
#define BALL_H

#include <threepp/threepp.hpp>

class Ball {
public:
    Ball();

    void update(float delta);
    void reset();

    void invertVelocityX();
    void invertVelocityY();

    std::shared_ptr<threepp::Mesh> getMesh() const;

private:
    std::shared_ptr<threepp::Mesh> ballMesh_;
    threepp::Vector2 velocity_;
    float speed_ = 10.0f;
};

#endif // BALL_H
