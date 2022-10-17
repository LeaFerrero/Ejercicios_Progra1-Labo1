/*
 ============================================================================
 Name        : ejercicio_8-7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 8-7: Realizar un programa con un menú de opciones que permita hacer altas
y bajas de un máximo de 30 productos. Los datos que se ingresan son Código, fecha
de ingreso y descripción. El código es una cadena de caracteres de 5 dígitos, y la
descripción no puede exceder los 15 caracteres.
Se deben usar funciones para validar los datos. El Código no puede repetirse, en el
caso de ingresar un código existente de debe informar y no dejar ingresar el resto de
los datos.

 */

#include <stdio.h>
#include <stdlib.h>
#include "general.h"

#define CANT 3

#define TAM
#define TAM_CODIGO 5
#define TAM_DESCRIPCION 15

void init_Array(int cantidad[], int len);

void mostrar_Arrays(int ocupado[], char codigo[][TAM_CODIGO], char descripcion[][TAM_DESCRIPCION], int dia[], int mes[], int anio[], int len);
int obtener_CodigoUnico(char codigo[][TAM_CODIGO], int index, int len, char mensaje[], char mensajeError[], char mensajeErrorDos[]);
int verificar_NoRepetido(char codigo[][TAM_CODIGO], char aux[],  int len);

int main(void) {

	setbuf(stdout, NULL);

	char codigo[CANT][TAM_CODIGO];
	char descripcion[CANT][TAM_DESCRIPCION];
	int dia[CANT];
	int mes[CANT];
	int anio[CANT];
	int ocupado[CANT];


	int i;
	int opcion;
	int index;

	init_Array(ocupado, CANT);

	do
	{
		menu(&opcion, "MENU", "\n1. Altas", "\n2. Bajas", "", "", "", "", "\n7. Salir", "Ingrese una opcion: ");

		switch(opcion)
		{
			case 1: //ALTA

				for(i = 0; i<CANT; i++)
				{
					if(ocupado[i] == 0)
					{
						obtener_CodigoUnico(codigo, i, TAM_CODIGO, "\nIngrese el codigo", "Error, modelo no codigo", "Error, ese codigo ya existe");
						get_ValidStingLetters(descripcion[i], TAM_DESCRIPCION, "\nIngrese la descripcion", "Error, descripcion no valida");
						get_ValidInt(&dia[i], "Ingrese un dia", "Error, dia no valido", 1, 31);
						get_ValidInt(&mes[i], "Ingrese un mes", "Error, mes no valido", 1, 12);
						get_ValidInt(&anio[i], "Ingrese un año", "Error, año no valido", 1900, 2100);
						ocupado[i] = 1;
					}
				}
			break;

			case 2: //BAJA
				mostrar_Arrays(ocupado, codigo, descripcion, dia, mes, anio, CANT);

				get_ValidInt(&index, "\nIngrese el infice", "Error, indice no valido", 0, 1);

				for(i = 0; i<CANT; i++)
				{
					if(index == i && ocupado[i] == 1)
					{
						ocupado[i] = 0;
						printf("\nBaja aceptada");
					}
				}

			break;

			case 3:
				printf("\nAdios");
			break;

			default:
				printf("\nOpcion no valida");
		}

	}while(opcion != 7);

	return EXIT_SUCCESS;
}

void init_Array(int cantidad[], int len)
{
	int i;

	for(i = 0; i<len; i++)
	{
		cantidad[i] = 0;
	}
}

void mostrar_Arrays(int ocupado[], char codigo[][TAM_CODIGO], char descripcion[][TAM_DESCRIPCION], int dia[], int mes[], int anio[], int len)
{
	int i;

	printf("\n%10s %10s %10s %10s %10s %10s", "Indice", "Codigo", "Descriocion", "Dia", "Mes", "Año");
	for(i = 0; i<len; i++)
	{
		if(ocupado[i] == 1)
		{
			printf("\n%10d %10s %10s %10d %10d %10d", i, codigo[i], descripcion[i], dia[i], mes[i], anio[i]);
		}
	}
}

int obtener_CodigoUnico(char codigo[][TAM_CODIGO], int index, int len, char mensaje[], char mensajeError[], char mensajeErrorDos[])
{
	int retorno;
	char aux[TAM_CODIGO];

	retorno = -1;

	if(codigo != NULL)
	{
		retorno = 0;

		do
		{
			if(get_ValidStingAlphanumeric(aux, TAM_CODIGO, mensaje, mensajeError) == 1 && verificar_NoRepetido(codigo, aux, len) == 0)
			{
				strcpy(codigo[index], aux);
				retorno = 1;
				break;
			}

			printf("\n%s", mensajeErrorDos);
		}
		while(retorno == 0);

	}

	return retorno;
}

int verificar_NoRepetido(char codigo[][TAM_CODIGO], char aux[],  int len)
{
	int retorno;
	int i;

	retorno = -1;

	if(codigo != NULL)
	{
		retorno = 0;

		for(i = 0; i < len; i++)
		{
			if(stricmp(codigo[i], aux) == 0)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

