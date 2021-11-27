#include "elegirBando.h"
#include "Recorrido.h"
#include"SFML/Graphics.hpp"
#include "mainscreen.h"
//
using namespace std;
using namespace sf;

#include <iostream>


void elegirBando::addingSprites_B() {

	if (!bgB.loadFromFile("Resources/bgElegirBando.jpg")) { cout << "NO ESTA"; }
	if (!g1.loadFromFile("Resources/textoR.png")) { cout << "NO SE ENCUENTRA"; }
	if (!g2.loadFromFile("Resources/textoE.png")) { cout << "NO SE ENCUENTRA"; }
	if (!mensjB.loadFromFile("Resources/mBando.png")) { cout << "NO SE ENCUENTRA"; }
	if (!izq.loadFromFile("Resources/Guardia izq.png")) { cout << "NO SE ENCUENTRA"; }


	bgBando.setTexture(bgB);
	bgBando.setPosition(0, 0);

	text1.setTexture(g1);
	text1.setPosition(150, 350);

	Sizq.setTexture(izq);
	Sizq.setPosition(45,525);

	text2.setTexture(g2);
	text2.setPosition(650, 350);

	Sder.setTexture(izq);
	Sder.setPosition(545, 525);

	mensj.setTexture(mensjB);
	mensj.setPosition(10, 50);
}

void elegirBando::loadScreen_B(RenderWindow& ventana, Music& musica)
{
	addingSprites_B();

	while (ventana.isOpen()) {
		while (ventana.pollEvent(this->evento)) {
			Vector2i mousePos = Mouse::getPosition(ventana);
			Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			if (this->evento.type == Event::Closed) {
				ventana.close();
			}

			if (this->evento.type == Event::MouseButtonPressed) {

				if (this->Sizq.getGlobalBounds().contains(mousePosF))
				{
					RenderWindow window;
					Recorrido choose;
					choose.loadQScreen_R(ventana, musica);
				}
				else if (this->Sder.getGlobalBounds().contains(mousePosF))
				{
					RenderWindow window;
					Recorrido choose;
					choose.loadQScreen_R(ventana, musica);

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
