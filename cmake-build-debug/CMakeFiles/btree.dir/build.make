# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.1.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.1.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/btree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/btree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/btree.dir/flags.make

CMakeFiles/btree.dir/b_tree.c.obj: CMakeFiles/btree.dir/flags.make
CMakeFiles/btree.dir/b_tree.c.obj: ../b_tree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/btree.dir/b_tree.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\btree.dir\b_tree.c.obj   -c "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\b_tree.c"

CMakeFiles/btree.dir/b_tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/btree.dir/b_tree.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\b_tree.c" > CMakeFiles\btree.dir\b_tree.c.i

CMakeFiles/btree.dir/b_tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/btree.dir/b_tree.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\b_tree.c" -o CMakeFiles\btree.dir\b_tree.c.s

CMakeFiles/btree.dir/b_tree.c.obj.requires:

.PHONY : CMakeFiles/btree.dir/b_tree.c.obj.requires

CMakeFiles/btree.dir/b_tree.c.obj.provides: CMakeFiles/btree.dir/b_tree.c.obj.requires
	$(MAKE) -f CMakeFiles\btree.dir\build.make CMakeFiles/btree.dir/b_tree.c.obj.provides.build
.PHONY : CMakeFiles/btree.dir/b_tree.c.obj.provides

CMakeFiles/btree.dir/b_tree.c.obj.provides.build: CMakeFiles/btree.dir/b_tree.c.obj


CMakeFiles/btree.dir/main.c.obj: CMakeFiles/btree.dir/flags.make
CMakeFiles/btree.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/btree.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\btree.dir\main.c.obj   -c "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\main.c"

CMakeFiles/btree.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/btree.dir/main.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\main.c" > CMakeFiles\btree.dir\main.c.i

CMakeFiles/btree.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/btree.dir/main.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\main.c" -o CMakeFiles\btree.dir\main.c.s

CMakeFiles/btree.dir/main.c.obj.requires:

.PHONY : CMakeFiles/btree.dir/main.c.obj.requires

CMakeFiles/btree.dir/main.c.obj.provides: CMakeFiles/btree.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\btree.dir\build.make CMakeFiles/btree.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/btree.dir/main.c.obj.provides

CMakeFiles/btree.dir/main.c.obj.provides.build: CMakeFiles/btree.dir/main.c.obj


CMakeFiles/btree.dir/registry/registries_generator.c.obj: CMakeFiles/btree.dir/flags.make
CMakeFiles/btree.dir/registry/registries_generator.c.obj: ../registry/registries_generator.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/btree.dir/registry/registries_generator.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\btree.dir\registry\registries_generator.c.obj   -c "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\registry\registries_generator.c"

CMakeFiles/btree.dir/registry/registries_generator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/btree.dir/registry/registries_generator.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\registry\registries_generator.c" > CMakeFiles\btree.dir\registry\registries_generator.c.i

CMakeFiles/btree.dir/registry/registries_generator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/btree.dir/registry/registries_generator.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\registry\registries_generator.c" -o CMakeFiles\btree.dir\registry\registries_generator.c.s

CMakeFiles/btree.dir/registry/registries_generator.c.obj.requires:

.PHONY : CMakeFiles/btree.dir/registry/registries_generator.c.obj.requires

CMakeFiles/btree.dir/registry/registries_generator.c.obj.provides: CMakeFiles/btree.dir/registry/registries_generator.c.obj.requires
	$(MAKE) -f CMakeFiles\btree.dir\build.make CMakeFiles/btree.dir/registry/registries_generator.c.obj.provides.build
.PHONY : CMakeFiles/btree.dir/registry/registries_generator.c.obj.provides

CMakeFiles/btree.dir/registry/registries_generator.c.obj.provides.build: CMakeFiles/btree.dir/registry/registries_generator.c.obj


CMakeFiles/btree.dir/registry/registry.c.obj: CMakeFiles/btree.dir/flags.make
CMakeFiles/btree.dir/registry/registry.c.obj: ../registry/registry.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/btree.dir/registry/registry.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\btree.dir\registry\registry.c.obj   -c "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\registry\registry.c"

CMakeFiles/btree.dir/registry/registry.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/btree.dir/registry/registry.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\registry\registry.c" > CMakeFiles\btree.dir\registry\registry.c.i

CMakeFiles/btree.dir/registry/registry.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/btree.dir/registry/registry.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\registry\registry.c" -o CMakeFiles\btree.dir\registry\registry.c.s

CMakeFiles/btree.dir/registry/registry.c.obj.requires:

.PHONY : CMakeFiles/btree.dir/registry/registry.c.obj.requires

CMakeFiles/btree.dir/registry/registry.c.obj.provides: CMakeFiles/btree.dir/registry/registry.c.obj.requires
	$(MAKE) -f CMakeFiles\btree.dir\build.make CMakeFiles/btree.dir/registry/registry.c.obj.provides.build
.PHONY : CMakeFiles/btree.dir/registry/registry.c.obj.provides

CMakeFiles/btree.dir/registry/registry.c.obj.provides.build: CMakeFiles/btree.dir/registry/registry.c.obj


CMakeFiles/btree.dir/statistic.c.obj: CMakeFiles/btree.dir/flags.make
CMakeFiles/btree.dir/statistic.c.obj: ../statistic.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/btree.dir/statistic.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\btree.dir\statistic.c.obj   -c "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\statistic.c"

CMakeFiles/btree.dir/statistic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/btree.dir/statistic.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\statistic.c" > CMakeFiles\btree.dir\statistic.c.i

CMakeFiles/btree.dir/statistic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/btree.dir/statistic.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\statistic.c" -o CMakeFiles\btree.dir\statistic.c.s

CMakeFiles/btree.dir/statistic.c.obj.requires:

.PHONY : CMakeFiles/btree.dir/statistic.c.obj.requires

CMakeFiles/btree.dir/statistic.c.obj.provides: CMakeFiles/btree.dir/statistic.c.obj.requires
	$(MAKE) -f CMakeFiles\btree.dir\build.make CMakeFiles/btree.dir/statistic.c.obj.provides.build
.PHONY : CMakeFiles/btree.dir/statistic.c.obj.provides

CMakeFiles/btree.dir/statistic.c.obj.provides.build: CMakeFiles/btree.dir/statistic.c.obj


CMakeFiles/btree.dir/graph/graph_generator.c.obj: CMakeFiles/btree.dir/flags.make
CMakeFiles/btree.dir/graph/graph_generator.c.obj: ../graph/graph_generator.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/btree.dir/graph/graph_generator.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\btree.dir\graph\graph_generator.c.obj   -c "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\graph\graph_generator.c"

CMakeFiles/btree.dir/graph/graph_generator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/btree.dir/graph/graph_generator.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\graph\graph_generator.c" > CMakeFiles\btree.dir\graph\graph_generator.c.i

CMakeFiles/btree.dir/graph/graph_generator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/btree.dir/graph/graph_generator.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\graph\graph_generator.c" -o CMakeFiles\btree.dir\graph\graph_generator.c.s

CMakeFiles/btree.dir/graph/graph_generator.c.obj.requires:

.PHONY : CMakeFiles/btree.dir/graph/graph_generator.c.obj.requires

CMakeFiles/btree.dir/graph/graph_generator.c.obj.provides: CMakeFiles/btree.dir/graph/graph_generator.c.obj.requires
	$(MAKE) -f CMakeFiles\btree.dir\build.make CMakeFiles/btree.dir/graph/graph_generator.c.obj.provides.build
.PHONY : CMakeFiles/btree.dir/graph/graph_generator.c.obj.provides

CMakeFiles/btree.dir/graph/graph_generator.c.obj.provides.build: CMakeFiles/btree.dir/graph/graph_generator.c.obj


CMakeFiles/btree.dir/registry/Fisher_Yates.c.obj: CMakeFiles/btree.dir/flags.make
CMakeFiles/btree.dir/registry/Fisher_Yates.c.obj: ../registry/Fisher_Yates.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/btree.dir/registry/Fisher_Yates.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\btree.dir\registry\Fisher_Yates.c.obj   -c "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\registry\Fisher_Yates.c"

CMakeFiles/btree.dir/registry/Fisher_Yates.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/btree.dir/registry/Fisher_Yates.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\registry\Fisher_Yates.c" > CMakeFiles\btree.dir\registry\Fisher_Yates.c.i

CMakeFiles/btree.dir/registry/Fisher_Yates.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/btree.dir/registry/Fisher_Yates.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\registry\Fisher_Yates.c" -o CMakeFiles\btree.dir\registry\Fisher_Yates.c.s

CMakeFiles/btree.dir/registry/Fisher_Yates.c.obj.requires:

.PHONY : CMakeFiles/btree.dir/registry/Fisher_Yates.c.obj.requires

CMakeFiles/btree.dir/registry/Fisher_Yates.c.obj.provides: CMakeFiles/btree.dir/registry/Fisher_Yates.c.obj.requires
	$(MAKE) -f CMakeFiles\btree.dir\build.make CMakeFiles/btree.dir/registry/Fisher_Yates.c.obj.provides.build
.PHONY : CMakeFiles/btree.dir/registry/Fisher_Yates.c.obj.provides

CMakeFiles/btree.dir/registry/Fisher_Yates.c.obj.provides.build: CMakeFiles/btree.dir/registry/Fisher_Yates.c.obj


# Object files for target btree
btree_OBJECTS = \
"CMakeFiles/btree.dir/b_tree.c.obj" \
"CMakeFiles/btree.dir/main.c.obj" \
"CMakeFiles/btree.dir/registry/registries_generator.c.obj" \
"CMakeFiles/btree.dir/registry/registry.c.obj" \
"CMakeFiles/btree.dir/statistic.c.obj" \
"CMakeFiles/btree.dir/graph/graph_generator.c.obj" \
"CMakeFiles/btree.dir/registry/Fisher_Yates.c.obj"

# External object files for target btree
btree_EXTERNAL_OBJECTS =

btree.exe: CMakeFiles/btree.dir/b_tree.c.obj
btree.exe: CMakeFiles/btree.dir/main.c.obj
btree.exe: CMakeFiles/btree.dir/registry/registries_generator.c.obj
btree.exe: CMakeFiles/btree.dir/registry/registry.c.obj
btree.exe: CMakeFiles/btree.dir/statistic.c.obj
btree.exe: CMakeFiles/btree.dir/graph/graph_generator.c.obj
btree.exe: CMakeFiles/btree.dir/registry/Fisher_Yates.c.obj
btree.exe: CMakeFiles/btree.dir/build.make
btree.exe: CMakeFiles/btree.dir/linklibs.rsp
btree.exe: CMakeFiles/btree.dir/objects1.rsp
btree.exe: CMakeFiles/btree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable btree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\btree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/btree.dir/build: btree.exe

.PHONY : CMakeFiles/btree.dir/build

CMakeFiles/btree.dir/requires: CMakeFiles/btree.dir/b_tree.c.obj.requires
CMakeFiles/btree.dir/requires: CMakeFiles/btree.dir/main.c.obj.requires
CMakeFiles/btree.dir/requires: CMakeFiles/btree.dir/registry/registries_generator.c.obj.requires
CMakeFiles/btree.dir/requires: CMakeFiles/btree.dir/registry/registry.c.obj.requires
CMakeFiles/btree.dir/requires: CMakeFiles/btree.dir/statistic.c.obj.requires
CMakeFiles/btree.dir/requires: CMakeFiles/btree.dir/graph/graph_generator.c.obj.requires
CMakeFiles/btree.dir/requires: CMakeFiles/btree.dir/registry/Fisher_Yates.c.obj.requires

.PHONY : CMakeFiles/btree.dir/requires

CMakeFiles/btree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\btree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/btree.dir/clean

CMakeFiles/btree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B" "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B" "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\cmake-build-debug" "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\cmake-build-debug" "D:\Cloud_Storage\Google Drive\Faculdade\Semestre 3\AEDS II\Trabalhos Praticos\AEDS2_Aplicacao_Arvore_B\cmake-build-debug\CMakeFiles\btree.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/btree.dir/depend

