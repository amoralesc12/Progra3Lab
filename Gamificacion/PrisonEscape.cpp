#include "PrisonEscape.h"

using std::cout;

void PrisonEscape::loadSprites(Music& musica) {

	//loading textures
	if (!fondoTex.loadFromFile("Resources/Mazmorra.jpg")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!fuegoTex.loadFromFile("Resources/Fuegos/Fuego1.png")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!fuegoMTex.loadFromFile("Resources/Fuegos/Fuegos1.png")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!fuegoM2Tex.loadFromFile("Resources/Fuegos/Fuegos3.png")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!musica.openFromFile("Resources/SuspenseTrack1.ogg")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!sfx.openFromFile("Resources/SFX Fuego.ogg")) { cout << "NO ESTA LA IMAGEN FONDO"; }

	sfx.play();
	sfx.setLoop(true);
	musica.play();
	musica.setLoop(true);
	
	fondo.setTexture(fondoTex);
	fondo.setPosition(-285, 0);
	fondo.setScale(.95f,.95f);

	fuegoMSec.setTexture(fuegoMTex);
	fuegoMSec.setPosition(-280, -7);
	fuegoMSec.setScale(.8f, .8f);

	fuegoM2Sec.setTexture(fuegoM2Tex);
	fuegoM2Sec.setPosition(488, -7);
	fuegoM2Sec.setScale(.8f, .8f);

	fuegoSec.setTexture(fuegoTex);
	fuegoSec.setPosition(0, 40);

};

PrisonEscape::PrisonEscape(RenderWindow& ventana, Music& musica)
{
	Clock clock;
	ventana.setFramerateLimit(60);
	loadSprites(musica);

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
				if (num >= 4)
					num = 0;
				if (alter >= 4)
					alter = 0;

				clock.restart();
				render(ventana);
			}
		}

		if (clock.getElapsedTime().asMilliseconds() > 60) {
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
	ventana.draw(this->fondo);
	ventana.draw(this->fuegoSec);
	ventana.draw(this->fuegoMSec);
	ventana.draw(this->fuegoM2Sec);

	ventana.display();
}
