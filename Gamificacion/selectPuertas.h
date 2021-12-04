#pragma once
#ifndef SELECTPUERTAS_H
#define SELECTPUERTAS_H
//COMMIT
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Question.h"
#include "TextArea.h"

using namespace sf;
class selectPuertas
{
public:
	selectPuertas(RenderWindow& ventana, Music& musica);

private:
	void loadSprites();
	void render(RenderWindow& ventana);
	bool recuadro = false;
	int puntos;

	Sprite	puerta1, puerta2, puerta3, puerta4, fondo;
	Texture	puertaA, puertaB, puertaC, puertaD, fondoT;
	Text	select, A, B, C, D;
	Text	Resp[4];
	TextArea	pregunta;
	Font	fuente;
	Question quest;

	RectangleShape	cuadro;

	Event evento;

};
#endif // !SELECTPUERTAS_H

