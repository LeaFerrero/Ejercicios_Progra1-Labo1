/*
 ============================================================================
 Name        : ejercicio_3-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 3-3: Crear una funci�n que permita determinar si un n�mero es par o no. La
funci�n retorna 1 en caso afirmativo y 0 en caso contrario. Probar en el main.

 */

#include <stdio.h>
#include <stdlib.h>

int determinarParImpar(int);

int main(void) {

	setbuf(stdout, NULL);

	int numero;
	int parImpar;

	printf("Ingrese un numero: ");
	scanf("%d", &numero);

	parImpar = determinarParImpar(numero);

	if(parImpar == 1)
	{
		printf("El numero %d es par.", numero);
	}
	else
	{
		printf("El numero %d es impar.", numero);
	}

	return EXIT_SUCCESS;
}

int determinarParImpar(int numero)
{
	int retorno;

	if((numero % 2) == 0)
	{
		retorno = 1;
	}
	else
	{
		retorno = 0;
	}

	return retorno;
}
