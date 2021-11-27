#include "Recorrido.h"
#include "TriviaSelect.h"
#include "Game.h"
#include "SFML/Graphics.hpp"
#include <iostream>
//COMMIT
using namespace sf;
using namespace std;


void Recorrido::loadSprites_R()
{
	if (!bg.loadFromFile("Resources/r.png")) { cout << "NO ESTA"; }
	if (!bg1.loadFromFile("Resources/r.png")) { cout << "NO ESTA"; }
	//if (!bg.loadFromFile("Resources/recorrido1.png")) { cout << "NO ESTA"; }

	rbg.setTexture(bg);
	rbg.setPosition(0, 0);

	r1bg.setTexture(bg1);
	r1bg.setPosition(0, 0);

	/*r2bg.setTexture(bg);
	r2bg.setPosition(0, 0);*/
}
// Primer recorrido despues de la seleccion de puertas
void Recorrido::loadQScreen_R(RenderWindow& ventana, Music& musica)
{
	loadSprites_R();

	while (ventana.isOpen()) {
		while (ventana.pollEvent(this->evento)) {
			Vector2i mousePos = Mouse::getPosition(ventana);
			Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

			if (evento.type == Event::KeyPressed) {
				if (evento.key.code == Keyboard::B) {
					RenderWindow window;
					TriviaSelect choose;
					choose.loadScreen_TS(ventana, musica);
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

// Recorrido despues de trivia select
void Recorrido::loadQScreen_R1(RenderWindow& ventana, Music& musica)
{
	loadSprites_R();

	while (ventana.isOpen()) {
		while (ventana.pollEvent(this->evento)) {
			Vector2i mousePos = Mouse::getPosition(ventana);
			Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

			if (evento.type == Event::KeyPressed) {
				if (evento.key.code == Keyboard::D) {
					RenderWindow window;
					Game choose(ventana);
					choose.run(ventana, musica);
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

// Recorrido despues de Game(Juego de globos)
//void Recorrido::loadQScreen_R2(RenderWindow& ventana)
//{
//	loadSprites_R();
//
//	while (ventana.isOpen()) {
//		while (ventana.pollEvent(this->evento)) {
//			Vector2i mousePos = Mouse::getPosition(ventana);
//			Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
//
//			if (evento.type == Event::KeyPressed) {
//				if (evento.key.code == Keyboard::D) {
//					RenderWindow window;
//					Game choose;
//					choose.run();
//				}
//			}
//
//
//		}
//
//		renderR2(ventana);
//	}
//}
//void Recorrido::renderR2(RenderWindow& ventana)
//{
//	ventana.clear(Color::Black);
//	ventana.draw(this->r1bg);
//	ventana.display();
//}