/*
 ============================================================================
 Name        : ejercicio_9-2-3-4-5-6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 9-2:Una empresa requiere un sistema para administrar su nómina de
empleados. Se sabe que dicha nómina bajo ninguna circunstancia superara los 300
empleados.
El sistema deberá tener el siguiente menú de
opciones:
Ejercicio 9-3:
1. ALTAS: Se debe permitir ingresar un empleado
calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
Ejercicio 9-4:
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar:
Nombre o Apellido o Salario o Sector
Ejercicio 9-5:
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
Ejercicio 9-6:
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.

 */

#include <stdio.h>
#include <stdlib.h>
#include "eEmpleado.h"

#define TAM 300

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	int opcionInformar;
	int cantidad;
	int criterio;

	eEmpleado arrayEmpleados[TAM];

	cantidad = 0;
	criterio = -1;

	eEmpleado_Inicializar(arrayEmpleados, TAM);

	do
	{
		menu(&opcion, "Menu", "\n1. Altas", "\n2. Modificacion", "\n3. Bajas", "\n4. Informar", "\n5. Carga forzada", "\n6. Salir", "", "Ingrese una opcion: ");

		switch(opcion)
		{
			case 1: //Alta
				if(!eEmpleado_Alta(arrayEmpleados, TAM))
				{
					cantidad++;
				}
			break;

			case 2: //Modificacion
				if(cantidad > 0)
				{
					eEmpleado_Modificacion(arrayEmpleados, TAM);
				}
			break;

			case 3: //Baja
				if(cantidad > 0)
				{
					eEmpleado_Baja(arrayEmpleados, TAM);
					cantidad --;
				}
			break;

			case 4: //Informar
				menu(&opcionInformar, "Informes", "\n1. Listado de empleados por apellido y sector", "\n2. Promedio de salarios y cuandos empleados superan el primedio", "", "", "", "", "", "Ingrese una opcion: ");

				switch(opcionInformar)
				{
					case 1:
						if(!eEmpleado_Sort(arrayEmpleados, TAM, criterio))
						{
							eEmpleado_MostrarTodos(arrayEmpleados, TAM);
						}
					break;

					case 2:
						eEmpleado_MostrarPromedio(arrayEmpleados, TAM);
					break;
				}
			break;

			case 5:
				eEmpleado_cadgaForzada(arrayEmpleados, TAM);
				cantidad = 5;
				printf("\nCarga forzada OK\n");
			break;

			case 6:
			break;
		}

	}while(opcion != 6);

	return EXIT_SUCCESS;
}
