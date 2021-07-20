// |------------------------------------------------ Bibliotecas --------------------------------------------------|

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// |-------------------------------------------------- Struct -----------------------------------------------------|

typedef struct{
	float x;
	float y;
}Ponto;

// |------------------------------------------------ Prototipação -------------------------------------------------|

Ponto* alocaMemoriaDoPonto();
Ponto** alocaMemoriaVetorDinamico(int);
void desalocaVetorDinamico(Ponto**, int);


int carregaPontos();
void gerarRandom(Ponto**,int);
float calculaPontosCirculo(Ponto**,int);
void escrevaResultados(float,int);

// |----------------------------------------------- Implementação -------------------------------------------------|

//Main
int main(void){
	int tam = carregaPontos();
  Ponto** vet_p;

  //Aloca memoria vetor dinamico:
  vet_p = alocaMemoriaVetorDinamico(tam);

	gerarRandom(vet_p, tam); 
	float pCirculo = calculaPontosCirculo(vet_p, tam); 
	escrevaResultados(pCirculo, tam); 

  //liberar a memória
  desalocaVetorDinamico(vet_p, tam);
  return 0;
}

//Aloca memoria do pi:
Ponto* alocaMemoriaDoPonto(){
  return (Ponto*) malloc(sizeof(Ponto));
}

//Aloca memoria vetor dinamico:
Ponto** alocaMemoriaVetorDinamico(int tam){
  return (Ponto**) malloc(sizeof(Ponto*) * tam);
}

void desalocaVetorDinamico(Ponto** vet_p, int tam){
	int i;
	for (i=0; i < tam; i++){
		free(vet_p[i]);
	}
	free(vet_p);
}

//Usuario carrega quantidade de pontos para serem distribuidos.
int carregaPontos(){
	int point_max;
  	printf("\n\n|============== |ESCREVA| ==============|\n|       O número maximo de pontos,      |\n|      para calcular o valor de PI.     |\n|=======================================|\n| Pontos: ");
	scanf("%i",&point_max);
	return point_max;
}

//Gera valores aleatorios entre 0 a 1, repetindo até chegar no valor de pontos fornecidos pelo usuario.
void gerarRandom(Ponto** vet_p, int tam){
	int i;
 	 Ponto* p;
	srand(time(NULL));

	for(i = 0; i < tam;i++){
		p = alocaMemoriaDoPonto();
		p->x = rand() / (float)RAND_MAX;
		p->y = rand() / (float)RAND_MAX;
    		vet_p[i] = p;
	}
}

//Usando pitagoras para verificar se os pontos estão *DENTRO* do circulo.
float calculaPontosCirculo(Ponto** vet_p, int tam){
	int i;
	float distancia;
	float pCirc;

	for(i = 0;i < tam;i++){

		distancia = sqrt((pow(vet_p[i]->x,2)) + (pow(vet_p[i]->y,2)));
		if(distancia <= 1.0){
		  pCirc ++;
		}
	}
	return pCirc;
}

//Saida dos resultados:
void escrevaResultados(float pCirculo, int tam){
	float pi = 4 * (pCirculo / (float)tam);
  	printf("|\n|============= |RESULTADO| =============|");
	printf("\n|\n|         Valor de PI: %.5f",pi);
	printf("\n|     Pontos dentro do circulo: %.0f", pCirculo);
	printf("\n|      Pontos fora do circulo: %.0f", tam-pCirculo);
 	printf("\n|\n|=============== |ALUNO| ===============|\n|      Claudionei Lovato Serafini.      |\n|=======================================|\n\n");
}

// |---------------------------------------------- FIM DO PROGRAMA ------------------------------------------------|
