#ifndef LISTA_ITINERARIO_H
#define LISTA_ITINERARIO_H

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



#endif