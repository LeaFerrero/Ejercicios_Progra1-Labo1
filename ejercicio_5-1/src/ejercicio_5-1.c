/*
 ============================================================================
 Name        : ejercicio_5-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 5-1: Pedir 5 números enteros, guardarlos en un Array. Calcular la sumatorio
de los mismos y mostrar los impares ingresados.

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	int arrayInt[5];
	int i;
	int suma;

	suma = 0;

	for(i=0; i<5; i++)
	{
		printf("Ingrese un numero entero: ");
		scanf("%d", &arrayInt[i]);

		suma += arrayInt[i];
	}

	printf("\nLa sumatoria es: %d", suma);
	printf("\nLos numeros imares ingresados son: ");

	for(i=0; i<5; i++)
	{
		if(arrayInt[i] % 2 == 1)
		{
			printf("%d ", arrayInt[i]);
		}
	}

	return EXIT_SUCCESS;
}
