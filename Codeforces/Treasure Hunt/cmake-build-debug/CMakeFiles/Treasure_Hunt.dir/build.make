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
CMAKE_SOURCE_DIR = "/home/phoenix/Next/Treasure Hunt"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/phoenix/Next/Treasure Hunt/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Treasure_Hunt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Treasure_Hunt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Treasure_Hunt.dir/flags.make

CMakeFiles/Treasure_Hunt.dir/main.cpp.o: CMakeFiles/Treasure_Hunt.dir/flags.make
CMakeFiles/Treasure_Hunt.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/phoenix/Next/Treasure Hunt/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Treasure_Hunt.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Treasure_Hunt.dir/main.cpp.o -c "/home/phoenix/Next/Treasure Hunt/main.cpp"

CMakeFiles/Treasure_Hunt.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Treasure_Hunt.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/phoenix/Next/Treasure Hunt/main.cpp" > CMakeFiles/Treasure_Hunt.dir/main.cpp.i

CMakeFiles/Treasure_Hunt.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Treasure_Hunt.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/phoenix/Next/Treasure Hunt/main.cpp" -o CMakeFiles/Treasure_Hunt.dir/main.cpp.s

CMakeFiles/Treasure_Hunt.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Treasure_Hunt.dir/main.cpp.o.requires

CMakeFiles/Treasure_Hunt.dir/main.cpp.o.provides: CMakeFiles/Treasure_Hunt.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Treasure_Hunt.dir/build.make CMakeFiles/Treasure_Hunt.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Treasure_Hunt.dir/main.cpp.o.provides

CMakeFiles/Treasure_Hunt.dir/main.cpp.o.provides.build: CMakeFiles/Treasure_Hunt.dir/main.cpp.o


# Object files for target Treasure_Hunt
Treasure_Hunt_OBJECTS = \
"CMakeFiles/Treasure_Hunt.dir/main.cpp.o"

# External object files for target Treasure_Hunt
Treasure_Hunt_EXTERNAL_OBJECTS =

Treasure_Hunt: CMakeFiles/Treasure_Hunt.dir/main.cpp.o
Treasure_Hunt: CMakeFiles/Treasure_Hunt.dir/build.make
Treasure_Hunt: CMakeFiles/Treasure_Hunt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/phoenix/Next/Treasure Hunt/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Treasure_Hunt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Treasure_Hunt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Treasure_Hunt.dir/build: Treasure_Hunt

.PHONY : CMakeFiles/Treasure_Hunt.dir/build

CMakeFiles/Treasure_Hunt.dir/requires: CMakeFiles/Treasure_Hunt.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Treasure_Hunt.dir/requires

CMakeFiles/Treasure_Hunt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Treasure_Hunt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Treasure_Hunt.dir/clean

CMakeFiles/Treasure_Hunt.dir/depend:
	cd "/home/phoenix/Next/Treasure Hunt/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/phoenix/Next/Treasure Hunt" "/home/phoenix/Next/Treasure Hunt" "/home/phoenix/Next/Treasure Hunt/cmake-build-debug" "/home/phoenix/Next/Treasure Hunt/cmake-build-debug" "/home/phoenix/Next/Treasure Hunt/cmake-build-debug/CMakeFiles/Treasure_Hunt.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Treasure_Hunt.dir/depend
