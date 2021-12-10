#pragma once
#ifndef QUESTION_H
#define QUESTION_H
//COMMIT
#include<string>
#include<array>

using namespace std;
class Question
{
public:
//Question = Arte
	void Arte();
	int getArte();
	int getResp_Arte();

	void Politica();
	int getPolitica();
	int getResp_Politica();

	void Ciencia();
	int getCiencia();
	int getResp_Ciencia();

	void Historia();
	int getHistoria();
	int getResp_Historia();

	void Game_Globos();
	int getGame_Globos();
	int getResp_Game_Globos();

	//Para select puertas(ruleta del saber)
	array<array<string, 7>, 5 >q;
	//Para juego de globos
	array<array<string, 6>, 4 >g;
	int temF;



private:
	//array de 5 columnas y 20 filas
	//Columna 1 guarda la Pregunta, de la 2 a la 5 las opciones, la columna 6 el numero de respuesta correcta 
	//y la 7 el tipo de pregunta(0-> Arte, 1->Politica, 2->Ciencia, 3-> Historia)

	int temC;

};
#endif // !QUESTION_H


