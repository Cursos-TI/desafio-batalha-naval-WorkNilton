#include <stdio.h>
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3


// Função para inicializar o tabuleiro com água (0)

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }
}


// Função para exibir o tabuleiro na tela

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("= TABULEIRO =\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar navio horizontal

int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int colunaInicial) {
    // Verifica se o navio cabe no tabuleiro horizontalmente
    if (colunaInicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        return 0;

    // Verifica se já há navio no caminho
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][colunaInicial + i] == VALOR_NAVIO)
            return 0;
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][colunaInicial + i] = VALOR_NAVIO;
    }

    return 1;
}

// Função para posicionar navio vertical

int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int coluna) {
    // Verifica se o navio cabe no tabuleiro verticalmente
    if (linhaInicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        return 0;

    // Verifica se já há navio no caminho
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaInicial + i][coluna] == VALOR_NAVIO)
            return 0;
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicial + i][coluna] = VALOR_NAVIO;
    }

    return 1;
}


// Função principal

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas dos navios (definidas no código)
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 4;

    int linhaNavioVertical = 5;
    int colunaNavioVertical = 1;

    // Posiciona navio horizontal
    if (!posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        printf("Erro ao posicionar o navio horizontal.\n");
        return 1;
    }

    // Posiciona navio vertical
    if (!posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        printf("Erro ao posicionar o navio vertical.\n");
        return 1;
    }

    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}