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
include c6-udp/CMakeFiles/udpserver.dir/depend.make

# Include the progress variables for this target.
include c6-udp/CMakeFiles/udpserver.dir/progress.make

# Include the compile flags for this target's objects.
include c6-udp/CMakeFiles/udpserver.dir/flags.make

c6-udp/CMakeFiles/udpserver.dir/udp_server.c.o: c6-udp/CMakeFiles/udpserver.dir/flags.make
c6-udp/CMakeFiles/udpserver.dir/udp_server.c.o: ../c6-udp/udp_server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/inf/CLionProjects/network-coding/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object c6-udp/CMakeFiles/udpserver.dir/udp_server.c.o"
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c6-udp && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/udpserver.dir/udp_server.c.o -c /Users/inf/CLionProjects/network-coding/c6-udp/udp_server.c

c6-udp/CMakeFiles/udpserver.dir/udp_server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udpserver.dir/udp_server.c.i"
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c6-udp && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/inf/CLionProjects/network-coding/c6-udp/udp_server.c > CMakeFiles/udpserver.dir/udp_server.c.i

c6-udp/CMakeFiles/udpserver.dir/udp_server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udpserver.dir/udp_server.c.s"
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c6-udp && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/inf/CLionProjects/network-coding/c6-udp/udp_server.c -o CMakeFiles/udpserver.dir/udp_server.c.s

# Object files for target udpserver
udpserver_OBJECTS = \
"CMakeFiles/udpserver.dir/udp_server.c.o"

# External object files for target udpserver
udpserver_EXTERNAL_OBJECTS =

bin/udpserver: c6-udp/CMakeFiles/udpserver.dir/udp_server.c.o
bin/udpserver: c6-udp/CMakeFiles/udpserver.dir/build.make
bin/udpserver: lib/libnetwork_coding.a
bin/udpserver: c6-udp/CMakeFiles/udpserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/inf/CLionProjects/network-coding/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/udpserver"
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c6-udp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udpserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
c6-udp/CMakeFiles/udpserver.dir/build: bin/udpserver

.PHONY : c6-udp/CMakeFiles/udpserver.dir/build

c6-udp/CMakeFiles/udpserver.dir/clean:
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c6-udp && $(CMAKE_COMMAND) -P CMakeFiles/udpserver.dir/cmake_clean.cmake
.PHONY : c6-udp/CMakeFiles/udpserver.dir/clean

c6-udp/CMakeFiles/udpserver.dir/depend:
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/inf/CLionProjects/network-coding /Users/inf/CLionProjects/network-coding/c6-udp /Users/inf/CLionProjects/network-coding/cmake-build-debug /Users/inf/CLionProjects/network-coding/cmake-build-debug/c6-udp /Users/inf/CLionProjects/network-coding/cmake-build-debug/c6-udp/CMakeFiles/udpserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : c6-udp/CMakeFiles/udpserver.dir/depend
