/*
 ============================================================================
 Name        : ejercicio_2-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 2-3: Usando el concepto de operadores l�gicos booleanos en el condicional.
Solicitar un n�mero al usuario e informar si el n�mero es par o impar.

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	int numero;
	int resultado;

	printf("Ingrese un numero: ");
	scanf("%d", &numero);

	resultado = numero & 0;
	if(resultado)
	{
		printf("El numero es par.");
	}
	else
	{
		printf("El numero es impar.");
	}

	return EXIT_SUCCESS;
}
