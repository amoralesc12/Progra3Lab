#pragma once

#ifndef SELECTPUERTAS_H
#define SELECTPUERTAS_H

#include "SFML/Graphics.hpp"
using namespace sf;

class selectPuertas {

public:
	selectPuertas(RenderWindow& ventana);

private:
	void loadSprites();
	void render(RenderWindow& ventana);
	bool recuadro = false;
	
	Sprite	puerta1,	puerta2,	puerta3,	puerta4,	fondo;
	Texture	puertaA,	puertaB,	puertaC,	puertaD,	fondoT;
	Text	select,	A,	B,	C,	D;
	Font	fuente;

	RectangleShape	cuadro;

	Event evento;

};

#endif // !SELECTPUERTAS_H


