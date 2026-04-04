#include <cassert>
#include <iostream>
#include "../include/lista_itinerario.h"

using namespace std;

void teste_criaLista(){
    cout << "\nTestando criaLista()..." << endl;
    ListaDuplamenteEncadeada* lista = criaLista();

    assert(lista != NULL);
    assert(lista->totalParadas == 0);
    assert(lista->inicio == NULL);
    assert(lista->fim == NULL);
    delete(lista);

    cout << "\n✓ criaLista() passou em todos os testes" << endl;
}

void teste_insereInicio(){
    cout << "\nTestando insereInicio()..." << endl;
    ListaDuplamenteEncadeada* lista = criaLista();

    insereInicio(*lista, "Ponto Final");

    assert(lista->totalParadas == 1);
    assert(lista->inicio->nomeParada == "Ponto Final");
    assert(lista->fim->nomeParada == "Ponto Final");

    insereInicio(*lista, "Terminal Centro");

    assert(lista->totalParadas == 2);
    assert(lista->inicio->nomeParada == "Terminal Centro");
    assert(lista->inicio->proximo->nomeParada == "Ponto Final");
    assert(lista->fim->anterior->nomeParada == "Terminal Centro");

    cout << "\n✓ insereInicio() passou em todos os teste" << endl;
}

void teste_insereFim(){
    cout << "\nTestando insereFim()..." << endl;
    ListaDuplamenteEncadeada* lista = criaLista();

    insereFim(*lista, "Terminal Centro");

    assert(lista->totalParadas == 1);
    assert(lista->inicio->nomeParada == "Terminal Centro");
    assert(lista->fim->nomeParada == "Terminal Centro");

    insereFim(*lista, "Ponto Final");

    assert(lista->totalParadas == 2);
    assert(lista->fim->nomeParada == "Ponto Final");
    assert(lista->inicio->proximo->nomeParada == "Ponto Final");
    assert(lista->fim->anterior->nomeParada == "Terminal Centro");

    cout << "\n✓ insereFim() passou em todos os teste" << endl;
}

void teste_inserePorNome(){
    cout << "\nTestando inserePorNome()..." << endl;
    ListaDuplamenteEncadeada *lista = criaLista();

    insereInicio(*lista, "Terminal Centro");
    insereFim(*lista, "Ponto Final");
    inserePorNome(*lista, "Terminal Centro", "Univali");

    assert(lista->totalParadas == 3);
    assert(lista->inicio->proximo->nomeParada == "Univali");
    assert(lista->inicio->proximo->anterior->nomeParada == "Terminal Centro");
    assert(lista->fim->anterior->nomeParada == "Univali");
    assert(lista->fim->anterior->proximo->nomeParada == "Ponto Final");

    cout << "\n✓ inserePorNome() passou em todos os teste" << endl;
}

void teste_removeInicio(){
    cout << "\nTestando removeInicio()..." << endl;
    ListaDuplamenteEncadeada* lista = criaLista();

    insereInicio(*lista, "Terminal Centro");
    insereFim(*lista, "Ponto Final");

    removerInicio(*lista);

    assert(lista->totalParadas == 1);
    assert(lista->inicio->nomeParada == "Ponto Final");
    assert(lista->fim->nomeParada == "Ponto Final");
    assert(lista->fim->proximo == NULL);
    assert(lista->inicio->anterior == NULL);
    
    cout << "\n✓ removeInicio() passou em todos os teste" << endl;
}

void teste_removeFim(){
    cout << "\nTestando removeFim()..." << endl;
    ListaDuplamenteEncadeada* lista = criaLista();

    insereInicio(*lista, "Terminal Centro");
    insereFim(*lista, "Ponto Final");

    removerFim(*lista);

    assert(lista->totalParadas == 1);
    assert(lista->inicio->nomeParada == "Terminal Centro");
    assert(lista->fim->nomeParada == "Terminal Centro");
    assert(lista->fim->proximo == NULL);
    assert(lista->inicio->anterior == NULL);
    
    cout << "\n✓ removeFim() passou em todos os teste" << endl;
}

void teste_buscaPorNome(){
    cout << "\nTestando buscaPorNome()..." << endl;
    ListaDuplamenteEncadeada *lista = criaLista();

    insereInicio(*lista, "Terminal Centro");
    insereFim(*lista, "Ponto Final");

    cout << "\nBuscando por 'Cent' (Esperado: Terminal Centro):" << endl;
    buscarPorNome(*lista, "Cent");

    cout << "\nBuscando por 'Univali' (Esperado: Parada não encontrada!)" << endl;
    buscarPorNome(*lista, "Univali");

    cout << "\n✓ buscarPorNome() visualmente testado" << endl;
}

void teste_imprimir(){
    cout << "\nTestando imprimirIda() e imprimirVolta()..." << endl;
    ListaDuplamenteEncadeada *lista = criaLista();

    insereInicio(*lista, "Terminal Centro");
    insereFim(*lista, "Ponto Final");
    inserePorNome(*lista, "Terminal Centro", "Univali");

    cout << "\nImprimindo trajeto de ida (Esperado: Terminal Centro -> Univali -> Ponto Final)" << endl;
    imprimirIda(*lista);

    cout << "\nImprimindo trajeto de volta (Esperado: Ponto Final -> Univali -> Terminal Centro)" << endl;
    imprimirVolta(*lista);

    cout << "\n✓ imprimirIda() e imprimirVolta() visualmente testados" << endl;
}

int main () {

    cout << "\n=======================================" << endl;
    cout << " INICIANDO TESTES DE LISTA ITINERARIO! " << endl;
    cout << "=======================================" << endl << endl;

    teste_criaLista();
    teste_insereInicio();
    teste_insereFim();
    teste_inserePorNome();
    teste_removeInicio();
    teste_removeFim();
    teste_buscaPorNome();
    teste_imprimir();

    cout << "\n========================================" << endl;
    cout << " ✓ TODOS OS TESTES PASSARAM COM SUCESSO!" << endl;
    cout << "========================================" << endl << endl;

    return 0;
}