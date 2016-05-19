#include <iostream>
#include <string>
#include <limits>
#include "Robot.h"
using namespace std;

// Initialize position to be (0,0) and x and y boundaries to be zeros
Robot::Robot()
	: xPosition(0), yPosition(0), xBoundary(0), yBoundary(0)
	{
	
	}

//function to set the x position	
void Robot::setXPosition(int desired_x)
{
	xPosition = desired_x;
}

//function to set the y position
void Robot::setYPosition(int desired_y)
{
	yPosition = desired_y;
}

int Robot::getXPosition() const
{
	return xPosition;
}

int Robot::getYPosition() const
{
	return yPosition;
}

void Robot::moveWest(int distance) 
{
	cout << "moveWest executing" << endl;

	int temp = xPosition - distance;
	if ((temp - xBoundary > 0) || (xBoundary + temp < 0))
		cout << "Out of boundary x"<<endl;		
	else
		setXPosition(temp);
}

void Robot::moveEast(int distance) 
{
	int temp = xPosition + distance;
	
	
	if ((temp - xBoundary > 0) || (xBoundary + temp < 0))
		cout << "Out of boundary X"<<endl;		
	else
		setXPosition(temp);
}

void Robot::moveNorth(int distance) 
{
	int temp = yPosition + distance;
	if ((temp - yBoundary > 0) || (yBoundary + temp < 0))
		cout << "Out of boundary Y"<<endl;		
	else
		setYPosition(temp);
}

void Robot::moveSouth(int distance) 
{
	int temp = yPosition - distance;
	if ((temp - yBoundary > 0) || (yBoundary + temp < 0))
		cout << "Out of boundary Y"<<endl;		
	else
		setYPosition(temp);
}

void Robot::inputBoundary()
{
	
	cout << "Please enter target x position: ";
	cin >> xBoundary;
	cout << "Please enter target y position: ";
	cin >> yBoundary;
}

void Robot::inputMove()
{
	string desired_direction;
	int desired_distance;
	cout << "Please enter the direction the robot should move (W, E, N, or S), followed by a positive ‌integer distance: ";
	cin >> desired_direction >> desired_distance;
	
	if(desired_direction.compare("W") == 0)
	{
		moveWest(desired_distance);
	}
	else if(desired_direction.compare("E") == 0)
	{
		moveEast(desired_distance);
	}
	else if(desired_direction.compare("N") == 0)
	{
		moveNorth(desired_distance);
	}
	else if(desired_direction.compare("S") == 0)
	{
		moveSouth(desired_distance);
	}
	else
	{
		cerr << "Please enter a valid direction (e.g. S 2)" <<endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}	

void Robot::displayPosition() const
{
	cout << "Robot is located at x = " << xPosition << " and y = " << yPosition << endl << endl;
}	





















