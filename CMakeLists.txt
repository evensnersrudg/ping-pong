cmake_minimum_required(VERSION 3.19)
project(PingPong)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

set(THREEPP_BUILD_TESTS OFF)
set(THREEPP_BUILD_EXAMPLES OFF)
FetchContent_Declare(
        threepp
        GIT_REPOSITORY https://github.com/markaren/threepp.git
        GIT_TAG 2e2397e0b7f0e639f254ea3046b70e53a71f0387
)
FetchContent_MakeAvailable(threepp)

add_subdirectory(external)

# Include header files directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add executable and sources
add_executable(threepp_demo main.cpp
        include/ting_man_kan_justere_i_spillet/Ball.h
        src/ting_man_kan/Ball.cpp
        include/ting_man_kan_justere_i_spillet/Frame.h
        src/ting_man_kan/Frame.cpp
        include/ting_man_kan_justere_i_spillet/Paddle.h
        src/ting_man_kan/Paddle.cpp
        include/ting_man_kan_justere_i_spillet/PaddleController.h
        src/ting_man_kan/PaddleController.cpp
        include/ting_man_kan_justere_i_spillet/Game.h
        src/ting_man_kan/Game.cpp
)

# Link libraries
target_link_libraries(threepp_demo PRIVATE threepp::threepp imgui::imgui)

######### Emscripten #######
if (DEFINED EMSCRIPTEN)

    set(LINK_FLAGS " --bind -sUSE_GLFW=3 -sGL_DEBUG=1 -sMIN_WEBGL_VERSION=2 -sMAX_WEBGL_VERSION=2 \
    -sFULL_ES3 -sASSERTIONS -sALLOW_MEMORY_GROWTH -sWASM=1")

    set_target_properties("demo"
            PROPERTIES SUFFIX ".html"
            LINK_FLAGS "${LINK_FLAGS}"
    )

endif ()
###########################
