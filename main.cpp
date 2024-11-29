#include "threepp/threepp.hpp"
#include "ting_man_kan_justere_i_spillet/Ball.h"
#include "ting_man_kan_justere_i_spillet/Frame.h"
#include "ting_man_kan_justere_i_spillet/Racket.h"
#include <GLFW/glfw3.h> // Inkluder riktig GLFW-header

using namespace threepp;

int main() {
    // Dimensjoner for spilleområdet
    float width = 800;
    float length = 600;

    // Opprett vindu og Canvas
    Canvas canvas{
        {"fullscreen", false} // Sett til `true` hvis du ønsker fullskjerm
    };

    GLFWwindow* window = canvas.window(); // Hent GLFW-vindu fra Canvas

    GLRenderer renderer{canvas.size()};

    // Sett opp kameraet
    PerspectiveCamera camera(75, canvas.aspect(), 0.1, 2000);
    camera.position.z = std::max(width, length) * 1.2f;

    // Opprett scene og sett bakgrunnsfarge
    Scene scene;
    scene.background = Color::aliceblue;

    // Opprett rammen (spilleområdet)
    Frame frame(width, length);
    frame.addToScene(scene);

    // Opprett ballen
    Ball ball(10, {1.0, 5.0}, 500);
    scene.add(ball.getMesh());

    // Opprett racketene
    Racket leftRacket({-width / 2 + 50, 0, 0}, 20, 100, GLFW_KEY_W, GLFW_KEY_S);
    Racket rightRacket({width / 2 - 50, 0, 0}, 20, 100, GLFW_KEY_UP, GLFW_KEY_DOWN);
    leftRacket.addToScene(scene);
    rightRacket.addToScene(scene);

    // Beregn grensene for spilleområdet
    float leftBorder = -width / 2 + ball.getRadius();
    float rightBorder = width / 2 - ball.getRadius();
    float bottomBorder = -length / 2 + ball.getRadius();
    float topBorder = length / 2 - ball.getRadius();

    // Klokke for tidsdifferanse
    Clock clock;

    // Animere sløyfen
    canvas.animate([&] {
        const auto dt = clock.getDelta(); // Tidsdifferanse mellom rammer

        // Lytt til tastetrykk for racketene
        bool leftUp = glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
        bool leftDown = glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS;
        bool rightUp = glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS;
        bool rightDown = glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS;

        // Oppdater racketenes posisjon
        leftRacket.update(dt, leftUp, leftDown);
        rightRacket.update(dt, rightUp, rightDown);

        // Oppdater ballens posisjon og sjekk for kollisjoner
        ball.update(dt, leftBorder, rightBorder, bottomBorder, topBorder);

        // Render scenen
        renderer.render(scene, camera);
    });

    return 0;
}
