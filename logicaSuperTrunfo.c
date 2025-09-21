#include <stdio.h>
#include <string.h>

int main() {
    // --- Definição das variáveis para armazenar as propriedades dos países ---
    struct Pais {
        char nome[50];
        long populacao;
        long area; // em km²
        long pib;  // em bilhões de dólares
    };

    struct Pais pais1, pais2;

    // --- Cadastro das Cartas (igual à versão anterior) ---
    printf("--- Cadastro do Primeiro Pais ---\n");
printf("Digite o nome do primeiro país: ");
fgets(pais1.nome, sizeof(pais1.nome), stdin);
pais1.nome[strcspn(pais1.nome, "\n")] = 0; // remove o \n

printf("Digite a populacao do primeiro país: ");
scanf("%ld", &pais1.populacao);
getchar(); // consome o \n deixado pelo scanf

printf("Digite a area em km² do primeiro país: ");
scanf("%ld", &pais1.area);
getchar();

printf("Digite o PIB em bilhoes de dolares do primeiro país: ");
scanf("%ld", &pais1.pib);
getchar();

printf("\n--- Cadastro do Segundo Pais ---\n");

printf("Digite o nome do segundo país: ");
fgets(pais2.nome, sizeof(pais2.nome), stdin);
pais2.nome[strcspn(pais2.nome, "\n")] = 0;

printf("Digite a populacao do segundo país: ");
scanf("%ld", &pais2.populacao);
getchar();

printf("Digite a area em km² do segundo país: ");
scanf("%ld", &pais2.area);
getchar();

printf("Digite o PIB em bilhoes de dolares do segundo país: ");
scanf("%ld", &pais2.pib);
getchar();

    // --- Comparação de Cartas e Exibição dos Resultados ---
    printf("\n--- Resultados da Comparação ---\n");

    // Para evitar o if/else, usaremos um truque com o operador ternário.
    // Primeiro, determinamos o país vencedor para cada atributo.

    // Vencedor por População
    printf("\nComparando População:\n");
    char *vencedorPop;
    vencedorPop = (pais1.populacao > pais2.populacao) ? pais1.nome : pais2.nome;
    long valorPop = (pais1.populacao > pais2.populacao) ? pais1.populacao : pais2.populacao;
    printf("%s tem a maior populacao com %ld habitantes.\n", vencedorPop, valorPop);
    
    // O problema de não usar if/else é tratar o caso de empate.
    // O operador ternário não permite essa verificação direta.
    // Uma solução seria aninhar ternários, mas isso pode ser confuso.
    // Por exemplo:
    // (pais1.populacao > pais2.populacao) ? printf(...) : ((pais2.populacao > pais1.populacao) ? printf(...) : printf(...));
    // Isso torna o código menos legível. A primeira solução usando if/else é geralmente a melhor.

    // Vencedor por Área
    printf("\nComparando Área:\n");
    char *vencedorArea;
    vencedorArea = (pais1.area > pais2.area) ? pais1.nome : pais2.nome;
    long valorArea = (pais1.area > pais2.area) ? pais1.area : pais2.area;
   
    printf("%s tem a maior area com %ld km².\n", vencedorArea, valorArea);

    // Vencedor por PIB
    printf("\nComparando PIB:\n");
    char *vencedorPIB;
    vencedorPIB = (pais1.pib > pais2.pib) ? pais1.nome : pais2.nome;
    long valorPIB = (pais1.pib > pais2.pib) ? pais1.pib : pais2.pib;
    printf("%s tem o maior PIB com $%ld bilhoes.\n", vencedorPIB, valorPIB);

    return 0;
}