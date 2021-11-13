#pragma once
#ifndef TRIVIASELECT_H
#define TRIVIASELECT_H
#include "SFML/Graphics.hpp"

using namespace sf;
class TriviaSelect
{
public:
	void loadSprites_TS();
	void loadScreen_TS(RenderWindow& ventana);
	void loadQuestionBoxScreen_TS();
	void loadQuestionBoxSprites_TS();
	void renderTS(RenderWindow& ventana);

private:

	Sprite bgN1, qb1, qb2,qb3,qb4,qb5,qb6,qb7,qb8;
	Texture bg, b1,b2,b3,b4,b5,b6,b7,b8;

	Sprite pregunEj, respEj;
	Texture pEj,rEj;

	Event evento;

};
#endif // !TRIVIASELECT_H



