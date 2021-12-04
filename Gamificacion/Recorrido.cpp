#include "Recorrido.h"
#include "TriviaSelect.h"
#include "Game.h"
#include "PrisonEscape.h"
#include "SFML/Graphics.hpp"
#include <iostream>
//COMMIT
using namespace sf;
using namespace std;


void Recorrido::loadSprites_R()
{
	if (!bg.loadFromFile("Resources/n1.png")) { cout << "NO ESTA"; }
	if (!bg1.loadFromFile("Resources/n2.png")) { cout << "NO ESTA"; }
	if (!bg2.loadFromFile("Resources/n3.png")) { cout << "NO ESTA"; }

	rbg.setTexture(bg);
	rbg.setPosition(0, 0);

	r1bg.setTexture(bg1);
	r1bg.setPosition(0, 0);

	r2bg.setTexture(bg2);
	r2bg.setPosition(0, 0);
}
// Primer recorrido despues de elegir bando
void Recorrido::loadQScreen_R(RenderWindow& ventana, Music& musica, int puntos)
{
	loadSprites_R();

	while (ventana.isOpen()) {
		while (ventana.pollEvent(this->evento)) {
			Vector2i mousePos = Mouse::getPosition(ventana);
			Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

			if (evento.type == Event::MouseButtonPressed) {
				if (this->rbg.getGlobalBounds().contains(mousePosF)) {
				
					RenderWindow window;
					Game choose(ventana);
					choose.run(ventana, musica, puntos);
				}
			}
			
		}
		renderR(ventana);
	}
}


void Recorrido::renderR(RenderWindow& ventana)
{
	ventana.clear(Color::Black);
	ventana.draw(this->rbg);
	ventana.display();
}

// Recorrido despues del juego de globos
void Recorrido::loadQScreen_R1(RenderWindow& ventana, Music& musica, int puntos)
{
	loadSprites_R();

	while (ventana.isOpen()) {
		while (ventana.pollEvent(this->evento)) {
			Vector2i mousePos = Mouse::getPosition(ventana);
			Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

			if (evento.type == Event::KeyPressed) {
				if (this->r1bg.getGlobalBounds().contains(mousePosF)) {
					RenderWindow window;
					TriviaSelect choose;
					choose.loadScreen_TS(ventana, musica, puntos);
					
				}
			}


		}

		renderR1(ventana);
	}
}
void Recorrido::renderR1(RenderWindow& ventana)
{
	ventana.clear(Color::Black);
	ventana.draw(this->r1bg);
	ventana.display();
}

// Recorrido despues de Trivia Select
void Recorrido::loadQScreen_R2(RenderWindow& ventana,Music& musica, int puntos)
{
	loadSprites_R();

	while (ventana.isOpen()) {
		while (ventana.pollEvent(this->evento)) {
			Vector2i mousePos = Mouse::getPosition(ventana);
			Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

			if (evento.type == Event::MouseButtonPressed) {
				if (this->r2bg.getGlobalBounds().contains(mousePosF)) {
					RenderWindow window;
					PrisonEscape PrisonEscape(ventana, musica, puntos);
					
				
				}
			}


		}

		renderR2(ventana);
	}
}
void Recorrido::renderR2(RenderWindow& ventana)
{
	ventana.clear(Color::Black);
	ventana.draw(this->r2bg);
	ventana.display();
}