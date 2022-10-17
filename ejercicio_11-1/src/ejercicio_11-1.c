/*
 ============================================================================
 Name        : ejercicio_11-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Ejercicio 11-1: Realizar una función que reciba un puntero a char y dos char. La función
deberá reemplazar en la cadena cada ocurrencia del primer carácter recibido, por el
segundo. Retornando la cantidad de reemplazos o -1 en caso de error.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cambiarCaracteres(char*, char, char);

int main(void) {

	setbuf(stdout, NULL);

	char string[] = {"Asterisco"};
	char* pChar = NULL;
	char charA;
	char charB;

	pChar = string;
	charA = 's';
	charB = 'P';

	printf("Esta es la cadena: %s", string);

	if(!cambiarCaracteres(pChar, charA, charB))
	{
		printf("\nEsta es la cadena ahora: %s", string);
	}

	return EXIT_SUCCESS;
}

int cambiarCaracteres(char* pChar, char charA, char charB)
{
	int isError;
	int largo;
	int i;

	isError = -1;

	if(pChar != NULL)
	{
		isError = 1;
		largo = strlen(pChar);

		for(i = 0; i < largo; i++)
		{
			if(*(pChar+i) == charA)
			{
				*(pChar+i) = charB;
			}
		}

		isError = 0;
	}

	return isError;
}
