# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/nikita/Загрузки/clion-2020.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/nikita/Загрузки/clion-2020.2.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nikita/prog/sem3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nikita/prog/sem3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sem3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sem3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sem3.dir/flags.make

CMakeFiles/sem3.dir/main.cpp.o: CMakeFiles/sem3.dir/flags.make
CMakeFiles/sem3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikita/prog/sem3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sem3.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sem3.dir/main.cpp.o -c /home/nikita/prog/sem3/main.cpp

CMakeFiles/sem3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sem3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nikita/prog/sem3/main.cpp > CMakeFiles/sem3.dir/main.cpp.i

CMakeFiles/sem3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sem3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nikita/prog/sem3/main.cpp -o CMakeFiles/sem3.dir/main.cpp.s

CMakeFiles/sem3.dir/Myfork.c.o: CMakeFiles/sem3.dir/flags.make
CMakeFiles/sem3.dir/Myfork.c.o: ../Myfork.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikita/prog/sem3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/sem3.dir/Myfork.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sem3.dir/Myfork.c.o   -c /home/nikita/prog/sem3/Myfork.c

CMakeFiles/sem3.dir/Myfork.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sem3.dir/Myfork.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nikita/prog/sem3/Myfork.c > CMakeFiles/sem3.dir/Myfork.c.i

CMakeFiles/sem3.dir/Myfork.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sem3.dir/Myfork.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nikita/prog/sem3/Myfork.c -o CMakeFiles/sem3.dir/Myfork.c.s

CMakeFiles/sem3.dir/myexec.c.o: CMakeFiles/sem3.dir/flags.make
CMakeFiles/sem3.dir/myexec.c.o: ../myexec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikita/prog/sem3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/sem3.dir/myexec.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sem3.dir/myexec.c.o   -c /home/nikita/prog/sem3/myexec.c

CMakeFiles/sem3.dir/myexec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sem3.dir/myexec.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nikita/prog/sem3/myexec.c > CMakeFiles/sem3.dir/myexec.c.i

CMakeFiles/sem3.dir/myexec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sem3.dir/myexec.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nikita/prog/sem3/myexec.c -o CMakeFiles/sem3.dir/myexec.c.s

CMakeFiles/sem3.dir/Myfork2.c.o: CMakeFiles/sem3.dir/flags.make
CMakeFiles/sem3.dir/Myfork2.c.o: ../Myfork2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikita/prog/sem3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/sem3.dir/Myfork2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sem3.dir/Myfork2.c.o   -c /home/nikita/prog/sem3/Myfork2.c

CMakeFiles/sem3.dir/Myfork2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sem3.dir/Myfork2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nikita/prog/sem3/Myfork2.c > CMakeFiles/sem3.dir/Myfork2.c.i

CMakeFiles/sem3.dir/Myfork2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sem3.dir/Myfork2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nikita/prog/sem3/Myfork2.c -o CMakeFiles/sem3.dir/Myfork2.c.s

CMakeFiles/sem3.dir/Myco.c.o: CMakeFiles/sem3.dir/flags.make
CMakeFiles/sem3.dir/Myco.c.o: ../Myco.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikita/prog/sem3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/sem3.dir/Myco.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sem3.dir/Myco.c.o   -c /home/nikita/prog/sem3/Myco.c

CMakeFiles/sem3.dir/Myco.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sem3.dir/Myco.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nikita/prog/sem3/Myco.c > CMakeFiles/sem3.dir/Myco.c.i

CMakeFiles/sem3.dir/Myco.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sem3.dir/Myco.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nikita/prog/sem3/Myco.c -o CMakeFiles/sem3.dir/Myco.c.s

# Object files for target sem3
sem3_OBJECTS = \
"CMakeFiles/sem3.dir/main.cpp.o" \
"CMakeFiles/sem3.dir/Myfork.c.o" \
"CMakeFiles/sem3.dir/myexec.c.o" \
"CMakeFiles/sem3.dir/Myfork2.c.o" \
"CMakeFiles/sem3.dir/Myco.c.o"

# External object files for target sem3
sem3_EXTERNAL_OBJECTS =

sem3: CMakeFiles/sem3.dir/main.cpp.o
sem3: CMakeFiles/sem3.dir/Myfork.c.o
sem3: CMakeFiles/sem3.dir/myexec.c.o
sem3: CMakeFiles/sem3.dir/Myfork2.c.o
sem3: CMakeFiles/sem3.dir/Myco.c.o
sem3: CMakeFiles/sem3.dir/build.make
sem3: CMakeFiles/sem3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nikita/prog/sem3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable sem3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sem3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sem3.dir/build: sem3

.PHONY : CMakeFiles/sem3.dir/build

CMakeFiles/sem3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sem3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sem3.dir/clean

CMakeFiles/sem3.dir/depend:
	cd /home/nikita/prog/sem3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nikita/prog/sem3 /home/nikita/prog/sem3 /home/nikita/prog/sem3/cmake-build-debug /home/nikita/prog/sem3/cmake-build-debug /home/nikita/prog/sem3/cmake-build-debug/CMakeFiles/sem3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sem3.dir/depend
