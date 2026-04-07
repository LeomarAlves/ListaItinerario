#include <iostream>
#include "lista_itinerario.h"
#include <string>

using namespace std;

int main () {

    ListaDuplamenteEncadeada* minhaRota = criaLista();

    int opcao;
    string nomeBusca, novoNome;

    do
    {
        cout << "\n-----   MENU DO ONIBUS   -----" << endl;
        cout << "1. Inserir parada no início" << endl;
        cout << "2. Inserir parada no fim" << endl;
        cout << "3. Inserir parada por posição" << endl;
        cout << "4. Remover primeira parada" << endl;
        cout << "5. Remover última parada" << endl;
        cout << "6. Buscar parada por nome" << endl;
        cout << "7. Listar rota completa (trajeto de ida)" << endl;
        cout << "8. Listar rota inversa (trajeto de volta)" << endl;
        cout << "9. Contar paradas" << endl;
        cout << "0. Sair" << endl;
        cout << "\nEscolha uma opcao: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 1:
            cout << "Informe o nome da nova parada: ";
            getline(cin, novoNome);
            insereInicio(*minhaRota, novoNome);
            break;
        case 2:
            cout << "Informe o nome da nova parada: ";
            getline(cin, novoNome);
            insereFim(*minhaRota, novoNome);
            break;
        case 3:
            cout << "Informe o nome da parada imediatamente anterior a nova parada: ";
            getline(cin, nomeBusca);
            cout << "Informe o nome da nova parada: ";
            getline(cin, novoNome);
            inserePorNome(*minhaRota, nomeBusca, novoNome);
            break;
        case 4:
            removerInicio(*minhaRota);
            break;
        case 5:
            removerFim(*minhaRota);
            break;
        case 6:
            cout << "Informe o nome da parada: ";
            getline(cin, nomeBusca);
            buscarPorNome(*minhaRota, nomeBusca);
            break;
        case 7:
            imprimirIda(*minhaRota);
            break;
        case 8:
            imprimirVolta(*minhaRota);
            break;
        case 9:
            imprimeTotalParadas(*minhaRota);
            break;
        case 0:
            cout << "Encerrando o sistema..." << endl;
            break;
        default:
            cout << "Digite uma opção válida!" << endl;
            break;
        }

        if (opcao != 0) {
            cout << "\nPressione Enter para retornar ao Menu..." ;
            cin.get();
        }

    } while (opcao != 0);
    
    destroiLista(minhaRota);

    return 0;
}

