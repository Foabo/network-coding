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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/inf/CLionProjects/network-coding

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/inf/CLionProjects/network-coding/cmake-build-debug

# Include any dependencies generated for this target.
include c4/CMakeFiles/make_sock.dir/depend.make

# Include the progress variables for this target.
include c4/CMakeFiles/make_sock.dir/progress.make

# Include the compile flags for this target's objects.
include c4/CMakeFiles/make_sock.dir/flags.make

c4/CMakeFiles/make_sock.dir/make_sock.c.o: c4/CMakeFiles/make_sock.dir/flags.make
c4/CMakeFiles/make_sock.dir/make_sock.c.o: ../c4/make_sock.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/inf/CLionProjects/network-coding/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object c4/CMakeFiles/make_sock.dir/make_sock.c.o"
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c4 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/make_sock.dir/make_sock.c.o -c /Users/inf/CLionProjects/network-coding/c4/make_sock.c

c4/CMakeFiles/make_sock.dir/make_sock.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/make_sock.dir/make_sock.c.i"
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c4 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/inf/CLionProjects/network-coding/c4/make_sock.c > CMakeFiles/make_sock.dir/make_sock.c.i

c4/CMakeFiles/make_sock.dir/make_sock.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/make_sock.dir/make_sock.c.s"
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c4 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/inf/CLionProjects/network-coding/c4/make_sock.c -o CMakeFiles/make_sock.dir/make_sock.c.s

# Object files for target make_sock
make_sock_OBJECTS = \
"CMakeFiles/make_sock.dir/make_sock.c.o"

# External object files for target make_sock
make_sock_EXTERNAL_OBJECTS =

bin/make_sock: c4/CMakeFiles/make_sock.dir/make_sock.c.o
bin/make_sock: c4/CMakeFiles/make_sock.dir/build.make
bin/make_sock: lib/libnetwork_coding.a
bin/make_sock: c4/CMakeFiles/make_sock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/inf/CLionProjects/network-coding/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/make_sock"
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c4 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/make_sock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
c4/CMakeFiles/make_sock.dir/build: bin/make_sock

.PHONY : c4/CMakeFiles/make_sock.dir/build

c4/CMakeFiles/make_sock.dir/clean:
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c4 && $(CMAKE_COMMAND) -P CMakeFiles/make_sock.dir/cmake_clean.cmake
.PHONY : c4/CMakeFiles/make_sock.dir/clean

c4/CMakeFiles/make_sock.dir/depend:
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/inf/CLionProjects/network-coding /Users/inf/CLionProjects/network-coding/c4 /Users/inf/CLionProjects/network-coding/cmake-build-debug /Users/inf/CLionProjects/network-coding/cmake-build-debug/c4 /Users/inf/CLionProjects/network-coding/cmake-build-debug/c4/CMakeFiles/make_sock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : c4/CMakeFiles/make_sock.dir/depend
