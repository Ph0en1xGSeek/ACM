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
CMAKE_SOURCE_DIR = "/home/phoenix/Next/Mister B and Book Reading"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/phoenix/Next/Mister B and Book Reading/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Mister_B_and_Book_Reading.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Mister_B_and_Book_Reading.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Mister_B_and_Book_Reading.dir/flags.make

CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.o: CMakeFiles/Mister_B_and_Book_Reading.dir/flags.make
CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/phoenix/Next/Mister B and Book Reading/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.o -c "/home/phoenix/Next/Mister B and Book Reading/main.cpp"

CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/phoenix/Next/Mister B and Book Reading/main.cpp" > CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.i

CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/phoenix/Next/Mister B and Book Reading/main.cpp" -o CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.s

CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.o.requires

CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.o.provides: CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Mister_B_and_Book_Reading.dir/build.make CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.o.provides

CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.o.provides.build: CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.o


# Object files for target Mister_B_and_Book_Reading
Mister_B_and_Book_Reading_OBJECTS = \
"CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.o"

# External object files for target Mister_B_and_Book_Reading
Mister_B_and_Book_Reading_EXTERNAL_OBJECTS =

Mister_B_and_Book_Reading: CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.o
Mister_B_and_Book_Reading: CMakeFiles/Mister_B_and_Book_Reading.dir/build.make
Mister_B_and_Book_Reading: CMakeFiles/Mister_B_and_Book_Reading.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/phoenix/Next/Mister B and Book Reading/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Mister_B_and_Book_Reading"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Mister_B_and_Book_Reading.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Mister_B_and_Book_Reading.dir/build: Mister_B_and_Book_Reading

.PHONY : CMakeFiles/Mister_B_and_Book_Reading.dir/build

CMakeFiles/Mister_B_and_Book_Reading.dir/requires: CMakeFiles/Mister_B_and_Book_Reading.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Mister_B_and_Book_Reading.dir/requires

CMakeFiles/Mister_B_and_Book_Reading.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Mister_B_and_Book_Reading.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Mister_B_and_Book_Reading.dir/clean

CMakeFiles/Mister_B_and_Book_Reading.dir/depend:
	cd "/home/phoenix/Next/Mister B and Book Reading/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/phoenix/Next/Mister B and Book Reading" "/home/phoenix/Next/Mister B and Book Reading" "/home/phoenix/Next/Mister B and Book Reading/cmake-build-debug" "/home/phoenix/Next/Mister B and Book Reading/cmake-build-debug" "/home/phoenix/Next/Mister B and Book Reading/cmake-build-debug/CMakeFiles/Mister_B_and_Book_Reading.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Mister_B_and_Book_Reading.dir/depend
