//ONLY EDIT

#ifndef __MY_ENGINE_H__
#define __MY_ENGINE_H__

#include "../EngineCommon.h"
#include "../GraphicsEngine.h"
#include "../EventEngine.h"
#include "../ResourceManager.h"
#include "SDL_audio.h"
//#include "../XCube2d.h"
//#include "../GameMath.h"

//other includes
#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SDL.h>


class MyEngineSystem {
	friend class XCube2Engine;

private:
	std::shared_ptr<GraphicsEngine> gfx;
	std::shared_ptr<EventEngine> evt;

	SDL_Rect buttonR;
	//
	SDL_Rect check;

	bool buttonR_pressed = false;
	bool check_pressed = false;
	bool guess = true;
	std::string word = "slay";
	bool wordMatch = false;
	bool playMusic = false;

	std::string colourWord[7] = { "Red", "Blue", "Green", "Yellow", "Orange", "Pink", "Purple" };

	SDL_Color col[7] = { SDL_COLOR_RED, SDL_COLOR_GREEN, SDL_COLOR_BLUE, SDL_COLOR_PINK,SDL_COLOR_YELLOW, SDL_COLOR_ORANGE, SDL_COLOR_PURPLE };
	int colIndex = 0;

	//sound
	Mix_Chunk* buttonSound = Mix_LoadWAV("res/sounds/click.wav");
	Mix_Chunk* correctSound = Mix_LoadWAV("res/sounds/correct.wav");
	Mix_Chunk* wrongSound = Mix_LoadWAV("res/sounds/wrong.wav");
	Mix_Music* backgroundMuse = Mix_LoadMUS("res/sounds/bg.mp3");
	

public:
	MyEngineSystem(std::shared_ptr<GraphicsEngine> gfxPtr);


	MyEngineSystem();
	~MyEngineSystem();

	void myButton();
	bool drawButton(std::shared_ptr<EventEngine> evt, int x, int y, int w, int h);
	bool drawCheckButton(std::shared_ptr<EventEngine> evt, int x, int y, int w, int h);
	void drawText(int x, int y, int w, int h);
	bool playSound(std::shared_ptr<AudioEngine> sfx);


};



#endif
#endif