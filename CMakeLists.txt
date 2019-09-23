cmake_minimum_required(VERSION 2.8)

project(post_treatment)

find_package(gromacs REQUIRED)
include_directories(${GROMACS_INCLUDE_DIRS})
target_link_libraries(${GROMACS_LIBRARIES})
link_libraries(libgromacs)


add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME} libgromacs)
