 #include "Grafo.h"
#include <iostream>

Grafo::Grafo()
{
    //ctor
}

Grafo::~Grafo()
{
    for (int i = 0; i < numeroArestas; i++) {
        delete arestas[i];
    }
    for (int i = 0; i < numeroVertices; i++) {
        delete vertices[i];
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

bool Grafo::existeVertice(char nome) {
    for (int i = 0; i < numeroVertices; i++) {
        if (vertices[i]->getNome() == nome) return true;
    }
    return false;
}

bool Grafo::adicionarAresta(char* nome, double comprimento, int inclinacao) {
    if (numeroArestas == MAXIMO_ARESTAS) return false;
    arestas[numeroArestas++] = new Aresta(nome, comprimento, inclinacao);
    return true;
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

double Grafo::distanciaHorizontal(Vertice* v1, Vertice* v2)
{
    double x1 = v1->getCoordenadas()[0];
    double x2 = v2->getCoordenadas()[0];
    return (x2 - x1);
}

double Grafo::distanciaVertical(Vertice* v1, Vertice* v2)
{
    double y1 = v1->getCoordenadas()[1];
    double y2 = v2->getCoordenadas()[1];
    return (y2 - y1);
}

bool Grafo::adicionarBarra(char* nome, double comprimento, int inclinacao) {
    double x0, y0;

    if (inclinacao == 0) {
        if (existeVertice(nome[0]) && !existeVertice(nome[1])) { // Barra para a direita
            adicionarVertice(nome[1]);
            x0 = getVertice(nome[0])->getCoordenadas()[0];
            y0 = getVertice(nome[0])->getCoordenadas()[1];
            getVertice(nome[1])->setCoordenadas(x0+comprimento, y0);
            adicionarAresta(nome, comprimento, 0);
            return true;
        }
        else if (!existeVertice(nome[0]) && existeVertice(nome[1])) { // Barra para a esquerda
            adicionarVertice(nome[0]);
            x0 = getVertice(nome[1])->getCoordenadas()[0];
            y0 = getVertice(nome[1])->getCoordenadas()[1];
            getVertice(nome[0])->setCoordenadas(x0-comprimento, y0);
            adicionarAresta(nome, comprimento, 0);
            return true;
        }
        else {
            // Barra isolada
            return false;
        }
    }
    else if (inclinacao == 90) {
        if (existeVertice(nome[0]) && !existeVertice(nome[1])) { // Barra esta para cima
            x0 = getVertice(nome[0])->getCoordenadas()[0];
            y0 = getVertice(nome[0])->getCoordenadas()[1];
            getVertice(nome[1])->setCoordenadas(x0, y0+comprimento);
            adicionarAresta(nome, comprimento, 90);
            return true;
        }
        else if (!existeVertice(nome[0]) && existeVertice(nome[1])) { // Barra esta para baixo
            x0 = getVertice(nome[1])->getCoordenadas()[0];
            y0 = getVertice(nome[1])->getCoordenadas()[1];
            getVertice(nome[0])->setCoordenadas(x0, y0-comprimento);
            adicionarAresta(nome, comprimento, 90);
            return true;
        }
        else {
            // Barra isolada
            return false;
        }
    }
    else {
        // Inclinacao errada
        return false;
    }
}
