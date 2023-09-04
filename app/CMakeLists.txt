cmake_minimum_required(VERSION 3.5)
project(hazelApp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ----------------------------------------
# SOURCES
# ----------------------------------------

set(HAZEL_APP_SOURCES
  hazelApp.cpp
)

# ----------------------------------------
# EXECUTABLE
# ----------------------------------------
add_executable(${PROJECT_NAME} ${HAZEL_APP_SOURCES})


# ----------------------------------------
# EXECUTABLE
# ----------------------------------------
target_link_libraries(${PROJECT_NAME} PUBLIC
  hazel
)

target_include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)
