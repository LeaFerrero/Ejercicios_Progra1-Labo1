/*
 ============================================================================
 Name        : ejercicio_4-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 4-2: Realizar una función Suma que reciba como parámetros dos enteros (los que
va a sumar) y un puntero a entero que guardara el resultado de esta. La función retorna 0 si
pudo realizar la suma y -1 en caso de no haberla podido realizar.

 */

#include <stdio.h>
#include <stdlib.h>

int sumar(int, int, int*);

int main(void) {

	setbuf(stdout, NULL);

	int numeroA;
	int numeroB;
	int resultado;

	numeroA = 5;
	numeroB = 3;

	if(!sumar(numeroA, numeroB, &resultado))
	{
		printf("El resultado es: %d", resultado);
	}


	return EXIT_SUCCESS;
}

int sumar(int numeroA, int numeroB, int* resultado)
{
	int retorno;

	retorno = -1;

	*resultado = numeroA + numeroB;

	retorno = 0;

	return retorno;
}
