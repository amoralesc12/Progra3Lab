#include "elegirBando.h"
#include "TriviaSelect.h"
#include"SFML/Graphics.hpp"
#include "mainscreen.h"

using namespace std;
using namespace sf;

#include <iostream>


void elegirBando::addingSprites_B() {

	if (!bgB.loadFromFile("Resources/bgElegirBando.jpg")) { cout << "NO ESTA"; }


	bgBando.setTexture(bgB);
	bgBando.setPosition(0, 0);

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

				if (this->bgBando.getGlobalBounds().contains(mousePosF))
				{
					TriviaSelect choose;
					window.close();
					choose.loadScreen_TS();
				}

			}

		}

		window.clear(Color::Black);
		window.draw(this->bgBando);

		window.display();
	}

}