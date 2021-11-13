#include "TriviaSelect.h"
#include "elegirBando.h"
#include "Recorrido.h"
#include"SFML/Graphics.hpp"
#include "mainscreen.h"
#include "Game.h"
using namespace std;
using namespace sf;

#include <iostream>
//COMMIT


void TriviaSelect::loadSprites_TS() {

	if (!bg.loadFromFile("Resources/bgTriviaSelect.jpg")) { cout << "NO ESTA"; }
	if (!b1.loadFromFile("Resources/qb.png")) { cout << "NO ESTA"; }
	
	
	bgN1.setTexture(bg);
	bgN1.setPosition(0, 0);

	//question boxes

	qb1.setTexture(b1);			qb1.setPosition(150, 200);
	qb2.setTexture(b1);			qb2.setPosition(350, 200);
	qb3.setTexture(b1);			qb3.setPosition(550, 200);
	qb4.setTexture(b1);			qb4.setPosition(750, 200);
	qb5.setTexture(b1);			qb5.setPosition(150, 400);
	qb6.setTexture(b1);			qb6.setPosition(350, 400);
	qb7.setTexture(b1);			qb7.setPosition(550, 400);
	qb8.setTexture(b1);			qb8.setPosition(750, 400);

}

void TriviaSelect::loadScreen_TS(RenderWindow& ventana) {

	loadSprites_TS();

	while (ventana.isOpen()) {
		while (ventana.pollEvent(this->evento)) {
			Vector2i mousePos = Mouse::getPosition(ventana);
			Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

			if (this->evento.type == Event::Closed) {
				ventana.close();
			}
			if (this->evento.type == Event::MouseButtonPressed) {

				if (this->qb1.getGlobalBounds().contains(mousePosF))
				{
					TriviaSelect choose;
					choose.loadQuestionBoxScreen_TS();
				}
				else if (this->qb2.getGlobalBounds().contains(mousePosF))
				{
					TriviaSelect choose;
					choose.loadQuestionBoxScreen_TS();

				}
				else if (this->qb3.getGlobalBounds().contains(mousePosF))
				{
					TriviaSelect choose;
					choose.loadQuestionBoxScreen_TS();

				}
				else if (this->qb4.getGlobalBounds().contains(mousePosF))
				{
					TriviaSelect choose;
					choose.loadQuestionBoxScreen_TS();

				}
				else if (this->qb5.getGlobalBounds().contains(mousePosF))
				{
					TriviaSelect choose;
					choose.loadQuestionBoxScreen_TS();

				}
				else if (this->qb6.getGlobalBounds().contains(mousePosF))
				{
					TriviaSelect choose;
					choose.loadQuestionBoxScreen_TS();

				}
				else if (this->qb7.getGlobalBounds().contains(mousePosF))
				{
					TriviaSelect choose;
					choose.loadQuestionBoxScreen_TS();

				}
				else if (this->qb8.getGlobalBounds().contains(mousePosF))
				{
					TriviaSelect choose;
					choose.loadQuestionBoxScreen_TS();

				}

			}
			if (evento.type == Event::KeyPressed) {
				if (evento.key.code == Keyboard::C) {
					RenderWindow window;
					Recorrido choose;
					choose.loadQScreen_R1(ventana);
				}
			}
			

		}

		renderTS(ventana);
	}

}
void TriviaSelect::loadQuestionBoxScreen_TS()
{
	RenderWindow window(VideoMode(900, 500), "Open Box", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	loadQuestionBoxSprites_TS();

	while (window.isOpen()) {
		while (window.pollEvent(this->evento)) {
			if (this->evento.type == Event::Closed) {
				window.close();
			}

		}

		window.clear(Color::Black);
		window.draw(this->pregunEj);
		window.draw(this->respEj);
		


		window.display();
	}

}
void TriviaSelect::loadQuestionBoxSprites_TS()
{
	if (!pEj.loadFromFile("Resources/ejemP.png")) { cout << "NO ESTA"; }
	if (!rEj.loadFromFile("Resources/ejemR.png")) { cout << "NO ESTA"; }

	pregunEj.setTexture(pEj);
	pregunEj.setPosition(10, 20);

	respEj.setTexture(rEj);
	respEj.setPosition(75, 100);

}
void TriviaSelect::renderTS(RenderWindow& ventana)
{
	ventana.clear(Color::Black);
	ventana.draw(this->bgN1);
	ventana.draw(this->qb1);
	ventana.draw(this->qb2);
	ventana.draw(this->qb3);
	ventana.draw(this->qb4);
	ventana.draw(this->qb5);
	ventana.draw(this->qb6);
	ventana.draw(this->qb7);
	ventana.draw(this->qb8);


	ventana.display();
}
;