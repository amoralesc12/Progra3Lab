#pragma once
#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include<array>
class Game
{

public:
	Game();
	void run();
private:
	void processEvents();
	//void update();
	void update(sf::Time);
	void render();
	void handlePlayerInput(sf::Keyboard::Key, bool);
	bool mIsMovingUp, mIsMovingDown, mIsMovingLeft,  mIsMovingRight;
	float PlayerSpeed;
	void load_graphs();
	
	
	


private:
	sf::RenderWindow mWindow;
	//sf::CircleShape mPlayer;
	sf::Time TimePerFrame;
	std::array< sf::Texture,4>tex_globos ;
	std::array< sf::Sprite, 4>spr_globos;
	sf::Texture tex_Ground;
	sf::Sprite spr_Ground;
};
#endif // !GLOBOS_H
