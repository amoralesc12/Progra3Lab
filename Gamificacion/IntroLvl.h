#pragma once

#ifndef INTROLVL_H
#define INTROLVL_H
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace sf;

class IntroLvl {

public:
	IntroLvl(RenderWindow& window, Music& musica);
	void pantalla(RenderWindow& window, Music& musica);
	void loadSprites(Music& musica);

private:
	float speedUp = 1;
	float x = 160; float y = 350;
	float x1 = -150; float y1 = -100;
	Sprite fondo; Texture fondoTexture;
	Sprite carta; Texture cartaTexture;
	Event evento;

	Font fuente;
	Text narracion, continuar;
};

#endif // !INTROLVL?H


