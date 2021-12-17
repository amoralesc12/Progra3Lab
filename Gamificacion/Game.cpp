#include "Game.h"
#include "Recorrido.h"
#include<iostream>
#include <stdlib.h> 
#include <ctime>
#include <stdio.h>
#include"Question.h"
#include "TriviaSelect.h"
#include<random>
//
Question question;
Game::Game(RenderWindow& mWindow)
{
	//
	if (!this->fuente.loadFromFile("Resources/CurlyLetters.ttf"))
	{
	}

	// Asignamos la fuente que hemos cargado al texto
	texto.setFont(fuente);
	// Tamaño de la fuente
	texto.setCharacterSize(18);
	// Posición del texto
	texto.setPosition(20, 10);
	sf::Color color(250, 16, 74);
	texto.setFillColor(color);

	question.Game_Globos();
	texto.setString(question.g[question.getGame_Globos()][0]);
	for (size_t i = 0; i < 4; i++) {
		resp[i].setFillColor(sf::Color::Black);
		resp[i].setFont(fuente);
		resp[i].setCharacterSize(30);
		resp[i].setString(std::to_string(i + 1) + " " + question.g[question.temF][i + 1]);
	}

	resp[0].setPosition(150, 540);
	resp[1].setPosition(400, 1000 - 60);
	resp[2].setPosition(650, 1400 - 60);
	resp[3].setPosition(700, 1800 - 60);



	spr_Ground.setPosition(0.f, 0.f);//FONDO

	//this->TimePerFrame = sf::seconds(1.f / 60.f);
	load_graphs();

	//MOUSE
	mWindow.setMouseCursorVisible(false);

}

void Game::load_graphs() {
	std::string path;

	for (int i = 0; i < 4; i++)
	{
		//GENERACION RANDOM DE POSICIONES
		/* initialize random seed: */
		std::default_random_engine motor(static_cast<unsigned int> (time(0)));
		std::uniform_int_distribution<unsigned int> randomX(1, 6);
		std::uniform_int_distribution<unsigned int> randomY(1, 6);

		std::cout << randomX << "\n";

		std::cout << randomY << "\n";

		path = "Resources/b" + std::to_string(i + 1) + ".png";

		if (!tex_globos[i].loadFromFile(path))
		{
			// Handle loading error
		}

		spr_globos[i].setTexture(tex_globos[i]);
		spr_globos[i].setScale(sf::Vector2f(0.2, 0.2));
		spr_globos[i].setPosition(100.f + float(i) * 250, 600.f + float(i) * 400);
	}

	//FONDO
	if (!tex_Ground.loadFromFile("Resources/ground.png"))
	{
		// Handle loading error
	}
	if (!tex_Pointer.loadFromFile("Resources/puntero3.png"))
	{
		// Handle loading error
	}


	spr_Ground.setTexture(tex_Ground);

	spr_Pointer.setTexture(tex_Pointer);
	spr_Pointer.setPosition(300.f, 200.f);
	//spr_Pointer.setScale(sf::Vector2f(0.8, 0.8));
}
void Game::run(RenderWindow& mWindow, Music& musica, int puntos, int contador, int bando)
{
	sf::Clock clock;
	while (mWindow.isOpen()){
		sf::Time deltaTime = clock.getElapsedTime();
		processEvents(mWindow, musica, puntos, contador, bando);
		update(deltaTime);
		render(mWindow, musica);
		
	}
}

void Game::processEvents(RenderWindow& mWindow, Music& musica, int puntos, int contador, int bando)
{
	sf::FloatRect rect(spr_Pointer.getPosition(), (sf::Vector2f)spr_Pointer.getTexture()->getSize());
	sf::Cursor def; def.loadFromSystem(sf::Cursor::Arrow);

	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow.close();

		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Escape) {
				Recorrido ch;
				mWindow.setMouseCursor(def);
				mWindow.setMouseCursorVisible(true);
				ch.loadQScreen_R1(mWindow, musica, puntos, bando);
			}
		}
		switch (event.type)
		{
		case sf::Event::MouseMoved:
			spr_Pointer.setPosition((sf::Vector2f)sf::Mouse::getPosition(mWindow));

			break;
		case sf::Event::MouseButtonPressed:
			for (int i = 0; i < 4; i++)
			{
				if (spr_globos[i].getGlobalBounds().intersects(rect))
				{
					//spr_globos[i].setColor(sf::Color(250, 0, 0));
					if (question.getResp_Game_Globos() == i)
					{
						//GANADORRRR
						spr_globos[i].setColor(sf::Color::Green);
						contador++;
						Clock delay;
						while (delay.getElapsedTime().asMilliseconds() <= 1350) { }

						if (contador >= 4) {
							Recorrido ch;
							mWindow.setMouseCursor(def);
							mWindow.setMouseCursorVisible(true);
							ch.loadQScreen_R1(mWindow,musica,puntos, bando);						
						}
						Game reset(mWindow);
						reset.run(mWindow, musica, puntos, contador, bando);

					}
					else {
						if (!tex_globos[i].loadFromFile("Resources/b5.png")) {

						}
						spr_globos[i].setTexture(tex_globos[i]);
					}



				}
			}

			break;
		}

	}

}

void Game::update(sf::Time deltaTime)
{
	/*this->PlayerSpeed = 3.f;
	sf::Vector2f movement(0.f, 0.f);
if (mIsMovingUp)
		movement.y -= PlayerSpeed;
	if (mIsMovingDown)
		movement.y += PlayerSpeed;
	if (mIsMovingLeft)
		movement.x -= PlayerSpeed;
	if (mIsMovingRight)
		movement.x += PlayerSpeed;*/

	for (int i = 0; i < 4; i++)
	{	
		resp[i].move(sf::Vector2f(0, -0.0005 * deltaTime.asMilliseconds()));
		spr_globos[i].move(sf::Vector2f(0, -0.0005 * deltaTime.asMilliseconds()));
	}

}

void Game::render(RenderWindow& mWindow, Music& musica)
{
	mWindow.clear();

	mWindow.draw(spr_Ground);
	for (int i = 0; i < 4; i++)
	{
		mWindow.draw(spr_globos[i]);
		mWindow.draw(resp[i]);
	}
	mWindow.draw(texto);
	mWindow.draw(spr_Pointer);
	mWindow.display();
}



void Game::handlePlayerInput(sf::Keyboard::Key key,
	bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}