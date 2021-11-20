#pragma once

#ifndef PRISIONESCAPE_H
#define PRISIONESCAPE_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

using namespace sf;

class PrisonEscape
{

public:
	PrisonEscape(RenderWindow& ventana, Music& musica);

private:
	void render(RenderWindow& ventana);
	int num = 2; int alter = 3;
	Clock clock;
	void loadSprites(Music&);
	Music	sfx;
	Sprite	fondo,		fuegoSec,	fuegoMSec,	fuegoM2Sec;
	Texture fondoTex,	fuegoTex,	fuegoMTex,	fuegoM2Tex;

	Event evento; 

};


#endif // !PRISIONESCAPE_H

