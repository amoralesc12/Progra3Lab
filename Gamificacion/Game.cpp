#include "Game.h"
#include<iostream>
#include <stdlib.h> 
#include <ctime>
#include <stdio.h>
#include<random>


Game::Game(): mWindow(sf::VideoMode(1000, 700), "Revienta los Globos")
{
	//
	
	//



	spr_Ground.setPosition(0.f, 0.f);//FONDO

	mWindow.setFramerateLimit(60);//DELIMITAR FPS
	
	//this->TimePerFrame = sf::seconds(1.f / 60.f);
	load_graphs();

	//CARGANDO LA FIGURA

	
}

void Game::load_graphs() {
	std::string path ;

	for (int i = 0; i < 4; i++)
	{
		//GENERACION RANDOM DE POSICIONES
		/* initialize random seed: */
		std::default_random_engine motor(static_cast<unsigned int> (time(0)));
		std::uniform_int_distribution<unsigned int> randomX(1, 6);
		std::uniform_int_distribution<unsigned int> randomY(1, 6);
		
		std::cout << randomX<<"\n";

		std::cout << randomY << "\n";

		path = "Graph/b" + std::to_string(i + 1) + ".png";
		
		if (!tex_globos[i].loadFromFile(path))
		{
			// Handle loading error
		}

		spr_globos[i].setTexture(tex_globos[i]);
		spr_globos[i].setScale(sf::Vector2f(0.2, 0.2));
		spr_globos[i].setPosition(100.f+float(i)*250, 600.f+float(i) * 400);
	}

	//FONDO
	if (!tex_Ground.loadFromFile("Graph/ground.png"))
	{
		// Handle loading error
	}



	spr_Ground.setTexture(tex_Ground);




}
void Game::run()
{
	sf::Clock clock;
	while (mWindow.isOpen())
	{
		sf::Time deltaTime = clock.getElapsedTime();
		processEvents();
		update(deltaTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
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

	for ( int i = 0; i < 4; i++)
	{
	spr_globos[i].move(sf::Vector2f(0, -0.0005 * deltaTime.asMilliseconds()));
	}
	
}

void Game::render()
{
	mWindow.clear();
	
	mWindow.draw(spr_Ground);
	for (int i = 0; i < 4; i++)
	{
		mWindow.draw(spr_globos[i]);
	}
	
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

