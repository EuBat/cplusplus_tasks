# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/macbook/code/cplusplus/task7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/macbook/code/cplusplus/task7/release

# Include any dependencies generated for this target.
include CMakeFiles/task7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task7.dir/flags.make

CMakeFiles/task7.dir/matrix.cpp.o: CMakeFiles/task7.dir/flags.make
CMakeFiles/task7.dir/matrix.cpp.o: ../matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/macbook/code/cplusplus/task7/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task7.dir/matrix.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task7.dir/matrix.cpp.o -c /Users/macbook/code/cplusplus/task7/matrix.cpp

CMakeFiles/task7.dir/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task7.dir/matrix.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbook/code/cplusplus/task7/matrix.cpp > CMakeFiles/task7.dir/matrix.cpp.i

CMakeFiles/task7.dir/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task7.dir/matrix.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbook/code/cplusplus/task7/matrix.cpp -o CMakeFiles/task7.dir/matrix.cpp.s

# Object files for target task7
task7_OBJECTS = \
"CMakeFiles/task7.dir/matrix.cpp.o"

# External object files for target task7
task7_EXTERNAL_OBJECTS =

task7: CMakeFiles/task7.dir/matrix.cpp.o
task7: CMakeFiles/task7.dir/build.make
task7: CMakeFiles/task7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/macbook/code/cplusplus/task7/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task7.dir/build: task7

.PHONY : CMakeFiles/task7.dir/build

CMakeFiles/task7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task7.dir/clean

CMakeFiles/task7.dir/depend:
	cd /Users/macbook/code/cplusplus/task7/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/macbook/code/cplusplus/task7 /Users/macbook/code/cplusplus/task7 /Users/macbook/code/cplusplus/task7/release /Users/macbook/code/cplusplus/task7/release /Users/macbook/code/cplusplus/task7/release/CMakeFiles/task7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task7.dir/depend

