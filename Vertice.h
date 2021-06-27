#ifndef VERTICE_H
#define VERTICE_H
#include "Aresta.h"
#include <iostream>
#include <string>
using namespace std;
class Aresta;

#define MAXIMO_ARESTAS 4 // maximo de arestas por vertice

class Vertice {
public:
	Vertice(char nome);
	virtual ~Vertice();
	char getNome();
	int getNumeroDeArestras();
	bool addForca(double intensidade, char direcao); // direcao pode ser 'i' ou 'j'
	double* getForcas();
	bool setIncognita(int booleana, char direcao); // direcao pode ser 'i', 'j'
	int* getIncognitas();
	Aresta** getArestas();
	bool adicionarAresta(Aresta* aresta);
	bool setCor(string novaCor);
	string getCor();
protected:
    string cor = "BRANCO"; // Pode ser branco, preto ou cinza
	char nome;
	Aresta* arestasPertencentes[MAXIMO_ARESTAS]; // Guarda as arestas que o vertice pertence
	int quantidadeDeArestas = 0;
	double forcas[2] = {0, 0}; // {Fx, Fy}
	int incognitas[3] = {0, 0, 0}; // {Fx, Fy, Mz} // 1 se tiver incognita, 0 caso contrario
};

#endif // VERTICE_H
