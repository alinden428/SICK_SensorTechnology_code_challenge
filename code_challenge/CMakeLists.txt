# CMakeList.txt : CMake project for code_challenge, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (code_challenge "code_challenge.cpp" "code_challenge.h" "main.cpp")

# TODO: Add tests and install targets if needed.
install (TARGETS code_challenge DESTINATION "code_challenge/bin")
