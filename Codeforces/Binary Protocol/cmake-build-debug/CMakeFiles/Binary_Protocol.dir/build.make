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
CMAKE_SOURCE_DIR = "/home/phoenix/Next/Binary Protocol"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/phoenix/Next/Binary Protocol/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Binary_Protocol.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Binary_Protocol.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Binary_Protocol.dir/flags.make

CMakeFiles/Binary_Protocol.dir/main.cpp.o: CMakeFiles/Binary_Protocol.dir/flags.make
CMakeFiles/Binary_Protocol.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/phoenix/Next/Binary Protocol/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Binary_Protocol.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Binary_Protocol.dir/main.cpp.o -c "/home/phoenix/Next/Binary Protocol/main.cpp"

CMakeFiles/Binary_Protocol.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Binary_Protocol.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/phoenix/Next/Binary Protocol/main.cpp" > CMakeFiles/Binary_Protocol.dir/main.cpp.i

CMakeFiles/Binary_Protocol.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Binary_Protocol.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/phoenix/Next/Binary Protocol/main.cpp" -o CMakeFiles/Binary_Protocol.dir/main.cpp.s

CMakeFiles/Binary_Protocol.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Binary_Protocol.dir/main.cpp.o.requires

CMakeFiles/Binary_Protocol.dir/main.cpp.o.provides: CMakeFiles/Binary_Protocol.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Binary_Protocol.dir/build.make CMakeFiles/Binary_Protocol.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Binary_Protocol.dir/main.cpp.o.provides

CMakeFiles/Binary_Protocol.dir/main.cpp.o.provides.build: CMakeFiles/Binary_Protocol.dir/main.cpp.o


# Object files for target Binary_Protocol
Binary_Protocol_OBJECTS = \
"CMakeFiles/Binary_Protocol.dir/main.cpp.o"

# External object files for target Binary_Protocol
Binary_Protocol_EXTERNAL_OBJECTS =

Binary_Protocol: CMakeFiles/Binary_Protocol.dir/main.cpp.o
Binary_Protocol: CMakeFiles/Binary_Protocol.dir/build.make
Binary_Protocol: CMakeFiles/Binary_Protocol.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/phoenix/Next/Binary Protocol/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Binary_Protocol"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Binary_Protocol.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Binary_Protocol.dir/build: Binary_Protocol

.PHONY : CMakeFiles/Binary_Protocol.dir/build

CMakeFiles/Binary_Protocol.dir/requires: CMakeFiles/Binary_Protocol.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Binary_Protocol.dir/requires

CMakeFiles/Binary_Protocol.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Binary_Protocol.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Binary_Protocol.dir/clean

CMakeFiles/Binary_Protocol.dir/depend:
	cd "/home/phoenix/Next/Binary Protocol/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/phoenix/Next/Binary Protocol" "/home/phoenix/Next/Binary Protocol" "/home/phoenix/Next/Binary Protocol/cmake-build-debug" "/home/phoenix/Next/Binary Protocol/cmake-build-debug" "/home/phoenix/Next/Binary Protocol/cmake-build-debug/CMakeFiles/Binary_Protocol.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Binary_Protocol.dir/depend

