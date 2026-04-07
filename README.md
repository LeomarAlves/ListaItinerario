# 🚌 Sistema de Itinerário de Ônibus

Este projeto implementa um sistema de gerenciamento de paradas de ônibus utilizando uma **Lista Duplamente Encadeada** em C++. O sistema permite adicionar, remover, buscar e visualizar paradas ao longo de uma rota, garantindo o trajeto correto de ida e volta através da manipulação de ponteiros duplos.

## ✨ Funcionalidades

O sistema do ônibus é capaz de:
* **Inserir Paradas:** No início da rota, no final da rota ou após uma parada específica já existente.
* **Remover Paradas:** Retirar a primeira ou a última parada do trajeto.
* **Buscar Paradas:** Procurar por uma parada específica pelo nome.
* **Visualizar Trajeto:** Imprimir a rota completa no sentido de ida (início ao fim) e no sentido de volta (fim ao início).
* **Contagem:** Manter um registro atualizado do total de paradas na rota.
* **Liberação de Memória:** Função para percorrer a lista e desalocar todos os nós, evitando memory leaks.

## 📂 Estrutura do Projeto

O código foi construído seguindo boas práticas de modularização em C++:

* `include/`
  * `lista_itinerario.h`: Arquivo de cabeçalho com as estruturas (`Node`, `ListaDuplamenteEncadeada`) e assinaturas das funções.
* `src/`
  * `lista_itinerario.cpp`: Implementação detalhada da lógica de ponteiros e regras do ônibus.
* `testes/`
  * `testes.cpp`: Suíte de testes automatizados com validação via `assert()` para garantir a integridade da memória e das conexões.
* `Raiz do Projeto`
  * `main.cpp`: Ponto de entrada do programa e menu interativo.
  * `Makefile`: Script de automação para compilar e executar o projeto facilmente em Linux ou Windows.

## ⚙️ Pré-requisitos

Para compilar e executar este projeto, você precisará ter instalado em sua máquina:
* Um compilador C++ (como o `g++` no Linux ou `MinGW` no Windows).
* A ferramenta `make`.

## 🚀 Como Compilar e Executar

Este projeto utiliza um `Makefile` multiplataforma para facilitar a compilação. Abra o terminal na pasta principal do projeto e utilize os comandos abaixo:

### 1. Programa Principal (Modo Interativo)
Para compilar o código fonte e iniciar o menu interativo do sistema:
```
make run
```
### 2. Suíte de Testes (Validação)
Para rodar os testes automatizados e verificar se a lógica interna (ponteiros e conexões) está funcionando:
```
make run_testes
```
### 3. Limpeza
Para remover os arquivos e manter a pasta limpa:
```
make clean
```

## 🐛 Depuração (Debugging)
### Via VSCode (Interface Gráfica)
**O projeto está configurado com os arquivos .vscode/tasks.json e .vscode/launch.json.**

1. Abra a pasta do projeto no VSCode.

2. Coloque breakpoints clicando na margem esquerda do código (ex: na função insereInicio).

3. Pressione F5 ou acesse a aba Run and Debug e clique em "(gdb) Iniciar Ônibus".

4. O VSCode utilizará o Makefile para compilar o projeto com símbolos de debug (-g) automaticamente.

### Via CLI (Terminal com GDB)
1. Compilar com símbolos de debug:

    ```
    make clean
    make build
    ```

2. Iniciar o GDB:

    ```
    gdb ./onibus
    ```
3. Comandos básicos do GDB:

    * break [função]: Define um ponto de parada (ex: break main).

    * run (ou r): Inicia a execução do programa.

    * next (ou n): Executa a próxima linha de código (pula funções).

    * step (ou s): Entra em uma função.

    * print <variavel> (ou p): Exibe o valor de uma variável (ex: p *minhaRota).

    * continue (ou c): Continua a execução até o próximo breakpoint.

    * quit (ou q): Sai do GDB.

4. Fluxo de Exemplo (Inspecionando a Rota): 

    ```
    (gdb) break main
    (gdb) run
    (gdb) next
    (gdb) next
    (gdb) print minhaRota
    (gdb) print *minhaRota
    (gdb) quit
    ```

## 🛠️ Tecnologias Utilizadas

* Linguagem: C++
* Estrutura de Dados: Lista Duplamente Encadeada
* Ferramenta de Build: GNU Make
* Compilador: GCC/G++
* Editor: Visual Studio Code (opcional)

## 🧠 Aprendizados Relevantes

### Este projeto foi fundamental para consolidar conceitos de:
* Manipulação de Ponteiros: Gestão manual de endereços e conexões entre nós.

* Modularização: Separação entre interface (.h), implementação (.cpp) e testes.

* Automação: Criação de Makefiles multiplataforma.

* Gestão de Ciclo de Vida: Implementação de funções de limpeza para garantir a integridade da memória RAM.

## 📝 Justificativas Técnicas

**1. Qual variação de lista foi escolhida?**

Foi implementada uma **Lista Duplamente Encadeada**.

**2. Por que essa estrutura é mais adequada para esse problema do que as demais?**

A Lista Duplamente Encadeada é a estrutura ideal porque um itinerário de ônibus convencional exige navegação bidirecional. Justificando com base nas operações implementadas: as funções `imprimirIda()` e `imprimirVolta()` dependem diretamente dessa característica. Como cada nó (parada) possui um ponteiro tanto para o `proximo` quanto para o `anterior`, o sistema consegue percorrer a rota do início ao fim e fazer o caminho inverso de forma direta e eficiente (O(*n*)). Se usássemos uma lista simplesmente encadeada, a função de imprimir a volta seria extremamente ineficiente, exigindo o uso de múltiplos laços de repetição.

**3. Haveria algum cenário real em que outra variação de lista seria mais vantajosa?**

Sim. A variação de **Lista Circular** seria a estrutura ideal para modelar uma **linha circular de ônibus**. Em uma rota circular, o ônibus não chega a um ponto final para inverter a direção; em vez disso, a última parada leva diretamente de volta à primeira parada. Nesse cenário, uma lista circular (onde o ponteiro `proximo` do último nó aponta para o `inicio`) seria muito mais vantajosa, pois representaria perfeitamente o trajeto contínuo na vida real com menos consumo de memória do que a lista dupla.
