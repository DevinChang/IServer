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
CMAKE_SOURCE_DIR = /home/devinchang/Code/315Server/src/test/testNet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/devinchang/Code/315Server/src/test/testNet

# Include any dependencies generated for this target.
include CMakeFiles/Acceptor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Acceptor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Acceptor.dir/flags.make

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o: CMakeFiles/Acceptor.dir/flags.make
CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o: /home/devinchang/Code/315Server/src/utl/Thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testNet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o -c /home/devinchang/Code/315Server/src/utl/Thread.cpp

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/Thread.cpp > CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.i

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/Thread.cpp -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.s

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o: CMakeFiles/Acceptor.dir/flags.make
CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o: /home/devinchang/Code/315Server/src/utl/CurrentThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testNet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o -c /home/devinchang/Code/315Server/src/utl/CurrentThread.cpp

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/CurrentThread.cpp > CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.i

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/CurrentThread.cpp -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.s

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o: CMakeFiles/Acceptor.dir/flags.make
CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o: /home/devinchang/Code/315Server/src/utl/EventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testNet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o -c /home/devinchang/Code/315Server/src/utl/EventLoop.cpp

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/EventLoop.cpp > CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.i

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/EventLoop.cpp -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.s

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.o: CMakeFiles/Acceptor.dir/flags.make
CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.o: /home/devinchang/Code/315Server/src/utl/Channel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testNet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.o -c /home/devinchang/Code/315Server/src/utl/Channel.cpp

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/Channel.cpp > CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.i

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/Channel.cpp -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.s

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.o: CMakeFiles/Acceptor.dir/flags.make
CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.o: /home/devinchang/Code/315Server/src/utl/Poller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testNet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.o -c /home/devinchang/Code/315Server/src/utl/Poller.cpp

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/Poller.cpp > CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.i

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/Poller.cpp -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.s

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.o: CMakeFiles/Acceptor.dir/flags.make
CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.o: /home/devinchang/Code/315Server/src/utl/TimeStamp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testNet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.o -c /home/devinchang/Code/315Server/src/utl/TimeStamp.cpp

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/TimeStamp.cpp > CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.i

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/TimeStamp.cpp -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.s

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.o: CMakeFiles/Acceptor.dir/flags.make
CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.o: /home/devinchang/Code/315Server/src/utl/Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testNet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.o -c /home/devinchang/Code/315Server/src/utl/Timer.cpp

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/Timer.cpp > CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.i

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/Timer.cpp -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.s

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.o: CMakeFiles/Acceptor.dir/flags.make
CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.o: /home/devinchang/Code/315Server/src/utl/Timerld.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testNet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.o -c /home/devinchang/Code/315Server/src/utl/Timerld.cpp

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/Timerld.cpp > CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.i

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/Timerld.cpp -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.s

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.o: CMakeFiles/Acceptor.dir/flags.make
CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.o: /home/devinchang/Code/315Server/src/utl/TimerQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testNet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.o -c /home/devinchang/Code/315Server/src/utl/TimerQueue.cpp

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/TimerQueue.cpp > CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.i

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/TimerQueue.cpp -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.s

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.o: CMakeFiles/Acceptor.dir/flags.make
CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.o: /home/devinchang/Code/315Server/src/utl/Date.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testNet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.o -c /home/devinchang/Code/315Server/src/utl/Date.cpp

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/Date.cpp > CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.i

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/Date.cpp -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.s

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Mutex.cpp.o: CMakeFiles/Acceptor.dir/flags.make
CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Mutex.cpp.o: /home/devinchang/Code/315Server/src/utl/Mutex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testNet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Mutex.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Mutex.cpp.o -c /home/devinchang/Code/315Server/src/utl/Mutex.cpp

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Mutex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Mutex.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/Mutex.cpp > CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Mutex.cpp.i

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Mutex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Mutex.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/Mutex.cpp -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Mutex.cpp.s

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/InetAddress.cpp.o: CMakeFiles/Acceptor.dir/flags.make
CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/InetAddress.cpp.o: /home/devinchang/Code/315Server/src/utl/InetAddress.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testNet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/InetAddress.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/InetAddress.cpp.o -c /home/devinchang/Code/315Server/src/utl/InetAddress.cpp

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/InetAddress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/InetAddress.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/InetAddress.cpp > CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/InetAddress.cpp.i

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/InetAddress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/InetAddress.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/InetAddress.cpp -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/InetAddress.cpp.s

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Socket.cpp.o: CMakeFiles/Acceptor.dir/flags.make
CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Socket.cpp.o: /home/devinchang/Code/315Server/src/utl/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testNet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Socket.cpp.o -c /home/devinchang/Code/315Server/src/utl/Socket.cpp

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/Socket.cpp > CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Socket.cpp.i

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/Socket.cpp -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Socket.cpp.s

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Acceptor.cpp.o: CMakeFiles/Acceptor.dir/flags.make
CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Acceptor.cpp.o: /home/devinchang/Code/315Server/src/utl/Acceptor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testNet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Acceptor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Acceptor.cpp.o -c /home/devinchang/Code/315Server/src/utl/Acceptor.cpp

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Acceptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Acceptor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/utl/Acceptor.cpp > CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Acceptor.cpp.i

CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Acceptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Acceptor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/utl/Acceptor.cpp -o CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Acceptor.cpp.s

CMakeFiles/Acceptor.dir/testAccept.cpp.o: CMakeFiles/Acceptor.dir/flags.make
CMakeFiles/Acceptor.dir/testAccept.cpp.o: testAccept.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/315Server/src/test/testNet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Acceptor.dir/testAccept.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Acceptor.dir/testAccept.cpp.o -c /home/devinchang/Code/315Server/src/test/testNet/testAccept.cpp

CMakeFiles/Acceptor.dir/testAccept.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Acceptor.dir/testAccept.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/315Server/src/test/testNet/testAccept.cpp > CMakeFiles/Acceptor.dir/testAccept.cpp.i

CMakeFiles/Acceptor.dir/testAccept.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Acceptor.dir/testAccept.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/315Server/src/test/testNet/testAccept.cpp -o CMakeFiles/Acceptor.dir/testAccept.cpp.s

# Object files for target Acceptor
Acceptor_OBJECTS = \
"CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o" \
"CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o" \
"CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o" \
"CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.o" \
"CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.o" \
"CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.o" \
"CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.o" \
"CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.o" \
"CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.o" \
"CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.o" \
"CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Mutex.cpp.o" \
"CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/InetAddress.cpp.o" \
"CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Socket.cpp.o" \
"CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Acceptor.cpp.o" \
"CMakeFiles/Acceptor.dir/testAccept.cpp.o"

# External object files for target Acceptor
Acceptor_EXTERNAL_OBJECTS =

Acceptor: CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Thread.cpp.o
Acceptor: CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/CurrentThread.cpp.o
Acceptor: CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/EventLoop.cpp.o
Acceptor: CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Channel.cpp.o
Acceptor: CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Poller.cpp.o
Acceptor: CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimeStamp.cpp.o
Acceptor: CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timer.cpp.o
Acceptor: CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Timerld.cpp.o
Acceptor: CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/TimerQueue.cpp.o
Acceptor: CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Date.cpp.o
Acceptor: CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Mutex.cpp.o
Acceptor: CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/InetAddress.cpp.o
Acceptor: CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Socket.cpp.o
Acceptor: CMakeFiles/Acceptor.dir/home/devinchang/Code/315Server/src/utl/Acceptor.cpp.o
Acceptor: CMakeFiles/Acceptor.dir/testAccept.cpp.o
Acceptor: CMakeFiles/Acceptor.dir/build.make
Acceptor: CMakeFiles/Acceptor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/devinchang/Code/315Server/src/test/testNet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable Acceptor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Acceptor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Acceptor.dir/build: Acceptor

.PHONY : CMakeFiles/Acceptor.dir/build

CMakeFiles/Acceptor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Acceptor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Acceptor.dir/clean

CMakeFiles/Acceptor.dir/depend:
	cd /home/devinchang/Code/315Server/src/test/testNet && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/devinchang/Code/315Server/src/test/testNet /home/devinchang/Code/315Server/src/test/testNet /home/devinchang/Code/315Server/src/test/testNet /home/devinchang/Code/315Server/src/test/testNet /home/devinchang/Code/315Server/src/test/testNet/CMakeFiles/Acceptor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Acceptor.dir/depend

