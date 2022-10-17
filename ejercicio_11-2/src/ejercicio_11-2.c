/*
 ============================================================================
 Name        : ejercicio_11-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 11-2: Realizar una función que reciba como parámetros dos vectores. La
función deberá determinar si el segundo vector está contenido en el primero.

 */

#include <stdio.h>
#include <stdlib.h>

int estaContenido(int*, int, int*, int);

int main(void) {

	setbuf(stdout, NULL);

	int arrayUno[5] = {1,2,3,4,5};
	int arrayDos[3] = {2, 3, 1};

	if(estaContenido(arrayUno, 5, arrayDos, 3))
	{
		puts("\nLo contiene");
	}
	else
	{
		puts("\nNo lo contiene");
	}

	return EXIT_SUCCESS;
}

int estaContenido(int* arrayUno, int lenArrayUno, int* arrayDos, int lenArrayDos)
{
	int contiene;
	int i;
	int j;

	for (i = 0; i < lenArrayDos; i++)
	{
		for (j = 0; j < lenArrayUno; j++)
		{
			if(arrayDos[i] == arrayUno[j])
			{
				break;
			}
		}

		if (j == lenArrayUno)
		{
			contiene = 0;
			break;
		}

		contiene = 1;
	}
	return contiene;
}

