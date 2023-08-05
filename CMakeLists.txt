cmake_minimum_required(VERSION 3.10)

# set the project name
project(cannon-crusaders)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(OpenGL_GL_PREFERENCE "GLVND")

# find necessary packages
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 3.2.1 REQUIRED)

# include directories
include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
include_directories(cannon-crusaders PUBLIC include/)

# add executable
add_executable(cannon-crusaders app/main.cpp)

# link libraries
target_link_libraries(cannon-crusaders ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} glfw)
