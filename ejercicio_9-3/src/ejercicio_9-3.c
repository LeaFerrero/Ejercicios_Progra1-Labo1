/*
 ============================================================================
 Name        : ejercicio_9-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 9-3:
El sistema deberá tener el siguiente menú de
opciones:
1. ALTAS: Se debe permitir ingresar un empleado
calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.

 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "entradas.h"

#define TRUE 1
#define FALSE 0
#define CAN_EMPLEADOS 3


typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;

}eEmpleado;

int main(void) {

	setbuf(stdout, NULL);

	eEmpleado arrayEmpleados[CAN_EMPLEADOS];
	int opcion;
	int i;
	int id;

	id = 0;

	for(i = 0; i < CAN_EMPLEADOS; i++)
	{
		arrayEmpleados[i].isEmpty = TRUE;
	}

	do
	{
		menu(&opcion, "Menu", "\n1. Altas", "\n2. Bajas", "\n3. Modificaciones", "", "", "", 1, 3);

		switch(opcion)
		{
			case 1:
				for(i = 0; i < CAN_EMPLEADOS; i++)
				{
					if(arrayEmpleados[i].isEmpty == TRUE)
					{

						arrayEmpleados[i].id = id++;

						printf("\nIngrese nombre: ");
						scanf("%[^\0]", arrayEmpleados[i].nombre);
						printf("\nIngrese apellido: ");
						scanf("%[^\0]", arrayEmpleados[i].apellido);
						printf("\nIngrese salario: ");
						scanf("%f", &arrayEmpleados[i].salario);
						printf("\nIngrese sector: ");
						scanf("%d", &arrayEmpleados[i].sector);

						arrayEmpleados[i].isEmpty = FALSE;
					}
				}
			break;

			default:
				printf("\nOpcion no valida.");
		}


	}while(opcion != 5);


	return EXIT_SUCCESS;
}
