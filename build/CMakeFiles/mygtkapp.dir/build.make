# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vladislavmogilny65/programming/Upozn

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vladislavmogilny65/programming/Upozn/build

# Include any dependencies generated for this target.
include CMakeFiles/mygtkapp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mygtkapp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mygtkapp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mygtkapp.dir/flags.make

CMakeFiles/mygtkapp.dir/src/main.c.o: CMakeFiles/mygtkapp.dir/flags.make
CMakeFiles/mygtkapp.dir/src/main.c.o: /home/vladislavmogilny65/programming/Upozn/src/main.c
CMakeFiles/mygtkapp.dir/src/main.c.o: CMakeFiles/mygtkapp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/vladislavmogilny65/programming/Upozn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mygtkapp.dir/src/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mygtkapp.dir/src/main.c.o -MF CMakeFiles/mygtkapp.dir/src/main.c.o.d -o CMakeFiles/mygtkapp.dir/src/main.c.o -c /home/vladislavmogilny65/programming/Upozn/src/main.c

CMakeFiles/mygtkapp.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/mygtkapp.dir/src/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vladislavmogilny65/programming/Upozn/src/main.c > CMakeFiles/mygtkapp.dir/src/main.c.i

CMakeFiles/mygtkapp.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/mygtkapp.dir/src/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vladislavmogilny65/programming/Upozn/src/main.c -o CMakeFiles/mygtkapp.dir/src/main.c.s

CMakeFiles/mygtkapp.dir/src/windows/main-w.c.o: CMakeFiles/mygtkapp.dir/flags.make
CMakeFiles/mygtkapp.dir/src/windows/main-w.c.o: /home/vladislavmogilny65/programming/Upozn/src/windows/main-w.c
CMakeFiles/mygtkapp.dir/src/windows/main-w.c.o: CMakeFiles/mygtkapp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/vladislavmogilny65/programming/Upozn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/mygtkapp.dir/src/windows/main-w.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mygtkapp.dir/src/windows/main-w.c.o -MF CMakeFiles/mygtkapp.dir/src/windows/main-w.c.o.d -o CMakeFiles/mygtkapp.dir/src/windows/main-w.c.o -c /home/vladislavmogilny65/programming/Upozn/src/windows/main-w.c

CMakeFiles/mygtkapp.dir/src/windows/main-w.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/mygtkapp.dir/src/windows/main-w.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vladislavmogilny65/programming/Upozn/src/windows/main-w.c > CMakeFiles/mygtkapp.dir/src/windows/main-w.c.i

CMakeFiles/mygtkapp.dir/src/windows/main-w.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/mygtkapp.dir/src/windows/main-w.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vladislavmogilny65/programming/Upozn/src/windows/main-w.c -o CMakeFiles/mygtkapp.dir/src/windows/main-w.c.s

CMakeFiles/mygtkapp.dir/src/windows/login-w.c.o: CMakeFiles/mygtkapp.dir/flags.make
CMakeFiles/mygtkapp.dir/src/windows/login-w.c.o: /home/vladislavmogilny65/programming/Upozn/src/windows/login-w.c
CMakeFiles/mygtkapp.dir/src/windows/login-w.c.o: CMakeFiles/mygtkapp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/vladislavmogilny65/programming/Upozn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/mygtkapp.dir/src/windows/login-w.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mygtkapp.dir/src/windows/login-w.c.o -MF CMakeFiles/mygtkapp.dir/src/windows/login-w.c.o.d -o CMakeFiles/mygtkapp.dir/src/windows/login-w.c.o -c /home/vladislavmogilny65/programming/Upozn/src/windows/login-w.c

CMakeFiles/mygtkapp.dir/src/windows/login-w.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/mygtkapp.dir/src/windows/login-w.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vladislavmogilny65/programming/Upozn/src/windows/login-w.c > CMakeFiles/mygtkapp.dir/src/windows/login-w.c.i

CMakeFiles/mygtkapp.dir/src/windows/login-w.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/mygtkapp.dir/src/windows/login-w.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vladislavmogilny65/programming/Upozn/src/windows/login-w.c -o CMakeFiles/mygtkapp.dir/src/windows/login-w.c.s

CMakeFiles/mygtkapp.dir/src/windows/databasel/databasel.c.o: CMakeFiles/mygtkapp.dir/flags.make
CMakeFiles/mygtkapp.dir/src/windows/databasel/databasel.c.o: /home/vladislavmogilny65/programming/Upozn/src/windows/databasel/databasel.c
CMakeFiles/mygtkapp.dir/src/windows/databasel/databasel.c.o: CMakeFiles/mygtkapp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/vladislavmogilny65/programming/Upozn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/mygtkapp.dir/src/windows/databasel/databasel.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mygtkapp.dir/src/windows/databasel/databasel.c.o -MF CMakeFiles/mygtkapp.dir/src/windows/databasel/databasel.c.o.d -o CMakeFiles/mygtkapp.dir/src/windows/databasel/databasel.c.o -c /home/vladislavmogilny65/programming/Upozn/src/windows/databasel/databasel.c

CMakeFiles/mygtkapp.dir/src/windows/databasel/databasel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/mygtkapp.dir/src/windows/databasel/databasel.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vladislavmogilny65/programming/Upozn/src/windows/databasel/databasel.c > CMakeFiles/mygtkapp.dir/src/windows/databasel/databasel.c.i

CMakeFiles/mygtkapp.dir/src/windows/databasel/databasel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/mygtkapp.dir/src/windows/databasel/databasel.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vladislavmogilny65/programming/Upozn/src/windows/databasel/databasel.c -o CMakeFiles/mygtkapp.dir/src/windows/databasel/databasel.c.s

CMakeFiles/mygtkapp.dir/src/windows/admin-w.c.o: CMakeFiles/mygtkapp.dir/flags.make
CMakeFiles/mygtkapp.dir/src/windows/admin-w.c.o: /home/vladislavmogilny65/programming/Upozn/src/windows/admin-w.c
CMakeFiles/mygtkapp.dir/src/windows/admin-w.c.o: CMakeFiles/mygtkapp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/vladislavmogilny65/programming/Upozn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/mygtkapp.dir/src/windows/admin-w.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mygtkapp.dir/src/windows/admin-w.c.o -MF CMakeFiles/mygtkapp.dir/src/windows/admin-w.c.o.d -o CMakeFiles/mygtkapp.dir/src/windows/admin-w.c.o -c /home/vladislavmogilny65/programming/Upozn/src/windows/admin-w.c

CMakeFiles/mygtkapp.dir/src/windows/admin-w.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/mygtkapp.dir/src/windows/admin-w.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vladislavmogilny65/programming/Upozn/src/windows/admin-w.c > CMakeFiles/mygtkapp.dir/src/windows/admin-w.c.i

CMakeFiles/mygtkapp.dir/src/windows/admin-w.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/mygtkapp.dir/src/windows/admin-w.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vladislavmogilny65/programming/Upozn/src/windows/admin-w.c -o CMakeFiles/mygtkapp.dir/src/windows/admin-w.c.s

# Object files for target mygtkapp
mygtkapp_OBJECTS = \
"CMakeFiles/mygtkapp.dir/src/main.c.o" \
"CMakeFiles/mygtkapp.dir/src/windows/main-w.c.o" \
"CMakeFiles/mygtkapp.dir/src/windows/login-w.c.o" \
"CMakeFiles/mygtkapp.dir/src/windows/databasel/databasel.c.o" \
"CMakeFiles/mygtkapp.dir/src/windows/admin-w.c.o"

# External object files for target mygtkapp
mygtkapp_EXTERNAL_OBJECTS =

mygtkapp: CMakeFiles/mygtkapp.dir/src/main.c.o
mygtkapp: CMakeFiles/mygtkapp.dir/src/windows/main-w.c.o
mygtkapp: CMakeFiles/mygtkapp.dir/src/windows/login-w.c.o
mygtkapp: CMakeFiles/mygtkapp.dir/src/windows/databasel/databasel.c.o
mygtkapp: CMakeFiles/mygtkapp.dir/src/windows/admin-w.c.o
mygtkapp: CMakeFiles/mygtkapp.dir/build.make
mygtkapp: CMakeFiles/mygtkapp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/vladislavmogilny65/programming/Upozn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable mygtkapp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mygtkapp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mygtkapp.dir/build: mygtkapp
.PHONY : CMakeFiles/mygtkapp.dir/build

CMakeFiles/mygtkapp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mygtkapp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mygtkapp.dir/clean

CMakeFiles/mygtkapp.dir/depend:
	cd /home/vladislavmogilny65/programming/Upozn/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vladislavmogilny65/programming/Upozn /home/vladislavmogilny65/programming/Upozn /home/vladislavmogilny65/programming/Upozn/build /home/vladislavmogilny65/programming/Upozn/build /home/vladislavmogilny65/programming/Upozn/build/CMakeFiles/mygtkapp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/mygtkapp.dir/depend

