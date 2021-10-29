#pragma once
#ifndef MAINSCREEN_H
#define MAINSCREEN_H
#include "SFML/Graphics.hpp"

using namespace sf;

class mainscreen
{
public:
	void pantallaInicial();
	void loadSprites();
private:

	Sprite bgInicio; Texture fondoInicial;

	Sprite Bsalir; Texture salir;

	Sprite Bplay; Texture play;

	Sprite tronTitle; Texture message;

	Event evento;

};
#endif // !MAINSCREEN_H



