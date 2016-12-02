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
	double radius = 200;
	double speed = 0.131;
	double angle = 0.0;
	double x, y = 0.0;
	double width = 10.0;

	int numObjs = 24;
	double slice = M_PI * 2 / numObjs;

	for (int i = 0; i < numObjs; i++) {
		angle = i * slice;
		x = centerX + cos(angle) * radius;
		y = centerY + sin(angle) * radius;
		screen.drawRect(x - width / 2, y - width / 2, width, width);
	}

	screen.present();

	// While loop used to keep track of if user has clicked x to quit
	while (true) {

		// Check for messages/events
		if (!screen.processEvents()) {
			break;
		}

	}

	screen.close();

	return 0;
}
