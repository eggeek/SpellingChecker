cmake_minimum_required(VERSION 3.8)
project(edist_spc)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        SpellingCorrector.cpp
        SpellingCorrector.h
        Trie.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
add_executable(SpellingCorrector ${SOURCE_FILES})