#include <stdio.h>
#include "computacao_grafica.h"

//FUNCOES
int lerNumeroMinimo(char* mensagem, int minimo) {
    //dados
    int resultado;

    //processamento
    do {
        printf("%s", mensagem);
        scanf("%d", &resultado);
        //error
        if (resultado < minimo)
            printf("Error: valor abaixo do minimo [n < %d]!\n", minimo);
    } while (resultado < minimo);

    //saida
    return resultado;
}


//PROGRAMA PRINCIPAL
int main() {
    //dados
    Grafico* grafico;
    int altura = 0, largura = 0;

    Poligono* poligono;
    int qtd_pontos;

    Ponto ponto;
    double x, y;

    int i, angulo;

    double** matrizRotacao;

    //leitura - processamento - saida
    printf("\n---GRAFICO---\n");
    altura = lerNumeroMinimo("Informe a altura do grafico: ", 20);
    largura = lerNumeroMinimo("Informe a largura do grafico: ", 20);
    grafico = criarGrafico(altura, largura);

    printf("\n---POLIGONO---\n");
    qtd_pontos = lerNumeroMinimo("Informe a quantidade de pontos do poligono: ", 1);
    poligono = criarPoligono(qtd_pontos);
    for (i = 0; i < qtd_pontos; i++) {
        printf("Informe o %d.o ponto [x y]: ", (i + 1));
        scanf("%lf %lf", &x, &y);

        ponto = criarPonto(x, y);
        adicionarPontoPoligono(ponto, poligono, i);
    }

    adicionarPoligonoGrafico(poligono, grafico);
    printf("\n---GRAFICO---\n");
    plotarGrafico(grafico);

    printf("\n---ROTACAO---\n");
    printf("Informe o angulo [inteiro] que deseja rotacionar: ");
    scanf("%d", &angulo);

    matrizRotacao = criarMatrizRotacao(angulo);

    /* DEBUG MATRIZ ROTACAO
    for (i = 0; i < 2; i++) {
        printf("%g %g\n", matrizRotacao[i][0], matrizRotacao[i][1]);
    }
    */

    for (i = 0; i < poligono->qtd_pontos; i++)
        adicionarPontoPoligono(rotacionarPonto(poligono->pontos[i], matrizRotacao), poligono, i);
    
    adicionarPoligonoGrafico(poligono, grafico);
    printf("\n---GRAFICO---\n");
    plotarGrafico(grafico);

    //limpeza da memoria
    destruirGrafico(grafico);
    destruirPoligono(poligono);
    destruirMatrizRotacao(matrizRotacao);

    return 0;
}