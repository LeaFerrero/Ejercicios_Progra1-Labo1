/*
 ============================================================================
 Name        : ejercicio_4-4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Ejercicios 4-4:
A. Hacer el menú de un programa en el MAIN con las siguientes opciones:
1. Loguearse
2. Comprar
3. Ver mis compras
4. Vender
5. Salir
B. Al menú anterior chequear que no pueda ingresar a ninguna opción si no se logueó.
C. Ahora agregamos, chequear que no pueda ver sus compras, si no ingresó primero a
comprar al menos una vez.
D. Cuando se ingresa a la opción vender del menú, debe abrirse otro menú que contenga:
1. Vender
2. Hacer factura
3. Volver atrás.
E. A lo anterior sumarle que haya compras para poder vender. (Si compré una vez y vendí
una vez no puedo ingresar a vender).
F. Pasar las acciones de menú a funciones y llevarlas a una biblioteca

 */

#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

int main(void) {

	setbuf(stdout, NULL);

	int opcionMenuVentas;
	int opcionMenu;
	int flagLog;
	int contadorCompras;
	int flagVenta;
	int contadorVentas;
	char opcionSalir;

	flagLog = 0;
	flagVenta = 0;
	contadorCompras = 0;
	contadorVentas = 0;
	opcionSalir = 'n';

	do
	{
		menuPrincipal(&opcionMenu);

		switch(opcionMenu)
		{
			case 1: //LOGUEO
				printf("\nSe ha logueado con exito.");
				flagLog = 1;
			break;

			case 2: //COMPRAR
				if(flagLog == 1)
				{
					printf("\nCompra realizada con exio con exito.");
					contadorCompras ++;
				}
				else
				{
					printf("\nDebe loguearse antes de poder comprar.");
				}
			break;

			case 3: //VER COMPRAS
				if(contadorCompras > 0)
				{
					printf("\nLas compras realizadas son: %d", contadorCompras);
				}
				else
				{
					printf("\nDebe comprar antes de poder ver sus compras.");

					if(flagLog == 0)
					{
						printf("\nAdemas todavia no se logueo.");

					}
				}
			break;

			case 4: //VENDER
				do
				{
					subMenu(&opcionMenuVentas);

					switch(opcionMenuVentas)
					{
						case 1:
							if(contadorCompras > 0)
							{
								printf("\nVenta realizada con exito.");
								contadorCompras --;
								flagVenta = 1;
								contadorVentas ++;
							}
							else
							{
								printf("\nNo hay nada que vender.");
							}
						break;

						case 2:
							if(flagVenta == 1)
							{
								printf("\nSe hizo una factura para %d ventas", contadorVentas);
								flagVenta = 0;
								contadorVentas = 0;
							}
							else
							{
								printf("\nNo se reallizaron ventas para hacer una factura");
							}
						break;

						case 3:
							printf("\nVolviendo al menu anterior");
						break;

						default:
							printf("\nOpcion no valida");
					}

				}while(opcionMenuVentas != 3);
			break;

			case 5:
				printf("\n¿Desea salir?(s/n): ");
				fflush(stdin);
				scanf("%c", &opcionSalir);
			break;

			default:
				printf("\nOpcion no valida.");
		}
	}while(opcionSalir != 's');

	return EXIT_SUCCESS;
}
