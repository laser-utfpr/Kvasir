# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/laser/Desktop/Kvasir/SMMCGUI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/laser/Desktop/Kvasir/SMMCGUI/build

# Include any dependencies generated for this target.
include source/CMakeFiles/smmcgui.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/smmcgui.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/smmcgui.dir/flags.make

source/CMakeFiles/smmcgui.dir/SMMCGUI.cpp.o: source/CMakeFiles/smmcgui.dir/flags.make
source/CMakeFiles/smmcgui.dir/SMMCGUI.cpp.o: ../source/SMMCGUI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laser/Desktop/Kvasir/SMMCGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/smmcgui.dir/SMMCGUI.cpp.o"
	cd /home/laser/Desktop/Kvasir/SMMCGUI/build/source && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smmcgui.dir/SMMCGUI.cpp.o -c /home/laser/Desktop/Kvasir/SMMCGUI/source/SMMCGUI.cpp

source/CMakeFiles/smmcgui.dir/SMMCGUI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smmcgui.dir/SMMCGUI.cpp.i"
	cd /home/laser/Desktop/Kvasir/SMMCGUI/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laser/Desktop/Kvasir/SMMCGUI/source/SMMCGUI.cpp > CMakeFiles/smmcgui.dir/SMMCGUI.cpp.i

source/CMakeFiles/smmcgui.dir/SMMCGUI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smmcgui.dir/SMMCGUI.cpp.s"
	cd /home/laser/Desktop/Kvasir/SMMCGUI/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laser/Desktop/Kvasir/SMMCGUI/source/SMMCGUI.cpp -o CMakeFiles/smmcgui.dir/SMMCGUI.cpp.s

source/CMakeFiles/smmcgui.dir/SMMCGUI.cpp.o.requires:

.PHONY : source/CMakeFiles/smmcgui.dir/SMMCGUI.cpp.o.requires

source/CMakeFiles/smmcgui.dir/SMMCGUI.cpp.o.provides: source/CMakeFiles/smmcgui.dir/SMMCGUI.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/smmcgui.dir/build.make source/CMakeFiles/smmcgui.dir/SMMCGUI.cpp.o.provides.build
.PHONY : source/CMakeFiles/smmcgui.dir/SMMCGUI.cpp.o.provides

source/CMakeFiles/smmcgui.dir/SMMCGUI.cpp.o.provides.build: source/CMakeFiles/smmcgui.dir/SMMCGUI.cpp.o


source/CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.o: source/CMakeFiles/smmcgui.dir/flags.make
source/CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.o: ../source/GUI/mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laser/Desktop/Kvasir/SMMCGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object source/CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.o"
	cd /home/laser/Desktop/Kvasir/SMMCGUI/build/source && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.o -c /home/laser/Desktop/Kvasir/SMMCGUI/source/GUI/mainwindow.cpp

source/CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.i"
	cd /home/laser/Desktop/Kvasir/SMMCGUI/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laser/Desktop/Kvasir/SMMCGUI/source/GUI/mainwindow.cpp > CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.i

source/CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.s"
	cd /home/laser/Desktop/Kvasir/SMMCGUI/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laser/Desktop/Kvasir/SMMCGUI/source/GUI/mainwindow.cpp -o CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.s

source/CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.o.requires:

.PHONY : source/CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.o.requires

source/CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.o.provides: source/CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/smmcgui.dir/build.make source/CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.o.provides.build
.PHONY : source/CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.o.provides

source/CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.o.provides.build: source/CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.o


source/CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.o: source/CMakeFiles/smmcgui.dir/flags.make
source/CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.o: source/smmcgui_automoc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laser/Desktop/Kvasir/SMMCGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object source/CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.o"
	cd /home/laser/Desktop/Kvasir/SMMCGUI/build/source && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.o -c /home/laser/Desktop/Kvasir/SMMCGUI/build/source/smmcgui_automoc.cpp

source/CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.i"
	cd /home/laser/Desktop/Kvasir/SMMCGUI/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laser/Desktop/Kvasir/SMMCGUI/build/source/smmcgui_automoc.cpp > CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.i

source/CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.s"
	cd /home/laser/Desktop/Kvasir/SMMCGUI/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laser/Desktop/Kvasir/SMMCGUI/build/source/smmcgui_automoc.cpp -o CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.s

source/CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.o.requires:

.PHONY : source/CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.o.requires

source/CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.o.provides: source/CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/smmcgui.dir/build.make source/CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.o.provides.build
.PHONY : source/CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.o.provides

source/CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.o.provides.build: source/CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.o


# Object files for target smmcgui
smmcgui_OBJECTS = \
"CMakeFiles/smmcgui.dir/SMMCGUI.cpp.o" \
"CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.o" \
"CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.o"

# External object files for target smmcgui
smmcgui_EXTERNAL_OBJECTS =

lib/libsmmcgui.so.0.0.0: source/CMakeFiles/smmcgui.dir/SMMCGUI.cpp.o
lib/libsmmcgui.so.0.0.0: source/CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.o
lib/libsmmcgui.so.0.0.0: source/CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.o
lib/libsmmcgui.so.0.0.0: source/CMakeFiles/smmcgui.dir/build.make
lib/libsmmcgui.so.0.0.0: source/CMakeFiles/smmcgui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/laser/Desktop/Kvasir/SMMCGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library ../lib/libsmmcgui.so"
	cd /home/laser/Desktop/Kvasir/SMMCGUI/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/smmcgui.dir/link.txt --verbose=$(VERBOSE)
	cd /home/laser/Desktop/Kvasir/SMMCGUI/build/source && $(CMAKE_COMMAND) -E cmake_symlink_library ../lib/libsmmcgui.so.0.0.0 ../lib/libsmmcgui.so.0.0.0 ../lib/libsmmcgui.so

lib/libsmmcgui.so: lib/libsmmcgui.so.0.0.0
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libsmmcgui.so

# Rule to build all files generated by this target.
source/CMakeFiles/smmcgui.dir/build: lib/libsmmcgui.so

.PHONY : source/CMakeFiles/smmcgui.dir/build

source/CMakeFiles/smmcgui.dir/requires: source/CMakeFiles/smmcgui.dir/SMMCGUI.cpp.o.requires
source/CMakeFiles/smmcgui.dir/requires: source/CMakeFiles/smmcgui.dir/GUI/mainwindow.cpp.o.requires
source/CMakeFiles/smmcgui.dir/requires: source/CMakeFiles/smmcgui.dir/smmcgui_automoc.cpp.o.requires

.PHONY : source/CMakeFiles/smmcgui.dir/requires

source/CMakeFiles/smmcgui.dir/clean:
	cd /home/laser/Desktop/Kvasir/SMMCGUI/build/source && $(CMAKE_COMMAND) -P CMakeFiles/smmcgui.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/smmcgui.dir/clean

source/CMakeFiles/smmcgui.dir/depend:
	cd /home/laser/Desktop/Kvasir/SMMCGUI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/laser/Desktop/Kvasir/SMMCGUI /home/laser/Desktop/Kvasir/SMMCGUI/source /home/laser/Desktop/Kvasir/SMMCGUI/build /home/laser/Desktop/Kvasir/SMMCGUI/build/source /home/laser/Desktop/Kvasir/SMMCGUI/build/source/CMakeFiles/smmcgui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/smmcgui.dir/depend

