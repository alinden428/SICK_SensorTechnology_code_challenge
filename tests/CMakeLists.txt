# CMakeList.txt : CMake project for code_challenge, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.8)

set (This RobotTests)

set (Sources
	RobotTests.cc
)

add_executable(${This} ${Sources})

target_link_libraries (${This} PUBLIC
	gtest_main
	code_challenge
)

add_test(
	NAME ${This}
	COMMAND ${This}
)