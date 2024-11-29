add_library(ping_pong_lib
        )

target_include_directories(ping_pong_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(ping_pong_lib PUBLIC
            threepp
            imgui::imgui)

