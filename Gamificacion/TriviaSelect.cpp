#include "TriviaSelect.h"
#include "elegirBando.h"
#include "Recorrido.h"
#include"SFML/Graphics.hpp"
#include "mainscreen.h"
#include "Game.h"
using namespace std;
using namespace sf;

#include <iostream>


//MAIN SCREEN
void TriviaSelect::loadSprites_TS() {

	if (!bg.loadFromFile("Resources/bgTriviaSelect.jpg")) { cout << "NO ESTA"; }
	if (!b1.loadFromFile("Resources/qb.png")) { cout << "NO ESTA"; }
	if (!fuente.loadFromFile("Resources/Elastic Stretch.ttf")) { cout << "NO ESTA LA FUENTE"; }
	
	bgN1.setTexture(bg);
	bgN1.setPosition(0, 0);

	//question boxes

	qb1.setTexture(b1);			qb1.setPosition(150, 200);
	qb2.setTexture(b1);			qb2.setPosition(350, 200);
	qb3.setTexture(b1);			qb3.setPosition(550, 200);
	qb4.setTexture(b1);			qb4.setPosition(750, 200);
	qb5.setTexture(b1);			qb5.setPosition(150, 400);
	qb6.setTexture(b1);			qb6.setPosition(350, 400);
	qb7.setTexture(b1);			qb7.setPosition(550, 400);
	qb8.setTexture(b1);			qb8.setPosition(750, 400);

	

}
void TriviaSelect::loadScreen_TS(RenderWindow& ventana, Music& musica) {

	loadSprites_TS();

	while (ventana.isOpen()) {
		while (ventana.pollEvent(this->evento)) {
			Vector2i mousePos = Mouse::getPosition(ventana);
			Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

			if (this->evento.type == Event::Closed) {
				ventana.close();
			}
			if (this->evento.type == Event::MouseButtonPressed) {

				if (this->qb1.getGlobalBounds().contains(mousePosF)|| this->qb3.getGlobalBounds().contains(mousePosF)
					|| this->qb4.getGlobalBounds().contains(mousePosF)|| this->qb7.getGlobalBounds().contains(mousePosF))
				{
					TriviaSelect choose;
					choose.loadWrongBoxScreen_TS(ventana, musica);
				}
				else if (this->qb2.getGlobalBounds().contains(mousePosF))
	      	     	 {
					TriviaSelect choose;
					choose.loadQuestionBoxScreen_TS(ventana, musica);

				     }
				else if ( this->qb5.getGlobalBounds().contains(mousePosF))
				{
					TriviaSelect choose;
					choose.loadQuestionBoxScreen2_TS(ventana, musica);

				}
				else if (this->qb6.getGlobalBounds().contains(mousePosF))
				{
					TriviaSelect choose;
					choose.loadQuestionBoxScreen3_TS(ventana, musica);

				}
				else if (this->qb8.getGlobalBounds().contains(mousePosF))
				{
					TriviaSelect choose;
					choose.loadQuestionBoxScreen4_TS(ventana, musica);
				}

			}
			if (evento.type == Event::KeyPressed) {
				if (evento.key.code == Keyboard::Escape) {
					RenderWindow window;
					Recorrido choose;
					choose.loadQScreen_R2(ventana, musica);
				}
			}
			

		}

		renderTS(ventana);
	}

}
void TriviaSelect::renderTS(RenderWindow& ventana)
{
	
	ventana.draw(this->bgN1);
	ventana.draw(this->qb1);
	ventana.draw(this->qb2);
	ventana.draw(this->qb3);
	ventana.draw(this->qb4);
	ventana.draw(this->qb5);
	ventana.draw(this->qb6);
	ventana.draw(this->qb7);
	ventana.draw(this->qb8);


	ventana.display();
}

//QUESTIONS & OPTIONS

void TriviaSelect::loadQuestionBoxScreen_TS(RenderWindow& ventana, Music& musica)
{
	RenderWindow window(VideoMode(626, 417), "Open Box", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	loadQuestionBoxSprites_TS();
	
	while (window.isOpen()) {
		Vector2i mousePos = Mouse::getPosition();
		Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		while (window.pollEvent(this->evento)) {

			if (this->evento.type == Event::Closed) {
				window.close();
			}
			if (this->evento.type == Event::KeyPressed)
			{
				if (evento.key.code == Keyboard::A) {
					TriviaSelect choose;
					window.close();
					choose.loadScreen_TS(ventana, musica);
				}
				else if (evento.key.code == Keyboard::B|| Keyboard::C||Keyboard::D) {
					TriviaSelect choose;
					window.close();
					choose.loadScreen_TS(ventana, musica);

				}
			}
		}

		window.draw(this->QuestionS);
		window.draw(this->question);
		window.draw(this->opA);
		window.draw(this->opB);
		window.draw(this->opC);
		window.draw(this->opD);
		window.display();
	}

}
void TriviaSelect::loadQuestionBoxSprites_TS()
{
	if (!qs.loadFromFile("Resources/QuestionS.jpg")) { cout << "NO ESTA"; }
	if (!fuente.loadFromFile("Resources/ScriptLetter.ttf")) { cout << "NO ESTA LA FUENTE"; }
	
	QuestionS.setTexture(qs);
	QuestionS.setPosition(0, 0);

	question.setString(" Para algunos de los siguientes filosofos,\n"
	                   "el criterio de verdad es la evidencia sensible:");
	question.setFont(fuente);
	question.setFillColor(Color::White);
	question.setPosition(150,100);
	question.setCharacterSize(25);

	opA.setString(" A. Empiristas ");
	opA.setFont(fuente);
	opA.setFillColor(Color::White);
	opA.setPosition(100, 220);
	opA.setCharacterSize(25);

	opB.setString(" B. Racionalistas ");
	opB.setFont(fuente);
	opB.setFillColor(Color::White);
	opB.setPosition(380, 220);
	opB.setCharacterSize(25);


	opC.setString(" c. Dogmaticos ");
	opC.setFont(fuente);
	opC.setFillColor(Color::White);
	opC.setPosition(100, 295);
	opC.setCharacterSize(25);

	opD.setString(" D. Esc�pticos ");
	opD.setFont(fuente);
	opD.setFillColor(Color::White);
	opD.setPosition(380, 295);
	opD.setCharacterSize(25);

}


void TriviaSelect::loadQuestionBoxScreen2_TS(RenderWindow& ventana, Music& musica)
{
	RenderWindow window(VideoMode(626, 417), "Open Box", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	loadQuestionBoxSprites2_TS();
	Vector2i mousePos = Mouse::getPosition();
	Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));


	while (window.isOpen()) {
		while (window.pollEvent(this->evento)) {
			if (this->evento.type == Event::Closed) {
				window.close();
			}
			
		}

		window.draw(this->QuestionS);
		window.draw(this->question);
		window.draw(this->opA);
		window.draw(this->opB);
		window.draw(this->opC);
		window.draw(this->opD);
		window.display();
	}

}
void TriviaSelect::loadQuestionBoxSprites2_TS()
{
	if (!qs.loadFromFile("Resources/Questions.jpg")) { cout << "NO ESTA"; }
	if (!fuente.loadFromFile("Resources/ScriptLetter.ttf")) { cout << "NO ESTA LA FUENTE"; }


	QuestionS.setTexture(qs);
	QuestionS.setPosition(0, 0);

	question.setString(" Filosofos para quienes la unica fuente del\n" " conocimiento es la raz�n");
	question.setFont(fuente);
	question.setFillColor(Color::White);
	question.setPosition(150, 100);
	question.setCharacterSize(25);

	opA.setString(" A. Epistem�logos ");
	opA.setFont(fuente);
	opA.setFillColor(Color::White);
	opA.setPosition(100, 220);
	opA.setCharacterSize(25);

	opB.setString(" B. Racionalistas ");
	opB.setFont(fuente);
	opB.setFillColor(Color::White);
	opB.setPosition(380, 220);
	opB.setCharacterSize(25);


	opC.setString(" C. Empiristas ");
	opC.setFont(fuente);
	opC.setFillColor(Color::White);
	opC.setPosition(100, 295);
	opC.setCharacterSize(25);
	
	opD.setString(" D. Esc�pticos ");
	opD.setFont(fuente);
	opD.setFillColor(Color::White);
	opD.setPosition(380, 295);
	opD.setCharacterSize(25);
	
}

void TriviaSelect::loadQuestionBoxScreen3_TS(RenderWindow& ventana, Music& musica)
{
	RenderWindow window(VideoMode(612, 408), "Open Box", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	loadQuestionBoxSprites3_TS();
	Vector2i mousePos = Mouse::getPosition();
	Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));


	while (window.isOpen()) {
		while (window.pollEvent(this->evento)) {
			if (this->evento.type == Event::Closed) {
				window.close();
			}


		}

		window.draw(this->QuestionS);
		window.draw(this->question);
		window.draw(this->opA);
		window.draw(this->opB);
		window.draw(this->opC);
		window.draw(this->opD);
		window.display();
	}

}
void TriviaSelect::loadQuestionBoxSprites3_TS()
{
	if (!qs.loadFromFile("Resources/Questions.jpg")) { cout << "NO ESTA"; }
	if (!fuente.loadFromFile("Resources/ScriptLetter.ttf")) { cout << "NO ESTA LA FUENTE"; }
	

	QuestionS.setTexture(qs);
	QuestionS.setPosition(0, 0);

	question.setString("\tPara algunos de los siguientes filosofos,\n"
		"\t\tla experiencia es la unica fuente\n""\t\tdel conocimiento");
	question.setFont(fuente);
	question.setFillColor(Color::White);
	question.setPosition(130, 90);
	question.setCharacterSize(25);

	opA.setString(" A. Epistem�logos ");
	opA.setFont(fuente);
	opA.setFillColor(Color::White);
	opA.setPosition(100, 220);
	opA.setCharacterSize(25);


	opB.setString(" B. Racionalistas ");
	opB.setFont(fuente);
	opB.setFillColor(Color::White);
	opB.setPosition(380, 220);
	opB.setCharacterSize(25);
	

	opC.setString(" C. Empiristas ");
	opC.setFont(fuente);
	opC.setFillColor(Color::White);
	opC.setPosition(100, 295);
	opC.setCharacterSize(25);
	
	opD.setString(" D. Esc�pticos ");
	opD.setFont(fuente);
	opD.setFillColor(Color::White);
	opD.setPosition(380, 295);
	opD.setCharacterSize(25);
	
}

void TriviaSelect::loadQuestionBoxScreen4_TS(RenderWindow& ventana, Music& musica)
{
	RenderWindow window(VideoMode(612, 408), "Open Box", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	loadQuestionBoxSprites4_TS();
	Vector2i mousePos = Mouse::getPosition();
	Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));


	while (window.isOpen()) {
		while (window.pollEvent(this->evento)) {
			


		}

		window.draw(this->QuestionS);
		window.draw(this->question);
		window.draw(this->opA);
		window.draw(this->opB);
		window.draw(this->opC);
		window.draw(this->opD);
		window.display();
	}
}
void TriviaSelect::loadQuestionBoxSprites4_TS()
{
	if (!qs.loadFromFile("Resources/Questions.jpg")) { cout << "NO ESTA"; }
	if (!fuente.loadFromFile("Resources/ScriptLetter.ttf")) { cout << "NO ESTA LA FUENTE"; }

	QuestionS.setTexture(qs);
	QuestionS.setPosition(0, 0);

	question.setString(" Uno de los siguientes fil�sofos,\n" " postula las ideas innatas en el sujeto: ");
	question.setFont(fuente);
	question.setFillColor(Color::White);
	question.setPosition(150, 100);
	question.setCharacterSize(25);

	opA.setString(" A. George Berkely ");
	opA.setFont(fuente);
	opA.setFillColor(Color::White);
	opA.setPosition(100, 220);
	opA.setCharacterSize(25);
	

	opB.setString(" B. David Hume ");
	opB.setFont(fuente);
	opB.setFillColor(Color::White);
	opB.setPosition(380, 220);
	opB.setCharacterSize(25);
	

	opC.setString(" C. Leibniz ");
	opC.setFont(fuente);
	opC.setFillColor(Color::White);
	opC.setPosition(100, 295);
	opC.setCharacterSize(25);
	

	opD.setString(" D. Hipat�a ");
	opD.setFont(fuente);
	opD.setFillColor(Color::White);
	opD.setPosition(380, 295);
	opD.setCharacterSize(25);
	
}

// WRONG BOX
void TriviaSelect::loadWrongBoxSprites_TS()
{
	if (!ws.loadFromFile("Resources/WrongQ.png")) { cout << "NO ESTA"; }
	if (!fuente.loadFromFile("Resources/Elastic Stretch.ttf")) { cout << "NO ESTA LA FUENTE"; }
	
	wrongS.setTexture(ws);
	wrongS.setPosition(0, 0);

	message.setString("\t\t\t\t\t\tINTENTALO DE NUEVO!\n\n"
		"\t\t\t\t OH NO! ESTA CAJA ESTA VACIA\n"
		" Recuerda que solo tienes 4 oportunidades\n"
		"\t\t\t\tpara poder obtener mas vidas");

	message.setFont(fuente);
	message.setFillColor(Color::Black);
	message.setPosition(40,100);
	message.setCharacterSize(35);

	


}
void TriviaSelect::loadWrongBoxScreen_TS(RenderWindow& ventana, Music& musica)
{
	RenderWindow window(VideoMode(900, 500), "Empty Box", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	loadWrongBoxSprites_TS();

	while (window.isOpen()) {
		Vector2i mousePos = Mouse::getPosition();
		Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		while (window.pollEvent(this->evento)) {
			if (this->evento.type == Event::Closed) {
				window.close();
			}
			if (this->evento.type == Event::MouseButtonPressed) {

				if (this->message.getGlobalBounds().contains(mousePosF))
				{
					TriviaSelect choose;
					window.close();
					choose.loadScreen_TS(ventana, musica);
				}

			}

			window.draw(this->wrongS);
			window.draw(this->message);
			window.display();
		}

	}
}
