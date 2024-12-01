#ifndef FRAME_H
#define FRAME_H

#include "threepp/threepp.hpp"

using namespace threepp;

class Frame {
public:
    Frame(float width, float length);
    void addToScene(Scene& scene) const;
    std::tuple<float, float, float, float> getBorders(float ballRadius) const;

private:
    std::shared_ptr<Line> createBorderLine(float startX, float startY, float endX, float endY) const;

    float width_;
    float length_;
    std::vector<std::shared_ptr<Line>> borders_;
};

#endif // FRAME_H
