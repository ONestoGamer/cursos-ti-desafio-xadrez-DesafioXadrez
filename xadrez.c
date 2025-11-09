// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.
// Ernesto da Silva Santana - 202507200003
// 08/11/2025

#include <stdio.h>
#include <stdlib.h>

#define TABULEIRO 8   // tamanho do tabuleiro
#define PASSOS 2      // número de casas para recursão

// ------------------ TORRE ------------------
void torre_recursiva(int passos) {
    if (passos == 0) return; // condição de parada

    printf("Cima\n");
    torre_recursiva(passos - 1);

    printf("Baixo\n");
    torre_recursiva(passos - 1);

    printf("Esquerda\n");
    torre_recursiva(passos - 1);

    printf("Direita\n");
    torre_recursiva(passos - 1);
}

// ------------------ BISPO ------------------
void bispo_recursivo(int passos) {
    if (passos == 0) return; // condição de parada

    // loops aninhados: vertical (i) e horizontal (j)
    for (int i = 1; i <= passos; i++) {
        for (int j = 1; j <= passos; j++) {
            if (i == j) {
                printf("Diagonal Cima-Direita\n");
            } else if (i + j == passos + 1) {
                printf("Diagonal Cima-Esquerda\n");
            }
        }
    }

    bispo_recursivo(passos - 1); // chamada recursiva
}

// ------------------ RAINHA ------------------
void rainha_recursiva(int passos) {
    if (passos == 0) return;

    // movimentos da Torre
    printf("Cima\n");
    rainha_recursiva(passos - 1);

    printf("Baixo\n");
    rainha_recursiva(passos - 1);

    printf("Esquerda\n");
    rainha_recursiva(passos - 1);

    printf("Direita\n");
    rainha_recursiva(passos - 1);

    // movimentos do Bispo
    printf("Diagonal Cima-Direita\n");
    rainha_recursiva(passos - 1);

    printf("Diagonal Cima-Esquerda\n");
    rainha_recursiva(passos - 1);

    printf("Diagonal Baixo-Direita\n");
    rainha_recursiva(passos - 1);

    printf("Diagonal Baixo-Esquerda\n");
    rainha_recursiva(passos - 1);
}

// ------------------ CAVALO ------------------
void cavalo_movimentos() {
    // loops complexos para simular "L"
    for (int i = 1; i <= TABULEIRO; i++) {
        for (int j = 1; j <= TABULEIRO; j++) {
            // movimento em L: duas casas para cima e uma para a direita
            if (i - 2 >= 1 && j + 1 <= TABULEIRO) {
                printf("Cima\n");
                printf("Cima\n");
                printf("Direita\n");
                break; // sai do loop interno após encontrar movimento válido
            } else {
                continue; // ignora posições inválidas
            }
        }
    }
}

// ------------------ MAIN ------------------
int main() {
    printf("Movimentos da Torre:\n");
    torre_recursiva(PASSOS);

    printf("\nMovimentos do Bispo:\n");
    bispo_recursivo(PASSOS);

    printf("\nMovimentos da Rainha:\n");
    rainha_recursiva(PASSOS);

    printf("\nMovimentos do Cavalo:\n");
    cavalo_movimentos();

    return 0;
}