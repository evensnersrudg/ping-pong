#include "ting_man_kan_justere_i_spillet/Frame.h"

Frame::Frame(float width, float length) : width_(width), length_(length) {
    // Define borders using width and length
    borders_.push_back(createBorderLine(-width_, length_, width_, length_));   // Top border
    borders_.push_back(createBorderLine(-width_, -length_, width_, -length_)); // Bottom border
    borders_.push_back(createBorderLine(-width_, -length_, -width_, length_)); // Left border
    borders_.push_back(createBorderLine(width_, -length_, width_, length_));   // Right border
}

void Frame::addToScene(Scene& scene) const {
    for (const auto& border : borders_) {
        scene.add(border);
    }
}

std::tuple<float, float, float, float> Frame::getBorders(float ballRadius) const {
    return {
        -width_ + ballRadius,  // Left border
         width_ - ballRadius,  // Right border
        -length_ + ballRadius, // Bottom border
         length_ - ballRadius  // Top border
    };
}

std::shared_ptr<Line> Frame::createBorderLine(float startX, float startY, float endX, float endY) const {
    auto geometry = BufferGeometry::create();
    std::vector<float> vertices = {startX, startY, 0, endX, endY, 0};
    geometry->setAttribute("position", FloatBufferAttribute::create(vertices, 3));

    auto material = LineBasicMaterial::create();
    material->color = Color::black;

    return Line::create(geometry, material);
}
