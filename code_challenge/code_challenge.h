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
	myRobot();
	~myRobot();
	void place(unsigned short int new_x, unsigned short int new_y, string new_direction);
	myRobot move();
	bool dontFall();
	void rotate(string leftOrRight);
	void report();
	friend istream& operator>>(istream& aInstream, myRobot& newRobot);
private:
	unsigned short int x;
	unsigned short int y;
	string direction;
};