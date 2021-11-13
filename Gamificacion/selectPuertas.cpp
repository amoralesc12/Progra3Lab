#include "selectPuertas.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "elegirBando.h"
#include "mainscreen.h"
#include "Recorrido.h"
#include <iostream>
#include <cstdlib>
//COMMIT
using std::cout;

void selectPuertas::loadSprites() {

	if (!fondoT.loadFromFile("Resources/FondoPuertas.jpg")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!puertaA.loadFromFile("Resources/PuertaA.png")) { cout << "NO ESTA LA IMAGEN PUERTA1"; }
	if (!puertaB.loadFromFile("Resources/PuertaB.png")) { cout << "NO ESTA LA IMAGEN PUERTA2"; }
	if (!puertaC.loadFromFile("Resources/PuertaC.png")) { cout << "NO ESTA LA IMAGEN PUERTA3"; }
	if (!puertaD.loadFromFile("Resources/PuertaD.png")) { cout << "NO ESTA LA IMAGEN PUERTA4"; }
	if (!fuente.loadFromFile("Resources/CurlyLetters.ttf")) { cout << "NO ESTA LA FUENTE"; }

	select.setFont(fuente);
	select.setString("Selecciona una puerta y veras el mundo de sabiduria...");
	select.setPosition(60, 70);
	select.setCharacterSize(40);

	A.setFont(fuente);
	A.setString("1");
	A.setPosition(137, 200);
	A.setCharacterSize(50);

	B.setFont(fuente);
	B.setString("2");
	B.setPosition(381, 180);
	B.setCharacterSize(50);

	C.setFont(fuente);
	C.setString("3");
	C.setPosition(590, 240);
	C.setCharacterSize(50);

	D.setFont(fuente);
	D.setString("4");
	D.setPosition(828, 220);
	D.setCharacterSize(50);

	fondo.setTexture(fondoT);
	fondo.setPosition(0, 0);

	puerta1.setTexture(puertaA);
	puerta1.setPosition(30, 268);
	puerta1.setScale(.55f, .55f);

	puerta2.setTexture(puertaB);
	puerta2.setPosition(310, 253);
	puerta2.setScale(.55f, .55f);

	puerta3.setTexture(puertaC);
	puerta3.setPosition(510, 308);
	puerta3.setScale(.55f, .55f);

	puerta4.setTexture(puertaD);
	puerta4.setPosition(730, 286);
	puerta4.setScale(.55f, .55f);

	cuadro.setPosition(75, 75);
	cuadro.setSize(Vector2f(850, 550));
	cuadro.setFillColor(Color(21, 53, 58, 255));
	cuadro.setOutlineThickness(3);
	cuadro.setOutlineColor(Color(200, 200, 200, 255));

}

void selectPuertas::render(RenderWindow& ventana) {
	ventana.clear(Color::Black);
	ventana.draw(this->fondo);
	ventana.draw(this->select);
	ventana.draw(this->puerta1);
	ventana.draw(this->puerta2);
	ventana.draw(this->puerta3);
	ventana.draw(this->puerta4);
	ventana.draw(this->A);
	ventana.draw(this->B);
	ventana.draw(this->C);
	ventana.draw(this->D);
	if (recuadro) {
		ventana.draw(this->cuadro);
	}
	ventana.display();
}

selectPuertas::selectPuertas(RenderWindow& ventana) {

	Cursor hand; hand.loadFromSystem(Cursor::Hand);
	Cursor def; def.loadFromSystem(Cursor::Arrow);

	loadSprites();

	while (ventana.isOpen()) {
		while (ventana.pollEvent(this->evento)) {
			Vector2i mousePos = Mouse::getPosition(ventana);
			Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

			if (this->evento.type == Event::Closed) {
				ventana.close();
			}

			if (!recuadro) {
				if (evento.type == Event::MouseMoved) {
					if (puerta1.getGlobalBounds().contains(mousePosF) || puerta2.getGlobalBounds().contains(mousePosF) ||
						puerta3.getGlobalBounds().contains(mousePosF) || puerta4.getGlobalBounds().contains(mousePosF)) {
						ventana.setMouseCursor(hand);
					}
					else { ventana.setMouseCursor(def); }
				}

				if (this->evento.type == Event::MouseButtonPressed) {
					if (puerta1.getGlobalBounds().contains(mousePosF) || puerta2.getGlobalBounds().contains(mousePosF) ||
						puerta3.getGlobalBounds().contains(mousePosF) || puerta4.getGlobalBounds().contains(mousePosF)) {
						recuadro = true;
						ventana.setMouseCursor(def);


					}
				}
				if (evento.type == Event::KeyPressed) {
					if (evento.key.code == Keyboard::A) {
						RenderWindow window;
						elegirBando choose;
						choose.loadScreen_B(ventana);
					}
				}
			}
			else {
				if (evento.type == Event::KeyPressed) {
					if (evento.key.code == Keyboard::Escape) {
						recuadro = false;
					}
				}
			}
		}
		render(ventana);
	}
}
