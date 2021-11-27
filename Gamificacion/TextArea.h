#pragma once

#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using std::string;

class TextArea
{

public:
	TextArea();
	TextArea(int max);
	TextArea(string, int max);
	void draw(RenderWindow& ventana);
	
	void setString(string str);
	void setLimit(int max);
	void justify();
	void setPosition(float x, float y);
	void setTextSize(float size);
	void setFont(Font& font);
	void setScale(float scaleX, float scaleY);
	FloatRect getGlobalBounds();

private:
	int limit;
	Text texto;
	Font fuente;

};


#endif // !TEXTAREA_H

