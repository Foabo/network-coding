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
include CMakeFiles/udp_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/udp_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/udp_server.dir/flags.make

CMakeFiles/udp_server.dir/c6-udp/udp_server.c.o: CMakeFiles/udp_server.dir/flags.make
CMakeFiles/udp_server.dir/c6-udp/udp_server.c.o: ../c6-udp/udp_server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/inf/CLionProjects/network-coding/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/udp_server.dir/c6-udp/udp_server.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/udp_server.dir/c6-udp/udp_server.c.o -c /Users/inf/CLionProjects/network-coding/c6-udp/udp_server.c

CMakeFiles/udp_server.dir/c6-udp/udp_server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_server.dir/c6-udp/udp_server.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/inf/CLionProjects/network-coding/c6-udp/udp_server.c > CMakeFiles/udp_server.dir/c6-udp/udp_server.c.i

CMakeFiles/udp_server.dir/c6-udp/udp_server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_server.dir/c6-udp/udp_server.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/inf/CLionProjects/network-coding/c6-udp/udp_server.c -o CMakeFiles/udp_server.dir/c6-udp/udp_server.c.s

# Object files for target udp_server
udp_server_OBJECTS = \
"CMakeFiles/udp_server.dir/c6-udp/udp_server.c.o"

# External object files for target udp_server
udp_server_EXTERNAL_OBJECTS =

bin/udp_server: CMakeFiles/udp_server.dir/c6-udp/udp_server.c.o
bin/udp_server: CMakeFiles/udp_server.dir/build.make
bin/udp_server: CMakeFiles/udp_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/inf/CLionProjects/network-coding/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/udp_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udp_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/udp_server.dir/build: bin/udp_server

.PHONY : CMakeFiles/udp_server.dir/build

CMakeFiles/udp_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/udp_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/udp_server.dir/clean

CMakeFiles/udp_server.dir/depend:
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/inf/CLionProjects/network-coding /Users/inf/CLionProjects/network-coding /Users/inf/CLionProjects/network-coding/cmake-build-debug /Users/inf/CLionProjects/network-coding/cmake-build-debug /Users/inf/CLionProjects/network-coding/cmake-build-debug/CMakeFiles/udp_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/udp_server.dir/depend
