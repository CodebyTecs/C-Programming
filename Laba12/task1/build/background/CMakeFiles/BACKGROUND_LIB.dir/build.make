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
CMAKE_SOURCE_DIR = /Users/tecs/Documents/Codding/task1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tecs/Documents/Codding/task1/build

# Include any dependencies generated for this target.
include background/CMakeFiles/BACKGROUND_LIB.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include background/CMakeFiles/BACKGROUND_LIB.dir/compiler_depend.make

# Include the progress variables for this target.
include background/CMakeFiles/BACKGROUND_LIB.dir/progress.make

# Include the compile flags for this target's objects.
include background/CMakeFiles/BACKGROUND_LIB.dir/flags.make

background/CMakeFiles/BACKGROUND_LIB.dir/codegen:
.PHONY : background/CMakeFiles/BACKGROUND_LIB.dir/codegen

background/CMakeFiles/BACKGROUND_LIB.dir/background.c.o: background/CMakeFiles/BACKGROUND_LIB.dir/flags.make
background/CMakeFiles/BACKGROUND_LIB.dir/background.c.o: /Users/tecs/Documents/Codding/task1/background/background.c
background/CMakeFiles/BACKGROUND_LIB.dir/background.c.o: background/CMakeFiles/BACKGROUND_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/tecs/Documents/Codding/task1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object background/CMakeFiles/BACKGROUND_LIB.dir/background.c.o"
	cd /Users/tecs/Documents/Codding/task1/build/background && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT background/CMakeFiles/BACKGROUND_LIB.dir/background.c.o -MF CMakeFiles/BACKGROUND_LIB.dir/background.c.o.d -o CMakeFiles/BACKGROUND_LIB.dir/background.c.o -c /Users/tecs/Documents/Codding/task1/background/background.c

background/CMakeFiles/BACKGROUND_LIB.dir/background.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/BACKGROUND_LIB.dir/background.c.i"
	cd /Users/tecs/Documents/Codding/task1/build/background && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tecs/Documents/Codding/task1/background/background.c > CMakeFiles/BACKGROUND_LIB.dir/background.c.i

background/CMakeFiles/BACKGROUND_LIB.dir/background.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/BACKGROUND_LIB.dir/background.c.s"
	cd /Users/tecs/Documents/Codding/task1/build/background && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tecs/Documents/Codding/task1/background/background.c -o CMakeFiles/BACKGROUND_LIB.dir/background.c.s

# Object files for target BACKGROUND_LIB
BACKGROUND_LIB_OBJECTS = \
"CMakeFiles/BACKGROUND_LIB.dir/background.c.o"

# External object files for target BACKGROUND_LIB
BACKGROUND_LIB_EXTERNAL_OBJECTS =

background/libBACKGROUND_LIB.a: background/CMakeFiles/BACKGROUND_LIB.dir/background.c.o
background/libBACKGROUND_LIB.a: background/CMakeFiles/BACKGROUND_LIB.dir/build.make
background/libBACKGROUND_LIB.a: background/CMakeFiles/BACKGROUND_LIB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/tecs/Documents/Codding/task1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libBACKGROUND_LIB.a"
	cd /Users/tecs/Documents/Codding/task1/build/background && $(CMAKE_COMMAND) -P CMakeFiles/BACKGROUND_LIB.dir/cmake_clean_target.cmake
	cd /Users/tecs/Documents/Codding/task1/build/background && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BACKGROUND_LIB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
background/CMakeFiles/BACKGROUND_LIB.dir/build: background/libBACKGROUND_LIB.a
.PHONY : background/CMakeFiles/BACKGROUND_LIB.dir/build

background/CMakeFiles/BACKGROUND_LIB.dir/clean:
	cd /Users/tecs/Documents/Codding/task1/build/background && $(CMAKE_COMMAND) -P CMakeFiles/BACKGROUND_LIB.dir/cmake_clean.cmake
.PHONY : background/CMakeFiles/BACKGROUND_LIB.dir/clean

background/CMakeFiles/BACKGROUND_LIB.dir/depend:
	cd /Users/tecs/Documents/Codding/task1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tecs/Documents/Codding/task1 /Users/tecs/Documents/Codding/task1/background /Users/tecs/Documents/Codding/task1/build /Users/tecs/Documents/Codding/task1/build/background /Users/tecs/Documents/Codding/task1/build/background/CMakeFiles/BACKGROUND_LIB.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : background/CMakeFiles/BACKGROUND_LIB.dir/depend
