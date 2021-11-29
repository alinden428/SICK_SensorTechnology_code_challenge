// Title: Toy robot code challenge for SICK sensor technologies
// Author: Alex Linden
// Created: 24/11/2021
// Function implementation

#include "code_challenge.h"
#include "iostream"
#include "regex"

using namespace std;

myRobot::myRobot() : x{ 10 }, y{ 10 }, direction{ "" }, stringForTesting{ "" }
{
}

myRobot::~myRobot() {}

void myRobot::place(unsigned short int new_x, unsigned short int new_y, string new_direction)
{
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
		return;
	}
	if (this->direction == "WEST")
	{
		if (leftOrRight == "LEFT") this->direction = "SOUTH";
		if (leftOrRight == "RIGHT") this->direction = "NORTH";
		return;
	}
	if (this->direction == "SOUTH")
	{
		if (leftOrRight == "LEFT") this->direction = "EAST";
		if (leftOrRight == "RIGHT") this->direction = "WEST";
		return;
	}
	if (this->direction == "EAST")
	{
		if (leftOrRight == "LEFT") this->direction = "NORTH";
		if (leftOrRight == "RIGHT") this->direction = "SOUTH";
		return;
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

void myRobot::report()		//this could be implemented as << operator instead
{
	cout << this->x << "," << this->y << "," + this->direction << endl;
}

istream& operator>>(istream& aInstream, myRobot& newRobot)
{
	string new_x, new_y, dir, input;
	regex placeRegex("[pP][lL][aA][cC][eE]\\s[0-4][,][0-4][,][nNsSwWeE][a-zA-Z]{1,4}"); //robot can only be placed within 5x5 unit table
	regex funcRegex("[a-zA-Z]{1,6}");


	if (newRobot.stringForTesting == "") //While not unit testing, behave as designed
	{
		cin.clear();			//clean input buffer
		getline(cin, input);	//accept user input with whitespace
	}
	else
	{
		input = newRobot.stringForTesting;
	}

	if (input == "exit" || input == "e")
	{
		exit(0); //exit .exe
	}

	//robot is inialised at 10,10. This is off the table. Only accept report() move() or rotate() after place()
	if (newRobot.x == 10 || newRobot.y == 10)
	{
		if (regex_match(input, placeRegex))
		{
			//Explicit input we know x and y will be string index 6 and 8
			new_x.append(input, 6, 1);
			new_y.append(input, 8, 1);
			dir.append(input, 10, 5);
			for (auto& x : dir) x = toupper(x);				//captilise e.g. north to NORTH
			newRobot.place(stoi(new_x), stoi(new_y), dir);	//place() at user input
		}
	}
	else if (newRobot.x != 10 && newRobot.y != 10)
	{
		if (regex_match(input, funcRegex))
		{
			for (auto& x : input) x = toupper(x);			//captilise input string
			if (input == "MOVE") newRobot = newRobot.move();
			if (input == "LEFT") newRobot.rotate(input);
			if (input == "RIGHT") newRobot.rotate(input);
			if (input == "REPORT") newRobot.report();
		}
		if (regex_match(input, placeRegex))
		{
			new_x.append(input, 6, 1);
			new_y.append(input, 8, 1);
			dir.append(input, 10, 5);
			for (auto& x : dir) x = toupper(x);				//captilise input string 
			newRobot.place(stoi(new_x), stoi(new_y), dir);	//place() at user input
		}
	}
	return aInstream;
}

void myRobot::attachUnitTestString(string unitTestingString) 
{
	this->stringForTesting = unitTestingString;
}

short int myRobot::getX()
{
	return this->x;
}
short int myRobot::getY()
{
	return this->y;
}
string myRobot::getDir()
{
	return this->direction;
}