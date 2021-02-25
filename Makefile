# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/mehdi/Bureau/C++/CPP_Learning_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mehdi/Bureau/C++/CPP_Learning_Project

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mehdi/Bureau/C++/CPP_Learning_Project/CMakeFiles /home/mehdi/Bureau/C++/CPP_Learning_Project/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mehdi/Bureau/C++/CPP_Learning_Project/CMakeFiles 0
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
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named tower

# Build rule for target.
tower: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 tower
.PHONY : tower

# fast build rule for target.
tower/fast:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/build
.PHONY : tower/fast

src/GL/opengl_interface.o: src/GL/opengl_interface.cpp.o

.PHONY : src/GL/opengl_interface.o

# target to build an object file
src/GL/opengl_interface.cpp.o:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/GL/opengl_interface.cpp.o
.PHONY : src/GL/opengl_interface.cpp.o

src/GL/opengl_interface.i: src/GL/opengl_interface.cpp.i

.PHONY : src/GL/opengl_interface.i

# target to preprocess a source file
src/GL/opengl_interface.cpp.i:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/GL/opengl_interface.cpp.i
.PHONY : src/GL/opengl_interface.cpp.i

src/GL/opengl_interface.s: src/GL/opengl_interface.cpp.s

.PHONY : src/GL/opengl_interface.s

# target to generate assembly for a file
src/GL/opengl_interface.cpp.s:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/GL/opengl_interface.cpp.s
.PHONY : src/GL/opengl_interface.cpp.s

src/aircraft.o: src/aircraft.cpp.o

.PHONY : src/aircraft.o

# target to build an object file
src/aircraft.cpp.o:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/aircraft.cpp.o
.PHONY : src/aircraft.cpp.o

src/aircraft.i: src/aircraft.cpp.i

.PHONY : src/aircraft.i

# target to preprocess a source file
src/aircraft.cpp.i:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/aircraft.cpp.i
.PHONY : src/aircraft.cpp.i

src/aircraft.s: src/aircraft.cpp.s

.PHONY : src/aircraft.s

# target to generate assembly for a file
src/aircraft.cpp.s:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/aircraft.cpp.s
.PHONY : src/aircraft.cpp.s

src/img/image.o: src/img/image.cpp.o

.PHONY : src/img/image.o

# target to build an object file
src/img/image.cpp.o:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/img/image.cpp.o
.PHONY : src/img/image.cpp.o

src/img/image.i: src/img/image.cpp.i

.PHONY : src/img/image.i

# target to preprocess a source file
src/img/image.cpp.i:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/img/image.cpp.i
.PHONY : src/img/image.cpp.i

src/img/image.s: src/img/image.cpp.s

.PHONY : src/img/image.s

# target to generate assembly for a file
src/img/image.cpp.s:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/img/image.cpp.s
.PHONY : src/img/image.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/tower.o: src/tower.cpp.o

.PHONY : src/tower.o

# target to build an object file
src/tower.cpp.o:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/tower.cpp.o
.PHONY : src/tower.cpp.o

src/tower.i: src/tower.cpp.i

.PHONY : src/tower.i

# target to preprocess a source file
src/tower.cpp.i:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/tower.cpp.i
.PHONY : src/tower.cpp.i

src/tower.s: src/tower.cpp.s

.PHONY : src/tower.s

# target to generate assembly for a file
src/tower.cpp.s:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/tower.cpp.s
.PHONY : src/tower.cpp.s

src/tower_sim.o: src/tower_sim.cpp.o

.PHONY : src/tower_sim.o

# target to build an object file
src/tower_sim.cpp.o:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/tower_sim.cpp.o
.PHONY : src/tower_sim.cpp.o

src/tower_sim.i: src/tower_sim.cpp.i

.PHONY : src/tower_sim.i

# target to preprocess a source file
src/tower_sim.cpp.i:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/tower_sim.cpp.i
.PHONY : src/tower_sim.cpp.i

src/tower_sim.s: src/tower_sim.cpp.s

.PHONY : src/tower_sim.s

# target to generate assembly for a file
src/tower_sim.cpp.s:
	$(MAKE) -f CMakeFiles/tower.dir/build.make CMakeFiles/tower.dir/src/tower_sim.cpp.s
.PHONY : src/tower_sim.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... tower"
	@echo "... src/GL/opengl_interface.o"
	@echo "... src/GL/opengl_interface.i"
	@echo "... src/GL/opengl_interface.s"
	@echo "... src/aircraft.o"
	@echo "... src/aircraft.i"
	@echo "... src/aircraft.s"
	@echo "... src/img/image.o"
	@echo "... src/img/image.i"
	@echo "... src/img/image.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/tower.o"
	@echo "... src/tower.i"
	@echo "... src/tower.s"
	@echo "... src/tower_sim.o"
	@echo "... src/tower_sim.i"
	@echo "... src/tower_sim.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
