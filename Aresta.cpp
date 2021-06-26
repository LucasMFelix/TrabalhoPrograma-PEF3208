#include "Aresta.h"

Aresta::Aresta(char* nome, float comprimento, float inclinacao, Vertice* primeiroVertice, Vertice* segundoVertice)
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
