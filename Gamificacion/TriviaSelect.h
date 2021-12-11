#pragma once
#ifndef TRIVIASELECT_H
#define TRIVIASELECT_H
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


using namespace sf;
class TriviaSelect
{
public:
	//MAIN SCREEN
	void loadSprites_TS();
	void loadScreen_TS(RenderWindow& ventana, Music& musica, int puntos);
	void renderTS(RenderWindow& ventana);

	//Try Again! Screen
	void loadWrongBoxScreen_TS(RenderWindow& ventana, Music& musica);
	void loadWrongBoxSprites_TS();
	
	//QUESTIONS & OPTIONS

	

	void loadQuestionBoxScreen_TS(RenderWindow& ventana, Music& musica);
	void loadQuestionBoxSprites_TS();

	void loadQuestionBoxScreen2_TS(RenderWindow& ventana, Music& musica);
	void loadQuestionBoxSprites2_TS();

	void loadQuestionBoxScreen3_TS(RenderWindow& ventana, Music& musica);
	void loadQuestionBoxSprites3_TS();

	void loadQuestionBoxScreen4_TS(RenderWindow& ventana, Music& musica);
	void loadQuestionBoxSprites4_TS();

	

	
	
private:
	bool respondido= true;
	int puntos = 0;
	int vidas =4;
	Sprite bgN1, qb1, qb2,qb3,qb4,qb5,qb6,qb7,qb8, a,b,c,d;
	Texture bg, b1,b2,b3,b4,b5,b6,b7,b8, options;

	Sprite wrongS, QuestionS;
	Texture ws, qs;
	Music musica;
	
	SoundBuffer soundbuffer, buffer;
	Sound wrong, right;
	Font fuente, font;
	Text  text, message1, message, question, opA, opB, opC, opD;
	
	Event evento;


};
#endif // !TRIVIASELECT_H




