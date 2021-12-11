#pragma once
#ifndef ELEGIR_BANDO_H
#define ELEGIR_BANDO_H
//COMMIT
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace sf;
class elegirBando
{
public:

	void loadScreen_B(RenderWindow& ventana, Music& musica, int puntos);
private:
	int puntos;
	void renderB(RenderWindow& ventana);

	void addingSprites_B();
	Sprite bgBando;  Texture bgB;
	Sprite text1;	 Texture g1;
	Sprite text2;	 Texture g2;
	Sprite mensj;    Texture mensjB;
	Sprite Sizq;	 Texture izq;
	Sprite Sder;	 Texture der;
	
	Event evento;
};
#endif // !ELEGIR_BANDO_H

