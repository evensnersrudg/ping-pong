add_executable(test1 test1.cpp)

add_test(NAME test1 COMMAND test1)


target_link_libraries(test1 PRIVATE Catch2::Catch2WithMain)

target_include_directories(test1 PUBLIC "${CMAKE_SOURCE_DIR}/include")