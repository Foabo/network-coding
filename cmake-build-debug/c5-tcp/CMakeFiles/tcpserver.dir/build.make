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
include c5-tcp/CMakeFiles/tcpserver.dir/depend.make

# Include the progress variables for this target.
include c5-tcp/CMakeFiles/tcpserver.dir/progress.make

# Include the compile flags for this target's objects.
include c5-tcp/CMakeFiles/tcpserver.dir/flags.make

c5-tcp/CMakeFiles/tcpserver.dir/tcp_server.c.o: c5-tcp/CMakeFiles/tcpserver.dir/flags.make
c5-tcp/CMakeFiles/tcpserver.dir/tcp_server.c.o: ../c5-tcp/tcp_server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/inf/CLionProjects/network-coding/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object c5-tcp/CMakeFiles/tcpserver.dir/tcp_server.c.o"
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c5-tcp && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tcpserver.dir/tcp_server.c.o -c /Users/inf/CLionProjects/network-coding/c5-tcp/tcp_server.c

c5-tcp/CMakeFiles/tcpserver.dir/tcp_server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tcpserver.dir/tcp_server.c.i"
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c5-tcp && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/inf/CLionProjects/network-coding/c5-tcp/tcp_server.c > CMakeFiles/tcpserver.dir/tcp_server.c.i

c5-tcp/CMakeFiles/tcpserver.dir/tcp_server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tcpserver.dir/tcp_server.c.s"
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c5-tcp && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/inf/CLionProjects/network-coding/c5-tcp/tcp_server.c -o CMakeFiles/tcpserver.dir/tcp_server.c.s

# Object files for target tcpserver
tcpserver_OBJECTS = \
"CMakeFiles/tcpserver.dir/tcp_server.c.o"

# External object files for target tcpserver
tcpserver_EXTERNAL_OBJECTS =

bin/tcpserver: c5-tcp/CMakeFiles/tcpserver.dir/tcp_server.c.o
bin/tcpserver: c5-tcp/CMakeFiles/tcpserver.dir/build.make
bin/tcpserver: lib/libnetwork_coding.a
bin/tcpserver: c5-tcp/CMakeFiles/tcpserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/inf/CLionProjects/network-coding/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/tcpserver"
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c5-tcp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tcpserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
c5-tcp/CMakeFiles/tcpserver.dir/build: bin/tcpserver

.PHONY : c5-tcp/CMakeFiles/tcpserver.dir/build

c5-tcp/CMakeFiles/tcpserver.dir/clean:
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c5-tcp && $(CMAKE_COMMAND) -P CMakeFiles/tcpserver.dir/cmake_clean.cmake
.PHONY : c5-tcp/CMakeFiles/tcpserver.dir/clean

c5-tcp/CMakeFiles/tcpserver.dir/depend:
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/inf/CLionProjects/network-coding /Users/inf/CLionProjects/network-coding/c5-tcp /Users/inf/CLionProjects/network-coding/cmake-build-debug /Users/inf/CLionProjects/network-coding/cmake-build-debug/c5-tcp /Users/inf/CLionProjects/network-coding/cmake-build-debug/c5-tcp/CMakeFiles/tcpserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : c5-tcp/CMakeFiles/tcpserver.dir/depend

