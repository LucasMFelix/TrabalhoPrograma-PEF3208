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

bool Vertice::setIncognita(int booleana, char direcao)
{
    if (direcao == 'i') {this->incognitas[0] = booleana; return true;}
    else if (direcao == 'j') {this->incognitas[1] = booleana; return true;}
    else if (direcao == 'k') {this->incognitas[2] = booleana; return true;}
    return false;
}

int* Vertice::getIncognitas() {
    return this->incognitas;
}

void Vertice::setCoordenadas(double x0, double y0)
{
    this->coordenadas[0] = x0;
    this->coordenadas[1] = y0;
}

double* Vertice::getCoordenadas()
{
    return this->coordenadas;
}
