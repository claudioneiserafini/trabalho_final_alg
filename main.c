// |------------------------------------------------ Bibliotecas --------------------------------------------------|

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// |-------------------------------------------------- Struct -----------------------------------------------------|

typedef struct sPi{
	float x;
	float y;
}Pi;

// |------------------------------------------------ Prototipação -------------------------------------------------|

int gerarPontos();
void calculaValorPi();
int calculaPontosQuadrado();
int calculaPontosCirculo();
float calculaDistancia();
void escrevaValorPi();

// |----------------------------------------------- Implementação -------------------------------------------------|

//
int main(void){
	Pi* pi;
	int raio = 2;

	int tam = gerarPontos();
	calculaValorPi(pi, tam, raio);

	return 0;
}

//
int gerarPontos(int tam){
	int point_max;
	printf("Digite o número maximo de pontos: ");
	scanf("%i",&point_max);
	
	//printf("Digite o valor do raio: ");
	//scanf("%i",&raio);
	
	return point_max;
}

//
void calculaValorPi(Pi* pi, int tam, int raio){
	srand(time(NULL));
	int i, acertos=0;
	float calcpi=0;

	for(i = 0; i < tam; i++){
		pi[i].x = rand()  / raio;
		pi[i].y = rand()  / raio;

		if(pi[i].x * pi[i].x + pi[i].y * pi[i].y < 1.0){
			acertos++;
		}
	}
	
	//calcpi= (4.0 * acertos) / tam;
}

//
int calculaPontosQuadrado(){
  
  return 0;
}

//
int calculaPontosCirculo(){
  return 0;
}

//
float calculaDistancia(){
  return 0;
}

//
void escrevaValorPi(){
  
}

// |---------------------------------------------- FIM DO PROGRAMA ------------------------------------------------|
