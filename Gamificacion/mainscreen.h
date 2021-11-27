#pragma once
#ifndef MAINSCREEN_H
#define MAINSCREEN_H
//COMMIT
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

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

	Sprite mTitle; Texture message;
	
	Music musica;

	Event evento;

};
#endif // !MAINSCREEN_H



