#pragma once
#ifndef GAME_H
#define GAME_H
//COMMIT
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <array>

using namespace sf;
class Game
{
public:
	Game(RenderWindow& mWindow);
	void run(RenderWindow& mWindow, Music& musica, int puntos);
private:
	void processEvents(RenderWindow& mWindow, Music& musica, int puntos);
	//void update();
	void update(sf::Time);
	void render(RenderWindow& mWindow, Music& musica);
	void handlePlayerInput(sf::Keyboard::Key, bool);
	bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
	float PlayerSpeed;
	void load_graphs();



private:
	//sf::CircleShape mPlayer;
	sf::Time TimePerFrame;
	std::array< sf::Texture, 4>tex_globos;
	std::array< sf::Sprite, 4>spr_globos;
	sf::Texture tex_Ground;
	sf::Texture tex_Pointer;
	sf::Sprite spr_Pointer;
	sf::Sprite spr_Ground;
	sf::Text texto;
	sf::Font fuente;
	sf::Music musica;
	Event evento;
};

#endif // GAME_H


