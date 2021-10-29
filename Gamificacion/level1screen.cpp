#include "level1screen.h"
#include"SFML/Graphics.hpp"
#include "mainscreen.h"
//#include "play.h"
using namespace std;
using namespace sf;

#include <iostream>



void level1screen::loadSprites() {

	if (!bg.loadFromFile("Resources/bgNivel1.png")) { cout << "NO ESTA"; }
	
	bgN1.setTexture(bg);
	bgN1.setPosition(0, 0);

}

void level1screen::loadScreen() {

	RenderWindow window(VideoMode(600, 480), "Nivel 1", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	loadSprites();

	while (window.isOpen()) {
		while (window.pollEvent(this->evento)) {
			if (this->evento.type == Event::Closed) {
				window.close();
			}

			if (this->evento.type == Event::MouseButtonPressed) {
				Vector2i mousePos = Mouse::getPosition(window);
				Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

				
			}
		}

		window.clear(Color::Black);
		window.draw(this->bgN1);
		
		window.display();
	}

};