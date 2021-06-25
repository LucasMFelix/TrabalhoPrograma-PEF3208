#include <iostream>

#include "Grafo.h"

using namespace std;

void addBarra(Grafo* estrutura) {
	int opcao = -1;
	while (opcao != 0) {
        cout << "Tipos de barra:" << endl
             << "0) Retornar;" << endl
             << "1) Horizontal;" << endl
             << "2) Vertical;" << endl
             << "3) Inclinada (desabilitado);" << endl
             << "Digite o numero da opcao: ";
        cin >> opcao;

        char nome[2];
        float comprimento;
        cout << "Digite o nome da barra (ex.: AB, CD): ";
        cin >> nome;
        cout << "Digite o comprimento da barra em metros (Utilize ponto): ";
        cin >> comprimento;
        estrutura->adicionarVertice(nome[0]);
        estrutura->adicionarVertice(nome[1]);

        switch (opcao) {
            case 0: break;

            case 1: {
                estrutura->adicionarAresta(nome, comprimento, 0);
                break;
            }

            case 2: {
                estrutura->adicionarAresta(nome, comprimento, 90);
                break;
            }

            case 3: {
                //
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
                if (Vertice* v = estrutura->getVertice(nome)) { // Caso haja um vertice com tal nome
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
        }
        break;
    }

    // Mz = 0
    double distX = 0;//braço do torque
    double fy2 = 0; //Segundo Fy
    for (int i = 0; i < estrutura->getNumeroVertices(); i++) {
        v = estrutura->getVertices()[i];
        if (v->getIncognitas()[1] == 1) { // Se tiver incognita em y
            // v sera o referencial do momento
		if (i < estrutura->getNumeroVertices() - 1){//Se todos os vertices não tiverem sido varridos
			for (int j = i + 1; j < estrutura->getNumeroVertices(); j++){//Varrendo os vertices restantes em busca de outro vertice com incognita em y 
				if (v->getIncognitas()[1] == 1){//Caso haja mais uma incognita y
					//Parei aqui para tomar banho
				}
			}
		}
            
        }
    }
    // Fy = 0

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
		     << "5) Diagramas dos esforcos solicitantes" << endl
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
                //
                break;
			}
			case 5: {
                //
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
}

int main() {
	//teste();
	interface();
	return 0;
}
