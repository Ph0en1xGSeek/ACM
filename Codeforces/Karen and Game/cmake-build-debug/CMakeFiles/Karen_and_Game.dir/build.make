# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/home/phoenix/Program Files/clion-2017.2/bin/cmake/bin/cmake"

# The command to remove a file.
RM = "/home/phoenix/Program Files/clion-2017.2/bin/cmake/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/phoenix/Next/Karen and Game"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/phoenix/Next/Karen and Game/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Karen_and_Game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Karen_and_Game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Karen_and_Game.dir/flags.make

CMakeFiles/Karen_and_Game.dir/main.cpp.o: CMakeFiles/Karen_and_Game.dir/flags.make
CMakeFiles/Karen_and_Game.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/phoenix/Next/Karen and Game/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Karen_and_Game.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Karen_and_Game.dir/main.cpp.o -c "/home/phoenix/Next/Karen and Game/main.cpp"

CMakeFiles/Karen_and_Game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Karen_and_Game.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/phoenix/Next/Karen and Game/main.cpp" > CMakeFiles/Karen_and_Game.dir/main.cpp.i

CMakeFiles/Karen_and_Game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Karen_and_Game.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/phoenix/Next/Karen and Game/main.cpp" -o CMakeFiles/Karen_and_Game.dir/main.cpp.s

CMakeFiles/Karen_and_Game.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Karen_and_Game.dir/main.cpp.o.requires

CMakeFiles/Karen_and_Game.dir/main.cpp.o.provides: CMakeFiles/Karen_and_Game.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Karen_and_Game.dir/build.make CMakeFiles/Karen_and_Game.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Karen_and_Game.dir/main.cpp.o.provides

CMakeFiles/Karen_and_Game.dir/main.cpp.o.provides.build: CMakeFiles/Karen_and_Game.dir/main.cpp.o


# Object files for target Karen_and_Game
Karen_and_Game_OBJECTS = \
"CMakeFiles/Karen_and_Game.dir/main.cpp.o"

# External object files for target Karen_and_Game
Karen_and_Game_EXTERNAL_OBJECTS =

Karen_and_Game: CMakeFiles/Karen_and_Game.dir/main.cpp.o
Karen_and_Game: CMakeFiles/Karen_and_Game.dir/build.make
Karen_and_Game: CMakeFiles/Karen_and_Game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/phoenix/Next/Karen and Game/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Karen_and_Game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Karen_and_Game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Karen_and_Game.dir/build: Karen_and_Game

.PHONY : CMakeFiles/Karen_and_Game.dir/build

CMakeFiles/Karen_and_Game.dir/requires: CMakeFiles/Karen_and_Game.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Karen_and_Game.dir/requires

CMakeFiles/Karen_and_Game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Karen_and_Game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Karen_and_Game.dir/clean

CMakeFiles/Karen_and_Game.dir/depend:
	cd "/home/phoenix/Next/Karen and Game/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/phoenix/Next/Karen and Game" "/home/phoenix/Next/Karen and Game" "/home/phoenix/Next/Karen and Game/cmake-build-debug" "/home/phoenix/Next/Karen and Game/cmake-build-debug" "/home/phoenix/Next/Karen and Game/cmake-build-debug/CMakeFiles/Karen_and_Game.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Karen_and_Game.dir/depend

