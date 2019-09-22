cmake_minimum_required(VERSION 2.8)

project(post_treatment)

set(INC_DIR /usr/locla/gromacs/include/gromacs)
set(LINK_DIR /usr/local/gromacs/lib64/)

add_executable(${PROJECT_NAME} "main.cpp")
