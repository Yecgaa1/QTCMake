# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\xtx\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7628.27\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\xtx\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7628.27\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\GitProject\QTCMake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\GitProject\QTCMake\cmake-build-debug

# Utility rule file for QTCMake_autogen.

# Include the progress variables for this target.
include CMakeFiles/QTCMake_autogen.dir/progress.make

CMakeFiles/QTCMake_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=D:\GitProject\QTCMake\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target QTCMake"
	C:\Users\xtx\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7628.27\bin\cmake\win\bin\cmake.exe -E cmake_autogen D:/GitProject/QTCMake/cmake-build-debug/CMakeFiles/QTCMake_autogen.dir/AutogenInfo.json Debug

QTCMake_autogen: CMakeFiles/QTCMake_autogen
QTCMake_autogen: CMakeFiles/QTCMake_autogen.dir/build.make

.PHONY : QTCMake_autogen

# Rule to build all files generated by this target.
CMakeFiles/QTCMake_autogen.dir/build: QTCMake_autogen

.PHONY : CMakeFiles/QTCMake_autogen.dir/build

CMakeFiles/QTCMake_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\QTCMake_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/QTCMake_autogen.dir/clean

CMakeFiles/QTCMake_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\GitProject\QTCMake D:\GitProject\QTCMake D:\GitProject\QTCMake\cmake-build-debug D:\GitProject\QTCMake\cmake-build-debug D:\GitProject\QTCMake\cmake-build-debug\CMakeFiles\QTCMake_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QTCMake_autogen.dir/depend
