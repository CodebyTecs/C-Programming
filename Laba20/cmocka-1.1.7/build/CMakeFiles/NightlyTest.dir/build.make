# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/build

# Utility rule file for NightlyTest.

# Include any custom commands dependencies for this target.
include CMakeFiles/NightlyTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/NightlyTest.dir/progress.make

CMakeFiles/NightlyTest:
	/opt/homebrew/bin/ctest -D NightlyTest

CMakeFiles/NightlyTest.dir/codegen:
.PHONY : CMakeFiles/NightlyTest.dir/codegen

NightlyTest: CMakeFiles/NightlyTest
NightlyTest: CMakeFiles/NightlyTest.dir/build.make
.PHONY : NightlyTest

# Rule to build all files generated by this target.
CMakeFiles/NightlyTest.dir/build: NightlyTest
.PHONY : CMakeFiles/NightlyTest.dir/build

CMakeFiles/NightlyTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NightlyTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NightlyTest.dir/clean

CMakeFiles/NightlyTest.dir/depend:
	cd /Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7 /Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7 /Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/build /Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/build /Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/build/CMakeFiles/NightlyTest.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/NightlyTest.dir/depend

