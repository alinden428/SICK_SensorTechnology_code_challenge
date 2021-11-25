// Title: Toy robot code challenge for SICK sensor technologies
// Author: Alex Linden
// Created: 24/11/2021
// Function prototypes

#pragma once

#include <iostream>

using namespace std;

class myRobot
{
public:
	myRobot(unsigned short int X, unsigned short int Y, string dir);
	~myRobot();
	void place(unsigned short int new_x, unsigned short int new_y, string new_direction, myRobot newRobot);
	void move();
	void dontFall();
	void report();
private:
	unsigned short int x;
	unsigned short int y;
	string direction;
};