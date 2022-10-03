/*
 ============================================================================
 Name        : ejercicio_9-4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 9-4:
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar:
Nombre o Apellido o Salario o Sector

 */

#include <stdio.h>
#include <stdlib.h>

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
	int idAux;

	for(i = 0; i < CAN_EMPLEADOS; i++)
	{
		arrayEmpleados[i].isEmpty = TRUE;
	}

	do
	{
		printf("\n\nMENU");
		printf("\n1. Altas");
		printf("\n2. Modificacion");
		printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1: //ALTAS
				for(i = 0; i < CAN_EMPLEADOS; i++)
				{
					if(arrayEmpleados[i].isEmpty == TRUE)
					{
						if(i == 0)
						{
							arrayEmpleados[i].id = 0;
							arrayEmpleados[i].id ++;
						}
						else
						{
							arrayEmpleados[i].id = arrayEmpleados[i-1].id + 1;
						}

						printf("\nIngrese nombre: ");
						scanf("%[^\n]", arrayEmpleados[i].nombre);
						printf("\nIngrese apellido: ");
						scanf("%[^\n]", arrayEmpleados[i].apellido);
						printf("\nIngrese salario: ");
						scanf("%f", &arrayEmpleados[i].salario);
						printf("\nIngrese sector: ");
						scanf("%d", &arrayEmpleados[i].sector);

						printf("\nID: %d", arrayEmpleados[i].id);

						arrayEmpleados[i].isEmpty = FALSE;
					}
				}
			break;

			case 2: //MODIFICACION
				printf("\nIngrese el id: ");
				scanf("%d", idAux);

				for(i = 0; i < CAN_EMPLEADOS; i++);
				{
					if(idAux == arrayEmpleados[i].id)
					{

					}
				}

			break;

			default:
				printf("\nOpcion no valida.");
		}


	}while(opcion != 5);


	return EXIT_SUCCESS;
}
