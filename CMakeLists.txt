
# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(This code_challenge)

project (${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include sub-projects.
#add_subdirectory (${This})

set(Headers
	code_challenge/code_challenge.h
)

set(source
	code_challenge/code_challenge.cpp
)

add_library(${This} STATIC ${source} ${Headers}) #//source folder already exists

add_subdirectory (tests)

# Add source to this project's executable.
add_executable (main "code_challenge/code_challenge.cpp" "code_challenge/code_challenge.h" "code_challenge/main.cpp")

# TODO: Add tests and install targets if needed.
install (TARGETS code_challenge DESTINATION "code_challenge/bin")