cmake_minimum_required(VERSION 3.19)
project(PingPong)

set(CMAKE_CXX_STANDARD 20)

# Fetch necessary libraries
include(FetchContent)

# Fetch Threepp
set(THREEPP_BUILD_TESTS OFF)
set(THREEPP_BUILD_EXAMPLES OFF)
FetchContent_Declare(
        threepp
        GIT_REPOSITORY https://github.com/markaren/threepp.git
        GIT_TAG 2e2397e0b7f0e639f254ea3046b70e53a71f0387
)
FetchContent_MakeAvailable(threepp)

# Fetch Catch2
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.7.0
)
FetchContent_MakeAvailable(Catch2)

# Enable testing
enable_testing()

# Add subdirectories
add_subdirectory(external)
add_subdirectory(tests)
add_subdirectory(src)

# Include header files

# Add main executable
add_executable(PingPong main.cpp)

# Link main executable with necessary libraries
target_link_libraries(PingPong PRIVATE threepp::threepp imgui::imgui ping_pong_lib)
