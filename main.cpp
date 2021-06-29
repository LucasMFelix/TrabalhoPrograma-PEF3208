#include <iostream>

#include "Grafo.h"

using namespace std;

void addBarra(Grafo* estrutura) {

	int opcao = -1;
	char nome[2];
    double comprimento = 0;

	while (opcao != 0) {
        cout << "Tipos de barra:" << endl
             << "0) Retornar;" << endl
             << "1) Horizontal;" << endl
             << "2) Vertical;" << endl
             << "3) Inclinada (desabilitado);" << endl
             << "Digite o numero da opcao: ";
        cin >> opcao;
        cout << "Digite o nome da barra (ex.: AB, CD): ";
        cin >> nome;
        cout << "Digite o comprimento da barra em metros (utilize ponto): ";
        cin >> comprimento;

        if (estrutura->getNumeroVertices() == 0) { // Caso seja a primeira barra
            estrutura->adicionarVertice(nome[0]);
            estrutura->getVertice(nome[0])->setCoordenadas(0, 0); // Vertice de origem
        }

        switch (opcao) {
            case 0: break;

            case 1: { // Barra horizontal
                if (estrutura->adicionarBarra(nome, comprimento, 0) ) {
                    cout << "Barra adicionada" << endl;
                }
                else cout << "Erro ao adicionar barra" << endl;
                break;
            }

            case 2: { // Barra vertical
                if (estrutura->adicionarBarra(nome, comprimento, 90)) {
                    cout << "Barra adicionada" << endl;
                }
                else cout << "Erro ao adicionar barra" << endl;
                break;
            }

            case 3: {
                cout << "Recurso desabilitado. Tente novamente." << endl;
                break;
            }

            default: {cout << "Numero invalido. Tente novamente." << endl; break;}
        }
	}
}

void addApoio(Grafo* estrutura) {
	int opcao = -1;
	while (opcao != 0) {
        cout << "Tipos de apoio:" << endl
             << "0) Retornar;" << endl
             << "1) Articulacao Movel;" << endl
             << "2) Articulacao Fixa;" << endl
             << "3) Engastamento;" << endl
             << "Digite o numero da opcao: ";
        cin >> opcao;

        char nome;
        cout << "Digite o nome do vertice: (ex.: A, E): ";
        cin >> nome;

        switch (opcao) {
            case 0: break;

            case 1: {
                if (Vertice* v = estrutura->getVertice(nome)) { // Se o vertice existir
                    v->setIncognita(1, 'j');
                }
                break;
            }

            case 2: {
                if (Vertice* v = estrutura->getVertice(nome)) { // Se o vertice existir
                    v->setIncognita(1, 'i');
                    v->setIncognita(1, 'j');
                }
                break;
            }

            case 3: {
                if (Vertice* v = estrutura->getVertice(nome)) { // Se o vertice existir
                    v->setIncognita(1, 'i');
                    v->setIncognita(1, 'j');
                    v->setIncognita(1, 'k');
                }
                break;
            }

            default: {cout << "Numero invalido. Tente novamente." << endl; break;}
        }
	}
}

void addCarga(Grafo* estrutura) {
	int opcao = -1;
	while (opcao != 0) {
        cout << "Tipos de carga:" << endl
             << "0) Retornar;" << endl
             << "1) Forca concentrada;" << endl
             << "2) Forca distribuida;" << endl
             << "Digite o numero da opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 0: break;

            case 1: {
                char nome;
                double intensidade;
                char direcao;
                cout << "Vertice (ponto) de acao da forca: ";
                cin >> nome;

                if (Vertice* v = estrutura->getVertice(nome)) { // Caso o vertice exista
                    cout << "Direcao (i ou j): ";
                    cin >> direcao;
                    cout << "Intensidade (em kN): ";
                    cin >> intensidade;
                    v->addForca(intensidade, direcao);
                }
                else cout << "Vertice inexistente. Tente novamente." << endl;

                break;
            }

            case 2: {
                char nome[2];
                double intensidade;
                cout << "Barra de acao da forca (ex.: AB, CD): ";
                cin >> nome;
                int forma;
                cout << "Forma geometrica da distribuicao:" << endl
                     << "1) Retangular;" << endl
                     << "2) Triangular;" << endl
                     << "Digite o numero da opcao: ";
                cin >> forma;
                switch (forma) {
                case 1:
                    cout << "Intensidade de distribuicao (em kN/m): ";
                    cin >> intensidade;
                    if (Aresta* a = estrutura->getAresta(nome)) { // Caso haja aresta com tal nome
                        a->addDistribuicao(intensidade, forma);
                    }
                    break;

                case 2:
                    cout << "Intensidade maxima da distribuicao (em kN/m): ";
                    cin >> intensidade;
                    if (Aresta* a = estrutura->getAresta(nome)) {
                        a->addDistribuicao(intensidade, forma);
                    }
                    break;

                default:
                    cout << "Numero invalido. Tente novamente." << endl;
                }

                break;
            }

            default: {cout << "Numero invalido. Tente novamente." << endl; break;}
        }
	}
}

void equilibrio (Grafo* estrutura, double &a, char &a_nome, char &a_direcao,
                                   double &b, char &b_nome, char &b_direcao,
                                   double &c, char &c_nome, char &c_direcao) {
    Vertice* v;
    // Fx = 0
    double sumFx = 0;
    for (int i = 0; i < estrutura->getNumeroVertices(); i++) {
        sumFx += estrutura->getVertices()[i]->getForcas()[0];
    }
    for (int i = 0; i < estrutura->getNumeroVertices(); i++) {
        v = estrutura->getVertices()[i];
        if (v->getIncognitas()[0] == 1) { // Se tiver incognita em x
            a = -sumFx; // a + sumFx = 0
            a_nome = v->getNome();
            a_direcao = 'i';
            v->addForca(a, 'i'); // Adicionando o valor da incognita como forca
            v->setIncognita(0, 'i'); // Tirando a incognita
            break;
        }
    }

    // Mz = 0
    Vertice* u;
    double sumMz = 0;
    for (int i = 0; i < estrutura->getNumeroVertices(); i++) {
        v = estrutura->getVertices()[i];
        if (v->getIncognitas()[1] == 1) { // Se tiver incognita em y
            break; // v sera o referencial do momento
        }
    }

    for (int i = 0; i < estrutura->getNumeroVertices(); i++) {
        u = estrutura->getVertices()[i];
        if (u->getForcas()[0] != 0) { // Se tiver forca em x
            sumMz +=  - estrutura->distanciaVertical(v, u) * u->getForcas()[0]; // Convencao de Grinter
        }
        if (u->getForcas()[1] != 0) { // Se tiver forca em y
            sumMz += estrutura->distanciaHorizontal(v, u) * u->getForcas()[1]; // Convencao de Grinter
        }
    }

    double braco;
    for (int i = 0; i < estrutura->getNumeroVertices(); i++) {
        u = estrutura->getVertices()[i];
        if (u->getIncognitas()[1] == 1) { // Se tiver incognita em y
            // u sera o vertice no qual descobriremos a incognita
            braco = estrutura->distanciaHorizontal(v, u);
            b = -sumMz/braco;
            b_nome = u->getNome();
            b_direcao = 'j';
            u->addForca(b, 'j'); // Adicionando o valor da incognita como forca
            u->setIncognita(0, 'j'); // Tirando a incognita
            break;
        }
    }

    // Fy = 0
    double sumFy = 0;
    // Descobriremos a incognita em y de v, nosso referencial do momento
    for (int i = 0; i < estrutura->getNumeroVertices(); i++) {
        sumFy += estrutura->getVertices()[i]->getForcas()[1];
    }
    c = -sumFy; // c + sumFy = 0
    c_nome = v->getNome();
    c_direcao = 'j';

}

void interface() {
	cout << "PROGRAMA SOLUCIONADOR DE PROBLEMAS SIMPLES DE MECANICA DAS ESTRUTURAS" << endl << endl;
	cout << "Software desenvolvido por Lucas Marques e Reinaldo Avelino durante a disciplina PEF3208." << endl;
	cout << "========================================================================================" << endl;

	Grafo* estrutura = new Grafo();
	int opcao = -1;

	// Incognitas do sistema 3x3
	double a = 0; char a_nome = 'o'; char a_direcao = 'o';
	double b = 0; char b_nome = 'o'; char b_direcao = 'o';
	double c = 0; char c_nome = 'o'; char c_direcao = 'o';

	while (opcao != 0) {
        cout << endl;
		cout << "Menu de opcoes:" << endl
		     << "0) Encerrar programa;" << endl
		     << "1) Adicionar barra;" << endl
		     << "2) Adicionar apoio;" << endl
		     << "3) Adicionar carga;" << endl
		     << "4) Obter reacoes de apoio" << endl
		     << "5) Diagramas dos esforcos solicitantes (desabilitado)" << endl
		     << "Digite o numero da opcao: ";
		cin >> opcao;

		switch (opcao) {
			case 0: {delete estrutura; break;}
			case 1: {addBarra(estrutura); break;}
			case 2: {addApoio(estrutura); break;}
			case 3: {addCarga(estrutura); break;}
			case 4: {
                equilibrio(estrutura, a, a_nome, a_direcao,
                                      b, b_nome, b_direcao,
                                      c, c_nome, c_direcao);
                cout << "Reacoes de apoio: " << endl;
                if (a_direcao == 'i') {
                    cout << "Horizontal em " << a_nome << " : " << a << " i kN" << endl;
                }
                else if (a_direcao == 'j') {
                    cout << "Vertical em " << a_nome << " : " << a << " j kN" << endl;
                }
                if (b_direcao == 'i') {
                    cout << "Horizontal em " << b_nome << " : " << b << " i kN" << endl;
                }
                else if (b_direcao == 'j') {
                    cout << "Vertical em " << b_nome << " : " << b << " j kN" << endl;
                }
                if (c_direcao == 'i') {
                    cout << "Horizontal em " << c_nome << " : " << c << " i kN" << endl;
                }
                else if (c_direcao == 'j') {
                    cout << "Vertical em " << c_nome << " : " << c << " j kN" << endl;
                }
                break;
			}
			case 5: {
                cout << "Recurso desabilitado. Aguarde a proxima versao do software." << endl;
                break;
			}
			default: cout << "Numero invalido. Tente novamente." << endl;
		}
	}
	cout << endl;
	cout << "Programa encerrado. Agradecemos pelo uso." << endl;
	cout << "============================================" << endl;
}

void teste() {
    //

    Grafo* estrutura = new Grafo();
    char nome[2];
    cout << "Nome da barra: ";
    cin >> nome;

    estrutura->adicionarVertice(nome[0]);

    estrutura->adicionarBarra(nome, 2, 0);

    for (int i = 0; i < estrutura->getNumeroVertices(); i++) {
        cout << estrutura->getVertices()[i]->getNome() << endl;
    }

    delete estrutura;
}

int main() {
	teste();
	//interface();
	return 0;
}
