add_executable(collisionTest collisionTest.cpp
        pastPaddleTest.cpp)

target_link_libraries(collisionTest PRIVATE Catch2::Catch2WithMain ping_pong_lib)

add_test(NAME collisionTest COMMAND collisionTest)

target_include_directories(collisionTest PUBLIC "${CMAKE_SOURCE_DIR}/include")

add_executable(simpleTest simpleTest.cpp)

target_link_libraries(simpleTest PRIVATE Catch2::Catch2WithMain)

add_test(NAME simpleTest COMMAND simpleTest)

add_executable(pastPaddleTest pastPaddleTest.cpp)

target_link_libraries(pastPaddleTest PRIVATE Catch2::Catch2WithMain ping_pong_lib)

add_test(NAME pastPaddleTest COMMAND pastPaddleTest)
