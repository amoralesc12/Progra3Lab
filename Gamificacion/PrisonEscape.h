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
	PrisonEscape(RenderWindow& ventana, Music& musica, int puntos);

private:
	void render(RenderWindow& ventana);
	int num = 2; int alter = 3; int puntVida;
	bool gameOver = false;
	Clock clock;
	void loadSprites(Music&, int puntos);
	Music	sfx;
	Text	OverTitle; Font fuente;
	Sprite	fondo,		fuegoSec,	fuegoMSec,	fuegoM2Sec,	personaje,		enemigo;
	Texture fondoTex,	fuegoTex,	fuegoMTex,	fuegoM2Tex,	personajeTex,	enemigoTex;
	RectangleShape vida, fondoRojo;

	Event evento; 

};


#endif // !PRISIONESCAPE_H



