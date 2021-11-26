


// Title: Toy robot code challenge for SICK sensor technologies
// Author: Alex Linden
// Created: 24/11/2021
// Function implementation

#include "code_challenge.h"
#include "iostream"

using namespace std;

myRobot::myRobot()
{
	x = 0;
	y = 0;
	direction = "";
}

myRobot::~myRobot() {}

void myRobot::place(unsigned short int new_x, unsigned short int new_y, string new_direction)
{	
	//unsigned short int old_x = this->x;
	//unsigned short int old_y = this->y;
	//string old_dir = this->direction;

	//assign robot coordinates to chosen location
	this->x = new_x;
	this->y = new_y;
	this->direction = new_direction;
}

myRobot myRobot::move()
{	
	myRobot returnRobot = *this;
	string what_dir = this->direction;
	if (this->dontFall()) 
	{
		if (what_dir == "NORTH")
		{
			returnRobot.x + 1;
		}
		if (what_dir == "SOUTH")
		{
			returnRobot.x - 1;
		}
		if (what_dir == "WEST")
		{
			returnRobot.y + 1;
		}
		if (what_dir == "EAST")
		{
			returnRobot.y -  1;
		}
		return returnRobot;
	}
	//else do nothing as per project specification.
	return *this;
}

bool myRobot::dontFall()
{
	//Robot cannot move north past X,4; south past X,0; west past 4,Y; east past 0,Y
	return true;

}

void myRobot::report()
{
	cout << this->x << "," << this->y << "," + this->direction << endl;
}
