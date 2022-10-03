/*
 ============================================================================
 Name        : ejercicio_8-1.c
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
#include <ctype.h>


#define CAN 1

int main(void) {

	setbuf(stdout, NULL);

	char opcion;
	char codigo[CAN][5];
	char modelo[CAN][11];
	int cantidad[CAN];
	float precio[CAN];
	char respuesta;
	int i;
	i = 0;

	do
	{
		menu(&opcion);

		switch(opcion)
		{
			case 'A': //CARGA
				for(i=0; i<CAN; i++)
				{
					getValidStingAlfanumerico(codigo[i], 5, "Ingrese el codigo", "Error");


				}

				for(i=0; i<CAN; i++)
				{
					printf("%s %d", codigo[i], strlen(codigo[i]));
				}
			break;

			case 'B': //VENTAS
			break;

			case 'C': //MODIFICAR PRECIO
			break;

			case 'D': //MODIFICAR MODELO
			break;

			case 'E': //LISTAR ORDENADO POR CODIGO

				printf("MODELO\tPRECIO\n");


			break;

			case 'F': //LISTAR DATOS CON MENOS DE 3 UNIDADES
			break;

			case 'G':

			break;

			default:
				printf("\nLa opcion no es valida");
		}

	}while(respuesta != 'S');



	return EXIT_SUCCESS;
}
