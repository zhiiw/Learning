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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhiiw/QT/ParkingLot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhiiw/QT/build-ParkingLot-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/mainwindow.cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mainwindow.cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mainwindow.cpp.dir/flags.make

CMakeFiles/mainwindow.cpp.dir/mainwindow.cpp_autogen/mocs_compilation.cpp.o: CMakeFiles/mainwindow.cpp.dir/flags.make
CMakeFiles/mainwindow.cpp.dir/mainwindow.cpp_autogen/mocs_compilation.cpp.o: mainwindow.cpp_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiiw/QT/build-ParkingLot-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mainwindow.cpp.dir/mainwindow.cpp_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mainwindow.cpp.dir/mainwindow.cpp_autogen/mocs_compilation.cpp.o -c /home/zhiiw/QT/build-ParkingLot-Desktop-Debug/mainwindow.cpp_autogen/mocs_compilation.cpp

CMakeFiles/mainwindow.cpp.dir/mainwindow.cpp_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainwindow.cpp.dir/mainwindow.cpp_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiiw/QT/build-ParkingLot-Desktop-Debug/mainwindow.cpp_autogen/mocs_compilation.cpp > CMakeFiles/mainwindow.cpp.dir/mainwindow.cpp_autogen/mocs_compilation.cpp.i

CMakeFiles/mainwindow.cpp.dir/mainwindow.cpp_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainwindow.cpp.dir/mainwindow.cpp_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiiw/QT/build-ParkingLot-Desktop-Debug/mainwindow.cpp_autogen/mocs_compilation.cpp -o CMakeFiles/mainwindow.cpp.dir/mainwindow.cpp_autogen/mocs_compilation.cpp.s

# Object files for target mainwindow.cpp
mainwindow_cpp_OBJECTS = \
"CMakeFiles/mainwindow.cpp.dir/mainwindow.cpp_autogen/mocs_compilation.cpp.o"

# External object files for target mainwindow.cpp
mainwindow_cpp_EXTERNAL_OBJECTS =

libmainwindow.cpp.a: CMakeFiles/mainwindow.cpp.dir/mainwindow.cpp_autogen/mocs_compilation.cpp.o
libmainwindow.cpp.a: CMakeFiles/mainwindow.cpp.dir/build.make
libmainwindow.cpp.a: CMakeFiles/mainwindow.cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhiiw/QT/build-ParkingLot-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmainwindow.cpp.a"
	$(CMAKE_COMMAND) -P CMakeFiles/mainwindow.cpp.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mainwindow.cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mainwindow.cpp.dir/build: libmainwindow.cpp.a

.PHONY : CMakeFiles/mainwindow.cpp.dir/build

CMakeFiles/mainwindow.cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mainwindow.cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mainwindow.cpp.dir/clean

CMakeFiles/mainwindow.cpp.dir/depend:
	cd /home/zhiiw/QT/build-ParkingLot-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhiiw/QT/ParkingLot /home/zhiiw/QT/ParkingLot /home/zhiiw/QT/build-ParkingLot-Desktop-Debug /home/zhiiw/QT/build-ParkingLot-Desktop-Debug /home/zhiiw/QT/build-ParkingLot-Desktop-Debug/CMakeFiles/mainwindow.cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mainwindow.cpp.dir/depend

