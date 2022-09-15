/*
 ============================================================================
 Name        : ejercicio_5-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 5-3: Realizar una función que reciba como parámetros un array de enteros y
un entero por referencia. La función calculara el máximo valor de ese array y utilizara
el valor por referencia para retornar ese valor.

 */

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void calcularMaximo(int*, int, int*);

int main(void) {

	setbuf(stdout, NULL);

	int arrayInt[TAM];
	int i;
	int maximo;

	for(i=0; i<TAM; i++)
	{
		printf("Ingrese un numero entero: ");
		scanf("%d", &arrayInt[i]);
	}

	calcularMaximo(arrayInt, TAM, &maximo);

	printf("El valor maximo es: %d", maximo);

	EXIT_SUCCESS;
}

void calcularMaximo(int* arrayInt, int tam, int* maximo)
{
	int i;

	*maximo = arrayInt[0];

	for(i=0; i<tam; i++)
	{
		if(arrayInt[i] > *maximo)
		{
			*maximo = arrayInt[i];
		}
	}
}
