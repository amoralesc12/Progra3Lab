#include "TextArea.h"

TextArea::TextArea() : limit(40)
{
	texto.setString("Holaaa");
	texto.setCharacterSize(20);
	texto.setPosition(0, 0);
}

TextArea::TextArea(int max) : limit(max)
{
	texto.setCharacterSize(20);
	texto.setPosition(0, 0);
}
void TextArea::draw(RenderWindow& ventana)
{
	ventana.draw(texto);
}

void TextArea::setString(string str)
{
		texto.setString(str);
		justify();
}

void TextArea::setLimit(int max)
{
	limit = max;
}

void TextArea::justify()
{
	string str = texto.getString();
	string stPaso = "";
	int actual = 0;
	int siguiente = 1;
	bool salto = false;
	while (actual < str.length())
	{
		const char* letra = &str.at(actual);
		if (actual % limit == 0 && actual != 0)
			salto = true;
		if (salto && str.at(siguiente) == ' ') {
			stPaso.append(letra, 1);
			stPaso.append("\n");
			salto = false;
		}
		else
			stPaso.append(letra, 1);
		actual++;
		siguiente++;
	}
	texto.setString(stPaso);
}

void TextArea::setPosition(float x, float y)
{
	texto.setPosition(x, y);
}

void TextArea::setTextSize(float size)
{
	texto.setCharacterSize(size);
}

void TextArea::setFont(Font& font)
{
	texto.setFont(font);
}

void TextArea::setScale(float scaleX, float scaleY)
{
	texto.setScale(scaleX, scaleY);
}

FloatRect TextArea::getGlobalBounds()
{
	return texto.getGlobalBounds();
}
