


// Title: Toy robot code challenge for SICK sensor technologies
// Author: Alex Linden
// Created: 24/11/2021
// Function implementation

#include "code_challenge.h"
#include "iostream"

using namespace std;

myRobot::myRobot(unsigned short int X, unsigned short int Y, string dir)
{
	x = X;
	y = Y;
	direction = dir;
}

myRobot::~myRobot() {}

void myRobot::place(unsigned short int new_x, unsigned short int new_y, string new_direction, myRobot newRobot)
{
	newRobot.x = new_x;
	newRobot.y = new_y;
	newRobot.direction = new_direction;
}

void myRobot::move()
{

}

void myRobot::dontFall()
{

}

void myRobot::report()
{

}