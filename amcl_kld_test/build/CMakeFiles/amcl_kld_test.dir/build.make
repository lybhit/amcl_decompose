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
CMAKE_SOURCE_DIR = /home/lyb/projects/amcl_kld_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lyb/projects/amcl_kld_test/build

# Include any dependencies generated for this target.
include CMakeFiles/amcl_kld_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/amcl_kld_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/amcl_kld_test.dir/flags.make

CMakeFiles/amcl_kld_test.dir/main.cpp.o: CMakeFiles/amcl_kld_test.dir/flags.make
CMakeFiles/amcl_kld_test.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyb/projects/amcl_kld_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/amcl_kld_test.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/amcl_kld_test.dir/main.cpp.o -c /home/lyb/projects/amcl_kld_test/main.cpp

CMakeFiles/amcl_kld_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/amcl_kld_test.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyb/projects/amcl_kld_test/main.cpp > CMakeFiles/amcl_kld_test.dir/main.cpp.i

CMakeFiles/amcl_kld_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/amcl_kld_test.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyb/projects/amcl_kld_test/main.cpp -o CMakeFiles/amcl_kld_test.dir/main.cpp.s

CMakeFiles/amcl_kld_test.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/amcl_kld_test.dir/main.cpp.o.requires

CMakeFiles/amcl_kld_test.dir/main.cpp.o.provides: CMakeFiles/amcl_kld_test.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/amcl_kld_test.dir/build.make CMakeFiles/amcl_kld_test.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/amcl_kld_test.dir/main.cpp.o.provides

CMakeFiles/amcl_kld_test.dir/main.cpp.o.provides.build: CMakeFiles/amcl_kld_test.dir/main.cpp.o


# Object files for target amcl_kld_test
amcl_kld_test_OBJECTS = \
"CMakeFiles/amcl_kld_test.dir/main.cpp.o"

# External object files for target amcl_kld_test
amcl_kld_test_EXTERNAL_OBJECTS =

amcl_kld_test: CMakeFiles/amcl_kld_test.dir/main.cpp.o
amcl_kld_test: CMakeFiles/amcl_kld_test.dir/build.make
amcl_kld_test: CMakeFiles/amcl_kld_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lyb/projects/amcl_kld_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable amcl_kld_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/amcl_kld_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/amcl_kld_test.dir/build: amcl_kld_test

.PHONY : CMakeFiles/amcl_kld_test.dir/build

CMakeFiles/amcl_kld_test.dir/requires: CMakeFiles/amcl_kld_test.dir/main.cpp.o.requires

.PHONY : CMakeFiles/amcl_kld_test.dir/requires

CMakeFiles/amcl_kld_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/amcl_kld_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/amcl_kld_test.dir/clean

CMakeFiles/amcl_kld_test.dir/depend:
	cd /home/lyb/projects/amcl_kld_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lyb/projects/amcl_kld_test /home/lyb/projects/amcl_kld_test /home/lyb/projects/amcl_kld_test/build /home/lyb/projects/amcl_kld_test/build /home/lyb/projects/amcl_kld_test/build/CMakeFiles/amcl_kld_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/amcl_kld_test.dir/depend

