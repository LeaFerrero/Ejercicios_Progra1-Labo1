/*
 ============================================================================
 Name        : ejercicio_2-6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 2-6:
Ingresar 5 caracteres e informar cuantas letras m (minúsculas) se ingresaron.

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	char caracter;
	int contador;
	int i;

	contador = 0;

	for(i = 0; i < 5; i++)
	{
		printf("Ingrese un caracter: ");
		fflush(stdin);
		scanf("%c", &caracter);

		if(caracter == 'n')
		{
			contador++;
		}
	}

	printf("Se ingresaron %d letra/s 'm'.", contador);

	return EXIT_SUCCESS;
}
