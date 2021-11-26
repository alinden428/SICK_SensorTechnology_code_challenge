


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
	if (this->dontFall()) {
		//assign robot coordinates to chosen location
		this->x = new_x;
		this->y = new_y;
		this->direction = new_direction;
	}
	else 
	{
		//In this path do not modify this->x,y,dir
		cout << "You must place the robot on the table within 0-4,0-4,XXXX";

	}

}

myRobot myRobot::move()
{	
	myRobot returnRobot = *this;
	string what_dir = this->direction;
	if (this->dontFall()) 
	{
		if (what_dir == "NORTH") returnRobot.y = returnRobot.y + 1;
		if (what_dir == "SOUTH") returnRobot.y = returnRobot.y - 1;
		if (what_dir == "WEST") returnRobot.x = returnRobot.x + 1;
		if (what_dir == "EAST") returnRobot.x = returnRobot.x - 1;
		return returnRobot;
	}
	//else do nothing as per project specification.
	return *this;
}

void myRobot::rotate(string leftOrRight)
{
	if (this->direction == "NORTH")
	{
		if (leftOrRight == "LEFT") this->direction = "WEST";
		if (leftOrRight == "RIGHT") this->direction = "EAST";
	}
	if (this->direction == "WEST")
	{
		if (leftOrRight == "LEFT") this->direction = "SOUTH";
		if (leftOrRight == "RIGHT") this->direction = "NORTH";
	}
	if (this->direction == "SOUTH")
	{
		if (leftOrRight == "LEFT") this->direction = "EAST";
		if (leftOrRight == "RIGHT") this->direction = "WEST";
	}
	if (this->direction == "EAST")
	{
		if (leftOrRight == "LEFT") this->direction = "NORTH";
		if (leftOrRight == "RIGHT") this->direction = "SOUTH";
	}
}

bool myRobot::dontFall()
{
	//Robot cannot move north past X,4; south past X,0; west past 4,Y; east past 0,Y
	if (this->direction == "NORTH") 
	{
		if (this->y <= 3) return true; 
		return false;
	}
	else if (this->direction == "WEST")
	{
		if (this->x <= 3) return true; 
		return false;
	}
	else if (this->direction == "SOUTH")
	{
		if (this->y >= 1) return true; 
		return false;
	}
	else if (this->direction == "EAST")
	{
		if (this->x >= 1) return true; 
		return false;
	}
	cout << "There was some error~in dontFall()!" << endl;
	return false;

}

void myRobot::report()
{
	cout << this->x << "," << this->y << "," + this->direction << endl;
}
