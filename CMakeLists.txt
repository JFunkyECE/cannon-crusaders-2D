cmake_minimum_required(VERSION 3.10)

# set the project name
project(cannon-crusaders)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(OpenGL_GL_PREFERENCE "GLVND")

# find necessary packages
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)

# include directories
include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

# add executable
add_executable(cannon-crusaders main.cpp)

# link libraries
target_link_libraries(cannon-crusaders ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} glfw)
