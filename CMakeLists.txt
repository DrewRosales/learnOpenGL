cmake_minimum_required(VERSION 3.5)
project(learn-opengl)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# turn off building GLFW docs, tests, and examples
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# GLFW
add_subdirectory("${CMAKE_SOURCE_DIR}/dependencies/glfw")

find_package(OpenGL REQUIRED)

#################### INCLUDES ####################

include_directories(${PROJECT_NAME} PUBLIC
  "${CMAKE_SOURCE_DIR}/include"
)

################### EXECUTABLE ###################

add_executable(${PROJECT_NAME} src/main.cpp)

#################### LIBRARY ####################

target_link_libraries(${PROJECT_NAME} PUBLIC
  glfw
  OpenGL::GL
)

