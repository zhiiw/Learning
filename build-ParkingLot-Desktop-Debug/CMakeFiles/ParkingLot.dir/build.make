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
include CMakeFiles/ParkingLot.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ParkingLot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ParkingLot.dir/flags.make

ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp: /home/zhiiw/QT/ParkingLot/test.qrc
ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp: CMakeFiles/ParkingLot_autogen.dir/AutoRcc_test_EWIEGA46WW_Info.json
ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp: /usr/bin/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zhiiw/QT/build-ParkingLot-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for test.qrc"
	/usr/bin/cmake -E cmake_autorcc /home/zhiiw/QT/build-ParkingLot-Desktop-Debug/CMakeFiles/ParkingLot_autogen.dir/AutoRcc_test_EWIEGA46WW_Info.json Debug

CMakeFiles/ParkingLot.dir/ParkingLot_autogen/mocs_compilation.cpp.o: CMakeFiles/ParkingLot.dir/flags.make
CMakeFiles/ParkingLot.dir/ParkingLot_autogen/mocs_compilation.cpp.o: ParkingLot_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiiw/QT/build-ParkingLot-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ParkingLot.dir/ParkingLot_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ParkingLot.dir/ParkingLot_autogen/mocs_compilation.cpp.o -c /home/zhiiw/QT/build-ParkingLot-Desktop-Debug/ParkingLot_autogen/mocs_compilation.cpp

CMakeFiles/ParkingLot.dir/ParkingLot_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParkingLot.dir/ParkingLot_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiiw/QT/build-ParkingLot-Desktop-Debug/ParkingLot_autogen/mocs_compilation.cpp > CMakeFiles/ParkingLot.dir/ParkingLot_autogen/mocs_compilation.cpp.i

CMakeFiles/ParkingLot.dir/ParkingLot_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParkingLot.dir/ParkingLot_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiiw/QT/build-ParkingLot-Desktop-Debug/ParkingLot_autogen/mocs_compilation.cpp -o CMakeFiles/ParkingLot.dir/ParkingLot_autogen/mocs_compilation.cpp.s

CMakeFiles/ParkingLot.dir/main.cpp.o: CMakeFiles/ParkingLot.dir/flags.make
CMakeFiles/ParkingLot.dir/main.cpp.o: /home/zhiiw/QT/ParkingLot/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiiw/QT/build-ParkingLot-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ParkingLot.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ParkingLot.dir/main.cpp.o -c /home/zhiiw/QT/ParkingLot/main.cpp

CMakeFiles/ParkingLot.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParkingLot.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiiw/QT/ParkingLot/main.cpp > CMakeFiles/ParkingLot.dir/main.cpp.i

CMakeFiles/ParkingLot.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParkingLot.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiiw/QT/ParkingLot/main.cpp -o CMakeFiles/ParkingLot.dir/main.cpp.s

CMakeFiles/ParkingLot.dir/mainwindow.cpp.o: CMakeFiles/ParkingLot.dir/flags.make
CMakeFiles/ParkingLot.dir/mainwindow.cpp.o: /home/zhiiw/QT/ParkingLot/mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiiw/QT/build-ParkingLot-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ParkingLot.dir/mainwindow.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ParkingLot.dir/mainwindow.cpp.o -c /home/zhiiw/QT/ParkingLot/mainwindow.cpp

CMakeFiles/ParkingLot.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParkingLot.dir/mainwindow.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiiw/QT/ParkingLot/mainwindow.cpp > CMakeFiles/ParkingLot.dir/mainwindow.cpp.i

CMakeFiles/ParkingLot.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParkingLot.dir/mainwindow.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiiw/QT/ParkingLot/mainwindow.cpp -o CMakeFiles/ParkingLot.dir/mainwindow.cpp.s

CMakeFiles/ParkingLot.dir/work.cpp.o: CMakeFiles/ParkingLot.dir/flags.make
CMakeFiles/ParkingLot.dir/work.cpp.o: /home/zhiiw/QT/ParkingLot/work.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiiw/QT/build-ParkingLot-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ParkingLot.dir/work.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ParkingLot.dir/work.cpp.o -c /home/zhiiw/QT/ParkingLot/work.cpp

CMakeFiles/ParkingLot.dir/work.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParkingLot.dir/work.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiiw/QT/ParkingLot/work.cpp > CMakeFiles/ParkingLot.dir/work.cpp.i

CMakeFiles/ParkingLot.dir/work.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParkingLot.dir/work.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiiw/QT/ParkingLot/work.cpp -o CMakeFiles/ParkingLot.dir/work.cpp.s

CMakeFiles/ParkingLot.dir/ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp.o: CMakeFiles/ParkingLot.dir/flags.make
CMakeFiles/ParkingLot.dir/ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp.o: ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiiw/QT/build-ParkingLot-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ParkingLot.dir/ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ParkingLot.dir/ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp.o -c /home/zhiiw/QT/build-ParkingLot-Desktop-Debug/ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp

CMakeFiles/ParkingLot.dir/ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParkingLot.dir/ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiiw/QT/build-ParkingLot-Desktop-Debug/ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp > CMakeFiles/ParkingLot.dir/ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp.i

CMakeFiles/ParkingLot.dir/ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParkingLot.dir/ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiiw/QT/build-ParkingLot-Desktop-Debug/ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp -o CMakeFiles/ParkingLot.dir/ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp.s

# Object files for target ParkingLot
ParkingLot_OBJECTS = \
"CMakeFiles/ParkingLot.dir/ParkingLot_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/ParkingLot.dir/main.cpp.o" \
"CMakeFiles/ParkingLot.dir/mainwindow.cpp.o" \
"CMakeFiles/ParkingLot.dir/work.cpp.o" \
"CMakeFiles/ParkingLot.dir/ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp.o"

# External object files for target ParkingLot
ParkingLot_EXTERNAL_OBJECTS =

ParkingLot: CMakeFiles/ParkingLot.dir/ParkingLot_autogen/mocs_compilation.cpp.o
ParkingLot: CMakeFiles/ParkingLot.dir/main.cpp.o
ParkingLot: CMakeFiles/ParkingLot.dir/mainwindow.cpp.o
ParkingLot: CMakeFiles/ParkingLot.dir/work.cpp.o
ParkingLot: CMakeFiles/ParkingLot.dir/ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp.o
ParkingLot: CMakeFiles/ParkingLot.dir/build.make
ParkingLot: /usr/lib/libQt5Widgets.so.5.15.2
ParkingLot: /usr/lib/libQt5Sql.so.5.15.2
ParkingLot: /usr/lib/libQt5Gui.so.5.15.2
ParkingLot: /usr/lib/libQt5Core.so.5.15.2
ParkingLot: CMakeFiles/ParkingLot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhiiw/QT/build-ParkingLot-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ParkingLot"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ParkingLot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ParkingLot.dir/build: ParkingLot

.PHONY : CMakeFiles/ParkingLot.dir/build

CMakeFiles/ParkingLot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ParkingLot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ParkingLot.dir/clean

CMakeFiles/ParkingLot.dir/depend: ParkingLot_autogen/EWIEGA46WW/qrc_test.cpp
	cd /home/zhiiw/QT/build-ParkingLot-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhiiw/QT/ParkingLot /home/zhiiw/QT/ParkingLot /home/zhiiw/QT/build-ParkingLot-Desktop-Debug /home/zhiiw/QT/build-ParkingLot-Desktop-Debug /home/zhiiw/QT/build-ParkingLot-Desktop-Debug/CMakeFiles/ParkingLot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ParkingLot.dir/depend

