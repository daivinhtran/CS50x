#include <iostream>
#include "Robot.h"
using namespace std;

int main()
{
	Robot myRobot;
	int initial_xPosition, initial_yPosition;
	
	cout << "Please enter starting x position: ";
	cin >> initial_xPosition;
	cout << "Please enter starting y position: ";
	cin >> initial_yPosition;
	
	myRobot.setXPosition(initial_xPosition);
	myRobot.setYPosition(initial_yPosition);
	
	myRobot.inputBoundary();
	
	while(1)
	{
		myRobot.inputMove();
		myRobot.displayPosition();
	}
}
