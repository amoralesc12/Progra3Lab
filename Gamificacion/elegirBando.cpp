#include "elegirBando.h"
#include "Recorrido.h"
#include"SFML/Graphics.hpp"
#include "mainscreen.h"
//
using namespace std;
using namespace sf;

#include <iostream>


void elegirBando::addingSprites_B() {

	if (!bgB.loadFromFile("Resources/FondoBando.jpg")) { cout << "NO ESTA"; }
	if (!g1.loadFromFile("Resources/textoR.png")) { cout << "NO SE ENCUENTRA"; }
	if (!g2.loadFromFile("Resources/textoE.png")) { cout << "NO SE ENCUENTRA"; }
	if (!mensjB.loadFromFile("Resources/mBando.png")) { cout << "NO SE ENCUENTRA"; }
	if (!izq.loadFromFile("Resources/CaballeroB1.png")) { cout << "NO SE ENCUENTRA"; }
	if (!der.loadFromFile("Resources/CaballeroR1i.png")) { cout << "NO SE ENCUENTRA"; }

	bgBando.setTexture(bgB);
	bgBando.setPosition(0, 0); 

	text1.setTexture(g1);
	text1.setPosition(150, 350);

	Sizq.setTexture(izq);
	Sizq.setPosition(45, 415);

	text2.setTexture(g2);
	text2.setPosition(650, 350);

	Sder.setTexture(der);
	Sder.setPosition(545, 415);

	mensj.setTexture(mensjB);
	mensj.setPosition(10, 50);
}

void elegirBando::loadScreen_B(RenderWindow& ventana, Music& musica, int puntos)
{
	addingSprites_B();
	Clock clock;
	bool ingresado = false;
	Cursor hand; hand.loadFromSystem(Cursor::Hand);
	Cursor def; def.loadFromSystem(Cursor::Arrow);

	while (ventana.isOpen()) {
		if (contador == 0 && clock.getElapsedTime().asMilliseconds() > 500 && !ingresado) {
			Sizq.setPosition(45, 413);
			Sder.setPosition(545, 413);
			clock.restart();
			contador = 1;
		}
		else if (contador == 1 && clock.getElapsedTime().asMilliseconds() > 500 && !ingresado) {
			Sizq.setPosition(45, 415);
			Sder.setPosition(545, 415);
			clock.restart();
			
			contador = 0;
		}
		while (ventana.pollEvent(this->evento)) {
			Vector2i mousePos = Mouse::getPosition(ventana);
			Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			if (this->evento.type == Event::Closed) {
				ventana.close();
			}

			if (this->evento.type == Event::MouseMoved) {
				if (this->Sizq.getGlobalBounds().contains(mousePosF))
				{
					Sizq.setScale(1.04f, 1.04f);
					Sizq.setPosition(45, 415);
					Sder.setPosition(545, 415);
					ventana.setMouseCursor(hand);
					ingresado = true;
				}
				else if (this->Sder.getGlobalBounds().contains(mousePosF))
				{
					Sder.setScale(1.04f, 1.04f);
					Sizq.setPosition(45, 415);
					Sder.setPosition(545, 415);
					ventana.setMouseCursor(hand);
					ingresado = true;
				}
				else {
					Sizq.setScale(1, 1);
					Sder.setScale(1, 1);
					ventana.setMouseCursor(def);
					ingresado = false;
				}
			}

			if (this->evento.type == Event::MouseButtonPressed) {

				if (this->Sizq.getGlobalBounds().contains(mousePosF))
				{	
					ventana.setMouseCursor(def);
					RenderWindow window;
					Recorrido choose;
					choose.loadQScreen_R(ventana, musica, puntos, 0);
				}
				else if (this->Sder.getGlobalBounds().contains(mousePosF))
				{
					ventana.setMouseCursor(def);
					RenderWindow window;
					Recorrido choose;
					choose.loadQScreen_R(ventana, musica, puntos, 1);

				}

			}

		}

		renderB(ventana);
	}

}

void elegirBando::renderB(RenderWindow& ventana)
{
	ventana.clear(Color::Black);
	ventana.draw(this->bgBando);
	ventana.draw(this->text1);
	ventana.draw(this->text2);
	ventana.draw(this->Sizq);
	ventana.draw(this->Sder);
	ventana.draw(this->mensj);
	ventana.display();
}
