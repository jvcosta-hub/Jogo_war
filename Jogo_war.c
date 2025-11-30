#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição da struct Territorio
struct Territorio {
    char nome[30];      // Nome do território
    char cor[10];       // Cor do exército
    int tropas;         // Quantidade de tropas
};

// Função para cadastrar os territórios
void cadastrarTerritorios(struct Territorio* territorios, int numTerritorios) {
    for (int i = 0; i < numTerritorios; i++) {
        printf("\n--- Cadastro do Território --- %d:\n", i + 1);
        
        // Limpar buffer de entrada antes de ler strings
        if (i > 0) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        // Leitura do nome do território
        printf("Nome do Territorio: ");
        scanf("%s", territorios[i].nome);
        
        // Leitura da cor do exército
        printf("Cor do exército (ex: Azul, Verde): ");
        scanf("%s", territorios[i].cor);
        
        // Leitura da quantidade de tropas
        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }
}

// Função para exibir os dados dos territórios
void exibirTerritorios(struct Territorio* territorios, int numTerritorios) {
    printf("\n==========================\n");
    printf("\nMAPA MUNDO - ESTADO ATUAL\n");
    printf("==========================\n");
    for (int i = 0; i < numTerritorios; i++) {
        printf("Território %d:\n", i + 1);
        printf("  Nome: %s\n", territorios[i].nome);
        printf("  Cor do exército: %s\n", territorios[i].cor);
        printf("  Quantidade de tropas: %d\n", territorios[i].tropas);
    }
    printf("==========================\n");
}

// Função para simular um ataque entre dois territórios
void atacar(struct Territorio* atacante, struct Territorio* defensor) {
    // Garante que ambos tenham pelo menos 1 tropa para atacar/defender
    if (atacante->tropas < 2 || defensor->tropas < 1) {
        printf("Ataque impossível: O atacante precisa de pelo menos 2 tropas e o defensor de pelo menos 1.\n");
        return;
    }

    int ataqueAtacante = rand() % 6 + 1; // Rolagem de dado para o atacante
    int ataqueDefensor = rand() % 6 + 1; // Rolagem de dado para o defensor

    printf("\n--- INÍCIO DO COMBATE ---\n");
    printf("Atacante: %s (%s) com %d tropas\n", atacante->nome, atacante->cor, atacante->tropas);
    printf("Defensor: %s (%s) com %d tropas\n", defensor->nome, defensor->cor, defensor->tropas);
    printf("Resultado dos dados: Atacante rolou %d | Defensor rolou %d\n", ataqueAtacante, ataqueDefensor);

    if (ataqueAtacante > ataqueDefensor) {
        printf("Resultado: %s venceu o ataque!\n", atacante->nome);
        
        // O atacante conquista o território
        strcpy(defensor->cor, atacante->cor);
        
        // Regra de conquista: O atacante move metade de suas tropas (arredondado para baixo)
        int tropasMovidas = atacante->tropas / 2;
        
        // O defensor perde todas as tropas (pois foi conquistado)
        defensor->tropas = tropasMovidas;
        atacante->tropas -= tropasMovidas;

    } else {
        printf("Resultado: %s defendeu com sucesso!\n", defensor->nome);
        // O atacante perde 1 tropa por falhar no ataque
        atacante->tropas -= 1; 
    }
    
    printf("--- FIM DO COMBATE ---\n");
    // Exibição dos dados atualizados (apenas para os dois envolvidos, mas vamos chamar a função geral)
    // Nota: Para exibir apenas os dois, seria necessário passar um array pequeno, mas vamos manter a função geral para ver o mapa completo.
}

// Função para liberar a memória alocada
void liberarMemoria(struct Territorio* territorios) {
    free(territorios);
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    int numTerritorios;
    printf("Bem-vindo ao Jogo de Estratégia!\n");
    printf("Quantos territórios você deseja cadastrar? ");
    scanf("%d", &numTerritorios);

    if (numTerritorios <= 0) {
        printf("Número inválido de territórios. Encerrando.\n");
        return 0;
    }

    // Alocação dinâmica de memória para os territórios
    struct Territorio* territorios = (struct Territorio*)calloc(numTerritorios, sizeof(struct Territorio));
    if (territorios == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 1;
    }

    // Cadastro dos territórios
    cadastrarTerritorios(territorios, numTerritorios);
    
    int continuar = 1;
    
    while (continuar) {
        // Exibição dos territórios cadastrados antes de cada rodada
        exibirTerritorios(territorios, numTerritorios);

        // Simulação de ataque
        int atacanteIdx, defensorIdx;
        printf("\n--- RODADA DE ATAQUE ---\n");
        
        printf("Escolha o índice do território atacante (1 a %d): ", numTerritorios);
        scanf("%d", &atacanteIdx);
        
        if (atacanteIdx == 0) {
            continuar = 0;
            printf("Opção '0' detectada. Encerrando o jogo.\n");
            break;
        }

        printf("Escolha o índice do território defensor (1 a %d): ", numTerritorios);
        scanf("%d", &defensorIdx);
        
        if (defensorIdx == 0) {
            continuar = 0;
            printf("Opção '0' detectada. Encerrando o jogo.\n");
            break;
        }

        // Verificação de limites e ajuste dos índices para 0-based
        if (atacanteIdx < 1 || atacanteIdx > numTerritorios || defensorIdx < 1 || defensorIdx > numTerritorios) {
            printf("Erro: Índice fora do intervalo válido (1 a %d).\n", numTerritorios);
            continue;
        }
        
        atacanteIdx--; 
        defensorIdx--; 

        // Verificação para garantir que o ataque não seja feito contra o próprio território ou se as tropas são insuficientes
        if (atacanteIdx == defensorIdx) {
            printf("Atenção: Você não pode atacar seu próprio território.\n");
        } else if (strcmp(territorios[atacanteIdx].cor, territorios[defensorIdx].cor) == 0) {
            printf("Atenção: Você só pode atacar territórios de cores inimigas.\n");
        } else if (territorios[atacanteIdx].tropas < 2) {
             printf("Atenção: O atacante precisa de pelo menos 2 tropas para iniciar um ataque.\n");
        } else {
            atacar(&territorios[atacanteIdx], &territorios[defensorIdx]);
        }

        // Pergunta de Continuação
        if (continuar) {
            printf("\nDeseja realizar outro ataque? Digite 0 para sair, ou qualquer outro número para continuar: ");
            scanf("%d", &continuar);
            if (continuar == 0) {
                printf("Obrigado por jogar!\n");
            }
        }
    }

    // Liberar a memória alocada
    liberarMemoria(territorios);

    return 0;
}