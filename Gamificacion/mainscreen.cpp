#include"SFML/Graphics.hpp"
#include"mainscreen.h"
#include "TriviaSelect.h"
#include "elegirBando.h"
#include<iostream>
using std::cout;
using namespace sf;




void mainscreen::loadSprites() {

	//textures
	if (!fondoInicial.loadFromFile("Resources/bgInicio.png")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!message.loadFromFile("Resources/bgmotto.png")) { cout << "NO ESTA EL TITULO"; }
	if (!play.loadFromFile("Resources/buttonplay.png")) { cout << "NO ESTA LA BOTON JUGAR!"; }
	if (!salir.loadFromFile("Resources/buttonsalir.png")) { cout << "NO ESTA BOTON SALIR!"; }

	//setting Sprites with textures
	this->bgInicio.setTexture(this->fondoInicial);
	this->bgInicio.setPosition(0, 0);

	mTitle.setTexture(this->message);
	
	mTitle.setPosition(266, 125);


	this->Bplay.setTexture(this->play);
	this->Bplay.setPosition(200, 515);

	this->Bsalir.setTexture(this->salir);
	this->Bsalir.setPosition(540, 515);
};




void mainscreen::pantallaInicial() {

	RenderWindow window(VideoMode(1000, 700), "Pantalla Inicio", Style::Titlebar | Style::Close);
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
					elegirBando choose;
					window.close();
					choose.loadScreen_B();
				}

			
				else if (Bsalir.getGlobalBounds().contains(mousePosF)) {
					window.close();
				}
			}
		}

		window.clear(Color::Black);
		window.draw(this->bgInicio);
		window.draw(this->mTitle);
		window.draw(this->Bplay);
		window.draw(Bsalir);
		window.display();
	}
};

