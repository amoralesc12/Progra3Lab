#include "TriviaSelect.h"
#include "elegirBando.h"
#include"SFML/Graphics.hpp"
#include "mainscreen.h"

using namespace std;
using namespace sf;

#include <iostream>



void TriviaSelect::loadSprites_TS() {

	if (!bg.loadFromFile("Resources/bgTriviaSelect.jpg")) { cout << "NO ESTA"; }
	if (!b1.loadFromFile("Resources/questionbox.png")) { cout << "NO ESTA"; }
	if (!b2.loadFromFile("Resources/questionbox.png")) { cout << "NO ESTA"; }
	if (!b3.loadFromFile("Resources/questionbox.png")) { cout << "NO ESTA"; }
	if (!b4.loadFromFile("Resources/questionbox.png")) { cout << "NO ESTA"; }
	if (!b5.loadFromFile("Resources/questionbox.png")) { cout << "NO ESTA"; }
	if (!b6.loadFromFile("Resources/questionbox.png")) { cout << "NO ESTA"; }
	if (!b7.loadFromFile("Resources/questionbox.png")) { cout << "NO ESTA"; }
	if (!b8.loadFromFile("Resources/questionbox.png")) { cout << "NO ESTA"; }
	
	bgN1.setTexture(bg);
	bgN1.setPosition(0, 0);

	//question boxes

	qb1.setTexture(b1);			qb1.setPosition(100, 150);
	qb2.setTexture(b2);			qb2.setPosition(300, 150);
	qb3.setTexture(b3);			qb3.setPosition(500, 150);
	qb4.setTexture(b4);			qb4.setPosition(700, 150);
	qb5.setTexture(b5);			qb5.setPosition(100, 400);
	qb6.setTexture(b6);			qb6.setPosition(300, 400);
	qb7.setTexture(b7);			qb7.setPosition(500, 400);
	qb8.setTexture(b8);			qb8.setPosition(700, 400);




}

void TriviaSelect::loadScreen_TS() {

	RenderWindow window(VideoMode(1000, 700), "Trivia Select", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	loadSprites_TS();

	while (window.isOpen()) {
		while (window.pollEvent(this->evento)) {
			if (this->evento.type == Event::Closed) {
				window.close();
			}
			
		}

		window.clear(Color::Black);
		window.draw(this->bgN1);
		window.draw(this->qb1);
		window.draw(this->qb2);
		window.draw(this->qb3);
		window.draw(this->qb4);
		window.draw(this->qb5);
		window.draw(this->qb6);
		window.draw(this->qb7);
		window.draw(this->qb8);
		
		
		window.display();
	}

};