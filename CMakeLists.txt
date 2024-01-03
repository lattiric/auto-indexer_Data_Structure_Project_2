cmake_minimum_required(VERSION 3.17)
project(21s_pa02_lattiric)

set(CMAKE_CXX_STANDARD 14)

set (input01 "keywords1.txt")
set (input02 "grading1.txt")
set (input03 "output.txt")

# Copy data files to build dir
foreach(file IN LISTS input01 input02)
    configure_file(${file} ${file} COPYONLY)
endforeach()

Include(FetchContent)           #added for test script
#https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#top
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_STANDARD 17)
add_executable(indexer main.cpp DSVector.h Page.cpp Page.h Test.cpp DSString.cpp DSString.h AnalyzeText.cpp AnalyzeText.h)
#target_link_libraries(${EXE_NAME} PRIVATE Catch2::Catch2)