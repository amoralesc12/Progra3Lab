#include "IntroLvl.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "selectPuertas.h"
#include <iostream>
//
using namespace std;
using namespace sf;

void IntroLvl::loadSprites(Music& musica) {

	//loading textures
	if (!fondoTexture.loadFromFile("Resources/FondoPiedra.png")) { cout << "NO ESTA LA IMAGEN FONDO"; }
	if (!cartaTexture.loadFromFile("Resources/Carta.png")) { cout << "NO ESTA LA IMAGEN CARTA"; }
	if (!fuente.loadFromFile("Resources/CurlyLetters.ttf")) { cout << "NO ESTA LA FUENTE"; }
	if (!musica.openFromFile("Resources/Musica2.ogg")) { cout << "NO ESTA LA MUSICA!"; }

	musica.play();

	//setting Sprites with textures
	this->fondo.setTexture(this->fondoTexture);
	this->fondo.setPosition(0, 0);
	this->fondo.setScale(.5f, .5f);

	this->carta.setTexture(this->cartaTexture);
	this->carta.setPosition(this->x1, this->y1);
	this->carta.setScale(.7f, 1);

	narracion = Text();
	narracion.setString(
		"En la segunda mitad del siglo XIV,\n"
		"las personas cultas en Italia\n"
		"insisten en que se ha producido\n"
		"un cambio fundamental en la actitud\n"
		"de los hombres frente al mundo\n"
		"y a la vida, denominado humanismo.\n"
		"Están convencidos que se ha producido\n"
		"una ruptura radical con el mundo\n"
		"medieval y tratan de entender cuál\n"
		"es el significado del cambio, luego\n"
		"para final del mismo siglo y durante\n"
		"el siglo XV, los reyes aprovecharon la\n"
		"crisis del feudalismo para retomar su\n"
		"poder, lo que supone el Renacimiento\n"
		"del hombre, de la cultura y la sociedad,\n"
		"pero sobre todo de transformaciones\n"
		"en los mecanismos del gobierno y en\n"
		"el ejercicio del poder, respaldado por\n"
		"la burguesía.El tratado de Paz firmado\n"
		"en Westfalia que finalizó la Guerra de\n"
		"los Treinta Años en Alemania y la Guerra\n"
		"de los ochenta años entre España y los\n"
		"Países Bajos en 1648, dio origen al\n"
		"Estado Nacional, replanteando los\n"
		"principios de soberanía y de integridad\n"
		"territorial en las naciones europeas.\n"
		"En el campo de la filosofía, después de\n"
		"la revolución científica, se revaloriza\n"
		"al hombre como sujeto de la razón,\n"
		"suscitando una visión antropocéntrica\n"
		"de la filosofía, la ciencia y otras\n"
		"disciplinas.En el terreno de la\n"
		"epistemología, se desarrollan grandes\n"
		"discusiones en torno al problema del\n"
		"conocimiento, uno de los cuales\n"
		"enfrentará a los racionalistas(quienes\n"
		"afirmaban que el conocimiento se origina\n"
		"en la razón a través de las ideas innatas)\n"
		"frente a los empiristas(quienes afirmaban\n"
		"que el conocimiento se origina en las\n"
		"experiencias sensibles, a través de\n"
		"los sentidos).A continuación, te invitamos\n"
		"a acompañarnos en este viaje cognitivo.\n"
		"Vas a seguir un trayecto a través de\n"
		"distintos niveles, que deberás seguir\n"
		"con responsabilidad.En el primero\n"
		"denominada ruleta del saber, inicias\n"
		"un nivel de entrenamiento donde vas\n"
		"a cargar vidas para los siguientes\n"
		"niveles, en el siguiente nivel denominado\n"
		"de andamiaje, vas asumiendo retos y\n"
		"guías mientras sumas puntos hasta llegar\n"
		"al nivel de dominio, nivel de experto");
	narracion.setFont(fuente);
	narracion.setFillColor(Color::Black);
	narracion.setPosition(this->x, this->y);
	narracion.setCharacterSize(44);

	continuar.setString("Clic para continuar...");
	continuar.setFont(fuente);
	continuar.setFillColor(Color::Black);
	continuar.setPosition(this->x, 550);
	continuar.setCharacterSize(44);

};

IntroLvl::IntroLvl(RenderWindow& window, Music& musica) {
	pantalla(window, musica);
}

void IntroLvl::pantalla(RenderWindow& window, Music& musica) {
	//  h    w
	window.setFramerateLimit(60);
	loadSprites(musica);

	Clock wait;
	Time tempo = wait.getElapsedTime();

	while (window.isOpen()) {
		while (window.pollEvent(this->evento)) {
			if (this->evento.type == Event::Closed) {
				window.close();
			}
			if (this->evento.type == Event::MouseButtonPressed) {
				speedUp = 8;
				if (this->narracion.getPosition().y < -3200) {
					window.clear();
					selectPuertas puertas(window);
				}
			}
			if (this->evento.key.code == Keyboard::Escape) {
				window.clear();
				selectPuertas puertas(window);
			}
			if (evento.type == Event::MouseButtonReleased) {
				speedUp = 1;
			}

		}

		window.clear(Color::Black);
		window.draw(this->fondo);
		window.draw(this->carta);
		window.draw(this->narracion);

		if (this->narracion.getPosition().y >= -3200) {
			this->y1 -= 0.86 * speedUp; this->y -= 1 * speedUp;
			this->carta.setPosition(this->x1, this->y1);
			this->narracion.setPosition(this->x, this->y);
		}
		else { window.draw(continuar); }

		window.display();
	}
}