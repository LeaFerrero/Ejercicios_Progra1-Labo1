/*
 ============================================================================
 Name        : ejercicio_10-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 10-2: Al ejercicio 9-2 agregar y re factorizar el código, la estructura eSector, que definirá
los siguientes campos:
● idSector (numérico)
● descripcionSector(alfanumérico)
Para esta estructura en principio trabajaremos con datos hardcodeados:
idSector descripcionSector
100 Sistemas
200 RecursosHumanos
300 Administración
400 Gerencia

En informes agregar:
Mostrar el sector con más empleados y listar los mismos.

*/

#include <stdio.h>
#include <stdlib.h>
#include "nexo.h"

#define TAM_EMPLEADOS 300
#define TAM_SECTOR 4

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	int opcionInformar;
	int cantidad;
	int criterio;

	eEmpleado arrayEmpleado[TAM_EMPLEADOS];
	eSector arraySector[TAM_SECTOR];

	cantidad = 0;
	criterio = -1;

	eEmpleado_Inicializar(arrayEmpleado, TAM_EMPLEADOS);
	eSector_Inicializar(arraySector, TAM_SECTOR);
	eSector_CargaForzada(arraySector, TAM_SECTOR);

	do
	{
		grl_Menu(&opcion, "Menu", "\n1. Altas", "\n2. Modificacion", "\n3. Bajas", "\n4. Informar", "\n5. Carga forzada", "\n6. Salir", "", "", "", "Ingrese una opcion");

		switch(opcion)
		{
			case 1: //Alta
				if(!nexo_eEmpleado_Alta(arrayEmpleado, TAM_EMPLEADOS, arraySector, TAM_SECTOR))
				{
					cantidad++;
				}
			break;

			case 2: //Modificacion
				nexo_Modificacion(arrayEmpleado, TAM_EMPLEADOS, arraySector, TAM_SECTOR);
			break;

			case 3: //Baja
				if(cantidad > 0)
				{
					if(!nexo_Baja(arrayEmpleado, TAM_EMPLEADOS, arraySector, TAM_SECTOR))
					{
						cantidad --;
					}
				}
			break;

			case 4: //Informar
				grl_Menu(&opcionInformar, "Informes", "\n1. Listado de empleados por apellido y sector", "\n2. Promedio de salarios y cuandos empleados superan el primedio", "\n3. Mostrar el sector con mas empleados y listar los mismos", "", "", "", "", "", "", "Ingrese una opcion");

				switch(opcionInformar)
				{
					case 1:
						if(!eEmpleado_Sort(arrayEmpleado, TAM_EMPLEADOS, criterio))
						{
							eEmpleado_MostrarTodos(arrayEmpleado, TAM_EMPLEADOS);
						}
					break;

					case 2:
						eEmpleado_MostrarPromedio(arrayEmpleado, TAM_EMPLEADOS);
					break;

					case 3:
						if(!nexo_infeorme(arraySector, TAM_SECTOR, arrayEmpleado, TAM_EMPLEADOS))
						{
							puts("\nNada que mostrar");
						}
					break;
				}
			break;

			case 5:
				eEmpleado_cadgaForzada(arrayEmpleado, TAM_EMPLEADOS);
				cantidad = 5;
				printf("\nCarga forzada OK\n");
			break;

			case 6:
			break;
		}

	}while(opcion != 6);

	return EXIT_SUCCESS;
}
