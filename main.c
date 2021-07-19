// |------------------------------------------------ Bibliotecas --------------------------------------------------|

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// |-------------------------------------------------- Struct -----------------------------------------------------|

typedef struct sPi{
	float x;
	float y;
}Pi;

// |------------------------------------------------ Prototipação -------------------------------------------------|

int carregaPontos();
void gerarRandom(Pi*,int);
float calculaPontosQuadrado(Pi*,int);
float calculaPontosCirculo(Pi*,int);
void escrevaResultados(float,float,int);

// |----------------------------------------------- Implementação -------------------------------------------------|

//Main
int main(void){
	int tam = carregaPontos();
	Pi* pi = (Pi*) malloc(tam * sizeof(Pi));

	gerarRandom(pi, tam);
	float pCirculo = calculaPontosCirculo(pi, tam);
	float pQuadrado = calculaPontosQuadrado(pi, tam);
	escrevaResultados(pCirculo, pQuadrado , tam);

  return 0;
}

//Usuario carrega quantidade de pontos para serem distribuidos.
int carregaPontos(){
	int point_max;
  	printf("\n\n|============== |ESCREVA| ==============|\n|       O número maximo de pontos,      |\n|      para calcular o valor de PI.     |\n|=======================================|\n| Pontos: ");
	scanf("%i",&point_max);
	return point_max;
}

//Gera valores aleatorios de 0 a 1, repetindo até chegar no valor de pontos fornecidos pelo usuario.
void gerarRandom(Pi* pi, int tam){
	int i;
	srand(time(NULL));

	for(i = 0;i < tam;i++){
		pi[i].x = rand() / (float)RAND_MAX;
		pi[i].y = rand() / (float)RAND_MAX;
	}
}

//Usando pitagoras para verificar se os pontos estão *DENTRO* do circulo.
float calculaPontosCirculo(Pi* pi, int tam){
	int i;
	float distancia;
	float pCirc;

	for(i = 0;i < tam;i++){
		distancia = sqrt(pi[i].x*pi[i].x + pi[i].y*pi[i].y);
		if(distancia <= 1.0){
		pCirc ++;
		}
	}
	return pCirc;
}

//Usando pitagoras para verificar se os pontos estão *FORA* do circulo.
float calculaPontosQuadrado(Pi* pi, int tam){
	int i;
	float distancia;
	float pQuad=0;

	for(i = 0; i < tam;i++){
		distancia = sqrt(pi[i].x*pi[i].x + pi[i].y*pi[i].y);
		if(distancia > 1.0){
			pQuad ++;
		}
	}
	return pQuad;
}

//
void escrevaResultados(float pCirculo, float pQuadrado, int tam){
	float pi = 4 * (pCirculo / tam);
  	printf("|\n|============= |RESULTADO| =============|");
	printf("\n|\n|         Valor de PI: %.5f",pi);
	printf("\n|     Pontos dentro do circulo: %.0f", pCirculo);
	printf("\n|      Pontos fora do circulo: %.0f", pQuadrado);
 	printf("\n|\n|=============== |ALUNO| ===============|\n|      Claudionei Lovato Serafini.      |\n|=======================================|\n\n");
}

// |---------------------------------------------- FIM DO PROGRAMA ------------------------------------------------|
