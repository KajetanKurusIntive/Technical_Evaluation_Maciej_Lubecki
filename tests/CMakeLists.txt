include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# gtest
find_package(GTest CONFIG REQUIRED)

set(TEST_TARGET_NAME tests.out)

add_executable(
        ${TEST_TARGET_NAME}
        test.cpp
        AnimalTests.cpp
)

target_link_libraries(
        ${TEST_TARGET_NAME}
        PRIVATE
        ${MAIN_LIBRARY_NAME}
        GTest::gtest
)

set_target_properties(
        ${TEST_TARGET_NAME}
        PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)