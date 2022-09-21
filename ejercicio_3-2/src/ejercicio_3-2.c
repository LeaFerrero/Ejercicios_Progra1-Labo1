/*
 ============================================================================
 Name        : ejercicio_3-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Ejercicio 3-2: Crear una función que pida el ingreso de un flotante y lo retorne.

 */

#include <stdio.h>
#include <stdlib.h>

float pedirNumeroFlotante(void);

int main(void) {

	setbuf(stdout, NULL);

	float numeroFlotante;

	numeroFlotante = pedirNumeroFlotante();

	printf("El numero flotante ingresado es: %.2f", numeroFlotante);

	return EXIT_SUCCESS;
}


float pedirNumeroFlotante(void)
{
	float numero;

	printf("Ingrese un numero flotante: ");
	scanf("%f", &numero);

	return numero;
}
