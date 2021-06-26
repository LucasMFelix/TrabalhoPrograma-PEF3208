#include "Grafo.h"
#include <iostream>

Grafo::Grafo()
{
    //ctor
}

Grafo::~Grafo()
{
    for (int i = 0; i < numeroVertices; i++) {
        delete vertices[i];
    }
    for (int i = 0; i < numeroArestas; i++) {
        delete arestas[i];
    }
}

bool Grafo::adicionarVertice(char nome) {
    if (numeroVertices == MAXIMO_VERTICES) return false;
    for (int i = 0; i < numeroVertices; i++) {
        if (vertices[i]->getNome() == nome) return false;
    }
    vertices[numeroVertices++] = new Vertice(nome);
    return true;
}

bool Grafo::adicionarAresta(char* nome, float comprimento, float inclinacao) {
    if(numeroArestas == MAXIMO_ARESTAS) return false;
    for (int i = 0; i < numeroVertices; i++){
        if(nome[0] == this->getVertices()[i]->getNome()){
            this->getVertices()[i]->adicionarAresta(nome);
        }
    }

    for (int i = 0; i < numeroVertices; i++){
        if(nome[1] == this->getVertices()[i]->getNome()){
            this->getVertices()[i]->adicionarAresta(nome);
        }
    }

    arestas[numeroArestas++] = new Aresta(nome, comprimento, inclinacao);
    return true;
}

Vertice* Grafo::get(char nome) {
    for (int i = 0; i < numeroVertices; i++) {
        if (vertices[i]->getNome() == nome) {
            return vertices[i];
        }
    }
    return NULL;
}

int Grafo::getNumeroVertices()
{
    return numeroVertices;
}

Vertice** Grafo::getVertices()
{
    return vertices;
}

int Grafo::getNumeroArestas()
{
    return numeroArestas;
}

Aresta** Grafo::getArestas()
{
    return arestas;
}

Vertice* Grafo::getVertice(char nome)
{
    for (int i = 0; i < numeroVertices; i++) {
        if (vertices[i]->getNome() == nome) return vertices[i];
    }
    return NULL;
}

Aresta* Grafo::getAresta(char* nome)
{
    for (int i = 0; i < numeroArestas; i++) {
        if (arestas[i]->getNome() == nome) return arestas[i];
    }
    return NULL;
}
