/*
 * menu.c
 *
 *  Created on: 8 sep. 2022
 *      Author: wilo waiko
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void menu(char* letra)
{
	char opcion;

	printf("\n\nMENU");
	printf("\nA-Carga de productos.");
	printf("\nB-Venta de productos.");
	printf("\nC-Modificación del precio.");
	printf("\nD-Modificar el modelo.");
	printf("\nE-Listar ordenado por código.");
	printf("\nF-Listar datos de los productos con menos de 3 unidades.");
	printf("\nG-Salir.");
	printf("\nIngrese una opcion: ");
	fflush(stdin);
	scanf("%c", &opcion);

	opcion = toupper(opcion);

	*letra = opcion;
}
