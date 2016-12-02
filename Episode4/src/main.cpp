//============================================================================
// Name        : SDL_Basic.cpp
// Author      : ThomasWilliams
// Version     :
// Copyright   : Copyright 2016 Thomas Williams
// Description : Basic SDL program that displays a white screen. Can now be
//				 used in later projects, to create the Coding Math library
//				 in C++
//============================================================================

#include <iostream>
#include <math.h>
#include <SDL.h>
#include <time.h>
#include "Screen.h"

int main(int argc, char* argv[]) {

	codingmath::Screen screen;

	srand(time(NULL));

	if (!screen.init()) {
		std::cout << "Error initialising SDL." << std::endl;
	}

	screen.clear();

	double centerY = screen.SCREEN_HEIGHT * 0.5;
	double centerX = screen.SCREEN_WIDTH * 0.5;
	double xRadius = 400;
	double yRadius = 200;
	double xSpeed = 0.1;
	double ySpeed = 0.131;
	double xAngle = 0.0;
	double yAngle = 0.0;
	double x, y = 0.0;
	double width = 10.0;

	// While loop used to keep track of if user has clicked x to quit
	while (true) {

		//screen.clear();

		x = centerX + cos(xAngle) * xRadius;
		y = centerY + sin(yAngle) * yRadius;

		screen.drawRect(x - width/2, y - width/2, width, width);

		screen.present();

		xAngle += xSpeed;
		yAngle += ySpeed;

		// Check for messages/events
		if (!screen.processEvents()) {
			break;
		}

	}

	screen.close();

	return 0;
}
