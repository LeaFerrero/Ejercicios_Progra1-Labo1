/*
 ============================================================================
 Name        : ejercicio_7-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 7-3: Realizar las siguientes funciones:

int esLetraConEspacio(char *pResultado);
int esSoloLetra(char *pResultado);
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 11

/**
* \brief valida que la cadena son solo letras y espacio en el medio
* \param cadena es un puntero al espacio de memoria donde se dejara el
resultado de la funcion
* return Retorna 1 si tod ok, 0, SI ES ERROR.
*/
int esLetraConEspacio(char *pResultado);

/**
* \brief valida que la cadena son solo letras
* \param cadena es un puntero al espacio de memoria donde se dejara el
resultado de la funcion
* return Retorna 1 si tod ok, 0, SI ES ERROR.
*/
int esSoloLetra(char *pResultado);


int main(void) {

	setbuf(stdout, NULL);

	char string[LEN];
	int largo;

	printf("Ingrese una cadena de 10 caracteres: ");

	fgets(string, LEN, stdin);

	largo = strlen(string);

	if(string[largo-1] == '\n')
	{
		string[largo-1] = '\0';
	}


	if(esLetraConEspacio(string) == 1)
	{
		printf("\nEs solo letras con espacio");
	}
	else
	{
		printf("\nNo es solo letras con espacio");
	}

	if(esSoloLetra(string) == 1)
	{
		printf("\nEs solo letras");
	}
	else
	{
		printf("\nNo es solo letras");
	}
	return EXIT_SUCCESS;
}

int esLetraConEspacio(char *pResultado)
{
	int retorno;
	int i;
	int largo;
	int flag;

	largo = strlen(pResultado);
	flag = 0;

	retorno = -1;

	if(pResultado != NULL)
	{
		retorno = 1;

		for(i = 0; i < largo && pResultado[i] != '\0'; i++)
		{
			if(isspace(pResultado[i]) && flag == 0)
			{
				flag = 1;
				continue;
			}
			if(!isalpha(pResultado[i]))
			{
				retorno = 0;
				break;
			}
		}
	}

return retorno;
}

int esSoloLetra(char *pResultado)
{
	int retorno;
	int i;
	int largo;

	largo = strlen(pResultado);

	retorno = -1;

	if(pResultado != NULL)
	{
		retorno = 1;

		for(i = 0; i < largo && pResultado[i] != '\0'; i++)
		{
			if(!isalpha(pResultado[i]))
			{
				retorno = 0;
				break;
			}
		}
	}

return retorno;
}
