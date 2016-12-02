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

	for (double angle = 0.0; angle < M_PI * 2; angle += 0.01) {
		double x = 10 + angle * 200;
		double y = 250 + sin(angle) * 200;

		screen.drawRect(x, screen.SCREEN_HEIGHT - y, 4, 4);
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
