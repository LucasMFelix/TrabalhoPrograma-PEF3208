#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
using namespace std;

#define MAXIMO_ARESTAS 4 // maximo de arestas por vertice

class Vertice {
public:
	Vertice(char nome);
	virtual ~Vertice();
	char getNome();
	int getNumeroDeArestrasDeSaida();
	bool addForca(double intensidade, char direcao); // direcao pode ser 'i' ou 'j'
	double* getForcas();
	bool setIncognita(int booleana, char direcao); // direcao pode ser 'i', 'j'
	int* getIncognitas();
protected:
	char nome;
	Vertice* adjacentes[MAXIMO_ARESTAS];
	int quantidade = 0;
	double forcas[2] = {0, 0}; // {Fx, Fy}
	int incognitas[3] = {0, 0, 0}; // {Fx, Fy, Mz} // 1 se tiver incognita, 0 caso contrario
};

#endif // VERTICE_H
