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
CMAKE_SOURCE_DIR = "/home/phoenix/Next/I'm bored with life"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/phoenix/Next/I'm bored with life/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/I_m_bored_with_life.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/I_m_bored_with_life.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/I_m_bored_with_life.dir/flags.make

CMakeFiles/I_m_bored_with_life.dir/main.cpp.o: CMakeFiles/I_m_bored_with_life.dir/flags.make
CMakeFiles/I_m_bored_with_life.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/phoenix/Next/I'm bored with life/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/I_m_bored_with_life.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/I_m_bored_with_life.dir/main.cpp.o -c "/home/phoenix/Next/I'm bored with life/main.cpp"

CMakeFiles/I_m_bored_with_life.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/I_m_bored_with_life.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/phoenix/Next/I'm bored with life/main.cpp" > CMakeFiles/I_m_bored_with_life.dir/main.cpp.i

CMakeFiles/I_m_bored_with_life.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/I_m_bored_with_life.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/phoenix/Next/I'm bored with life/main.cpp" -o CMakeFiles/I_m_bored_with_life.dir/main.cpp.s

CMakeFiles/I_m_bored_with_life.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/I_m_bored_with_life.dir/main.cpp.o.requires

CMakeFiles/I_m_bored_with_life.dir/main.cpp.o.provides: CMakeFiles/I_m_bored_with_life.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/I_m_bored_with_life.dir/build.make CMakeFiles/I_m_bored_with_life.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/I_m_bored_with_life.dir/main.cpp.o.provides

CMakeFiles/I_m_bored_with_life.dir/main.cpp.o.provides.build: CMakeFiles/I_m_bored_with_life.dir/main.cpp.o


# Object files for target I_m_bored_with_life
I_m_bored_with_life_OBJECTS = \
"CMakeFiles/I_m_bored_with_life.dir/main.cpp.o"

# External object files for target I_m_bored_with_life
I_m_bored_with_life_EXTERNAL_OBJECTS =

I_m_bored_with_life: CMakeFiles/I_m_bored_with_life.dir/main.cpp.o
I_m_bored_with_life: CMakeFiles/I_m_bored_with_life.dir/build.make
I_m_bored_with_life: CMakeFiles/I_m_bored_with_life.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/phoenix/Next/I'm bored with life/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable I_m_bored_with_life"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/I_m_bored_with_life.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/I_m_bored_with_life.dir/build: I_m_bored_with_life

.PHONY : CMakeFiles/I_m_bored_with_life.dir/build

CMakeFiles/I_m_bored_with_life.dir/requires: CMakeFiles/I_m_bored_with_life.dir/main.cpp.o.requires

.PHONY : CMakeFiles/I_m_bored_with_life.dir/requires

CMakeFiles/I_m_bored_with_life.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/I_m_bored_with_life.dir/cmake_clean.cmake
.PHONY : CMakeFiles/I_m_bored_with_life.dir/clean

CMakeFiles/I_m_bored_with_life.dir/depend:
	cd "/home/phoenix/Next/I'm bored with life/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/phoenix/Next/I'm bored with life" "/home/phoenix/Next/I'm bored with life" "/home/phoenix/Next/I'm bored with life/cmake-build-debug" "/home/phoenix/Next/I'm bored with life/cmake-build-debug" "/home/phoenix/Next/I'm bored with life/cmake-build-debug/CMakeFiles/I_m_bored_with_life.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/I_m_bored_with_life.dir/depend

