#include "lista_itinerario.h"
#include <iostream>
#include <cstdlib>

using namespace std;

ListaDuplamenteEncadeada* criaLista()
{
    ListaDuplamenteEncadeada* lista = (ListaDuplamenteEncadeada*) malloc(sizeof(ListaDuplamenteEncadeada));
    lista->totalParadas = 0;
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

void insereInicio(ListaDuplamenteEncadeada &lista, string nome) {
    Node* novoNode = new Node;
    novoNode->nomeParada = nome;

    novoNode->proximo = lista.inicio;
    novoNode->anterior = NULL;

    if (lista.inicio == NULL) {
        lista.fim = novoNode;
    } else {
        lista.inicio->anterior = novoNode;
    }

    lista.inicio = novoNode;
    lista.totalParadas++;
}

void insereFim(ListaDuplamenteEncadeada &lista, string nome) {
    Node* novoNode = new Node;
    novoNode->nomeParada = nome;
    novoNode->proximo = NULL;

    if (lista.inicio == NULL) {
        novoNode->anterior = NULL;
        lista.inicio = novoNode;
    } else {
        novoNode->anterior = lista.fim;
        lista.fim->proximo = novoNode;
    }

    lista.fim = novoNode;
    lista.totalParadas++;
}

void inserePorNome(ListaDuplamenteEncadeada &lista, string nomeBusca, string novoNome) {
    Node* atual = lista.inicio;

    while (atual != NULL && atual->nomeParada != nomeBusca) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        cout <<"Erro: Parada não encontrada." << endl;
        return;
    }

    Node* novoNode = new Node;
    novoNode->nomeParada = novoNome;
    novoNode->proximo = atual->proximo;
    novoNode->anterior = atual;

    if (atual->proximo != NULL){
        atual->proximo->anterior = novoNode;
    } else {
        lista.fim = novoNode;
    }

    atual->proximo = novoNode;
    lista.totalParadas++;
}