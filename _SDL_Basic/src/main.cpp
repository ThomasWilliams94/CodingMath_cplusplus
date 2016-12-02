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
#include "Screen.h"

using namespace std;

int main(int argc, char* argv[]) {

	codingmath::Screen screen;

	if (!screen.init()) {
		cout << "Error initialising SDL." << endl;
	}

	screen.clear();

	int rectWidth = 500;
	int rectHeight = 200;

	screen.drawRect((screen.SCREEN_WIDTH - rectWidth) / 2,
			(screen.SCREEN_HEIGHT - rectHeight) / 2, rectWidth, rectHeight);

	screen.present();

	SDL_Delay(1000);

	screen.clear();

	screen.drawLine(0, 0, screen.SCREEN_WIDTH, screen.SCREEN_HEIGHT);

	screen.present();

	SDL_Delay(1000);

	screen.clear();

	screen.drawRect((screen.SCREEN_WIDTH - rectWidth) / 2,
				(screen.SCREEN_HEIGHT - rectHeight) / 2, rectWidth, rectHeight);
	screen.drawLine(0, 0, screen.SCREEN_WIDTH, screen.SCREEN_HEIGHT);

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
