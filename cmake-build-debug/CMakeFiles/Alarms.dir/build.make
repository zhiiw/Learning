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
CMAKE_COMMAND = /home/zhiiw/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7142.21/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/zhiiw/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7142.21/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhiiw/CLionProjects/Learning

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhiiw/CLionProjects/Learning/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Alarms.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Alarms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Alarms.dir/flags.make

Alarms_autogen/EWIEGA46WW/qrc_qml.cpp: ../qml.qrc
Alarms_autogen/EWIEGA46WW/qrc_qml.cpp: CMakeFiles/Alarms_autogen.dir/AutoRcc_qml_EWIEGA46WW_Info.json
Alarms_autogen/EWIEGA46WW/qrc_qml.cpp: ../main.qml
Alarms_autogen/EWIEGA46WW/qrc_qml.cpp: /usr/bin/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zhiiw/CLionProjects/Learning/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for qml.qrc"
	/home/zhiiw/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7142.21/bin/cmake/linux/bin/cmake -E cmake_autorcc /home/zhiiw/CLionProjects/Learning/cmake-build-debug/CMakeFiles/Alarms_autogen.dir/AutoRcc_qml_EWIEGA46WW_Info.json Debug

CMakeFiles/Alarms.dir/Alarms_autogen/mocs_compilation.cpp.o: CMakeFiles/Alarms.dir/flags.make
CMakeFiles/Alarms.dir/Alarms_autogen/mocs_compilation.cpp.o: Alarms_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiiw/CLionProjects/Learning/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Alarms.dir/Alarms_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Alarms.dir/Alarms_autogen/mocs_compilation.cpp.o -c /home/zhiiw/CLionProjects/Learning/cmake-build-debug/Alarms_autogen/mocs_compilation.cpp

CMakeFiles/Alarms.dir/Alarms_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Alarms.dir/Alarms_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiiw/CLionProjects/Learning/cmake-build-debug/Alarms_autogen/mocs_compilation.cpp > CMakeFiles/Alarms.dir/Alarms_autogen/mocs_compilation.cpp.i

CMakeFiles/Alarms.dir/Alarms_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Alarms.dir/Alarms_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiiw/CLionProjects/Learning/cmake-build-debug/Alarms_autogen/mocs_compilation.cpp -o CMakeFiles/Alarms.dir/Alarms_autogen/mocs_compilation.cpp.s

CMakeFiles/Alarms.dir/main.cpp.o: CMakeFiles/Alarms.dir/flags.make
CMakeFiles/Alarms.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiiw/CLionProjects/Learning/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Alarms.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Alarms.dir/main.cpp.o -c /home/zhiiw/CLionProjects/Learning/main.cpp

CMakeFiles/Alarms.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Alarms.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiiw/CLionProjects/Learning/main.cpp > CMakeFiles/Alarms.dir/main.cpp.i

CMakeFiles/Alarms.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Alarms.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiiw/CLionProjects/Learning/main.cpp -o CMakeFiles/Alarms.dir/main.cpp.s

CMakeFiles/Alarms.dir/Alarms_autogen/EWIEGA46WW/qrc_qml.cpp.o: CMakeFiles/Alarms.dir/flags.make
CMakeFiles/Alarms.dir/Alarms_autogen/EWIEGA46WW/qrc_qml.cpp.o: Alarms_autogen/EWIEGA46WW/qrc_qml.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiiw/CLionProjects/Learning/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Alarms.dir/Alarms_autogen/EWIEGA46WW/qrc_qml.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Alarms.dir/Alarms_autogen/EWIEGA46WW/qrc_qml.cpp.o -c /home/zhiiw/CLionProjects/Learning/cmake-build-debug/Alarms_autogen/EWIEGA46WW/qrc_qml.cpp

CMakeFiles/Alarms.dir/Alarms_autogen/EWIEGA46WW/qrc_qml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Alarms.dir/Alarms_autogen/EWIEGA46WW/qrc_qml.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiiw/CLionProjects/Learning/cmake-build-debug/Alarms_autogen/EWIEGA46WW/qrc_qml.cpp > CMakeFiles/Alarms.dir/Alarms_autogen/EWIEGA46WW/qrc_qml.cpp.i

CMakeFiles/Alarms.dir/Alarms_autogen/EWIEGA46WW/qrc_qml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Alarms.dir/Alarms_autogen/EWIEGA46WW/qrc_qml.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiiw/CLionProjects/Learning/cmake-build-debug/Alarms_autogen/EWIEGA46WW/qrc_qml.cpp -o CMakeFiles/Alarms.dir/Alarms_autogen/EWIEGA46WW/qrc_qml.cpp.s

# Object files for target Alarms
Alarms_OBJECTS = \
"CMakeFiles/Alarms.dir/Alarms_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/Alarms.dir/main.cpp.o" \
"CMakeFiles/Alarms.dir/Alarms_autogen/EWIEGA46WW/qrc_qml.cpp.o"

# External object files for target Alarms
Alarms_EXTERNAL_OBJECTS =

Alarms: CMakeFiles/Alarms.dir/Alarms_autogen/mocs_compilation.cpp.o
Alarms: CMakeFiles/Alarms.dir/main.cpp.o
Alarms: CMakeFiles/Alarms.dir/Alarms_autogen/EWIEGA46WW/qrc_qml.cpp.o
Alarms: CMakeFiles/Alarms.dir/build.make
Alarms: /usr/lib/libQt5Quick.so.5.15.2
Alarms: /usr/lib/libQt5QmlModels.so.5.15.2
Alarms: /usr/lib/libQt5Qml.so.5.15.2
Alarms: /usr/lib/libQt5Network.so.5.15.2
Alarms: /usr/lib/libQt5Gui.so.5.15.2
Alarms: /usr/lib/libQt5Core.so.5.15.2
Alarms: CMakeFiles/Alarms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhiiw/CLionProjects/Learning/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Alarms"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Alarms.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Alarms.dir/build: Alarms

.PHONY : CMakeFiles/Alarms.dir/build

CMakeFiles/Alarms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Alarms.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Alarms.dir/clean

CMakeFiles/Alarms.dir/depend: Alarms_autogen/EWIEGA46WW/qrc_qml.cpp
	cd /home/zhiiw/CLionProjects/Learning/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhiiw/CLionProjects/Learning /home/zhiiw/CLionProjects/Learning /home/zhiiw/CLionProjects/Learning/cmake-build-debug /home/zhiiw/CLionProjects/Learning/cmake-build-debug /home/zhiiw/CLionProjects/Learning/cmake-build-debug/CMakeFiles/Alarms.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Alarms.dir/depend

