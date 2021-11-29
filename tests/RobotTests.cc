#include "gtest/gtest.h"
#include "../code_challenge/code_challenge.h"

bool result;

//Simulating Command line user input
string place = "place 3,1,north"; //place command
string report = "report";
string moveFunc = "move";
string leftStr = "left";
string rightStr = "right";

myRobot newRobot = myRobot();

TEST(RobotTests, PlaceReportTest) {
	//report() simply prints the private elements of a myRobot object, thus this test covers
	//both place() and report()
	newRobot.attachUnitTestString(place);
	cin >> newRobot;
	if (newRobot.getX() == 3 && newRobot.getY() == 1 && newRobot.getDir() == "NORTH") {
		result = true;
	}
	else
	{
		result = false;
	}
	EXPECT_TRUE(result);
}

TEST(RobotTests, MoveNorthTest) {
	newRobot.attachUnitTestString(place);
	cin >> newRobot;
	newRobot.attachUnitTestString(moveFunc);
	cin >> newRobot;
	if (newRobot.getY() == 2 && newRobot.getDir() == "NORTH")
	{
		result = true;
	}
	else
	{
		result = false;
	}
	EXPECT_TRUE(result);
}

TEST(RobotTests, MoveSouthTest) {
	newRobot.attachUnitTestString(place);
	cin >> newRobot;
	newRobot.attachUnitTestString(leftStr);
	cin >> newRobot;
	cin >> newRobot; //rotato 180 degrees
	newRobot.attachUnitTestString(moveFunc);
	cin >> newRobot;
	if (newRobot.getY() == 0 && newRobot.getDir() == "SOUTH")
	{
		result = true;
	}
	else
	{
		result = false;
	}
	EXPECT_TRUE(result);
}

TEST(RobotTests, MoveEastTest) {
	newRobot.attachUnitTestString(place);
	cin >> newRobot;
	newRobot.attachUnitTestString(rightStr);
	cin >> newRobot;
	newRobot.attachUnitTestString(moveFunc);
	cin >> newRobot;
	if (newRobot.getX() == 2 && newRobot.getDir() == "EAST")
	{
		result = true;
	}
	else
	{
		result = false;
	}
	EXPECT_TRUE(result);
}

TEST(RobotTests, MoveWestTest) {
	newRobot.attachUnitTestString(place);
	cin >> newRobot;
	newRobot.attachUnitTestString(leftStr);
	cin >> newRobot;
	newRobot.attachUnitTestString(moveFunc);
	cin >> newRobot;
	if (newRobot.getX() == 4 && newRobot.getDir() == "WEST")
	{
		result = true;
	}
	else
	{
		result = false;
	}
	EXPECT_TRUE(result);
}

TEST(RobotTests, RotateLeftTest) {
	newRobot.attachUnitTestString(place);
	cin >> newRobot;
	newRobot.attachUnitTestString(leftStr);
	cin >> newRobot;
	if (newRobot.getY() == 1 && newRobot.getDir() == "WEST")
	{
		result = true;
	}
	else
	{
		result = false;
	}
	EXPECT_TRUE(result);
}

TEST(RobotTests, RotateRightTest) {
	newRobot.attachUnitTestString(place);
	cin >> newRobot;
	newRobot.attachUnitTestString(rightStr);
	cin >> newRobot;
	if (newRobot.getY() == 1 && newRobot.getDir() == "EAST")
	{
		result = true;
	}
	else
	{
		result = false;
	}
	EXPECT_TRUE(result);
}