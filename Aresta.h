#ifndef ARESTA_H
#define ARESTA_H

#include "Vertice.h"

class Aresta {
public:
    Aresta(char nome1, char nome2, double comprimento, int inclinacao);
    virtual ~Aresta();
    char getNome1();
    char getNome2();
    void addDistribuicao(double intensidade, int forma); // adiciona uma carga de forca distribuida
                                                         // forma 1 para retangulo e 2 para triangulo

protected:
    char nome1; // Nome vertice 1
    char nome2; // Nome vertice 2
    double comprimento;
    int inclinacao; // habilitado somente para 0 ou 90 graus
    double intensidade; // intensidade da forca distribuida
    int forma; // forma geometrica da forca distribuida
};

#endif // ARESTA_H
