/*
 * menus.c
 *
 *  Created on: 12 sep. 2022
 *      Author: wilo waiko
 */

#include <stdio.h>
#include <stdlib.h>


void menuPrincipal(int* opcion)
{
	int buffer;

	printf("\n\nMENU");
	printf("\n1. Loguearse.");
	printf("\n2. Comprar.");
	printf("\n3. Ver mis compras.");
	printf("\n4. Vender.");
	printf("\n5. Salir");
	printf("\nIngrese una opcion: ");
	scanf("%d", &buffer);

	*opcion = buffer;

}void subMenu(int* opcion)
{
	int buffer;
	printf("\n\nMENU DE VENTAS");
	printf("\n1. Vender.");
	printf("\n2. Hacer factura.");
	printf("\n3. Volver atras.");
	printf("\nIngrese una opcion: ");
	scanf("%d", &buffer);

	*opcion = buffer;

}
