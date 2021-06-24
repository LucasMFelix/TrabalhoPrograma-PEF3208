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

double* Vertice::getForcas() {
    return this->forcas;
}

bool Vertice::addIncognita(char direcao)
{
    if (direcao == 'i') {this->incognitas[0] = 1; return true;}
    else if (direcao == 'j') {this->incognitas[1] = 1; return true;}
    else if (direcao == 'k') {this->incognitas[2] = 1; return true;}
    return false;
}

int* Vertice::getIncognitas() {
    return this->incognitas;
}

