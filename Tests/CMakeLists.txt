add_executable(Tests Tests.cpp)

target_link_libraries(Tests
        PRIVATE
        GTest::GTest
        Methods)

add_test(GTests Tests)