#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
struct Territorio {
    char nome[30];      // Nome do território
    char cor[10];       // Cor do exército
    int tropas;         // Quantidade de tropas
};

int main() {
    printf("=========================================================\n\n");
    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n");
    // Declaração de um vetor de structs para armazenar 5 territórios
    struct Territorio territorios[5];

    // Entrada dos dados
    for (int i = 0; i < 5; i++) {
        printf("\n--- Cadastro do Território --- %d:\n", i + 1);
        
        // Leitura do nome do território
        printf("Nome do Territorio: ");
        scanf("%s", territorios[i].nome); // Usando scanf para ler a string

        // Leitura da cor do exército
        printf("Cor do exército (ex: Azul, Verde): ");
        scanf("%s", territorios[i].cor); // Usando scanf para ler a string

        // Leitura da quantidade de tropas
        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas); // Leitura do número de tropas
    }

    // Exibição dos dados cadastrados
    printf("\n==========================\n");
    printf("\nMAPA MUNDO - ESTADO ATUAL\n");
    printf("\n==========================\n");
    printf("\nTerritórios cadastrados:\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Quantidade de tropas: %d\n\n", territorios[i].tropas);
    }

    return 0;
}