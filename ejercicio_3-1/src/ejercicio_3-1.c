/*
 ============================================================================
 Name        : ejercicio_3-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 3-1: Crear una funci�n que muestre por pantalla el n�mero entero que
recibe como par�metro.

 */

#include <stdio.h>
#include <stdlib.h>

void mostrarResultado(int);

int main(void) {

	setbuf(stdout, NULL);

	int numero;

	printf("Ingrese un numero entero: ");
	scanf("%d", &numero);

	mostrarResultado(numero);

	return EXIT_SUCCESS;
}

void mostrarResultado(int numero)
{
	printf("El numero es: %d", numero);
}
