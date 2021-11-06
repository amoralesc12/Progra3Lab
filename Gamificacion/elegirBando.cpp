#include "elegirBando.h"
#include "TriviaSelect.h"
#include"SFML/Graphics.hpp"
#include "mainscreen.h"

using namespace std;
using namespace sf;

#include <iostream>


void elegirBando::addingSprites_B() {

	if (!bgB.loadFromFile("Resources/bgElegirBando.jpg")) { cout << "NO ESTA"; }
	if (!g1.loadFromFile("Resources/textoR.png")) { cout << "NO SE ENCUENTRA"; }
	if (!g2.loadFromFile("Resources/textoE.png")) { cout << "NO SE ENCUENTRA"; }
	if (!mensjB.loadFromFile("Resources/mBando.png")) { cout << "NO SE ENCUENTRA"; }

	bgBando.setTexture(bgB);
	bgBando.setPosition(0, 0);

	text1.setTexture(g1);
	text1.setPosition(150, 350);


	text2.setTexture(g2);
	text2.setPosition(650, 350);

	mensj.setTexture(mensjB);
	mensj.setPosition(10, 50);
}

void elegirBando::loadScreen_B()
{
	RenderWindow window(VideoMode(1000, 700), "Elegir Bando", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	addingSprites_B();

	while (window.isOpen()) {
		while (window.pollEvent(this->evento)) {
			if (this->evento.type == Event::Closed) {
				window.close();
			}

			if (this->evento.type == Event::MouseButtonPressed) {
				Vector2i mousePos = Mouse::getPosition(window);
				Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

				if (this->text1.getGlobalBounds().contains(mousePosF))
				{
					TriviaSelect choose;
					window.close();
					choose.loadScreen_TS();
				}
				else if (this->text2.getGlobalBounds().contains(mousePosF))
				{
					TriviaSelect choose;
					window.close();
					choose.loadScreen_TS();

				}

			}

		}

		window.clear(Color::Black);
		window.draw(this->bgBando);
		window.draw(this->text1);
		window.draw(this->text2);
		window.draw(this->mensj);
		window.display();
	}

}