# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /home/ccx/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ccx/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ccx/CLionProjects/re_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ccx/CLionProjects/re_project/cmake-build-debug

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/home/ccx/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/bin/cmake/linux/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/home/ccx/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/bin/cmake/linux/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ccx/CLionProjects/re_project/cmake-build-debug/CMakeFiles /home/ccx/CLionProjects/re_project/cmake-build-debug/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ccx/CLionProjects/re_project/cmake-build-debug/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named re_project

# Build rule for target.
re_project: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 re_project
.PHONY : re_project

# fast build rule for target.
re_project/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/build
.PHONY : re_project/fast

doctor.o: doctor.cpp.o

.PHONY : doctor.o

# target to build an object file
doctor.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/doctor.cpp.o
.PHONY : doctor.cpp.o

doctor.i: doctor.cpp.i

.PHONY : doctor.i

# target to preprocess a source file
doctor.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/doctor.cpp.i
.PHONY : doctor.cpp.i

doctor.s: doctor.cpp.s

.PHONY : doctor.s

# target to generate assembly for a file
doctor.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/doctor.cpp.s
.PHONY : doctor.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/main.cpp.s
.PHONY : main.cpp.s

my_time.o: my_time.cpp.o

.PHONY : my_time.o

# target to build an object file
my_time.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/my_time.cpp.o
.PHONY : my_time.cpp.o

my_time.i: my_time.cpp.i

.PHONY : my_time.i

# target to preprocess a source file
my_time.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/my_time.cpp.i
.PHONY : my_time.cpp.i

my_time.s: my_time.cpp.s

.PHONY : my_time.s

# target to generate assembly for a file
my_time.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/my_time.cpp.s
.PHONY : my_time.cpp.s

patient.o: patient.cpp.o

.PHONY : patient.o

# target to build an object file
patient.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/patient.cpp.o
.PHONY : patient.cpp.o

patient.i: patient.cpp.i

.PHONY : patient.i

# target to preprocess a source file
patient.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/patient.cpp.i
.PHONY : patient.cpp.i

patient.s: patient.cpp.s

.PHONY : patient.s

# target to generate assembly for a file
patient.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/patient.cpp.s
.PHONY : patient.cpp.s

record.o: record.cpp.o

.PHONY : record.o

# target to build an object file
record.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/record.cpp.o
.PHONY : record.cpp.o

record.i: record.cpp.i

.PHONY : record.i

# target to preprocess a source file
record.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/record.cpp.i
.PHONY : record.cpp.i

record.s: record.cpp.s

.PHONY : record.s

# target to generate assembly for a file
record.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/record.cpp.s
.PHONY : record.cpp.s

start.o: start.cpp.o

.PHONY : start.o

# target to build an object file
start.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/start.cpp.o
.PHONY : start.cpp.o

start.i: start.cpp.i

.PHONY : start.i

# target to preprocess a source file
start.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/start.cpp.i
.PHONY : start.cpp.i

start.s: start.cpp.s

.PHONY : start.s

# target to generate assembly for a file
start.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re_project.dir/build.make CMakeFiles/re_project.dir/start.cpp.s
.PHONY : start.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... re_project"
	@echo "... doctor.o"
	@echo "... doctor.i"
	@echo "... doctor.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... my_time.o"
	@echo "... my_time.i"
	@echo "... my_time.s"
	@echo "... patient.o"
	@echo "... patient.i"
	@echo "... patient.s"
	@echo "... record.o"
	@echo "... record.i"
	@echo "... record.s"
	@echo "... start.o"
	@echo "... start.i"
	@echo "... start.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

