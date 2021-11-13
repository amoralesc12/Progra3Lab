#pragma once
#ifndef RECORRIDO_H
#define RECORRIDO_H

#include "SFML/Graphics.hpp"
using namespace sf;
class Recorrido
{
public:
	void loadQScreen_R(RenderWindow& ventana);
	void loadSprites_R();
	void renderR(RenderWindow& ventana);

	void loadQScreen_R1(RenderWindow& ventana);
	void renderR1(RenderWindow& ventana);

	void loadQScreen_R2(RenderWindow& ventana);
	void renderR2(RenderWindow& ventana);

private:

	Sprite rbg, r1bg, r2bg;  Texture bg, bg1;
	Event evento;

};
#endif // !RECORRIDO_H


