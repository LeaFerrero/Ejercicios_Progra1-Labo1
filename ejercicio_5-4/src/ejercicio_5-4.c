/*
 ============================================================================
 Name        : ejercicio_5-4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 5-4: Pedir 10 números entre -100 y 100, guardarlos en un Array. Determinar:
a) Cantidad de negativos.
b) Sumatoria de los impares.
c) El mayor de los pares.
d) Listado de los números ingresados.
e) Listado de los números mayores a 15.
f) Listado de los números de las posiciones impares.

 */

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main(void) {

	setbuf(stdout, NULL);

	int arrayInt[TAM];
	int i;
	int cantNegativos;
	int sumImpares;
	int maxPar;
	int flagMax;
	int flag;

	cantNegativos = 0;
	sumImpares = 0;
	flagMax = 0;
	flag = 0;



	for(i=0; i<TAM; i++)
	{
		printf("Ingrese un numero entero entre -100 y 100: ");
		scanf("%d", &arrayInt[i]);
		while(arrayInt[i] < -100 || arrayInt[i] > 100)
		{
			printf("Error. Ingrese un numero entero entre -100 y 100: ");
			scanf("%d", &arrayInt[i]);
		}

		if(arrayInt[i] < 0)
		{
			cantNegativos ++;
		}

		if(arrayInt[i] % 2 != 0)
		{
			sumImpares += arrayInt[i];
		}
		else
		{
			if(flagMax == 0 || arrayInt[i] > maxPar)
			{
				maxPar = arrayInt[i];
				flagMax = 1;
			}
		}
	}

	printf("\nLa cantidad de negativos es de: %d", cantNegativos);
	printf("\nLa sumatoria de los impares da: %d", sumImpares);
	printf("\nEl mayor de los pares es: %d", maxPar);

	printf("\nELos numeros ingresados son: ");

	for(i=0; i<TAM; i++)
	{
		printf("%d ", arrayInt[i]);
	}

	printf("\nELos numeros mayores a 15 son: ");

	for(i=0; i<TAM; i++)
		{
			if(arrayInt[i] > 15)
			{
				printf("%d ", arrayInt[i]);
			}
			else
			{
				if(flag == 0)
				{
					printf("No hay");
					flag = 1;
				}
			}
		}

	printf("\nLos numeros en posiciones impares son: ");

	for(i=0; i<TAM; i++)
		{
			if(i % 2 != 0)
			{
				printf("%d ", arrayInt[i]);
			}
		}



	return EXIT_SUCCESS;
}
