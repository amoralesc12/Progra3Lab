#include "Question.h"
#include <random>;
#include <ctime>
//COMMIT
using namespace std;

void Question::Arte() {

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


	this->q[4][0] = "Cuatro genios del renacimiento (Leonardo, Donatello, Rafael y Michelangelo) han sido llevados a la pantalla en los comics de : ";
	this->q[4][1] = "Las tortugas ninjas";
	this->q[4][2] = "Los caballeros del Zodiaco";
	this->q[4][3] = "Los cuatro fantasticos";
	this->q[4][4] = "Los antagonistas de Attack Titan";
	this->q[4][5] = "1";
	this->q[4][6] = "0";



}

int Question::getArte() {
	default_random_engine motor(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> intRan(0, 4);
	int f = intRan(motor);
	this->temF = f;


	return f;

}

int Question::getResp_Arte() {
	return stoi(this->q[this->temF][5]) - 1;//Pasar string a int con stoi
	//A->0, B->1...
}


void Question::Politica()
{
	this->q[0][0] = "Durante el renacimiento, el modelo de gobierno es uno de los siguientes:";
	this->q[0][1] = "Monarquia absoluta";
	this->q[0][2] = "Tiranía republicana";
	this->q[0][3] = "Democracia participativa";
	this->q[0][4] = " Liberalismo politico";
	this->q[0][5] = "1";
	this->q[0][6] = "1";

	this->q[1][0] = "De los siguientes acontecimientos, selecciones el que inicia el periodo moderno: ";
	this->q[1][1] = "Toma de Constantinopla";
	this->q[1][2] = "Tratado de paz de westfalia";
	this->q[1][3] = "Toma de la Bastilla";
	this->q[1][4] = "La ruta de la seda";
	this->q[1][5] = "2";
	this->q[1][6] = "1";

	this->q[2][0] = "Durante el siglo XV, la sociedad se estratifica en tres estamentos definidos: ";
	this->q[2][1] = "Toma de Constantinopla";
	this->q[2][2] = "Tratado de paz de westfalia";
	this->q[2][3] = "Toma de la Bastilla";
	this->q[2][4] = "La ruta de la seda";
	this->q[2][5] = "2";
	this->q[2][6] = "1";

	this->q[3][0] = "Aparece el realismo politico, que se basaba en un orden establecido, explicacion de un sistema y recomendaciones de como gobernar : ";
	this->q[3][1] = "Tomas Moro";
	this->q[3][2] = "Jean Bodin";
	this->q[3][3] = "Nicolas Maquiavelo";
	this->q[3][4] = " Erasmo de Rotterdam";
	this->q[3][5] = "2";
	this->q[3][6] = "1";

	this->q[4][0] = "Terminada la edad media, en el contexto de la politica resulta que:";
	this->q[4][1] = "La Iglesia resalta su poder";
	this->q[4][2] = "La Iglesia pierde el papel rector en la politica";
	this->q[4][3] = " La Iglesia evangelica se posiciona en la politica";
	this->q[4][4] = " La política desaparece";
	this->q[4][5] = "2";
	this->q[4][6] = "1";
}

int Question::getPolitica()
{
	default_random_engine motor(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> intRan(0, 4);
	int f = intRan(motor);
	this->temF = f;
	return f;
}

int Question::getResp_Politica()
{
	return stoi(this->q[this->temF][5]) - 1;
}


void Question::Ciencia()
{

	this->q[0][0] = "Entre los siguientes renacentistas seleccione, uno de los precursores filosofo-cientifico del heliocentrismo (teoria que firma que el sol el centro del universo:";
	this->q[0][1] = "Tomas Moro";
	this->q[0][2] = "Galileo";
	this->q[0][3] = "Platon";
	this->q[0][4] = "Arquimedes";
	this->q[0][5] = "2";
	this->q[0][6] = "2";


	this->q[1][0] = "El metodo cientifico se introduce por el interes de tres filosofos. Entre los siguientes uno de los mencionados no es percursor del metodo cientifico:";
	this->q[1][1] = "Francis Bacon";
	this->q[1][2] = "Galileo Galilei";
	this->q[1][3] = "Nicolas Maquiavelo";
	this->q[1][4] = "Rene Descartes";
	this->q[1][5] = "3";
	this->q[1][6] = "2";

	this->q[2][0] = "Es uno de los precursores del pensamiento Moderno:";
	this->q[2][1] = "Isaac Newton";
	this->q[2][2] = "Rene Descartes";
	this->q[2][3] = "Erasmo de Roterdam";
	this->q[2][4] = "Francis Bacon";
	this->q[2][5] = "2";
	this->q[2][6] = "2";

	this->q[3][0] = "De los siguientes filosofos, quien niega el geocentrismo (teoria que afirma que el centro de nuestro sistema solar es la tierra): ";
	this->q[3][1] = "Aristoteles";
	this->q[3][2] = "Nicolas Copernico";
	this->q[3][3] = "Tomas de Aquino";
	this->q[3][4] = "Isaac Newton";
	this->q[3][5] = "2";
	this->q[3][6] = "2";


	this->q[4][0] = "Uno de los inventos que suscito un conocimiento ilimitado, fue el de Gutenberg: ";
	this->q[4][1] = "El astrolabio";
	this->q[4][2] = "La imprenta";
	this->q[4][3] = "La Nao y la Carabela";
	this->q[4][4] = "El Telescopio";
	this->q[4][5] = "1";
	this->q[4][6] = "2";
}

int Question::getCiencia()
{
	default_random_engine motor(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> intRan(0, 4);
	int f = intRan(motor);
	this->temF = f;
	return f;
}

int Question::getResp_Ciencia()
{
	return stoi(this->q[this->temF][5]) - 1;
}


void Question::Historia()
{
	this->q[0][0] = "Despues del feudalismo medieval acudimos al surgimiento de una nueva clase social conocida como la:";
	this->q[0][1] = "La monarquia";
	this->q[0][2] = "El mercantilismo";
	this->q[0][3] = "La burguesia";
	this->q[0][4] = "El proletariado";
	this->q[0][5] = "3";
	this->q[0][6] = "3";


	this->q[1][0] = "El renacimiento supone una epoca de absolutismo y nacionalismos, como el nacimiento de fuertes monarquias europeas centralizadas como:";
	this->q[1][1] = "Grecia";
	this->q[1][2] = "Inglaterra";
	this->q[1][3] = "Yugoslavia";
	this->q[1][4] = "Egipto";
	this->q[1][5] = "2";
	this->q[1][6] = "3";

	this->q[2][0] = "Antes de la consolidacion del estado moderno, Italia estuvo divida en pequeñas ciudades-estado normalmente enfrentadas entre si, como es el caso de:";
	this->q[2][1] = "Florencia-Napoli";
	this->q[2][2] = "Amsterdam-Cracovia";
	this->q[2][3] = "Remis-Colonia";
	this->q[2][4] = "Milan-Lourdes";
	this->q[2][5] = "1";
	this->q[2][6] = "3";

	this->q[3][0] = "La toma de Constantinopla supone un bloqueo comercial entre Europa y Asia (la ruta de la seda) y corrio en lo que hoy es actualmente: ";
	this->q[3][1] = "Eslovaquia";
	this->q[3][2] = "Estambul en Turquia";
	this->q[3][3] = "Mesopotamia";
	this->q[3][4] = "Jerusalen";
	this->q[3][5] = "2";
	this->q[3][6] = "3";


	this->q[4][0] = "Resurge el interes por Grecia y Roma, junto al declive del sistema feudal, el crecimiento del comercio e innovaciones entre las que mencionamos: ";
	this->q[4][1] = "La imprenta y la brujula";
	this->q[4][2] = "La rueda y la escritura";
	this->q[4][3] = "Las maquinas de vapor y la produccion en masa";
	this->q[4][4] = "La polvora y la rueda";
	this->q[4][5] = "1";
	this->q[4][6] = "3";
}

int Question::getHistoria()
{
	default_random_engine motor(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> intRan(0, 4);
	int f = intRan(motor);
	this->temF = f;
	return f;
}

int Question::getResp_Historia()
{
	return stoi(this->q[this->temF][5]) - 1;
}


void Question::Game_Globos()
{
	
	this->g[0][0] = "De las siguientes, una de ellas es la corriente filosófica que en general tiende a negar la"
		            "posibilidad de la metafísica y a sostener que hay conocimiento únicamente de los fenómenos.";
	this->g[0][1] = "Racionalistas";
	this->g[0][2] = "Empiristas";
	this->g[0][3] = "Escolasticos";
	this->g[0][4] = "Escepticos";
	this->g[0][5] = "2";
	
	this->g[1][0] = "Filósofos que postulan las ideas innatas en el sujeto.";
	this->g[1][1] = "Empiristas";
	this->g[1][2] = "Idealistas";
	this->g[1][3] = "Racionalistas";
	this->g[1][4] = "Innatistas";
	this->g[1][5] = "3";
	

	this->g[2][0] = "De los siguientes filosofos seleccione el que no se considera Racionalista:";
	this->g[2][1] = "David Hume";
	this->g[2][2] = "John Locke";
	this->g[2][3] = "Nicolas Malebranch";
	this->g[2][4] = "Francis Bacon";
	this->g[2][5] = "3";


	this->g[6][0] = "Es la doctrina que establece que todos nuestros conocimientos provienen de la razon: ";
	this->g[6][1] = "Empirismo";
	this->g[6][2] = "Criticismo";
	this->g[6][3] = "Racionalismo";
	this->g[6][4] = "Epistemologia";
	this->g[6][5] = "3";

	
}

int Question::getGame_Globos()
{

	default_random_engine motor(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> intRan(0, 3);
	int f = intRan(motor);
	this->temF = f;
	return f;
}

int Question::getResp_Game_Globos()
{
	return stoi(this->q[this->temF][5]) - 1;
}




