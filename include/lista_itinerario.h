#ifndef LISTA_ITINERARIO_H
#define LISTA_ITINERARIO_H
#include <string>

using namespace std;

struct Node {
    string nomeParada;
    Node* proximo;
    Node* anterior;
};

struct ListaDuplamenteEncadeada {
    Node* inicio;
    Node* fim;
    int totalParadas;
};

ListaDuplamenteEncadeada* criaLista();
void insereInicio(ListaDuplamenteEncadeada &lista, string nome);
void insereFim(ListaDuplamenteEncadeada &lista, string nome);
void inserePorNome(ListaDuplamenteEncadeada &lista, string nomeBusca, string novoNome);
void removerInicio(ListaDuplamenteEncadeada &lista);
void removerFim(ListaDuplamenteEncadeada &lista);
void imprimirIda(ListaDuplamenteEncadeada lista);
void imprimirVolta(ListaDuplamenteEncadeada lista);
void imprimeTotalParadas(ListaDuplamenteEncadeada lista);
void buscarPorNome(ListaDuplamenteEncadeada lista, string nomeBusca);

#endif