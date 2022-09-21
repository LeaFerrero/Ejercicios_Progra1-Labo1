/*
 ============================================================================
 Name        : ejercicio_7-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Ejercicio 7-2: Realizar funciones para validar y obtener:
-Alfanumericos, ej. ab555gT6
-Teléfonos, ej. 4XXX-XXXX

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"

#define ALPHA 5
#define TEL 8

int obtenerAlfaNumerico(char cadena[], int longitud);
int obtenerTelefono(char cadena[], int longitud);

int main(void) {

	setbuf(stdout, NULL);

	char alfanumerico[ALPHA];

	if(obtenerAlfaNumerico(alfanumerico, ALPHA))
	{
		printf("El codigo alfanumerico es: %s", alfanumerico);
	}
	else
	{
		printf("No es alfanumerico.");
	}



	return EXIT_SUCCESS;
}

int obtenerAlfaNumerico(char cadena[], int longitud)
{
    int retorno;
    int i;
    int largo;

	printf("Ingrese un codigo alpfanumerico: ");
	fflush(stdin);
	fgets(cadena, 9, stdin);
	largo = strlen(cadena);
	cadena[largo-1] = '\0';

    retorno = 1;

    if(cadena != NULL && longitud > 0)
    {
		for(i = 0; i < longitud && cadena[i] != '\0'; i++)
		{
			if(!isalnum(cadena[i]))
			{
				retorno = 0;
				break;
			}
		}
    }

    return retorno;
}

int obtenerTelefono(char cadena[], int longitud)
{
    int retorno;
    int i;
    int largo;

	printf("Ingrese un numero de telefono: ");
	fflush(stdin);
	fgets(cadena, 9, stdin);
	largo = strlen(cadena);
	cadena[largo-1] = '\0';

	retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i = 0; i < longitud && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(!isdigit(cadena[i]))
			{
				retorno = 0;
				break;
			}
		}
	}
}
