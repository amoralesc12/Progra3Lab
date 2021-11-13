#pragma once
#ifndef QUESTION_H
#define QUESTION_H

#include<string>
#include<array>

using namespace std;
class Question
{
public:
	Question();
	int getQuestion();
	int getResp();
	array<array<string, 7>, 10 >q;


private:
	//array de 5 columnas y 20 filas
	//Columna 1 guarda la Pregunta, de la 2 a la 5 las opciones, la columna 6 el numero de respuesta correcta y la 7 el tipo de pregunta(0-> Arte, 2->Politica ...)

	int temF;
	int temC;

};
#endif // !QUESTION_H


