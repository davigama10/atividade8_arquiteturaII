#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

double randfrom(double min, double max){
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

int main(){

	int N = 500;

	double time_spent = 0.0;
  	clock_t begin, end;

  	begin = clock();

	struct m_struct{
		double altura, peso;
		double IMC;
		int situacao;
	};

	struct m_struct humano[N];
	double humanos_matriz[N][N];
	int i, j;

	// Inicialização

	for (i = 0 ; i < N ; i++){
		humano[i].altura = randfrom(1.5, 2.0);
		humano[i].peso = randfrom(50.0, 100.0);
	}

	// Calcula IMC

	for (i = 0 ; i < N ; i++){
		humano[i].IMC = humano[i].peso * (humano[i].altura * humano[i].altura);
	}

	// Recebe a situação do humano

	for (i = 0 ; i < N ; i++){
		if (humano[i].IMC < 24.9){
			humano[i].situacao = 0; //peso normal
		}
		else if (humano[i].IMC >= 25 && humano[i].IMC < 30){
			humano[i].situacao = 1; //sobrepeso
		}
		else if (humano[i].IMC >= 30.01 && humano[i].IMC < 35){
			humano[i].situacao = 2; //obesidade 1
		}
		else{
			humano[i].situacao = 3; //obesidade 2
		}
	}
	

	// Calcula a distância para a borda do sobrepeso

	for (int k = 0 ; k < N ; k++){
		if (humano[k].IMC > 25){
			for (i = 0 ; i < N ; i++){
				for (j = 0 ; j < N ; j++){
					humanos_matriz[i][j] = humano[k].IMC - 25; //quanto falta para sair do sobrepeso
				}
			}
		}
		else{
			for (i = 0 ; i < N ; i++){
				for (j = 0 ; j < N ; j++){
					humanos_matriz[i][j] = humano[k].IMC - 25; //quanto falta para chegar no sobrepeso
				}
			}
		}
	}
	
	

	end = clock();

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  	printf("Tempo: %f segundos\n", time_spent);

  	system("pause");


	return 0;
}