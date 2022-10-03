/*
 ============================================================================
 Name        : bibliotecas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "general.h"

#define TAM 11


int main(void) {

	setbuf(stdout, NULL);

	char str[TAM];

	if(get_ValidName(str, TAM, "Nombre", "Nope"))
	{
		printf("El numero es: %s", str);
	}
	else
	{
		printf("No se pudo");
	}

	return EXIT_SUCCESS;
}
