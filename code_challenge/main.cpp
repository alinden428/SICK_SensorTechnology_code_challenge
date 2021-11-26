// Title: Toy robot code challenge for SICK sensor technologies
// Author: Alex Linden
// Created: 24/11/2021
// Main function

#include "code_challenge.h"
#include "iostream"

using namespace std;



int main()
{
	int my_x = 0;
	int my_y = 1;
	string my_dir = "NORTH";
	myRobot newRobot = myRobot();
	newRobot.place(my_x, my_y, my_dir);
	newRobot.report();



}



