# Code Challenge for Sick Sensor Intelligence, completed by Alexander Linden 

The approach used to complete this task involved several steps.

The first step was to break the project down into separate tasks. These can be viewed in the Projects tab of this repository.

The tasks were:
- Initial commit
- Plan each task, provide detail and context
- Basic design, create header file outlining each function, method
- Implementation .cpp 
- Create and verify unit tests with google test and ctest
- Modify install targets within cmake (Done during the previous task)
- Create github action workflow for automated testing

The second step was to interpret the project requirements:
 - Robot has to be placed before move and rotate commands can be issued
 - Must be a command line program
 - Robot needs to be able to report its position and coordinates through the console
 - Robot must not fall off the table (5 x 5 units)
 - Commands that would see the robot fall must be ignored, but must still allow future valid commands
 
In order to address these requirements, the following was implemented:

1. When an object of type myRobot() is initalised it is set to 10,10 (a point off the table). 

*if (newRobot.x == 10 || newRobot.y == 10)*
 
This check determines if move, rotate and report commands can be issued. 

2. Regular expressions are used to ensure user input follows the desired input format explicitly.

3. A report function simply prints the private elements of a myRobot object to the console. 

4. A boolen function dontfall() is used to check if the robot is on either of the four table edges. 
The southwest corner of the table is the origin (0,0) (x,y)

 
 All the build tools required are included in project repository, there may be a few tweaks needed to build through ubuntu. 
