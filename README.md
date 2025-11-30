# Jogo_war

# Jogo de Estratégia

## Descrição

O Jogo de Estratégia é um jogo interativo onde os jogadores podem cadastrar territórios, cada um com suas próprias tropas e cores de exército. Os jogadores podem atacar territórios inimigos e tentar conquistar o mapa, utilizando uma mecânica simples de rolagem de dados para determinar os resultados dos combates.

## Como Jogar

1. **Cadastro de Territórios**
   - O jogador deve cadastrar um número específico de territórios, fornecendo um nome, uma cor para o exército e a quantidade de tropas.

2. **Ataques**
   - Após cadastrar os territórios, o jogador pode escolher um território atacante e um território defensor.
   - O ataque é resolvido através de uma rolagem de dados:
     - O atacante precisa ter pelo menos 2 tropas.
     - O defensor deve ter pelo menos 1 tropa.
   - O resultado do combate é determinado pela comparação dos resultados dos dados.

3. **Conquista**
   - Se o atacante vencer, ele conquista o território defensor, transferindo tropas para o novo território.
   - Se o defensor vencer, o atacante perde uma tropa.

4. **Continuação do Jogo**
   - Após cada rodada de ataque, o jogador é perguntado se deseja continuar jogando ou sair do jogo.

## Requisitos

- Compilador C (ex: GCC)
- Sistema operacional compatível com C

## Como Compilar

Para compilar o jogo, use o seguinte comando no terminal:

```bash
gcc -o jogo_estrategia jogo_estrategia.c
