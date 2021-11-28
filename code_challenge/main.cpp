// Title: Toy robot code challenge for SICK sensor technologies
// Author: Alex Linden
// Created: 24/11/2021
// Main function

#include "code_challenge.h"
#include "iostream"

using namespace std;


void parseInput()
{

}

int main()
{
	int my_x = 3;
	int my_y = 3;
	string input = "RIGHT";
	string my_dir = "WEST";
	myRobot newRobot = myRobot();
	newRobot.place(my_x, my_y, my_dir);
	newRobot.report();
	newRobot = newRobot.move();
	newRobot.report();
	newRobot.rotate(input);
	newRobot.report();
	//while (!(cin >> ))

}



