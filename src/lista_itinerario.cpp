#include "lista_itinerario.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

ListaDuplamenteEncadeada* criaLista()
{
    ListaDuplamenteEncadeada* lista = new ListaDuplamenteEncadeada;
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
    cout << "Parada: " << nome << " adicionada com sucesso!" << endl;
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
    cout << "Parada: " << nome << " adicionada com sucesso!" << endl;
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

    cout << "Parada " << novoNome << " adicionada com sucesso!" << endl;
}

void removerInicio(ListaDuplamenteEncadeada &lista) {
    if (lista.inicio == NULL) {
        cout << "A rota está vazia" << endl;
        return;
    }

    Node* alvo = lista.inicio;
    lista.inicio = lista.inicio->proximo;

    if (lista.inicio != NULL) {
        lista.inicio->anterior = NULL;
    } else {
        lista.fim = NULL;
    }

    delete alvo;
    lista.totalParadas--;
    cout << "Parada removida com sucesso!";
}

void removerFim(ListaDuplamenteEncadeada &lista){
    if (lista.fim == NULL) {
        cout << "A rota está vazia" << endl;
    }

    Node* alvo = lista.fim;
    lista.fim = lista.fim->anterior;

    if (lista.fim != NULL) {
        lista.fim->proximo = NULL;
    } else {
        lista.inicio = NULL;
    }

    delete alvo;
    lista.totalParadas--;
    cout << "Parada removida com sucesso!";
}

void imprimirIda(ListaDuplamenteEncadeada lista) {
    Node* atual = lista.inicio;

    cout << "Rota de Ida: ";
    while (atual != NULL) {
        cout << atual->nomeParada << " -> ";
        atual = atual->proximo;
    }
    cout << "FIM" << endl;
}

void imprimirVolta(ListaDuplamenteEncadeada lista) {
    Node* atual = lista.fim;

    cout << "Rota de Volta: ";
    while (atual != NULL) {
        cout << atual->nomeParada << " -> ";
        atual = atual->anterior;
    }
    cout << "FIM" << endl;
}

void imprimeTotalParadas(ListaDuplamenteEncadeada lista) {
    cout << "Total de paradas: " << lista.totalParadas << endl;
}

void buscarPorNome(ListaDuplamenteEncadeada lista, string nomeBusca) {
    Node* atual = lista.inicio;
    bool encontrou = false;

    while (atual != NULL) {
        if (atual->nomeParada.find(nomeBusca) != string::npos) {
        cout <<"Parada: " << atual->nomeParada << " encontrada."<< endl;
        encontrou = true;
        }
        atual = atual->proximo;
    }
    if(!encontrou) {
            cout << "Parada não encontrada!" << endl;
        }
}


