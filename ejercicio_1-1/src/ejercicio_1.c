/*
 ============================================================================
 Name        : ejercicio_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 1-1: Ingresar dos números enteros entre -50 y 100, sumarlos y mostrar el
resultado. Ejemplo: Si ingresamos 3 y 2 el programa mostrará: “La suma entre 3 y 2
da como resultado 5”

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	int primerNumero;
	int segundoNumero;
	int suma;

	printf("Ingrese el primer numero: ");
	scanf("%d", &primerNumero);

	while(primerNumero < -50 || primerNumero > 100 )
	{
		printf("Error. Ingrese el primer numero nuevamete: ");
		scanf("%d", &primerNumero);
	}

	printf("Ingrese el segundo numero: ");
	scanf("%d", &segundoNumero);

	while(primerNumero < -50 || segundoNumero > 100 )
	{
		printf("Error. Ingrese el segundo numero nuevamete: ");
		scanf("%d", &segundoNumero);
	}

	suma = primerNumero + segundoNumero;

	printf("La suma entre %d y %d da como resultado %d ", primerNumero, segundoNumero, suma);

	return EXIT_SUCCESS;
}
