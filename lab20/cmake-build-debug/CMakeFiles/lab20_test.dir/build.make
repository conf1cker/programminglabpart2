# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/clion/152/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/152/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sascha/Programing/lab20

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sascha/Programing/lab20/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab20_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab20_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab20_test.dir/flags.make

CMakeFiles/lab20_test.dir/test/test.c.o: CMakeFiles/lab20_test.dir/flags.make
CMakeFiles/lab20_test.dir/test/test.c.o: ../test/test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sascha/Programing/lab20/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab20_test.dir/test/test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab20_test.dir/test/test.c.o -c /home/sascha/Programing/lab20/test/test.c

CMakeFiles/lab20_test.dir/test/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab20_test.dir/test/test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sascha/Programing/lab20/test/test.c > CMakeFiles/lab20_test.dir/test/test.c.i

CMakeFiles/lab20_test.dir/test/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab20_test.dir/test/test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sascha/Programing/lab20/test/test.c -o CMakeFiles/lab20_test.dir/test/test.c.s

CMakeFiles/lab20_test.dir/src/list.c.o: CMakeFiles/lab20_test.dir/flags.make
CMakeFiles/lab20_test.dir/src/list.c.o: ../src/list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sascha/Programing/lab20/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab20_test.dir/src/list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab20_test.dir/src/list.c.o -c /home/sascha/Programing/lab20/src/list.c

CMakeFiles/lab20_test.dir/src/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab20_test.dir/src/list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sascha/Programing/lab20/src/list.c > CMakeFiles/lab20_test.dir/src/list.c.i

CMakeFiles/lab20_test.dir/src/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab20_test.dir/src/list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sascha/Programing/lab20/src/list.c -o CMakeFiles/lab20_test.dir/src/list.c.s

CMakeFiles/lab20_test.dir/src/guitar.c.o: CMakeFiles/lab20_test.dir/flags.make
CMakeFiles/lab20_test.dir/src/guitar.c.o: ../src/guitar.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sascha/Programing/lab20/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lab20_test.dir/src/guitar.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab20_test.dir/src/guitar.c.o -c /home/sascha/Programing/lab20/src/guitar.c

CMakeFiles/lab20_test.dir/src/guitar.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab20_test.dir/src/guitar.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sascha/Programing/lab20/src/guitar.c > CMakeFiles/lab20_test.dir/src/guitar.c.i

CMakeFiles/lab20_test.dir/src/guitar.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab20_test.dir/src/guitar.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sascha/Programing/lab20/src/guitar.c -o CMakeFiles/lab20_test.dir/src/guitar.c.s

# Object files for target lab20_test
lab20_test_OBJECTS = \
"CMakeFiles/lab20_test.dir/test/test.c.o" \
"CMakeFiles/lab20_test.dir/src/list.c.o" \
"CMakeFiles/lab20_test.dir/src/guitar.c.o"

# External object files for target lab20_test
lab20_test_EXTERNAL_OBJECTS =

lab20_test: CMakeFiles/lab20_test.dir/test/test.c.o
lab20_test: CMakeFiles/lab20_test.dir/src/list.c.o
lab20_test: CMakeFiles/lab20_test.dir/src/guitar.c.o
lab20_test: CMakeFiles/lab20_test.dir/build.make
lab20_test: CMakeFiles/lab20_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sascha/Programing/lab20/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable lab20_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab20_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab20_test.dir/build: lab20_test

.PHONY : CMakeFiles/lab20_test.dir/build

CMakeFiles/lab20_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab20_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab20_test.dir/clean

CMakeFiles/lab20_test.dir/depend:
	cd /home/sascha/Programing/lab20/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sascha/Programing/lab20 /home/sascha/Programing/lab20 /home/sascha/Programing/lab20/cmake-build-debug /home/sascha/Programing/lab20/cmake-build-debug /home/sascha/Programing/lab20/cmake-build-debug/CMakeFiles/lab20_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab20_test.dir/depend

