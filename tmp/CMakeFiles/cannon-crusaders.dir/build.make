# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jacobfunk/Desktop/assignments475/cannon-crusaders-2D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jacobfunk/Desktop/assignments475/cannon-crusaders-2D/tmp

# Include any dependencies generated for this target.
include CMakeFiles/cannon-crusaders.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cannon-crusaders.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cannon-crusaders.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cannon-crusaders.dir/flags.make

CMakeFiles/cannon-crusaders.dir/app/main.cpp.o: CMakeFiles/cannon-crusaders.dir/flags.make
CMakeFiles/cannon-crusaders.dir/app/main.cpp.o: /Users/jacobfunk/Desktop/assignments475/cannon-crusaders-2D/app/main.cpp
CMakeFiles/cannon-crusaders.dir/app/main.cpp.o: CMakeFiles/cannon-crusaders.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jacobfunk/Desktop/assignments475/cannon-crusaders-2D/tmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cannon-crusaders.dir/app/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cannon-crusaders.dir/app/main.cpp.o -MF CMakeFiles/cannon-crusaders.dir/app/main.cpp.o.d -o CMakeFiles/cannon-crusaders.dir/app/main.cpp.o -c /Users/jacobfunk/Desktop/assignments475/cannon-crusaders-2D/app/main.cpp

CMakeFiles/cannon-crusaders.dir/app/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cannon-crusaders.dir/app/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jacobfunk/Desktop/assignments475/cannon-crusaders-2D/app/main.cpp > CMakeFiles/cannon-crusaders.dir/app/main.cpp.i

CMakeFiles/cannon-crusaders.dir/app/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cannon-crusaders.dir/app/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jacobfunk/Desktop/assignments475/cannon-crusaders-2D/app/main.cpp -o CMakeFiles/cannon-crusaders.dir/app/main.cpp.s

# Object files for target cannon-crusaders
cannon__crusaders_OBJECTS = \
"CMakeFiles/cannon-crusaders.dir/app/main.cpp.o"

# External object files for target cannon-crusaders
cannon__crusaders_EXTERNAL_OBJECTS =

cannon-crusaders: CMakeFiles/cannon-crusaders.dir/app/main.cpp.o
cannon-crusaders: CMakeFiles/cannon-crusaders.dir/build.make
cannon-crusaders: /opt/homebrew/lib/libglfw.3.3.dylib
cannon-crusaders: CMakeFiles/cannon-crusaders.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jacobfunk/Desktop/assignments475/cannon-crusaders-2D/tmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cannon-crusaders"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cannon-crusaders.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cannon-crusaders.dir/build: cannon-crusaders
.PHONY : CMakeFiles/cannon-crusaders.dir/build

CMakeFiles/cannon-crusaders.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cannon-crusaders.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cannon-crusaders.dir/clean

CMakeFiles/cannon-crusaders.dir/depend:
	cd /Users/jacobfunk/Desktop/assignments475/cannon-crusaders-2D/tmp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jacobfunk/Desktop/assignments475/cannon-crusaders-2D /Users/jacobfunk/Desktop/assignments475/cannon-crusaders-2D /Users/jacobfunk/Desktop/assignments475/cannon-crusaders-2D/tmp /Users/jacobfunk/Desktop/assignments475/cannon-crusaders-2D/tmp /Users/jacobfunk/Desktop/assignments475/cannon-crusaders-2D/tmp/CMakeFiles/cannon-crusaders.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cannon-crusaders.dir/depend

