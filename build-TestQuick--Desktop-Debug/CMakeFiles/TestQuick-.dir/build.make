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
CMAKE_SOURCE_DIR = /home/zhiiw/QT/TestQuick-

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhiiw/QT/build-TestQuick--Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/TestQuick-.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestQuick-.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestQuick-.dir/flags.make

TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp: /home/zhiiw/QT/TestQuick-/qml.qrc
TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp: CMakeFiles/TestQuick-_autogen.dir/AutoRcc_qml_EWIEGA46WW_Info.json
TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp: /home/zhiiw/QT/TestQuick-/main.qml
TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp: /usr/bin/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zhiiw/QT/build-TestQuick--Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for qml.qrc"
	/usr/bin/cmake -E cmake_autorcc /home/zhiiw/QT/build-TestQuick--Desktop-Debug/CMakeFiles/TestQuick-_autogen.dir/AutoRcc_qml_EWIEGA46WW_Info.json Debug

CMakeFiles/TestQuick-.dir/TestQuick-_autogen/mocs_compilation.cpp.o: CMakeFiles/TestQuick-.dir/flags.make
CMakeFiles/TestQuick-.dir/TestQuick-_autogen/mocs_compilation.cpp.o: TestQuick-_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiiw/QT/build-TestQuick--Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TestQuick-.dir/TestQuick-_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestQuick-.dir/TestQuick-_autogen/mocs_compilation.cpp.o -c /home/zhiiw/QT/build-TestQuick--Desktop-Debug/TestQuick-_autogen/mocs_compilation.cpp

CMakeFiles/TestQuick-.dir/TestQuick-_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestQuick-.dir/TestQuick-_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiiw/QT/build-TestQuick--Desktop-Debug/TestQuick-_autogen/mocs_compilation.cpp > CMakeFiles/TestQuick-.dir/TestQuick-_autogen/mocs_compilation.cpp.i

CMakeFiles/TestQuick-.dir/TestQuick-_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestQuick-.dir/TestQuick-_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiiw/QT/build-TestQuick--Desktop-Debug/TestQuick-_autogen/mocs_compilation.cpp -o CMakeFiles/TestQuick-.dir/TestQuick-_autogen/mocs_compilation.cpp.s

CMakeFiles/TestQuick-.dir/main.cpp.o: CMakeFiles/TestQuick-.dir/flags.make
CMakeFiles/TestQuick-.dir/main.cpp.o: /home/zhiiw/QT/TestQuick-/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiiw/QT/build-TestQuick--Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TestQuick-.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestQuick-.dir/main.cpp.o -c /home/zhiiw/QT/TestQuick-/main.cpp

CMakeFiles/TestQuick-.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestQuick-.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiiw/QT/TestQuick-/main.cpp > CMakeFiles/TestQuick-.dir/main.cpp.i

CMakeFiles/TestQuick-.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestQuick-.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiiw/QT/TestQuick-/main.cpp -o CMakeFiles/TestQuick-.dir/main.cpp.s

CMakeFiles/TestQuick-.dir/TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp.o: CMakeFiles/TestQuick-.dir/flags.make
CMakeFiles/TestQuick-.dir/TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp.o: TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiiw/QT/build-TestQuick--Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TestQuick-.dir/TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestQuick-.dir/TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp.o -c /home/zhiiw/QT/build-TestQuick--Desktop-Debug/TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp

CMakeFiles/TestQuick-.dir/TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestQuick-.dir/TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiiw/QT/build-TestQuick--Desktop-Debug/TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp > CMakeFiles/TestQuick-.dir/TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp.i

CMakeFiles/TestQuick-.dir/TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestQuick-.dir/TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiiw/QT/build-TestQuick--Desktop-Debug/TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp -o CMakeFiles/TestQuick-.dir/TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp.s

# Object files for target TestQuick-
TestQuick___OBJECTS = \
"CMakeFiles/TestQuick-.dir/TestQuick-_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/TestQuick-.dir/main.cpp.o" \
"CMakeFiles/TestQuick-.dir/TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp.o"

# External object files for target TestQuick-
TestQuick___EXTERNAL_OBJECTS =

TestQuick-: CMakeFiles/TestQuick-.dir/TestQuick-_autogen/mocs_compilation.cpp.o
TestQuick-: CMakeFiles/TestQuick-.dir/main.cpp.o
TestQuick-: CMakeFiles/TestQuick-.dir/TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp.o
TestQuick-: CMakeFiles/TestQuick-.dir/build.make
TestQuick-: /usr/lib/libQt5Quick.so.5.15.2
TestQuick-: /usr/lib/libQt5QmlModels.so.5.15.2
TestQuick-: /usr/lib/libQt5Qml.so.5.15.2
TestQuick-: /usr/lib/libQt5Network.so.5.15.2
TestQuick-: /usr/lib/libQt5Gui.so.5.15.2
TestQuick-: /usr/lib/libQt5Core.so.5.15.2
TestQuick-: CMakeFiles/TestQuick-.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhiiw/QT/build-TestQuick--Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable TestQuick-"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestQuick-.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestQuick-.dir/build: TestQuick-

.PHONY : CMakeFiles/TestQuick-.dir/build

CMakeFiles/TestQuick-.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestQuick-.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestQuick-.dir/clean

CMakeFiles/TestQuick-.dir/depend: TestQuick-_autogen/EWIEGA46WW/qrc_qml.cpp
	cd /home/zhiiw/QT/build-TestQuick--Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhiiw/QT/TestQuick- /home/zhiiw/QT/TestQuick- /home/zhiiw/QT/build-TestQuick--Desktop-Debug /home/zhiiw/QT/build-TestQuick--Desktop-Debug /home/zhiiw/QT/build-TestQuick--Desktop-Debug/CMakeFiles/TestQuick-.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestQuick-.dir/depend

