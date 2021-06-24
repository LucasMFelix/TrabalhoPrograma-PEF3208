#include "Vertice.h"

Vertice::Vertice(char nome) {
	this->nome = nome;
}

Vertice::~Vertice() {
	//dtor
}

char Vertice::getNome() {
    return this->nome;
}

int Vertice::getNumeroDeArestrasDeSaida() {
    return quantidade;
}

bool Vertice::addForca(double intensidade, char direcao)
{
    if (direcao == 'i') {
        forcas[0] += intensidade; // forcas na direcao i
        return true;
    }
    else if (direcao == 'j') {
        forcas[1] += intensidade; // forcas na direcao j
        return true;
    }
    return false;
}

void Vertice::getForcas() {
    return this->forcas;
}

bool Vertice::addIncognita(double intensidade, char direcao)
{
    if (direcao == 'i') {this->incognitas[0] = intensidade; return true;}
    else if (direcao == 'j') {this->incognitas[1] = intensidade; return true;}
    else if (direcao == 'k') {this->incognitas[2] = intensidade; return true;}
    return false;
}

void Vertice::getIncognitas() {
    return this->incognitas;
}
