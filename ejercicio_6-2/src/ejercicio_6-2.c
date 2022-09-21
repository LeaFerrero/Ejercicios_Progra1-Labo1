/*
 ============================================================================
 Name        : ejercicio_6-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 6-2: Realizar un programa que permita el ingreso de 10 números enteros
(positivos y negativos). Necesito generar un listado de los números positivos de
manera creciente y negativos de manera decreciente. (Como máximo 5 estructuras
repetitivas)
[Listado 1: 4, 5, 6, 10, 18, 29]
[Listado 2 : -1,-5,-9,-12]
 */

#include <stdio.h>
#include <stdlib.h>
#define CAN 5

int main(void) {

	setbuf(stdout, NULL);

	int arrayInt[CAN];
	int i;
	int j;
	int aux;

	for(i = 0; i < CAN; i++)
	{
		printf("Ingrese un numero entero: ");
		scanf("%d", &arrayInt[i]);
	}

	for(i = 0; i < CAN - 1; i++)
	{
		for(j = i + 1; j < CAN; j++)
		{
			if(arrayInt[i] > 0)
			{
				if(arrayInt[i] > arrayInt[j])
				{
					aux = arrayInt[i];
					arrayInt[i] = arrayInt[j];
					arrayInt[j] = aux;
				}
			}
			if(arrayInt[i] < 0)
			{
				if(arrayInt[i] < arrayInt[j])
				{
					aux = arrayInt[i];
					arrayInt[i] = arrayInt[j];
					arrayInt[j] = aux;
				}
			}
		}
	}

	for(i = 0; i < CAN; i++)
	{
		if(arrayInt[i] > 0)
		{
			printf("%d ", arrayInt[i]);
		}
	}

	printf("\n");

	for(i = 0; i < CAN; i++)
	{
		if(arrayInt[i] < 0)
		{
			printf("%d ", arrayInt[i]);
		}
	}

	return EXIT_SUCCESS;
}
