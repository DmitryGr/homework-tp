# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/dmitry/TPF/PatternsCollection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmitry/TPF/PatternsCollection

# Utility rule file for copy_configs.

# Include the progress variables for this target.
include Decorator/cpp-source/CMakeFiles/copy_configs.dir/progress.make

Decorator/cpp-source/CMakeFiles/copy_configs: /home/dmitry/TPF/bin/configs/config.ini


/home/dmitry/TPF/bin/configs/config.ini: Decorator/cpp-source/configs/config.ini
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dmitry/TPF/PatternsCollection/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) configs
	cd /home/dmitry/TPF/PatternsCollection/Decorator/cpp-source && /usr/bin/cmake -E copy_if_different /home/dmitry/TPF/PatternsCollection/Decorator/cpp-source/configs/config.ini /home/dmitry/TPF/PatternsCollection/../bin/configs/config.ini

copy_configs: Decorator/cpp-source/CMakeFiles/copy_configs
copy_configs: /home/dmitry/TPF/bin/configs/config.ini
copy_configs: Decorator/cpp-source/CMakeFiles/copy_configs.dir/build.make

.PHONY : copy_configs

# Rule to build all files generated by this target.
Decorator/cpp-source/CMakeFiles/copy_configs.dir/build: copy_configs

.PHONY : Decorator/cpp-source/CMakeFiles/copy_configs.dir/build

Decorator/cpp-source/CMakeFiles/copy_configs.dir/clean:
	cd /home/dmitry/TPF/PatternsCollection/Decorator/cpp-source && $(CMAKE_COMMAND) -P CMakeFiles/copy_configs.dir/cmake_clean.cmake
.PHONY : Decorator/cpp-source/CMakeFiles/copy_configs.dir/clean

Decorator/cpp-source/CMakeFiles/copy_configs.dir/depend:
	cd /home/dmitry/TPF/PatternsCollection && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmitry/TPF/PatternsCollection /home/dmitry/TPF/PatternsCollection/Decorator/cpp-source /home/dmitry/TPF/PatternsCollection /home/dmitry/TPF/PatternsCollection/Decorator/cpp-source /home/dmitry/TPF/PatternsCollection/Decorator/cpp-source/CMakeFiles/copy_configs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Decorator/cpp-source/CMakeFiles/copy_configs.dir/depend

