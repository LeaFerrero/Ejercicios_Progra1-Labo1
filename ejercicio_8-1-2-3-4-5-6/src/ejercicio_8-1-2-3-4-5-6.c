/*
 ============================================================================
 Name        : ejercicio_8-1-2-3-4-5-6-7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Tema 8 (Arrays Paralelos)
Ejercicio 8-1:De 20 productos se carga:
- Código(alfanumérico 4 caracteres),
- Modelo (máximo 10 char),
- Cantidad,
- Precio(float)
Se pide que por medio de un menú de opciones se permita hacer lo siguiente
A) Carga de productos
Ejercicio 8-2:
B) Venta de productos
Ejercicio 8-3:
C) Modificación del precio
Ejercicio 8-4:
D) Modificar el modelo
Ejercicio 8-5:
E) Listar ordenado por código
Ejercicio 8-6:
F) Listar datos de los productos con menos de 3 unidades

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "general.h"

#define CANT 2
#define TAM_CODIGO 5
#define TAM_MODELO 11

void init_Array(int cantidad[], int len);

void mostrar_Arrays(char codigo[][TAM_CODIGO], char modelo[][TAM_MODELO], int cantidad[], float precio[], int len);

void ordenar_ArraysCodigo(char codigo[][TAM_CODIGO], char modelo[][TAM_MODELO], int cantidad[], float precio[], int len);

void mostrar_ArraysMasDeTres(char codigo[][TAM_CODIGO], char modelo[][TAM_MODELO], int cantidad[], float precio[], int len);

int main(void) {

	setbuf(stdout, NULL);

	char codigo[CANT][TAM_CODIGO];
	char modelo[CANT][TAM_MODELO];
	int cantidad[CANT];
	float precio[CANT];

	int i;
	int opcion;
	int index;
	int vender;

	init_Array(cantidad, CANT);

	do
	{
		menu(&opcion, "MENU", "\n1. Carga", "\n2. Venta", "\n3. Modificar precio", "\n4. Modificar modelo",
				"\n5. Listar ordenado por código", "\n6. Listar datos de los productos con menos de 3 unidades",
				"\n7. Salir", "Ingrese una opcion: ");

		switch(opcion)
		{
			case 1: //CARGA

				for(i = 0; i<CANT; i++)
				{
					if(cantidad[i] == 0)
					{
						get_ValidStingAlphanumeric(codigo[i], TAM_CODIGO, "\nIngrese el codigo", "Error. Codigo no valido");
						get_ValidStingLetters(modelo[i], TAM_MODELO, "\nIngrese el modelo", "Error, modelo no valido");
						get_ValidIntPositive(&cantidad[i], "\nIngrese una cantidad", "Error, cantidad no valida");
						get_ValidFloat(&precio[i], "\nIngrese el precio", "Error, precio no valido", 1.00, 10.00);
					}
				}
			break;

			case 2: //VENTA
				mostrar_Arrays(codigo, modelo, cantidad, precio, CANT);

				get_ValidInt(&index, "\nIngrese el infice", "Error, indice no valido", 0, 1);

				for(i = 0; i<CANT; i++)
				{
					if(index == i && cantidad[i] != 0)
					{
						get_ValidInt(&vender, "Ingrese la cantidad a vender", "Error, cantidad no valida", 1, cantidad[i]);
						cantidad[i] -= vender;
						printf("\nVendiste");
					}
				}

			break;

			case 3: //MODIFICAR PRECIO
				mostrar_Arrays(codigo, modelo, cantidad, precio, CANT);

				get_ValidInt(&index, "\nIngrese el infice", "Error, indice no valido", 0, 1);

				for(i = 0; i<CANT; i++)
				{
					if(index == i && cantidad[i] != 0)
					{
						get_ValidFloat(&precio[i], "\nIngrese el precio", "Error, precio no valido", 1.00, 10.00);
						printf("\nModificado");
					}
				}
			break;

			case 4: //MODIFICAR MODELO
				mostrar_Arrays(codigo, modelo, cantidad, precio, CANT);

				get_ValidInt(&index, "\nIngrese el infice", "Error, indice no valido", 0, 1);

				for(i = 0; i<CANT; i++)
				{
					if(index == i && cantidad[i] != 0)
					{
						get_ValidStingLetters(modelo[i], TAM_MODELO, "\nIngrese el modelo", "Error, modelo no valido");
						printf("\nModificado");
					}
				}
			break;
			case 5: //LISTA ORDENADO POR CODIGO
				ordenar_ArraysCodigo(codigo, modelo, cantidad, precio, CANT);
				mostrar_Arrays(codigo, modelo, cantidad, precio, CANT);
			break;
			case 6:
				mostrar_ArraysMasDeTres(codigo, modelo, cantidad, precio, CANT);
			break;
			case 7:
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

void mostrar_Arrays(char codigo[][TAM_CODIGO], char modelo[][TAM_MODELO], int cantidad[], float precio[], int len)
{
	int i;

	printf("\n%10s %10s %10s %10s %10s", "Indice", "Codigo", "Modelo", "Cantidad", "Precio");
	for(i = 0; i<len; i++)
	{
		if(cantidad[i] != 0)
		{
			printf("\n%10d %10s %10s %10d %10.2f", i, codigo[i], modelo[i], cantidad[i], precio[i]);
		}
	}
}

void mostrar_ArraysMasDeTres(char codigo[][TAM_CODIGO], char modelo[][TAM_MODELO], int cantidad[], float precio[], int len)
{
	int i;

	printf("\n%10s %10s %10s %10s %10s", "Indice", "Codigo", "Modelo", "Cantidad", "Precio");
	for(i = 0; i<len; i++)
	{
		if(cantidad[i] != 0 && cantidad[i] > 3)
		{
			printf("\n%10d %10s %10s %10d %10.2f", i, codigo[i], modelo[i], cantidad[i], precio[i]);
		}
	}
}

void ordenar_ArraysCodigo(char codigo[][TAM_CODIGO], char modelo[][TAM_MODELO], int cantidad[], float precio[], int len)
{
	char auxiliar[30];
	int auxCant;
	float auxPrecio;

	for(int i = 0; i< len - 1; i++)
	{
		for(int j = i+1; j< len; j++)
		{
			if(strcmp(codigo[i], codigo[j]) > 0)
			{
				strcpy(auxiliar, codigo[i]);
				strcpy(codigo[i], codigo[j]);
				strcpy(codigo[j], auxiliar);

				strcpy(auxiliar, modelo[i]);
				strcpy(modelo[i], modelo[j]);
				strcpy(modelo[j], auxiliar);

				auxCant = cantidad[i];
				cantidad[i] = cantidad[j];
				cantidad[j] = auxCant;

				auxPrecio = precio[i];
				precio[i] = precio[j];
				precio[j] = auxPrecio;
			}
		}
	}
}
