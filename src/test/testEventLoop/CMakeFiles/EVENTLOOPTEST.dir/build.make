# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/devinchang/anaconda3/bin/cmake

# The command to remove a file.
RM = /home/devinchang/anaconda3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/devinchang/Code/315Server/src/test/testEventLoop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/devinchang/Code/315Server/src/test/testEventLoop

# Include any dependencies generated for this target.
include CMakeFiles/EVENTLOOPTEST.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EVENTLOOPTEST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EVENTLOOPTEST.dir/flags.make

CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o: CMakeFiles/EVENTLOOPTEST.dir/flags.make
CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o: /home/devinchang/Code/315Server/src/utl/Thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testEventLoop/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o -c /home/devinchang/Code/315Server/src/utl/Thread.cpp

CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/Thread.cpp > CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.i

CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/Thread.cpp -o CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.s

CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o: CMakeFiles/EVENTLOOPTEST.dir/flags.make
CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o: /home/devinchang/Code/315Server/src/utl/CurrentThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testEventLoop/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o -c /home/devinchang/Code/315Server/src/utl/CurrentThread.cpp

CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/CurrentThread.cpp > CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.i

CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/CurrentThread.cpp -o CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.s

CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o: CMakeFiles/EVENTLOOPTEST.dir/flags.make
CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o: /home/devinchang/Code/315Server/src/utl/EventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testEventLoop/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o -c /home/devinchang/Code/315Server/src/utl/EventLoop.cpp

CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/EventLoop.cpp > CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.i

CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/EventLoop.cpp -o CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.s

CMakeFiles/EVENTLOOPTEST.dir/testEventLoop.cpp.o: CMakeFiles/EVENTLOOPTEST.dir/flags.make
CMakeFiles/EVENTLOOPTEST.dir/testEventLoop.cpp.o: testEventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testEventLoop/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/EVENTLOOPTEST.dir/testEventLoop.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EVENTLOOPTEST.dir/testEventLoop.cpp.o -c /home/devinchang/Code/315Server/src/test/testEventLoop/testEventLoop.cpp

CMakeFiles/EVENTLOOPTEST.dir/testEventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EVENTLOOPTEST.dir/testEventLoop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/test/testEventLoop/testEventLoop.cpp > CMakeFiles/EVENTLOOPTEST.dir/testEventLoop.cpp.i

CMakeFiles/EVENTLOOPTEST.dir/testEventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EVENTLOOPTEST.dir/testEventLoop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/test/testEventLoop/testEventLoop.cpp -o CMakeFiles/EVENTLOOPTEST.dir/testEventLoop.cpp.s

# Object files for target EVENTLOOPTEST
EVENTLOOPTEST_OBJECTS = \
"CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o" \
"CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o" \
"CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o" \
"CMakeFiles/EVENTLOOPTEST.dir/testEventLoop.cpp.o"

# External object files for target EVENTLOOPTEST
EVENTLOOPTEST_EXTERNAL_OBJECTS =

EVENTLOOPTEST: CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o
EVENTLOOPTEST: CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o
EVENTLOOPTEST: CMakeFiles/EVENTLOOPTEST.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o
EVENTLOOPTEST: CMakeFiles/EVENTLOOPTEST.dir/testEventLoop.cpp.o
EVENTLOOPTEST: CMakeFiles/EVENTLOOPTEST.dir/build.make
EVENTLOOPTEST: CMakeFiles/EVENTLOOPTEST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/devinchang/Code/315Server/src/test/testEventLoop/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable EVENTLOOPTEST"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EVENTLOOPTEST.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EVENTLOOPTEST.dir/build: EVENTLOOPTEST

.PHONY : CMakeFiles/EVENTLOOPTEST.dir/build

CMakeFiles/EVENTLOOPTEST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EVENTLOOPTEST.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EVENTLOOPTEST.dir/clean

CMakeFiles/EVENTLOOPTEST.dir/depend:
	cd /home/devinchang/Code/315Server/src/test/testEventLoop && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/devinchang/Code/315Server/src/test/testEventLoop /home/devinchang/Code/315Server/src/test/testEventLoop /home/devinchang/Code/315Server/src/test/testEventLoop /home/devinchang/Code/315Server/src/test/testEventLoop /home/devinchang/Code/315Server/src/test/testEventLoop/CMakeFiles/EVENTLOOPTEST.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EVENTLOOPTEST.dir/depend

