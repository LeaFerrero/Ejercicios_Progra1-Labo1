/*
 ============================================================================
 Name        : ejercicio_5-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Ejercicio 5-2: Hacer una función que calcule el promedio de los valores del Array que
recibe y me devuelva el promedio.

 */

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void promediarInt(int*, int, float*);

int main(void) {

	setbuf(stdout, NULL);

	int arrayInt[TAM];
	int i;
	float promedio;

	for(i=0; i<TAM; i++)
	{
		printf("Ingrese un numero entero: ");
		scanf("%d", &arrayInt[i]);
	}

	promediarInt(arrayInt, TAM, &promedio);

	printf("El promedio es: %.2f", promedio);

	return EXIT_SUCCESS;
}

void promediarInt(int* array, int tam, float* resultado)
{
	int i;
	int suma;

	for(i=0; i<tam; i++)
	{
		suma += array[i];
	}

	*resultado = (float)suma / tam;
}
