cmake_minimum_required(VERSION 3.8)

if ($ENV{TRAVIS_BUILD_NUMBER})
    project(matrix VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ()
    project(matrix VERSION 0.0.1)
endif ()

set(CMAKE_CXX_STANDARD 17)

add_executable(matrix main.cpp matrix.h)
install(TARGETS matrix RUNTIME DESTINATION bin)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(matrix_test matrix.h test_matrix.cpp)
target_link_libraries(matrix_test gtest gtest_main)
add_test(matrix_test matrix_test)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
