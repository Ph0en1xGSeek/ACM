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
CMAKE_SOURCE_DIR = "/home/phoenix/Next/Okabe and Boxes"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/phoenix/Next/Okabe and Boxes/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Okabe_and_Boxes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Okabe_and_Boxes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Okabe_and_Boxes.dir/flags.make

CMakeFiles/Okabe_and_Boxes.dir/main.cpp.o: CMakeFiles/Okabe_and_Boxes.dir/flags.make
CMakeFiles/Okabe_and_Boxes.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/phoenix/Next/Okabe and Boxes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Okabe_and_Boxes.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Okabe_and_Boxes.dir/main.cpp.o -c "/home/phoenix/Next/Okabe and Boxes/main.cpp"

CMakeFiles/Okabe_and_Boxes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Okabe_and_Boxes.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/phoenix/Next/Okabe and Boxes/main.cpp" > CMakeFiles/Okabe_and_Boxes.dir/main.cpp.i

CMakeFiles/Okabe_and_Boxes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Okabe_and_Boxes.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/phoenix/Next/Okabe and Boxes/main.cpp" -o CMakeFiles/Okabe_and_Boxes.dir/main.cpp.s

CMakeFiles/Okabe_and_Boxes.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Okabe_and_Boxes.dir/main.cpp.o.requires

CMakeFiles/Okabe_and_Boxes.dir/main.cpp.o.provides: CMakeFiles/Okabe_and_Boxes.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Okabe_and_Boxes.dir/build.make CMakeFiles/Okabe_and_Boxes.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Okabe_and_Boxes.dir/main.cpp.o.provides

CMakeFiles/Okabe_and_Boxes.dir/main.cpp.o.provides.build: CMakeFiles/Okabe_and_Boxes.dir/main.cpp.o


# Object files for target Okabe_and_Boxes
Okabe_and_Boxes_OBJECTS = \
"CMakeFiles/Okabe_and_Boxes.dir/main.cpp.o"

# External object files for target Okabe_and_Boxes
Okabe_and_Boxes_EXTERNAL_OBJECTS =

Okabe_and_Boxes: CMakeFiles/Okabe_and_Boxes.dir/main.cpp.o
Okabe_and_Boxes: CMakeFiles/Okabe_and_Boxes.dir/build.make
Okabe_and_Boxes: CMakeFiles/Okabe_and_Boxes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/phoenix/Next/Okabe and Boxes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Okabe_and_Boxes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Okabe_and_Boxes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Okabe_and_Boxes.dir/build: Okabe_and_Boxes

.PHONY : CMakeFiles/Okabe_and_Boxes.dir/build

CMakeFiles/Okabe_and_Boxes.dir/requires: CMakeFiles/Okabe_and_Boxes.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Okabe_and_Boxes.dir/requires

CMakeFiles/Okabe_and_Boxes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Okabe_and_Boxes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Okabe_and_Boxes.dir/clean

CMakeFiles/Okabe_and_Boxes.dir/depend:
	cd "/home/phoenix/Next/Okabe and Boxes/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/phoenix/Next/Okabe and Boxes" "/home/phoenix/Next/Okabe and Boxes" "/home/phoenix/Next/Okabe and Boxes/cmake-build-debug" "/home/phoenix/Next/Okabe and Boxes/cmake-build-debug" "/home/phoenix/Next/Okabe and Boxes/cmake-build-debug/CMakeFiles/Okabe_and_Boxes.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Okabe_and_Boxes.dir/depend

