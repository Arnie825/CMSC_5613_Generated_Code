cmake_minimum_required(VERSION 3.10)
project(CMSC_5613_Generated_Code)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add source files
add_executable(test UserTest.cpp User.cpp)

# Add Google Test and Google Mock submodule to build them
add_subdirectory(external/googletest)

# Include Google Test and Google Mock directories
include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})

# Link Google Test and Google Mock libraries to your test
target_link_libraries(test gmock gtest pthread)