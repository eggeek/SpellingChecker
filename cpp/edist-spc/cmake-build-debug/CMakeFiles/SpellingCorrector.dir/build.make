# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SpellingCorrector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SpellingCorrector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SpellingCorrector.dir/flags.make

CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.o: CMakeFiles/SpellingCorrector.dir/flags.make
CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.o: ../SpellingCorrector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.o -c /Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc/SpellingCorrector.cpp

CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc/SpellingCorrector.cpp > CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.i

CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc/SpellingCorrector.cpp -o CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.s

CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.o.requires:

.PHONY : CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.o.requires

CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.o.provides: CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.o.requires
	$(MAKE) -f CMakeFiles/SpellingCorrector.dir/build.make CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.o.provides.build
.PHONY : CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.o.provides

CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.o.provides.build: CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.o


CMakeFiles/SpellingCorrector.dir/Trie.cpp.o: CMakeFiles/SpellingCorrector.dir/flags.make
CMakeFiles/SpellingCorrector.dir/Trie.cpp.o: ../Trie.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SpellingCorrector.dir/Trie.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpellingCorrector.dir/Trie.cpp.o -c /Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc/Trie.cpp

CMakeFiles/SpellingCorrector.dir/Trie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpellingCorrector.dir/Trie.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc/Trie.cpp > CMakeFiles/SpellingCorrector.dir/Trie.cpp.i

CMakeFiles/SpellingCorrector.dir/Trie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpellingCorrector.dir/Trie.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc/Trie.cpp -o CMakeFiles/SpellingCorrector.dir/Trie.cpp.s

CMakeFiles/SpellingCorrector.dir/Trie.cpp.o.requires:

.PHONY : CMakeFiles/SpellingCorrector.dir/Trie.cpp.o.requires

CMakeFiles/SpellingCorrector.dir/Trie.cpp.o.provides: CMakeFiles/SpellingCorrector.dir/Trie.cpp.o.requires
	$(MAKE) -f CMakeFiles/SpellingCorrector.dir/build.make CMakeFiles/SpellingCorrector.dir/Trie.cpp.o.provides.build
.PHONY : CMakeFiles/SpellingCorrector.dir/Trie.cpp.o.provides

CMakeFiles/SpellingCorrector.dir/Trie.cpp.o.provides.build: CMakeFiles/SpellingCorrector.dir/Trie.cpp.o


# Object files for target SpellingCorrector
SpellingCorrector_OBJECTS = \
"CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.o" \
"CMakeFiles/SpellingCorrector.dir/Trie.cpp.o"

# External object files for target SpellingCorrector
SpellingCorrector_EXTERNAL_OBJECTS =

../SpellingCorrector: CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.o
../SpellingCorrector: CMakeFiles/SpellingCorrector.dir/Trie.cpp.o
../SpellingCorrector: CMakeFiles/SpellingCorrector.dir/build.make
../SpellingCorrector: CMakeFiles/SpellingCorrector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../SpellingCorrector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SpellingCorrector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SpellingCorrector.dir/build: ../SpellingCorrector

.PHONY : CMakeFiles/SpellingCorrector.dir/build

CMakeFiles/SpellingCorrector.dir/requires: CMakeFiles/SpellingCorrector.dir/SpellingCorrector.cpp.o.requires
CMakeFiles/SpellingCorrector.dir/requires: CMakeFiles/SpellingCorrector.dir/Trie.cpp.o.requires

.PHONY : CMakeFiles/SpellingCorrector.dir/requires

CMakeFiles/SpellingCorrector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SpellingCorrector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SpellingCorrector.dir/clean

CMakeFiles/SpellingCorrector.dir/depend:
	cd /Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc /Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc /Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc/cmake-build-debug /Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc/cmake-build-debug /Users/eggeek/Dropbox/eggeek.me/Dropbox/Research-Method/mini-proj/spelling-checker-analysis/edist-spc/cmake-build-debug/CMakeFiles/SpellingCorrector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SpellingCorrector.dir/depend

