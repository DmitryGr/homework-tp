# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dmitry/TPF/PatternsCollection/CMakeFiles /home/dmitry/TPF/PatternsCollection/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dmitry/TPF/PatternsCollection/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named AbstractFactorySerializer

# Build rule for target.
AbstractFactorySerializer: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 AbstractFactorySerializer
.PHONY : AbstractFactorySerializer

# fast build rule for target.
AbstractFactorySerializer/fast:
	$(MAKE) -f AbstractFactory/cpp-source/CMakeFiles/AbstractFactorySerializer.dir/build.make AbstractFactory/cpp-source/CMakeFiles/AbstractFactorySerializer.dir/build
.PHONY : AbstractFactorySerializer/fast

#=============================================================================
# Target rules for targets named AbstractFactory

# Build rule for target.
AbstractFactory: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 AbstractFactory
.PHONY : AbstractFactory

# fast build rule for target.
AbstractFactory/fast:
	$(MAKE) -f AbstractFactory/cpp-source/CMakeFiles/AbstractFactory.dir/build.make AbstractFactory/cpp-source/CMakeFiles/AbstractFactory.dir/build
.PHONY : AbstractFactory/fast

#=============================================================================
# Target rules for targets named serializers

# Build rule for target.
serializers: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 serializers
.PHONY : serializers

# fast build rule for target.
serializers/fast:
	$(MAKE) -f AbstractFactory/cpp-source/serializers/CMakeFiles/serializers.dir/build.make AbstractFactory/cpp-source/serializers/CMakeFiles/serializers.dir/build
.PHONY : serializers/fast

#=============================================================================
# Target rules for targets named isaac_rooms

# Build rule for target.
isaac_rooms: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 isaac_rooms
.PHONY : isaac_rooms

# fast build rule for target.
isaac_rooms/fast:
	$(MAKE) -f AbstractFactory/cpp-source/rooms/CMakeFiles/isaac_rooms.dir/build.make AbstractFactory/cpp-source/rooms/CMakeFiles/isaac_rooms.dir/build
.PHONY : isaac_rooms/fast

#=============================================================================
# Target rules for targets named isaac_factories

# Build rule for target.
isaac_factories: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 isaac_factories
.PHONY : isaac_factories

# fast build rule for target.
isaac_factories/fast:
	$(MAKE) -f AbstractFactory/cpp-source/factories/CMakeFiles/isaac_factories.dir/build.make AbstractFactory/cpp-source/factories/CMakeFiles/isaac_factories.dir/build
.PHONY : isaac_factories/fast

#=============================================================================
# Target rules for targets named burger_shop

# Build rule for target.
burger_shop: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 burger_shop
.PHONY : burger_shop

# fast build rule for target.
burger_shop/fast:
	$(MAKE) -f Builder/cpp-source/CMakeFiles/burger_shop.dir/build.make Builder/cpp-source/CMakeFiles/burger_shop.dir/build
.PHONY : burger_shop/fast

#=============================================================================
# Target rules for targets named Builder

# Build rule for target.
Builder: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Builder
.PHONY : Builder

# fast build rule for target.
Builder/fast:
	$(MAKE) -f Builder/cpp-source/CMakeFiles/Builder.dir/build.make Builder/cpp-source/CMakeFiles/Builder.dir/build
.PHONY : Builder/fast

#=============================================================================
# Target rules for targets named Prototype

# Build rule for target.
Prototype: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Prototype
.PHONY : Prototype

# fast build rule for target.
Prototype/fast:
	$(MAKE) -f Prototype/cpp-source/CMakeFiles/Prototype.dir/build.make Prototype/cpp-source/CMakeFiles/Prototype.dir/build
.PHONY : Prototype/fast

#=============================================================================
# Target rules for targets named Bridge

# Build rule for target.
Bridge: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Bridge
.PHONY : Bridge

# fast build rule for target.
Bridge/fast:
	$(MAKE) -f Bridge/cpp-source/CMakeFiles/Bridge.dir/build.make Bridge/cpp-source/CMakeFiles/Bridge.dir/build
.PHONY : Bridge/fast

#=============================================================================
# Target rules for targets named Facade

# Build rule for target.
Facade: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Facade
.PHONY : Facade

# fast build rule for target.
Facade/fast:
	$(MAKE) -f Facade/cpp-source/CMakeFiles/Facade.dir/build.make Facade/cpp-source/CMakeFiles/Facade.dir/build
.PHONY : Facade/fast

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... install"
	@echo "... install/local"
	@echo "... list_install_components"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... AbstractFactorySerializer"
	@echo "... AbstractFactory"
	@echo "... serializers"
	@echo "... isaac_rooms"
	@echo "... isaac_factories"
	@echo "... burger_shop"
	@echo "... Builder"
	@echo "... Prototype"
	@echo "... Bridge"
	@echo "... Facade"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

