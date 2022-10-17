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

#define TAM 4


int main(void) {

	setbuf(stdout, NULL);

	char str[TAM];

	get_ValidStingAlphanumeric(str, TAM, "Nombre", "Nope");

	printf("El numero es: %s", str);



	return EXIT_SUCCESS;
}
