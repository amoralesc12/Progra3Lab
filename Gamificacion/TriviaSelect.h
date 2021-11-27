#pragma once
#ifndef TRIVIASELECT_H
#define TRIVIASELECT_H
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace sf;
class TriviaSelect
{
public:
	void loadSprites_TS();
	void loadScreen_TS(RenderWindow& ventana, Music& musica);
	void loadQuestionBoxScreen_TS();
	void loadQuestionBoxSprites_TS();
	void renderTS(RenderWindow& ventana);

	//Try Again! Screen

	void loadWrongBoxScreen_TS(RenderWindow& ventana, Music& musica);
	void loadWrongBoxSprites_TS();

private:

	Sprite bgN1, qb1, qb2,qb3,qb4,qb5,qb6,qb7,qb8;
	Texture bg, b1,b2,b3,b4,b5,b6,b7,b8;

	Sprite wrongS, QuestionS;
	Texture ws, qs;

	Font fuente;
	Text message, tryagain;

	Event evento;

};
#endif // !TRIVIASELECT_H



