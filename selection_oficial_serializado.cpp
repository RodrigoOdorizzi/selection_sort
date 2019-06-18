// selection_oficial.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <stdio.h>
#include<omp.h>
#include "pch.h"
#include <iostream>
#include <chrono>
#include<windows.h>
#include<assert.h>
#include<stdio.h> 
#include<ctime>




using namespace std;


void selectionSort(int arr[], int n) {
 

		int i, j, minIndex, tmp;
 

		for (i = 0; i < n - 1; i++) {

			minIndex = i;

			for (j = i + 1; j < n; j++)
				if (arr[j] < arr[minIndex])
					minIndex = j;
			if (minIndex != i) {
				tmp = arr[i];
				arr[i] = arr[minIndex];
 
				arr[minIndex] = tmp;
			}
		}

	 
}


double tempo = 0;

int main()
{

	int num = 0;
	//inicia contagem de tempo
	int re = 0;

	while (re < 10) {
		int x[10000];
		printf("\nRepetindo pela vez num: %d\n", (re + 1));

		//atribuindo valor randômico para as posições do vetor
		for (int i = 0; i < 10000; i++) {

			x[i] = (rand() % 10000) + 1;
		}

		//Inicia contagem de tempo

		auto start = std::chrono::system_clock::now();


		//chama método com o vetor de 10000 posições, e com número de interações
		selectionSort(x, 10000);

		//finaliza contagem de tempo

		auto end = std::chrono::system_clock::now();

		//print do resultado
		for (int i = 0; i < 10000; i++) {
			printf("%d\n", x[i]);
		}

		re++;

		std::chrono::duration<double> elapsed_seconds = (end - start);
		tempo = tempo + elapsed_seconds.count();

	}

	//fim da contagem de tempo e mostragem dos valores
	printf("\nMedia de Tempo: %f\n", tempo / 10);



	return 0;

}