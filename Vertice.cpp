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

char** Vertice::getArestas()
{
    return arestasPertencentes;
}

bool Vertice::adicionarAresta(char* nomeAresta)
{
    bool retorno = false;
    if (quantidadeDeArestas < MAXIMO_ARESTAS){
        arestasPertencentes[quantidadeDeArestas] = nomeAresta;
        quantidadeDeArestas++;
        retorno = true;
    }
    return retorno;
}

bool Vertice::setCor(string novaCor)
{
    bool retorno = false;
    if ((novaCor == "BRANCO" || novaCor == "CINZA" || novaCor == "PRETO") && novaCor != cor){
        cor = novaCor;
        retorno = true;
    }
    return retorno;
}

string Vertice::getCor()
{
    return cor;
}
