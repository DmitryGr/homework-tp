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

# Include any dependencies generated for this target.
include Builder/cpp-source/CMakeFiles/burger_shop.dir/depend.make

# Include the progress variables for this target.
include Builder/cpp-source/CMakeFiles/burger_shop.dir/progress.make

# Include the compile flags for this target's objects.
include Builder/cpp-source/CMakeFiles/burger_shop.dir/flags.make

Builder/cpp-source/CMakeFiles/burger_shop.dir/Chef.cpp.o: Builder/cpp-source/CMakeFiles/burger_shop.dir/flags.make
Builder/cpp-source/CMakeFiles/burger_shop.dir/Chef.cpp.o: Builder/cpp-source/Chef.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/TPF/PatternsCollection/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Builder/cpp-source/CMakeFiles/burger_shop.dir/Chef.cpp.o"
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/burger_shop.dir/Chef.cpp.o -c /home/dmitry/TPF/PatternsCollection/Builder/cpp-source/Chef.cpp

Builder/cpp-source/CMakeFiles/burger_shop.dir/Chef.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/burger_shop.dir/Chef.cpp.i"
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/TPF/PatternsCollection/Builder/cpp-source/Chef.cpp > CMakeFiles/burger_shop.dir/Chef.cpp.i

Builder/cpp-source/CMakeFiles/burger_shop.dir/Chef.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/burger_shop.dir/Chef.cpp.s"
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/TPF/PatternsCollection/Builder/cpp-source/Chef.cpp -o CMakeFiles/burger_shop.dir/Chef.cpp.s

Builder/cpp-source/CMakeFiles/burger_shop.dir/Chef.cpp.o.requires:

.PHONY : Builder/cpp-source/CMakeFiles/burger_shop.dir/Chef.cpp.o.requires

Builder/cpp-source/CMakeFiles/burger_shop.dir/Chef.cpp.o.provides: Builder/cpp-source/CMakeFiles/burger_shop.dir/Chef.cpp.o.requires
	$(MAKE) -f Builder/cpp-source/CMakeFiles/burger_shop.dir/build.make Builder/cpp-source/CMakeFiles/burger_shop.dir/Chef.cpp.o.provides.build
.PHONY : Builder/cpp-source/CMakeFiles/burger_shop.dir/Chef.cpp.o.provides

Builder/cpp-source/CMakeFiles/burger_shop.dir/Chef.cpp.o.provides.build: Builder/cpp-source/CMakeFiles/burger_shop.dir/Chef.cpp.o


Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.o: Builder/cpp-source/CMakeFiles/burger_shop.dir/flags.make
Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.o: Builder/cpp-source/builders/BurgerBuilder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/TPF/PatternsCollection/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.o"
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.o -c /home/dmitry/TPF/PatternsCollection/Builder/cpp-source/builders/BurgerBuilder.cpp

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.i"
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/TPF/PatternsCollection/Builder/cpp-source/builders/BurgerBuilder.cpp > CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.i

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.s"
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/TPF/PatternsCollection/Builder/cpp-source/builders/BurgerBuilder.cpp -o CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.s

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.o.requires:

.PHONY : Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.o.requires

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.o.provides: Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.o.requires
	$(MAKE) -f Builder/cpp-source/CMakeFiles/burger_shop.dir/build.make Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.o.provides.build
.PHONY : Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.o.provides

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.o.provides.build: Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.o


Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.o: Builder/cpp-source/CMakeFiles/burger_shop.dir/flags.make
Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.o: Builder/cpp-source/builders/HamburgerBuilder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/TPF/PatternsCollection/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.o"
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.o -c /home/dmitry/TPF/PatternsCollection/Builder/cpp-source/builders/HamburgerBuilder.cpp

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.i"
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/TPF/PatternsCollection/Builder/cpp-source/builders/HamburgerBuilder.cpp > CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.i

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.s"
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/TPF/PatternsCollection/Builder/cpp-source/builders/HamburgerBuilder.cpp -o CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.s

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.o.requires:

.PHONY : Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.o.requires

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.o.provides: Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.o.requires
	$(MAKE) -f Builder/cpp-source/CMakeFiles/burger_shop.dir/build.make Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.o.provides.build
.PHONY : Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.o.provides

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.o.provides.build: Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.o


Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.o: Builder/cpp-source/CMakeFiles/burger_shop.dir/flags.make
Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.o: Builder/cpp-source/builders/base/Burger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/TPF/PatternsCollection/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.o"
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.o -c /home/dmitry/TPF/PatternsCollection/Builder/cpp-source/builders/base/Burger.cpp

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.i"
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/TPF/PatternsCollection/Builder/cpp-source/builders/base/Burger.cpp > CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.i

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.s"
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/TPF/PatternsCollection/Builder/cpp-source/builders/base/Burger.cpp -o CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.s

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.o.requires:

.PHONY : Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.o.requires

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.o.provides: Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.o.requires
	$(MAKE) -f Builder/cpp-source/CMakeFiles/burger_shop.dir/build.make Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.o.provides.build
.PHONY : Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.o.provides

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.o.provides.build: Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.o


Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.o: Builder/cpp-source/CMakeFiles/burger_shop.dir/flags.make
Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.o: Builder/cpp-source/builders/VegiburgerBuilder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/TPF/PatternsCollection/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.o"
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.o -c /home/dmitry/TPF/PatternsCollection/Builder/cpp-source/builders/VegiburgerBuilder.cpp

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.i"
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/TPF/PatternsCollection/Builder/cpp-source/builders/VegiburgerBuilder.cpp > CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.i

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.s"
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/TPF/PatternsCollection/Builder/cpp-source/builders/VegiburgerBuilder.cpp -o CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.s

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.o.requires:

.PHONY : Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.o.requires

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.o.provides: Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.o.requires
	$(MAKE) -f Builder/cpp-source/CMakeFiles/burger_shop.dir/build.make Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.o.provides.build
.PHONY : Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.o.provides

Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.o.provides.build: Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.o


# Object files for target burger_shop
burger_shop_OBJECTS = \
"CMakeFiles/burger_shop.dir/Chef.cpp.o" \
"CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.o" \
"CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.o" \
"CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.o" \
"CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.o"

# External object files for target burger_shop
burger_shop_EXTERNAL_OBJECTS =

/home/dmitry/TPF/lib-arm/libburger_shop.so: Builder/cpp-source/CMakeFiles/burger_shop.dir/Chef.cpp.o
/home/dmitry/TPF/lib-arm/libburger_shop.so: Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.o
/home/dmitry/TPF/lib-arm/libburger_shop.so: Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.o
/home/dmitry/TPF/lib-arm/libburger_shop.so: Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.o
/home/dmitry/TPF/lib-arm/libburger_shop.so: Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.o
/home/dmitry/TPF/lib-arm/libburger_shop.so: Builder/cpp-source/CMakeFiles/burger_shop.dir/build.make
/home/dmitry/TPF/lib-arm/libburger_shop.so: Builder/cpp-source/CMakeFiles/burger_shop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmitry/TPF/PatternsCollection/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library /home/dmitry/TPF/lib-arm/libburger_shop.so"
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/burger_shop.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Builder/cpp-source/CMakeFiles/burger_shop.dir/build: /home/dmitry/TPF/lib-arm/libburger_shop.so

.PHONY : Builder/cpp-source/CMakeFiles/burger_shop.dir/build

Builder/cpp-source/CMakeFiles/burger_shop.dir/requires: Builder/cpp-source/CMakeFiles/burger_shop.dir/Chef.cpp.o.requires
Builder/cpp-source/CMakeFiles/burger_shop.dir/requires: Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/BurgerBuilder.cpp.o.requires
Builder/cpp-source/CMakeFiles/burger_shop.dir/requires: Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/HamburgerBuilder.cpp.o.requires
Builder/cpp-source/CMakeFiles/burger_shop.dir/requires: Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/base/Burger.cpp.o.requires
Builder/cpp-source/CMakeFiles/burger_shop.dir/requires: Builder/cpp-source/CMakeFiles/burger_shop.dir/builders/VegiburgerBuilder.cpp.o.requires

.PHONY : Builder/cpp-source/CMakeFiles/burger_shop.dir/requires

Builder/cpp-source/CMakeFiles/burger_shop.dir/clean:
	cd /home/dmitry/TPF/PatternsCollection/Builder/cpp-source && $(CMAKE_COMMAND) -P CMakeFiles/burger_shop.dir/cmake_clean.cmake
.PHONY : Builder/cpp-source/CMakeFiles/burger_shop.dir/clean

Builder/cpp-source/CMakeFiles/burger_shop.dir/depend:
	cd /home/dmitry/TPF/PatternsCollection && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmitry/TPF/PatternsCollection /home/dmitry/TPF/PatternsCollection/Builder/cpp-source /home/dmitry/TPF/PatternsCollection /home/dmitry/TPF/PatternsCollection/Builder/cpp-source /home/dmitry/TPF/PatternsCollection/Builder/cpp-source/CMakeFiles/burger_shop.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Builder/cpp-source/CMakeFiles/burger_shop.dir/depend

