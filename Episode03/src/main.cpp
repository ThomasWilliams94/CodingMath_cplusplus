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

	double centerY, centerX, baseWidth, offset, speed, angle;

	centerY = screen.SCREEN_HEIGHT * 0.5;
	centerX = screen.SCREEN_WIDTH * 0.5;
	baseWidth = 100;
	offset = 50;
	speed = 0.05;
	angle = 0.0;

	// While loop used to keep track of if user has clicked x to quit
	while (true) {

		//double y = centerY + cos(angle) * offset*3;
		double width = baseWidth + sin(angle) * offset;

		screen.clear();
		// draw circle; for now I'll draw a rectangle, to see if code works
		screen.drawRect(centerX - width/2, centerY -width/2, width, width);
		screen.present();

		angle += speed;

		// Check for messages/events
		if (!screen.processEvents()) {
			break;
		}

	}

	screen.close();

	return 0;
}
