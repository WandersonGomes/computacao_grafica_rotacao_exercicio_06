#ifndef _COMPUTACAO_GRAFICA_H
#define _COMPUTACAO_GRAFICA_H

//GRAFICO
typedef struct {
    int altura;
    int largura;
    char** malha;
} Grafico;

//PONTO
typedef struct {
    int x;
    int y;
} Ponto;

//POLIGONO
typedef struct {
    int qtd_pontos;
    Ponto* pontos;
} Poligono;

//grafico
Grafico* criarGrafico(int altura, int largura);
void adicionarPoligonoGrafico(Poligono* poligono, Grafico* grafico);
void plotarGrafico(Grafico* grafico);
void destruirGrafico(Grafico* grafico);

//ponto
Ponto criarPonto(double x, double y);

//poligono
Poligono* criarPoligono(int qtd_pontos);
void adicionarPontoPoligono(Ponto ponto, Poligono* poligono, int indice);
void destruirPoligono(Poligono* poligono);

//rotacionar ponto
double** criarMatrizRotacao(int angulo); 
Ponto rotacionarPonto(Ponto ponto, double** matrizRotacao);
void destruirMatrizRotacao(double** matriz);

#endif