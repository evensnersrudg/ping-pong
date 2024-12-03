add_library(ping_pong_lib
        Implementation/Ball.cpp
        Implementation/Game.cpp
        Implementation/Paddle.cpp
        Implementation/PaddleController.cpp
)

# Inkluder header-filene
target_include_directories(ping_pong_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Link nødvendige biblioteker
target_link_libraries(ping_pong_lib PUBLIC
        threepp
        imgui::imgui
)
