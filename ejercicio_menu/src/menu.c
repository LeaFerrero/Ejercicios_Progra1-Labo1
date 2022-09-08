/*
 * menu.c
 *
 *  Created on: 8 sep. 2022
 *      Author: wilo waiko
 */

#include <stdio.h>
#include <stdlib.h>

char menu(void)
{
	char opcion;

	printf("\n\nMENU");
	printf("\na-Iniciar");
	printf("\nb-Procesar");
	printf("\nc-Finalizar");
	printf("\nd-Salir");
	printf("\nIngrese una opcion: ");
	fflush(stdin);
	scanf("%c", &opcion);

	return opcion;
}
