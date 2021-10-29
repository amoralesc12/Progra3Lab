#pragma once
#ifndef LEVEL1SCREEN_H
#define LEVEL1SCREEN_H

#include "SFML/Graphics.hpp"

using namespace sf;
class level1screen
{
public:
	void loadSprites();
	void loadScreen();

private:

	Sprite bgN1; Texture bg;

	Event evento;

};
#endif // !LEVEL1SCREEN_H



