#include"SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include"mainscreen.h"
#include "TriviaSelect.h"
#include "elegirBando.h"
#include "PrisonEscape.h"
#include "IntroLvl.h"
#include<iostream>
using std::cout;
using namespace sf;
//COMMIT
void mainscreen::loadSprites() {

	//textures
	if (!fondoInicial.loadFromFile("Resources/bgInicio.png")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!message.loadFromFile("Resources/bgmotto.png")) { cout << "NO ESTA EL TITULO"; }
	if (!play.loadFromFile("Resources/buttonplay.png")) { cout << "NO ESTA LA BOTON JUGAR!"; }
	if (!salir.loadFromFile("Resources/buttonsalir.png")) { cout << "NO ESTA BOTON SALIR!"; }
	if (!musica.openFromFile("Resources/Intro.ogg")) { cout << "NO ESTA LA MUSICA!"; }
	if (!fuente.loadFromFile("Resources/velvenda chill.ttf")) { cout << "NO ESTA LA FUENTE"; }

	//setting Sprites with textures
	this->bgInicio.setTexture(this->fondoInicial);
	this->bgInicio.setPosition(-18, 0);
	this->bgInicio.setScale(1.1, 1.1);

	mTitle.setTexture(this->message);

	mTitle.setPosition(286, 125);

	musica.play();
	musica.setVolume(20);

	this->Bplay.setTexture(this->play);
	this->Bplay.setPosition(220, 515);

	this->Bsalir.setTexture(this->salir);
	this->Bsalir.setPosition(560, 515);

	titulo.setString("Los Reyes de la Filosfia");
	titulo.setFont(fuente);
	titulo.setFillColor(Color::Black);
	titulo.setPosition(225, 180);
	titulo.setCharacterSize(60);
}

void mainscreen::pantallaInicial() {

	RenderWindow window(VideoMode(982, 700), "Pantalla Inicio", Style::Titlebar | Style::Close);
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
					window.clear();
					IntroLvl intro(window, musica);
					/*TriviaSelect ch;
					ch.loadScreen_TS(window,musica, puntos);*/
					
				}


				else if (Bsalir.getGlobalBounds().contains(mousePosF)) {
					window.close();
				}
			}
		}

		window.clear(Color::Black);
		window.draw(this->bgInicio);
		window.draw(this->titulo);
		window.draw(this->Bplay);
		window.draw(Bsalir);
		window.display();
	}
};
