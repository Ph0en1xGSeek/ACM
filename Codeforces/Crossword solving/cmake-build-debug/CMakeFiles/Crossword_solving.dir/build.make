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
CMAKE_SOURCE_DIR = "/home/phoenix/Next/Crossword solving"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/phoenix/Next/Crossword solving/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Crossword_solving.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Crossword_solving.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Crossword_solving.dir/flags.make

CMakeFiles/Crossword_solving.dir/main.cpp.o: CMakeFiles/Crossword_solving.dir/flags.make
CMakeFiles/Crossword_solving.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/phoenix/Next/Crossword solving/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Crossword_solving.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Crossword_solving.dir/main.cpp.o -c "/home/phoenix/Next/Crossword solving/main.cpp"

CMakeFiles/Crossword_solving.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Crossword_solving.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/phoenix/Next/Crossword solving/main.cpp" > CMakeFiles/Crossword_solving.dir/main.cpp.i

CMakeFiles/Crossword_solving.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Crossword_solving.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/phoenix/Next/Crossword solving/main.cpp" -o CMakeFiles/Crossword_solving.dir/main.cpp.s

CMakeFiles/Crossword_solving.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Crossword_solving.dir/main.cpp.o.requires

CMakeFiles/Crossword_solving.dir/main.cpp.o.provides: CMakeFiles/Crossword_solving.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Crossword_solving.dir/build.make CMakeFiles/Crossword_solving.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Crossword_solving.dir/main.cpp.o.provides

CMakeFiles/Crossword_solving.dir/main.cpp.o.provides.build: CMakeFiles/Crossword_solving.dir/main.cpp.o


# Object files for target Crossword_solving
Crossword_solving_OBJECTS = \
"CMakeFiles/Crossword_solving.dir/main.cpp.o"

# External object files for target Crossword_solving
Crossword_solving_EXTERNAL_OBJECTS =

Crossword_solving: CMakeFiles/Crossword_solving.dir/main.cpp.o
Crossword_solving: CMakeFiles/Crossword_solving.dir/build.make
Crossword_solving: CMakeFiles/Crossword_solving.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/phoenix/Next/Crossword solving/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Crossword_solving"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Crossword_solving.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Crossword_solving.dir/build: Crossword_solving

.PHONY : CMakeFiles/Crossword_solving.dir/build

CMakeFiles/Crossword_solving.dir/requires: CMakeFiles/Crossword_solving.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Crossword_solving.dir/requires

CMakeFiles/Crossword_solving.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Crossword_solving.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Crossword_solving.dir/clean

CMakeFiles/Crossword_solving.dir/depend:
	cd "/home/phoenix/Next/Crossword solving/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/phoenix/Next/Crossword solving" "/home/phoenix/Next/Crossword solving" "/home/phoenix/Next/Crossword solving/cmake-build-debug" "/home/phoenix/Next/Crossword solving/cmake-build-debug" "/home/phoenix/Next/Crossword solving/cmake-build-debug/CMakeFiles/Crossword_solving.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Crossword_solving.dir/depend
