#pragma once
#ifndef ELEGIR_BANDO_H
#define ELEGIR_BANDO_H
 
#include "SFML/Graphics.hpp"

using namespace sf;
class elegirBando
{
public:

	void loadScreen_B();
	void addingSprites_B();
private:

	Sprite bgBando;  Texture bgB;
	Sprite text1;	 Texture g1;
	Sprite text2;	 Texture g2;

	
	Event evento;
};
#endif // !ELEGIR_BANDO_H

