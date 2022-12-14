# atividade8_arquiteturaII

## 01) Faça um programa para demonstrar as técnicas de otimização de pipeline compilação. Apresente em o link para um arquivo único (preferência PDF): 1) código-fonte antes; 2) apresentação de quais otimizações foram realizadas; 3) código fonte após as otimizações; 4) tabela ou gráfico apresentando as melhorias alcançadas com as otimizações. Detalhe: pode ser feito em qualquer linguagem de programação

## No meu código, simulo um calculo de IMC de seres humanos.

```C
int N = 500;

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
```

## Resultados

Tempo de execução sem otimizações: 0.25 segundo.

Tempo de execução com otimização -O1: 0.031 segundo.

Tempo de execução com otimização -O2: 0.031 segundo.

Tempo de execução com otimização -O2: 0.037 segundo.
  
