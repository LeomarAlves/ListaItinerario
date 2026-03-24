#ifndef LISTA_ITINERARIO_H
#define LISTA_ITINERARIO_H

struct Node {
    int conteudo;
    Node* proximo;
    Node* anterior;
};

struct ListaDuplamenteEncadeada {
    int cardinalidade;
    Node* inicio;
    Node* fim;    
};

#endif