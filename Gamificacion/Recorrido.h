#pragma once
#ifndef RECORRIDO_H
#define RECORRIDO_H
//COMMIT
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
using namespace sf;
class Recorrido
{
public:
	void loadQScreen_R(RenderWindow& ventana, Music& musica, int puntos);
	void loadSprites_R();
	void renderR(RenderWindow& ventana);

	void loadQScreen_R1(RenderWindow& ventana, Music& musica, int puntos);
	void renderR1(RenderWindow& ventana);

	void loadQScreen_R2(RenderWindow& ventana, Music& musica, int puntos);
	void renderR2(RenderWindow& ventana);

private:

	Sprite rbg, r1bg, r2bg;  Texture bg, bg1, bg2;
	Event evento;
	int contador,puntos;
};
#endif // !RECORRIDO_H


