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
include c15-address-used/CMakeFiles/addressused02.dir/depend.make

# Include the progress variables for this target.
include c15-address-used/CMakeFiles/addressused02.dir/progress.make

# Include the compile flags for this target's objects.
include c15-address-used/CMakeFiles/addressused02.dir/flags.make

c15-address-used/CMakeFiles/addressused02.dir/addressused02.c.o: c15-address-used/CMakeFiles/addressused02.dir/flags.make
c15-address-used/CMakeFiles/addressused02.dir/addressused02.c.o: ../c15-address-used/addressused02.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/inf/CLionProjects/network-coding/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object c15-address-used/CMakeFiles/addressused02.dir/addressused02.c.o"
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c15-address-used && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/addressused02.dir/addressused02.c.o -c /Users/inf/CLionProjects/network-coding/c15-address-used/addressused02.c

c15-address-used/CMakeFiles/addressused02.dir/addressused02.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/addressused02.dir/addressused02.c.i"
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c15-address-used && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/inf/CLionProjects/network-coding/c15-address-used/addressused02.c > CMakeFiles/addressused02.dir/addressused02.c.i

c15-address-used/CMakeFiles/addressused02.dir/addressused02.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/addressused02.dir/addressused02.c.s"
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c15-address-used && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/inf/CLionProjects/network-coding/c15-address-used/addressused02.c -o CMakeFiles/addressused02.dir/addressused02.c.s

# Object files for target addressused02
addressused02_OBJECTS = \
"CMakeFiles/addressused02.dir/addressused02.c.o"

# External object files for target addressused02
addressused02_EXTERNAL_OBJECTS =

bin/addressused02: c15-address-used/CMakeFiles/addressused02.dir/addressused02.c.o
bin/addressused02: c15-address-used/CMakeFiles/addressused02.dir/build.make
bin/addressused02: lib/libnetwork_coding.a
bin/addressused02: c15-address-used/CMakeFiles/addressused02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/inf/CLionProjects/network-coding/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/addressused02"
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c15-address-used && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/addressused02.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
c15-address-used/CMakeFiles/addressused02.dir/build: bin/addressused02

.PHONY : c15-address-used/CMakeFiles/addressused02.dir/build

c15-address-used/CMakeFiles/addressused02.dir/clean:
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug/c15-address-used && $(CMAKE_COMMAND) -P CMakeFiles/addressused02.dir/cmake_clean.cmake
.PHONY : c15-address-used/CMakeFiles/addressused02.dir/clean

c15-address-used/CMakeFiles/addressused02.dir/depend:
	cd /Users/inf/CLionProjects/network-coding/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/inf/CLionProjects/network-coding /Users/inf/CLionProjects/network-coding/c15-address-used /Users/inf/CLionProjects/network-coding/cmake-build-debug /Users/inf/CLionProjects/network-coding/cmake-build-debug/c15-address-used /Users/inf/CLionProjects/network-coding/cmake-build-debug/c15-address-used/CMakeFiles/addressused02.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : c15-address-used/CMakeFiles/addressused02.dir/depend

