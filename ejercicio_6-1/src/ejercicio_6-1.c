/*
 ============================================================================
 Name        : ejercicio_6-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 6-1: Disponemos de dos variables numéricas (a y b). Realizar un algoritmo
que permita el intercambio de valores de dichas variables.

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int numA;
	int numB;
	int aux;

	numA = 5;
	numB = 3;

	printf("Los numeros antes del swap son: %d %d", numA, numB);

	aux = numA;
	numA = numB;
	numB = aux;

	printf("\nLos numeros despues del swap son: %d %d", numA, numB);

	return EXIT_SUCCESS;
}
