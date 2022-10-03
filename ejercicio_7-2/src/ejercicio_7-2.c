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
#define TEL 10

int obtenerAlfaNumerico(char cadena[], int longitud);
int obtenerTelefono(char cadena[], int longitud);
void formatearTelefono(char[], char[]);

int main(void) {

	setbuf(stdout, NULL);

	char alfanumerico[ALPHA];
	char telefono[TEL];

	if(obtenerAlfaNumerico(alfanumerico, ALPHA))
	{
		printf("\nEl codigo alfanumerico es: %s\n\n", alfanumerico);
	}
	else
	{
		printf("\nNo es alfanumerico.\n");
	}

	if(obtenerTelefono(telefono, TEL) == 1)
	{
		printf("\nEs un numero de telefono %s\n", telefono);
	}
	else
	{
		printf("\nNo es un numero de telefono.\n");
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

int obtenerTelefono(char telefono[], int longitud)
{
    int retorno;
    int i;
    int largo;
    char auxTelefono[50];

	printf("Ingrese un numero de telefono: ");
	fflush(stdin);
	fgets(auxTelefono, longitud, stdin);
	largo = strlen(auxTelefono);

	if(auxTelefono[largo-1] == '\n')
	{
		auxTelefono[largo-1] = '\0';
	}

	largo = strlen(auxTelefono);

	retorno = -1;

	if(auxTelefono != NULL && longitud > 0)
	{
		if(largo == 8)
		{
			retorno = 1;

			for(i = 0; i < largo && auxTelefono[i] != '\0'; i++)
			{
				if((i == 0 && auxTelefono[i] != '4') || !isdigit(auxTelefono[i]))
				{
					retorno = 0;
					break;
				}
			}
			formatearTelefono(auxTelefono, telefono);
		}
	}

	return retorno;
}

void formatearTelefono(char auxTelefono[], char telefono[])
{
	char aux[10];
	int largo;
	int i;
	int j;

	j = 0;
	largo = strlen(auxTelefono);


	for(i = 0; i <= largo; i++)
	{
		if(i != 4)
		{
			aux[i] = auxTelefono[j];

			j++;
		}
		else
		{
			aux[i] = '-';
		}
	}

	strcpy(telefono, aux);
}
