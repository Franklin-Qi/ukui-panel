# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/kylin/work/panel/ukui-panel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kylin/work/panel/ukui-panel/obj-x86_64-linux-gnu

# Utility rule file for ukui-panel_autogen.

# Include the progress variables for this target.
include panel/CMakeFiles/ukui-panel_autogen.dir/progress.make

panel/CMakeFiles/ukui-panel_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kylin/work/panel/ukui-panel/obj-x86_64-linux-gnu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target ukui-panel"
	cd /home/kylin/work/panel/ukui-panel/obj-x86_64-linux-gnu/panel && /usr/bin/cmake -E cmake_autogen /home/kylin/work/panel/ukui-panel/obj-x86_64-linux-gnu/panel/CMakeFiles/ukui-panel_autogen.dir/AutogenInfo.cmake RelWithDebInfo

ukui-panel_autogen: panel/CMakeFiles/ukui-panel_autogen
ukui-panel_autogen: panel/CMakeFiles/ukui-panel_autogen.dir/build.make

.PHONY : ukui-panel_autogen

# Rule to build all files generated by this target.
panel/CMakeFiles/ukui-panel_autogen.dir/build: ukui-panel_autogen

.PHONY : panel/CMakeFiles/ukui-panel_autogen.dir/build

panel/CMakeFiles/ukui-panel_autogen.dir/clean:
	cd /home/kylin/work/panel/ukui-panel/obj-x86_64-linux-gnu/panel && $(CMAKE_COMMAND) -P CMakeFiles/ukui-panel_autogen.dir/cmake_clean.cmake
.PHONY : panel/CMakeFiles/ukui-panel_autogen.dir/clean

panel/CMakeFiles/ukui-panel_autogen.dir/depend:
	cd /home/kylin/work/panel/ukui-panel/obj-x86_64-linux-gnu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kylin/work/panel/ukui-panel /home/kylin/work/panel/ukui-panel/panel /home/kylin/work/panel/ukui-panel/obj-x86_64-linux-gnu /home/kylin/work/panel/ukui-panel/obj-x86_64-linux-gnu/panel /home/kylin/work/panel/ukui-panel/obj-x86_64-linux-gnu/panel/CMakeFiles/ukui-panel_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : panel/CMakeFiles/ukui-panel_autogen.dir/depend
