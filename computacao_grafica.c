#include "computacao_grafica.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Grafico* criarGrafico(int altura, int largura) {
    //dados
    Grafico* grafico = NULL;
    int i, j;
    
    //processamento
    grafico = (Grafico*) malloc(sizeof(Grafico));

    grafico->altura = altura;
    grafico->largura =largura;

    grafico->malha = (char**) malloc(sizeof(char*) * altura);
    for (i = 0; i < altura; i++)
        grafico->malha[i] = (char*) malloc(sizeof(char) * largura);
    
    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            if (i == (altura/2))
                grafico->malha[i][j] = '-';
            else if (j == (largura/2))
                grafico->malha[i][j] = '|';
            else
                grafico->malha[i][j] = ' ';
        }
    }

    //saida
    return grafico;
}

void plotarGrafico(Grafico* grafico) {
    //dados
    int i, j;

    //processamento
    for (i = 0; i < grafico->altura; i++) {
        for (j = 0; j < grafico->largura; j++) {
            printf("%c", grafico->malha[i][j]);
        }
        printf("\n");
    }
}

void destruirGrafico(Grafico* grafico) {
    //dados
    int i;

    //processamento
    for (i = 0; i < grafico->altura; i++)
        free(grafico->malha[i]);
    free(grafico->malha);

    free(grafico);
}

Poligono* criarPoligono(int qtd_pontos) {
    //dados
    Poligono* poligono = NULL;

    //processamento
    poligono = (Poligono*) malloc(sizeof(Poligono));
    poligono->qtd_pontos = qtd_pontos;
    poligono->pontos = (Ponto*) malloc(sizeof(Ponto) * qtd_pontos);

    //saida
    return poligono;
}

void destruirPoligono(Poligono* poligono) {
    free(poligono->pontos);
    free(poligono);
}

Ponto criarPonto(double x, double y) {
    //dados
    Ponto ponto;

    //processamento
    ponto.x = (int) x;
    ponto.y = (int) y;

    //saida
    return ponto;
}

void adicionarPontoPoligono(Ponto ponto, Poligono* poligono, int indice) {
    poligono->pontos[indice] = ponto;
}

void adicionarPoligonoGrafico(Poligono* poligono, Grafico* grafico) {
    //dados
    int i, x, y;

    //processamento
    for (i = 0; i < poligono->qtd_pontos; i++) {
        x = poligono->pontos[i].x + (grafico->largura/2);
        y = (grafico->altura/2) - poligono->pontos[i].y;

        grafico->malha[y][x] = '+';
    }
}

double** criarMatrizRotacao(int angulo) {
    //dados
    double** matriz;
    double radianos;
    int i;

    //processamento
    matriz = (double**) malloc(sizeof(double*) * 2);
    for (i = 0; i < 2; i++)
        matriz[i] = (double*) malloc(sizeof(double) * 2);

    radianos = (angulo * M_PI)/180;

    matriz[0][0] = ((int) (100 * cos(radianos))) / 100.00;
    matriz[0][1] = ((int) (100 * sin(radianos))) / 100.00;
    matriz[1][0] = -((int) (100 * sin(radianos))) / 100.00;
    matriz[1][1] = ((int) (100 * cos(radianos))) / 100.00;

    //saida
    return matriz;
}

Ponto rotacionarPonto(Ponto ponto, double** matrizRotacao) {
    //dados
    Ponto novo_ponto;
    
    //processamento
    novo_ponto.x = ceil(ponto.x * matrizRotacao[0][0] + ponto.y * matrizRotacao[1][0]);
    novo_ponto.y = ceil(ponto.x * matrizRotacao[0][1] + ponto.y * matrizRotacao[1][1]);

    //saida
    return novo_ponto;
}

void destruirMatrizRotacao(double** matriz) {
    //dados
    int i;

    //processamento
    for (i = 0; i < 2; i++)
        free(matriz[i]);

    free(matriz);
}