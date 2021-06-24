#ifndef VERTICE_H
#define VERTICE_H

using namespace std;

#define MAXIMO_ARESTAS 4 // maximo de arestas por vertice
#define MAXIMO_FORCAS 2 // maximo de forcas por vertice

class Vertice {
public:
	Vertice(char nome);
	virtual ~Vertice();
	char getNome();
	int getNumeroDeArestrasDeSaida();
	bool addForca(double intensidade, char direcao); // direcao pode ser 'i' ou 'j'
	void getForcas();
	bool addIncognita(double intensidade, char direcao); // direcao pode ser 'i', 'j' ou 'k'
	void getIncognitas();
protected:
	char nome;
	Vertice* adjacentes[MAXIMO_ARESTAS];
	int quantidade = 0;
	double forcas[MAXIMO_FORCAS];
	double incognitas[3] = {0, 0, 0}; // {Fx, Fy, Mz}
};

#endif // VERTICE_H
