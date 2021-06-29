#include "Aresta.h"

Aresta::Aresta(char* nome, double comprimento, int inclinacao)
{
    this->nome = nome;
    this->comprimento = comprimento;
    this->inclinacao = inclinacao;
}

Aresta::~Aresta()
{
    //dtor
}

char* Aresta::getNome() {
    return this->nome;
}

void Aresta::addDistribuicao(double intensidade, int forma)
{
    this->intensidade = intensidade;
    this->forma = forma;
}
