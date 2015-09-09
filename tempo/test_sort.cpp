#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <float.h>

void selectSort(int [], int n);

void mergeSort(int [], int);

void merge(int[], int);

void gerar_vetores(int [], int, int);

void redefinir_vetores(int [], int [], int[], int);

int main(int argc, char *argv[])
{
	/* Definir parametros de entrada */
	// Parametros default
	int tam = 1000; int qtd_amostras = 1000; int faixa = 100;
	// -t -a -f
	char com;

	for(int i = 1; i < argc; i = i + 2)
	{
		sscanf(argv[i], "%*c %c", &com);
		switch(com)
		{
			case 't':
				tam = atoi(argv[i + 1]);
				break;

			case 'a':
				qtd_amostras = atoi(argv[i + 1]);
				break;

			case 'f':
				faixa = atoi(argv[i + 1]);
				break;
		}
	}

	srand(time(NULL));

	/* Geração do vetores */
	int *select_vet, *merge_vet, *base;
	base = new int[tam];
	select_vet = new int[tam];
	merge_vet = new int[tam];

	gerar_vetores(base, tam, faixa);
	redefinir_vetores(base, select_vet, merge_vet, tam);

	// Tempos de execução e CPU
	time_t *tempo_exec_select, *tempo_exec_merge;
	double *tempo_cpu_select, *tempo_cpu_merge;

	tempo_exec_select = new time_t[qtd_amostras];
	tempo_exec_merge = new time_t[qtd_amostras];

	tempo_cpu_select = new double[qtd_amostras];
	tempo_cpu_merge = new double[qtd_amostras];
	
	// Melhor e pior tempo de execução
	double maior_exec_select = -DBL_MAX, maior_exec_merge = -DBL_MAX;
	double menor_exec_select = DBL_MAX, menor_exec_merge = DBL_MAX;

	// Melhor e pior tempo de CPU
	double maior_cpu_select = -DBL_MAX, maior_cpu_merge = -DBL_MAX;
	double menor_cpu_select = DBL_MAX, menor_cpu_merge = DBL_MAX;

	/* --- Calcular tempos --- */
	time_t tempo_exec_incio, tempo_exec_fim;
	clock_t tempo_cpu_incio, tempo_cpu_fim;
	for (int i = 0; i < qtd_amostras; ++i)
	{
		// Inicio contagem
		tempo_cpu_incio = clock();
		tempo_exec_incio = time(0);
		selectSort(select_vet, tam);
		tempo_exec_fim = time(0);
		tempo_cpu_fim = clock();
		// Fim contagem

		// Guardar tempo select
		tempo_exec_select[i] = tempo_exec_fim - tempo_exec_incio;
		maior_exec_select = tempo_exec_select[i] > maior_exec_select ? tempo_exec_select[i] : maior_exec_select;
		menor_exec_select = tempo_exec_select[i] < menor_exec_select ? tempo_exec_select[i] : menor_exec_select;
		
		tempo_cpu_select[i] = ((double)((int) (tempo_cpu_fim - tempo_cpu_incio)))/((double)CLOCKS_PER_SEC);
		maior_cpu_select = tempo_cpu_select[i] > maior_cpu_select ? tempo_cpu_select[i] : maior_cpu_select;
		menor_cpu_select = tempo_cpu_select[i] < menor_cpu_select ? tempo_cpu_select[i] : menor_cpu_select;

		// Incio contagem
		tempo_cpu_incio = clock();
		tempo_exec_incio = time(0);
		mergeSort(merge_vet, tam);
		tempo_exec_fim = time(0);
		tempo_cpu_fim = clock();
		// Fim contagem

		//Guardar tempo merge
		tempo_exec_merge[i] = tempo_exec_fim - tempo_exec_incio;
		maior_exec_merge = tempo_exec_merge[i] > maior_exec_merge ? tempo_exec_merge[i] : maior_exec_merge;
		menor_exec_merge = tempo_exec_merge[i] < menor_exec_merge ? tempo_exec_merge[i] : menor_exec_merge;

		tempo_cpu_merge[i] = ((double)((int)(tempo_cpu_fim - tempo_cpu_incio)))/((double)CLOCKS_PER_SEC);
		maior_cpu_merge = tempo_cpu_merge[i] > maior_cpu_merge ? tempo_cpu_merge[i] : maior_cpu_merge;
		menor_cpu_merge = tempo_cpu_merge[i] < menor_cpu_merge ? tempo_cpu_merge[i] : menor_cpu_merge;

		redefinir_vetores(base, select_vet, merge_vet, tam);
	}

	/* --- Calcular estatícas --- */

	/* Média */
	double media_exec_select = 0, media_exec_merge = 0;
	double media_cpu_select = 0, media_cpu_merge = 0;

	for (int i = 0; i < qtd_amostras; ++i)
	{
		media_exec_select += tempo_exec_select[i];
		media_exec_merge += tempo_exec_merge[i];

		media_cpu_select += tempo_cpu_select[i];
		media_cpu_merge += tempo_cpu_merge[i];
	}

	media_exec_select = media_exec_select/(float)qtd_amostras;
	media_exec_merge = media_exec_merge/(float)qtd_amostras;

	media_cpu_select = media_cpu_select/(float)qtd_amostras;
	media_cpu_merge = media_cpu_merge/(float)qtd_amostras;
	/* ------------------------ */

	/* Desvio padrão */

	double desvio_exec_select = 0, desvio_exec_merge = 0;
	double desvio_cpu_select = 0, desvio_cpu_merge = 0;

	for (int i = 0; i < qtd_amostras; ++i)
	{
		desvio_exec_select += pow(tempo_exec_select[i] - media_exec_select, 2);
		desvio_exec_merge += pow(tempo_exec_merge[i] - media_exec_merge, 2);

		desvio_cpu_select += pow(tempo_cpu_select[i] - media_cpu_select, 2);
		desvio_cpu_merge += pow(tempo_cpu_merge[i] - media_cpu_merge, 2);
	}

	desvio_exec_select = sqrt(desvio_exec_select/(float)(qtd_amostras - 1));
	desvio_exec_merge = sqrt(desvio_exec_merge/(float)(qtd_amostras - 1));

	desvio_cpu_select = sqrt(desvio_cpu_select/(float)(qtd_amostras - 1));
	desvio_cpu_merge = sqrt(desvio_cpu_merge/(float)(qtd_amostras - 1));

	/* ------------------------ */

	printf("\n ------------------------ \n\n");

	printf("Select Sort\n");
	
	printf("Maior tempo de execução: %f\n", maior_exec_select);
	printf("Menor tempo de execução: %f\n", menor_exec_select);

	printf("Maior tempo de CPU: %f\n", maior_cpu_select);
	printf("Menor tempo de CPU: %f\n", menor_cpu_select);

	printf("Média de execução: %f\n", media_exec_select);
	printf("Média de CPU: %f\n", media_cpu_select);

	printf("Desvio padrão de execução: %f\n", desvio_exec_select);
	printf("Desvio padrão de CPU: %f\n", desvio_cpu_select);

	printf("\n ------------------------ \n\n");

	printf("Merge Sort\n");
	
	printf("Maior tempo de execução: %f\n", maior_exec_merge);
	printf("Menor tempo de execução: %f\n", menor_exec_merge);

	printf("Maior tempo de CPU: %f\n", maior_cpu_merge);
	printf("Menor tempo de CPU: %f\n", menor_cpu_merge);

	printf("Média de execução: %f\n", media_exec_merge);
	printf("Média de CPU: %f\n", media_cpu_merge);

	printf("Desvio padrão de execução: %f\n", desvio_exec_merge);
	printf("Desvio padrão de CPU: %f\n", desvio_cpu_merge);

	printf("\n ------------------------ \n");

	return 0;
}

void gerar_vetores(int base[], int tam, int faixa)
{
	int num;
	for (int i = 0; i < tam; i++)
	{
		num = rand() % faixa;
		base[i] = num;
	}
}

void redefinir_vetores(int base[], int select_vet[], int merge_vet[], int tam)
{
	for (int i = 0; i < tam; ++i)
	{
		select_vet[i] = base[i];
		merge_vet[i] = base[i];
	}
}

void selectSort(int arr[], int n)
{
	int pos_min,temp;

	for (int i=0; i < n-1; i++)
	{
		pos_min = i;
		
		for (int j=i+1; j < n; j++)
		{
			if (arr[j] < arr[pos_min])
				pos_min=j;
		}

		if (pos_min != i)
		{
			temp = arr[i];
			arr[i] = arr[pos_min];
			arr[pos_min] = temp;
		}
	}
}

void merge(int vec[], int vecSize) {
	int mid;
	int i, j, k;
	int* tmp;

	tmp = (int*) malloc(vecSize * sizeof(int));
	if (tmp == NULL) {
		exit(1);
	}

	mid = vecSize / 2;

	i = 0;
	j = mid;
	k = 0;
	while (i < mid && j < vecSize) {
		if (vec[i] <= vec[j]) {
			tmp[k] = vec[i++];
		}
		else {
			tmp[k] = vec[j++];
		}
		++k;
	}

	if (i == mid) {
		while (j < vecSize) {
			tmp[k++] = vec[j++];
		}
	}
	else {
		while (i < mid) {
			tmp[k++] = vec[i++];
		}
	}

	for (i = 0; i < vecSize; ++i) {
		vec[i] = tmp[i];
	}

	free(tmp);
}

void mergeSort(int vec[], int vecSize) {
	int mid;

	if (vecSize > 1) {
		mid = vecSize / 2;
		mergeSort(vec, mid);
		mergeSort(vec + mid, vecSize - mid);
		merge(vec, vecSize);
	}
}