cmake_minimum_required(VERSION 3.5)
project(hazel)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# turn off building GLFW docs, tests, and examples
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# GLFW
add_subdirectory("${CMAKE_SOURCE_DIR}/dependencies/glfw")
find_package(OpenGL REQUIRED)

# GLAD
set(GLAD_SRC
  ${CMAKE_SOURCE_DIR}/dependencies/glad/src
)

# ----------------------------------------
# INCLUDES
# ----------------------------------------

include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_SOURCE_DIR}/Hazel
  ${CMAKE_SOURCE_DIR}/Hazel/include
  ${CMAKE_SOURCE_DIR}/dependencies/glad/include
)

# ----------------------------------------
# SOURCES
# ----------------------------------------

set(HAZEL_SOURCES
  Hazel/src/Application.cpp
  ${GLAD_SRC}/glad.c
)
# ----------------------------------------
# EXECUTABLE
# ----------------------------------------

add_library(${PROJECT_NAME}  ${HAZEL_SOURCES})

# ----------------------------------------
# DEPENDENCIES
# ----------------------------------------

target_link_libraries(${PROJECT_NAME} PUBLIC
  glfw
  OpenGL::GL
)

# ----------------------------------------
# APPLICATION
# ----------------------------------------

add_subdirectory(app)
