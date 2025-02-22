cmake_minimum_required(VERSION 3.10)
project(CMSC_5613_Generated_Code)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add source files
add_executable(test UserTest.cpp User.cpp)

# Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link Google Test and pthread
target_link_libraries(test ${GTEST_LIBRARIES} pthread)