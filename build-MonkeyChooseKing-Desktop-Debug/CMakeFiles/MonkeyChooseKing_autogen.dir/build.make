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
CMAKE_SOURCE_DIR = /home/zhiiw/QT/MonkeyChooseKing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhiiw/QT/build-MonkeyChooseKing-Desktop-Debug

# Utility rule file for MonkeyChooseKing_autogen.

# Include the progress variables for this target.
include CMakeFiles/MonkeyChooseKing_autogen.dir/progress.make

CMakeFiles/MonkeyChooseKing_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zhiiw/QT/build-MonkeyChooseKing-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target MonkeyChooseKing"
	/usr/bin/cmake -E cmake_autogen /home/zhiiw/QT/build-MonkeyChooseKing-Desktop-Debug/CMakeFiles/MonkeyChooseKing_autogen.dir/AutogenInfo.json Debug

MonkeyChooseKing_autogen: CMakeFiles/MonkeyChooseKing_autogen
MonkeyChooseKing_autogen: CMakeFiles/MonkeyChooseKing_autogen.dir/build.make

.PHONY : MonkeyChooseKing_autogen

# Rule to build all files generated by this target.
CMakeFiles/MonkeyChooseKing_autogen.dir/build: MonkeyChooseKing_autogen

.PHONY : CMakeFiles/MonkeyChooseKing_autogen.dir/build

CMakeFiles/MonkeyChooseKing_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MonkeyChooseKing_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MonkeyChooseKing_autogen.dir/clean

CMakeFiles/MonkeyChooseKing_autogen.dir/depend:
	cd /home/zhiiw/QT/build-MonkeyChooseKing-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhiiw/QT/MonkeyChooseKing /home/zhiiw/QT/MonkeyChooseKing /home/zhiiw/QT/build-MonkeyChooseKing-Desktop-Debug /home/zhiiw/QT/build-MonkeyChooseKing-Desktop-Debug /home/zhiiw/QT/build-MonkeyChooseKing-Desktop-Debug/CMakeFiles/MonkeyChooseKing_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MonkeyChooseKing_autogen.dir/depend

