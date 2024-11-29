#ifndef FRAME_H
#define FRAME_H

#include "threepp/threepp.hpp"

using namespace threepp;

class Frame {
public:
    // Constructor with width and length
    Frame(float width, float length);

    void addToScene(Scene& scene) const;

private:
    std::shared_ptr<Line> createBorderLine(float startX, float startY, float endX, float endY) const;

    float width_;  // Width of the frame
    float length_; // Length of the frame
    std::vector<std::shared_ptr<Line>> borders_;
};

#endif // FRAME_H
