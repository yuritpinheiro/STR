#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void selectSort(int [], int n);

void mergeSort(int [], int);

void merge(int[], int);

int main(int argc, char **argv)
{
	srand(time(NULL));
	int *select_vet, *merge_vet;

	int tam  = 10;

	/* Geração dos vetores */
	select_vet = new int[tam];
	merge_vet = new int[tam];
	for (int i = 0; i < tam; i++)
	{
		int num = rand() % 100;
		select_vet[i] = num;
		merge_vet[i] = num;
	}

	for (int i = 0; i < tam; ++i)
	{
		printf("%d\n", merge_vet[i]);
	}

	selectSort(select_vet, tam);

	mergeSort(merge_vet, tam);

	printf("------------------\n");

	for (int i = 0; i < tam; ++i)
	{
		printf("%d\n", merge_vet[i]);
	}

	return 0;
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