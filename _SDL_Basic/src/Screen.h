/*
 * Screen.h
 *
 *  Created on: 6 Nov 2016
 *      Author: Thomas
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace codingmath {

class Screen {
public:
	const static int SCREEN_WIDTH = 1364;
	const static int SCREEN_HEIGHT = 700;

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;

public:
	Screen();
	bool init();
	void update();
	void present();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void drawRect(int x, int y, int w, int h);
	void drawLine(int x1, int y1, int x2, int y2);
	bool processEvents();
	void close();
	void clear();
	void boxBlur();
};

} /* namespace codingmath */

#endif /* SCREEN_H_ */
