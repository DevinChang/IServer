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
CMAKE_SOURCE_DIR = /home/devinchang/Code/315Server/src/test/testTimeQueue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/devinchang/Code/315Server/src/test/testTimeQueue

# Include any dependencies generated for this target.
include CMakeFiles/TIMER.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TIMER.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TIMER.dir/flags.make

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o: CMakeFiles/TIMER.dir/flags.make
CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o: /home/devinchang/Code/315Server/src/utl/Thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testTimeQueue/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o -c /home/devinchang/Code/315Server/src/utl/Thread.cpp

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/Thread.cpp > CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.i

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/Thread.cpp -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.s

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o: CMakeFiles/TIMER.dir/flags.make
CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o: /home/devinchang/Code/315Server/src/utl/CurrentThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testTimeQueue/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o -c /home/devinchang/Code/315Server/src/utl/CurrentThread.cpp

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/CurrentThread.cpp > CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.i

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/CurrentThread.cpp -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.s

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o: CMakeFiles/TIMER.dir/flags.make
CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o: /home/devinchang/Code/315Server/src/utl/EventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testTimeQueue/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o -c /home/devinchang/Code/315Server/src/utl/EventLoop.cpp

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/EventLoop.cpp > CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.i

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/EventLoop.cpp -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.s

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.o: CMakeFiles/TIMER.dir/flags.make
CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.o: /home/devinchang/Code/315Server/src/utl/Channel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testTimeQueue/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.o -c /home/devinchang/Code/315Server/src/utl/Channel.cpp

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/Channel.cpp > CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.i

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/Channel.cpp -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.s

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.o: CMakeFiles/TIMER.dir/flags.make
CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.o: /home/devinchang/Code/315Server/src/utl/Poller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testTimeQueue/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.o -c /home/devinchang/Code/315Server/src/utl/Poller.cpp

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/Poller.cpp > CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.i

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/Poller.cpp -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.s

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.o: CMakeFiles/TIMER.dir/flags.make
CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.o: /home/devinchang/Code/315Server/src/utl/TimeStamp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testTimeQueue/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.o -c /home/devinchang/Code/315Server/src/utl/TimeStamp.cpp

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/TimeStamp.cpp > CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.i

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/TimeStamp.cpp -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.s

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.o: CMakeFiles/TIMER.dir/flags.make
CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.o: /home/devinchang/Code/315Server/src/utl/Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testTimeQueue/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.o -c /home/devinchang/Code/315Server/src/utl/Timer.cpp

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/Timer.cpp > CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.i

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/Timer.cpp -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.s

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.o: CMakeFiles/TIMER.dir/flags.make
CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.o: /home/devinchang/Code/315Server/src/utl/Timerld.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testTimeQueue/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.o -c /home/devinchang/Code/315Server/src/utl/Timerld.cpp

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/Timerld.cpp > CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.i

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/Timerld.cpp -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.s

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.o: CMakeFiles/TIMER.dir/flags.make
CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.o: /home/devinchang/Code/315Server/src/utl/TimerQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testTimeQueue/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.o -c /home/devinchang/Code/315Server/src/utl/TimerQueue.cpp

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/TimerQueue.cpp > CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.i

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/TimerQueue.cpp -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.s

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.o: CMakeFiles/TIMER.dir/flags.make
CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.o: /home/devinchang/Code/315Server/src/utl/Date.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testTimeQueue/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.o -c /home/devinchang/Code/315Server/src/utl/Date.cpp

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/Date.cpp > CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.i

CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/Date.cpp -o CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.s

CMakeFiles/TIMER.dir/testTimeQueue.cpp.o: CMakeFiles/TIMER.dir/flags.make
CMakeFiles/TIMER.dir/testTimeQueue.cpp.o: testTimeQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testTimeQueue/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/TIMER.dir/testTimeQueue.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIMER.dir/testTimeQueue.cpp.o -c /home/devinchang/Code/315Server/src/test/testTimeQueue/testTimeQueue.cpp

CMakeFiles/TIMER.dir/testTimeQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIMER.dir/testTimeQueue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/test/testTimeQueue/testTimeQueue.cpp > CMakeFiles/TIMER.dir/testTimeQueue.cpp.i

CMakeFiles/TIMER.dir/testTimeQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIMER.dir/testTimeQueue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/test/testTimeQueue/testTimeQueue.cpp -o CMakeFiles/TIMER.dir/testTimeQueue.cpp.s

# Object files for target TIMER
TIMER_OBJECTS = \
"CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o" \
"CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o" \
"CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o" \
"CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.o" \
"CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.o" \
"CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.o" \
"CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.o" \
"CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.o" \
"CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.o" \
"CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.o" \
"CMakeFiles/TIMER.dir/testTimeQueue.cpp.o"

# External object files for target TIMER
TIMER_EXTERNAL_OBJECTS =

TIMER: CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o
TIMER: CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o
TIMER: CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o
TIMER: CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.o
TIMER: CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.o
TIMER: CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.o
TIMER: CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.o
TIMER: CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.o
TIMER: CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.o
TIMER: CMakeFiles/TIMER.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.o
TIMER: CMakeFiles/TIMER.dir/testTimeQueue.cpp.o
TIMER: CMakeFiles/TIMER.dir/build.make
TIMER: CMakeFiles/TIMER.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/devinchang/Code/315Server/src/test/testTimeQueue/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable TIMER"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TIMER.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TIMER.dir/build: TIMER

.PHONY : CMakeFiles/TIMER.dir/build

CMakeFiles/TIMER.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TIMER.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TIMER.dir/clean

CMakeFiles/TIMER.dir/depend:
	cd /home/devinchang/Code/315Server/src/test/testTimeQueue && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/devinchang/Code/315Server/src/test/testTimeQueue /home/devinchang/Code/315Server/src/test/testTimeQueue /home/devinchang/Code/315Server/src/test/testTimeQueue /home/devinchang/Code/315Server/src/test/testTimeQueue /home/devinchang/Code/315Server/src/test/testTimeQueue/CMakeFiles/TIMER.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TIMER.dir/depend

