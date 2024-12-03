add_library(ping_pong_lib
        ting_man_kan/Ball.cpp
        ting_man_kan/Game.cpp
        ting_man_kan/Paddle.cpp
        ting_man_kan/PaddleController.cpp
)

# Inkluder header-filene
target_include_directories(ping_pong_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Link nødvendige biblioteker
target_link_libraries(ping_pong_lib PUBLIC
        threepp
        imgui::imgui
)
