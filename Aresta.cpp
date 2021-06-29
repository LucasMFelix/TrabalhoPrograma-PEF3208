#include "Aresta.h"

Aresta::Aresta(char nome1, char nome2, double comprimento, int inclinacao)
{
    this->nome1 = nome1;
    this->nome2 = nome2;
    this->comprimento = comprimento;
    this->inclinacao = inclinacao;
}

Aresta::~Aresta()
{
    //dtor
}

char Aresta::getNome1() {
    return nome1;
}

char Aresta::getNome2() {
    return nome2;
}

void Aresta::addDistribuicao(double intensidade, int forma)
{
    this->intensidade = intensidade;
    this->forma = forma;
}
