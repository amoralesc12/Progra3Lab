#include "PrisonEscape.h"

using std::cout;

void PrisonEscape::loadSprites(Music& musica, int puntos) {

	//loading textures
	if (!fondoTex.loadFromFile("Resources/Mazmorra.jpg")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!personajeTex.loadFromFile("Resources/Caballero.png")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!enemigoTex.loadFromFile("Resources/Rey.png")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!fuegoTex.loadFromFile("Resources/Fuegos/Fuego1.png")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!fuegoMTex.loadFromFile("Resources/Fuegos/Fuegos1.png")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!fuegoM2Tex.loadFromFile("Resources/Fuegos/Fuegos3.png")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!musica.openFromFile("Resources/SuspenseTrack1.ogg")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!sfx.openFromFile("Resources/SFX Fuego.ogg")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!fuente.loadFromFile("Resources/CurlyLetters.ttf")) { cout << "NO ESTA LA FUENTE"; }

	sfx.play();
	sfx.setLoop(true);
	musica.play();
	musica.setLoop(true);
	
	fondo.setTexture(fondoTex);
	fondo.setPosition(-285, 0);
	fondo.setScale(.95f,.95f);

	personaje.setTexture(personajeTex);
	personaje.setPosition(40, 325);
	personaje.setScale(.97f, .97f);

	enemigo.setTexture(enemigoTex);
	enemigo.setPosition(700, 315);
	enemigo.setScale(.97f, .97f);
	
	fondoRojo.setFillColor(Color::Red);
	fondoRojo.setPosition(40, 650);
	fondoRojo.setSize(Vector2f(300, 40));

	OverTitle.setFont(fuente);
	OverTitle.setString("Game Over");
	OverTitle.setPosition(300, 300);
	OverTitle.setCharacterSize(70);

	vida.setFillColor(Color::Green);
	vida.setPosition(40, 650);
	vida.setSize(Vector2f(puntVida, 40));

	fuegoMSec.setTexture(fuegoMTex);
	fuegoMSec.setPosition(-280, -7);
	fuegoMSec.setScale(.8f, .8f);

	fuegoM2Sec.setTexture(fuegoM2Tex);
	fuegoM2Sec.setPosition(488, -7);
	fuegoM2Sec.setScale(.8f, .8f);

	fuegoSec.setTexture(fuegoTex);
	fuegoSec.setPosition(0, 40);

};

PrisonEscape::PrisonEscape(RenderWindow& ventana, Music& musica, int puntos) : puntVida(puntos*300/2400)
{
	Clock clock;
	ventana.setFramerateLimit(60);
	loadSprites(musica, puntos);

	while (ventana.isOpen()) {
		while (ventana.pollEvent(this->evento)) {
			if (this->evento.type == Event::Closed) {
				ventana.close();
			}

			if (clock.getElapsedTime().asMilliseconds() > 60) {
				num++;
				alter++;
				fuegoTex.loadFromFile("Resources/Fuegos/Fuego" + std::to_string(num) + ".png");
				fuegoMTex.loadFromFile("Resources/Fuegos/Fuegos" + std::to_string(num) + ".png");
				fuegoM2Tex.loadFromFile("Resources/Fuegos/Fuegos" + std::to_string(alter) + ".png");
				if (num >= 4) {
					num = 0;
				}
				if (alter >= 4)
					alter = 0;

				clock.restart();
				render(ventana);
			}
		}
		if (puntVida <= 0)
			gameOver = true;

		if (clock.getElapsedTime().asMilliseconds() > 60) {
			if (puntVida > 0) {
				puntVida--;
				vida.setSize(Vector2f(puntVida, 40));
			}
			num++;
			alter++;
			fuegoTex.loadFromFile("Resources/Fuegos/Fuego" + std::to_string(num) + ".png");
			fuegoMTex.loadFromFile("Resources/Fuegos/Fuegos" + std::to_string(num) + ".png");
			fuegoM2Tex.loadFromFile("Resources/Fuegos/Fuegos" + std::to_string(alter) + ".png");
			if (num >= 4)
				num = 0;
			if (alter >= 4)
				alter = 0;

			clock.restart();
			render(ventana);
		}
	}
}

void PrisonEscape::render(RenderWindow& ventana)
{
	ventana.clear(Color::Black);
	if (!gameOver) {
		ventana.draw(this->fondo);
		ventana.draw(this->fuegoMSec);
		ventana.draw(this->fuegoM2Sec);
		ventana.draw(personaje);
		ventana.draw(enemigo);
		ventana.draw(this->fuegoSec);
		ventana.draw(fondoRojo);
		ventana.draw(vida);
	}
	else {
		ventana.draw(OverTitle);
	}

	ventana.display();
}
