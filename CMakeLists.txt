cmake_minimum_required(VERSION 2.8)

project(post_treatment)




find_package(gromacs REQUIRED)
include_directories(${GROMACS_INCLUDE_DIRS})
target_link_libraries(${GROMACS_LIBRARIES})
link_libraries(libgromacs)
aux_source_directory(src SRC_LIST)
file(GLOB INC_DIRC src/*.h)


add_executable(${PROJECT_NAME} ${SRC_LIST})
add_custom_target(headers SOURCES ${INC_DIRC})
target_link_libraries(${PROJECT_NAME} libgromacs)




