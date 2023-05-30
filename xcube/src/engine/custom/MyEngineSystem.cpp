//ONLY EDIT

#include "MyEngineSystem.h"
#include "../XCube2d.h"

//other inc
#include <iostream>
#include <SDL.h>


MyEngineSystem::MyEngineSystem(){}

MyEngineSystem::MyEngineSystem(std::shared_ptr<GraphicsEngine> gfxPtr) : gfx(gfxPtr), buttonR(), buttonR_pressed(false), check_pressed(false)
{
	//https://mixkit.co/free-sound-effects/click/
	//click melodic tone
    buttonSound = Mix_LoadWAV("res/sounds/click.wav");
	if (buttonSound == nullptr) {
		std::cout << "sound failed";
	}
}


MyEngineSystem::~MyEngineSystem() {


}

void MyEngineSystem::myButton() {}


bool MyEngineSystem::drawButton(std::shared_ptr<EventEngine> evt, int x, int y, int w, int h) {

	//button
//https://opengameart.org/content/ui-buttons-7 , AnaMayArt , UI Buttons
//loading a texture
	SDL_Texture* buttonR = ResourceManager::loadTexture("./res/textures/button.png", SDL_Color());

	SDL_Rect buttonRPos = { x, y, w, h };

	//draw texture
	gfx->drawTexture(buttonR, &buttonRPos, SDL_FLIP_NONE);

	//mouse
	//SDL_GetMouseState(&pos.x, &pos.y);

	Point2 mousepos = evt->getMousePos();

	if (evt->isPressed(BTN_LEFT)) {
		if (mousepos.x > x && mousepos.x < x + w) {
			if (mousepos.y > y && mousepos.y < y + h) {
				buttonR_pressed = true;

				//play sound when clicked
				Mix_PlayChannel(-1, buttonSound, 0);

				return buttonR_pressed;
				//button clicked
			}
		}
	}

	//bool buttonR_pressed = false;
	return buttonR_pressed;


}

bool MyEngineSystem::drawCheckButton(std::shared_ptr<EventEngine> evt, int x, int y, int w, int h) {
	
	//button 2
// https://opengameart.org/content/button-0
 //spysky button
//loading texture
	SDL_Texture* check = ResourceManager::loadTexture("./res/textures/check.png", SDL_Color());

	SDL_Rect checkPos = { x, y, w, h };

	//draw texture
	gfx->drawTexture(check, &checkPos, SDL_FLIP_NONE);

	Point2 mousepos = evt->getMousePos();

	if (evt->isPressed(BTN_LEFT)) {
		if (mousepos.x > x && mousepos.x < x + w) {
			if (mousepos.y > y && mousepos.y < y + h) {
				check_pressed = true;
				std::cout << check_pressed;

				//play sound when clicked
				Mix_PlayChannel(-1, buttonSound, 0);

				return check_pressed;
				//button clicked
			}
		}
	}

	return check_pressed;
}

void MyEngineSystem::drawText(int x, int y, int w, int h) {

	//setting a colour to chosen test

	while (guess == true) {
		//setting chosen to a random colour from array
		std::srand(std::time(0)); // Seed the random number generator with the current time

		int randomNumber = std::rand() % 8; // Generate a random number between 0 and 5

		//word is randomly generated 
		word = colourWord[randomNumber];
		guess = false;

	}

	gfx->setDrawColor(SDL_COLOR_PURPLE);
	gfx->drawText(word, 700 - word.length() * 110, 200);

	//if button pressed then loop through the col array
	while (buttonR_pressed == true) {

		// Increment the color index
		colIndex = (colIndex + 1) % (sizeof(col) / sizeof(col[0]));

		buttonR_pressed = false;
	}

	gfx->setDrawColor(col[colIndex]);
	gfx->drawText(word, 700 - word.length() * 110, 200);

	while(check_pressed == true){
	
	std::cout<<"check";
	 
	//if word is the colour red (colIndex), and the word is "Red"
	if (colIndex == 0 && word == colourWord[0]) {
		/*std::cout << "yes";
		guess = true;*/
		wordMatch = true;
	}
	//if word is the colour green (colIndex), and the word is "Green"
	if (colIndex == 1 && word == colourWord[2]) {
		/*std::cout << "yes";
		guess = true;*/
		wordMatch = true;
	}
	//if word is the colour Blue (colIndex), and the word is "Blue"
	if (colIndex == 2 && word == colourWord[1]) {
		/*std::cout << "yes";
		guess = true;*/
		wordMatch = true;
	}
	//if word is the colour pink (colIndex), and the word is "Pink"
	if (colIndex == 3 && word == colourWord[5]) {
		/*std::cout << "yes";
		guess = true;*/
		std::cout << "\n POPPY_EYRES - CI517 - 2022/23 \n";
		wordMatch = true;
	}
	//if word is the colour yellow (colIndex), and the word is "Yellow"
	if (colIndex == 4 && word == colourWord[3]) {
		/*std::cout << "yes";
		guess = true;*/
		wordMatch = true;
	}
	//if word is the colour orange (colIndex), and the word is "Orange"
	if (colIndex == 5 && word == colourWord[4]) {
		/*std::cout << "yes";
		guess = true;*/
		wordMatch = true;
	}
	//if word is the colour purple (colIndex), and the word is "Purple"
	if (colIndex == 6 && word == colourWord[6]) {
		/*std::cout << "yes";
		guess = true;*/
		wordMatch = true;
	}
	 check_pressed = false;
	 playMusic = true;
	 
	 }


	if (wordMatch == true){

		// Delay for 1 second
		SDL_Delay(1000);
		guess = true;

	}
}

bool MyEngineSystem::playSound(std::shared_ptr<AudioEngine> sfx) {

	//Correct answer tone
//https://mixkit.co/free-sound-effects/correct/
	Mix_Chunk* correctSound = Mix_LoadWAV("res/sounds/correct.wav");
	if (correctSound == nullptr) {
		std::cout << "sound failed";
	}

	//Wrong electricity buzz
	//https://mixkit.co/free-sound-effects/wrong/
	Mix_Chunk* wrongSound = Mix_LoadWAV("res/sounds/wrong.wav");
	if (wrongSound == nullptr) {
		std::cout << "sound failed";
	}


	//bg music
	//Game Boy by Diego Nava
//https://mixkit.co/free-stock-music/tag/chill/?page=2
	Mix_Music* backgroundMuse = Mix_LoadMUS("res/sounds/bg.mp3");
	if (backgroundMuse == nullptr) {
		std::cout << "sound failed";
	}

	//sfx->playMP3(backgroundMuse, -1);


	while (playMusic == true){
		playMusic = false;
		if(wordMatch == true) {

			sfx->playSound(correctSound);
			
			
		}
		if (wordMatch == false) {

			sfx->playSound(wrongSound);
			
		}
		wordMatch = false;
	}

	return check_pressed;
}
