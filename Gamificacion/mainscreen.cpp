#include"SFML/Graphics.hpp"
#include"mainscreen.h"
//#include"play.h"
#include "level1screen.h"
#include<iostream>
using std::cout;
using namespace sf;




void mainscreen::loadSprites() {

	//loading textures
	if (!fondoInicial.loadFromFile("Resources/bgInicio.png")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!message.loadFromFile("Resources/bgmotto.png")) { cout << "NO ESTA EL TITULO"; }
	if (!play.loadFromFile("Resources/buttonplay.png")) { cout << "NO ESTA LA BOTON JUGAR!"; }
	if (!salir.loadFromFile("Resources/buttonsalir.png")) { cout << "NO ESTA BOTON SALIR!"; }

	//setting Sprites with textures
	this->bgInicio.setTexture(this->fondoInicial);
	this->bgInicio.setPosition(0, 0);

	tronTitle.setTexture(this->message);
	// h    w
	tronTitle.setPosition(0, 30);


	this->Bplay.setTexture(this->play);
	this->Bplay.setPosition(320, 220);

	this->Bsalir.setTexture(this->salir);
	this->Bsalir.setPosition(316, 340);
};




void mainscreen::pantallaInicial() {
	//  h    w
	RenderWindow window(VideoMode(800, 533), "Pantalla Inicio", Style::Titlebar | Style::Close);
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

				if (this->Bplay.getGlobalBounds().contains(mousePosF))
				{
					level1screen choose;
					window.close();
					choose.loadScreen();
				}

			
				else if (Bsalir.getGlobalBounds().contains(mousePosF)) {
					window.close();
				}
			}
		}

		window.clear(Color::Black);
		window.draw(this->bgInicio);
		window.draw(this->tronTitle);
		window.draw(this->Bplay);
		window.draw(Bsalir);
		window.display();
	}
};

