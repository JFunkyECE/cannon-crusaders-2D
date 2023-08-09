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
include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} )
include_directories(cannon-crusaders PUBLIC include/)

# add executable
add_executable(cannon-crusaders app/main.cpp lib/tank.cpp 
								lib/menus.cpp lib/game.cpp 
								lib/cannonballs.cpp lib/enemy.cpp 
								lib/collisiondetection.cpp)
# link libraries
target_link_libraries(cannon-crusaders ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} glfw )

#enable ASan if ENABLE_ASAN set to 1 by user
if(${ENABLE_ASAN})
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
endif ()
#enable UBSan if ENABLE_ASAN set to 1 by user
if(${ENABLE_UBSAN})
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined")
endif ()