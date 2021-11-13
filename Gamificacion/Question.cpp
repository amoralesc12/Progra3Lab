#include "Question.h"
#include <random>;
#include <ctime>

using namespace std;
Question::Question(){
	this->q[0][0] = "Uno de los siguientes personajes fue el encargado de pintar la capilla Sixtina:";

		this->q[0][1] = "Miguel Angel";
		this->q[0][2] = "Donatello";
		this->q[0][3] = "Leonardo Da Vinci";
		this->q[0][4] = "Francis Bacon";
		this->q[0][5] = "1";
		this->q[0][6] = "0";


	this->q[1][0] = "Genio del renacimiento que esculpió el Moisés, el David y la Pieta:";
		this->q[1][1] = "Miguel Angel Buonarroti";
		this->q[1][2] = "Leonardo Da Vinci";
		this->q[1][3] = "Rafael Sanzio";
		this->q[1][4] = "Galileo Galilei";
		this->q[1][5] = "1";
		this->q[1][6] = "0";
	this->q[2][0] = " Durante el renacimiento el estilo artístico que impregnó el arte, la filosofia, la pintura escritura fue el:";
		this->q[2][1] = "El Gotico";
		this->q[2][2] = "El barroco";
		this->q[2][3] = "El clasicismo";
		this->q[2][4] = "Romanticismo";
		this->q[2][5] = "2";
		this->q[2][6] = "0";
		
	this->q[3][0] = "Durante el renacimiento surge una nueva vision del hombre, que se vio reflejada en el arte, en la politica y en las ciencias sociales y humanas, a lo que se denomina : ";
		this->q[3][1] = "Antropocentrismo";
		this->q[3][2] = "Humanismo";
		this->q[3][3] = "Paradigma antropologico";
		this->q[3][4] = "Teocentrismo";
		this->q[3][5] = "2";
		this->q[3][6] = "0";
	
	
	this->q[4][0] = " Cuatro genios del renacimiento (Leonardo, Donatello, Rafael y Michelangelo) han sido llevados a la pantalla en los comics de : ";
		this->q[4][1] = "Las tortugas ninjas";
		this->q[4][2] = "Los caballeros del Zodiaco";
		this->q[4][3] = "Los cuatro fantasticos";
		this->q[4][4] = "Los antagonistas de Attack Titan";
		this->q[4][5] = "1";
		this->q[4][6] = "0";
	
	
	this->q[5][0] = " Durante el renacimiento, el modelo de gobierno es uno de los siguientes:";
		this->q[5][1] = "Monarquia absoluta";
		this->q[5][2] = "Tiranía republicana";
		this->q[5][3] = "Democracia participativa";
		this->q[5][4] = " Liberalismo politico";
		this->q[5][5] = "1";
		this->q[5][6] = "1";

	this->q[6][0] = "De los siguientes acontecimientos, selecciones el que inicia el periodo moderno: ";
		this->q[6][1] = "Toma de Constantinopla";
		this->q[6][2] = "Tratado de paz de westfalia";
		this->q[6][3] = "Toma de la Bastilla";
		this->q[6][4] = "La ruta de la seda";
		this->q[6][5] = "2";
		this->q[6][6] = "1";

	this->q[7][0] = "Durante el siglo XV, la sociedad se estratifica en tres estamentos definidos: ";
		this->q[7][1] = "Toma de Constantinopla";
		this->q[7][2] = "Tratado de paz de westfalia";
		this->q[7][3] = "Toma de la Bastilla";
		this->q[7][4] = "La ruta de la seda";
		this->q[7][5] = "2";
		this->q[7][6] = "1";

	this->q[8][0] = "Aparece el realismo politico, que se basaba en un orden establecido, explicacion de un sistema y recomendaciones de como gobernar : ";
		this->q[8][1] = "Tomas Moro";
		this->q[8][2] = "Jean Bodin";
		this->q[8][3] = "Nicolas Maquiavelo";
		this->q[8][4] = " Erasmo de Rotterdam";
		this->q[8][5] = "2";
		this->q[8][6] = "1";
	this->q[9][0] = "Terminada la edad media, en el contexto de la politica resulta que:";
		this->q[9][1] = "La Iglesia resalta su poder";
		this->q[9][2] = "La Iglesia pierde el papel rector en la politica";
		this->q[9][3] = " La Iglesia evangelica se posiciona en la politica";
		this->q[9][4] = " La política desaparece";
		this->q[9][5] = "2";
		this->q[9][6] = "1";

}

int Question::getQuestion() {
	default_random_engine motor(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> intRan(0, 9);
	int f = intRan(motor);
	this->temF = f;
	
	
return f;

}

int Question::getResp() {
	return stoi(this->q[this->temF][5])-1;//Pasar string a int con stoi
	//A->0, B->1...
}

