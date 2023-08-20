cmake_minimum_required(VERSION 3.5)
project(learn-opengl)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(GLFW_INCLUDES 
  "${CMAKE_SOURCE_DIR}/dependencies/glfw/include/"
)

set(GLFW_LIBRARY
  "${CMAKE_SOURCE_DIR}/dependencies/glfw/lib-arm64/libglfw3.a"
)

#################### INCLUDES ####################

include_directories(${PROJECT_NAME} PUBLIC
  "${CMAKE_SOURCE_DIR}/include"
  "${GLFW_INCLUDES}"
)

################### EXECUTABLE ###################

add_executable(${PROJECT_NAME} src/main.cpp)

#################### LIBRARY ####################

target_link_directories(${PROJECT_NAME} PUBLIC
  "${GLFW_INCLUDES}"
)

target_link_libraries(${PROJECT_NAME} PUBLIC
  "${GLFW_LIBRARY}"
)
