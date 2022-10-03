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
#include "entradas.h"
#include "menu.h"


#define TAM 5

int main(void) {

	setbuf(stdout, NULL);

	int numero;
	int opcionMaximaMenu;

	opcionMaximaMenu = 2;

	if(menu(&numero, "Cases", "\nCase 1", "\nCase 2", "", "", "", ""))
	{
		switch(numero)
		{
			case 1:
				printf("\nCASE 1");
			break;
			case 2:
				printf("\nCASE 2");
			break;
		}
	}

	return EXIT_SUCCESS;
}
