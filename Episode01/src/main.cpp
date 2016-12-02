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
#include <SDL.h>
#include <time.h>
#include "Screen.h"

using namespace std;

int main(int argc, char* argv[]) {

	codingmath::Screen screen;

	srand(time(NULL));

	if (!screen.init()) {
		cout << "Error initialising SDL." << endl;
	}

	screen.clear();

	for(int i = 0; i < 100; i++) {
		int x1, x2, y1, y2;
		x1 = rand() % screen.SCREEN_WIDTH + 1;
		x2 = rand() % screen.SCREEN_WIDTH + 1;
		y1 = rand() % screen.SCREEN_HEIGHT + 1;
		y2 = rand() % screen.SCREEN_HEIGHT + 1;

		screen.drawLine(x1, y1, x2, y2);
	}

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
