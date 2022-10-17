/*
 * eEmpleado.c
 *
 *  Created on: 4 oct. 2022
 *      Author: wilo waiko
 */

#include "eEmpleado.h"

static int eEmpleado_ObtenerID(void);
static int eEmpleado_ObtenerID(void)
{

	static int eEmpleado_idIncremental = 1;
	return eEmpleado_idIncremental++;
}

int eEmpleado_GetID(void)
{
	int id;

	id = eEmpleado_ObtenerID();

	return id;
}

int eEmpleado_Inicializar(eEmpleado array[], int len)
{
	int isError;
	int i;

	isError = -1;

	if (array != NULL && len > 0)
	{
		isError = 1;

		for (i = 0; i < len; i++)
		{

			array[i].isEmpty = LIBRE;
			isError = 0;
		}
	}

	return isError;
}

int eEmpleado_ObtenerIndexLibre(eEmpleado array[], int len)
{
	int index = -1;
	int i;


	if (array != NULL && len > 0)
	{

		for (i = 0; i < len; i++)
		{

			if (array[i].isEmpty == LIBRE)
			{

				index = i;
				break;
			}
		}
	}

	return index;
}

int eEmpleado_BuscarPorID(eEmpleado array[], int len, int id)
{
	int index = -1;
	int i;


	if (array != NULL && len > 0)
	{

		for (i = 0; i < len; i++)
		{
			if (array[i].id == id && array[i].isEmpty == OCUPADO)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int eEmpleado_ValidID(eEmpleado* array, int len, int* idAux)
{
	int isError;;
	int auxilliar;

	isError = -1;

	if(array != NULL && len > 0)
	{
		isError = 1;
		do
		{
			if(!grl_Get_ValidInt(&auxilliar, "\nIngrese el id a buscar", "Error, id no valido") && eEmpleado_BuscarPorID(array, len, auxilliar) != -1)
			{
				*idAux = auxilliar;
				isError = 0;
				break;
			}
			printf("El id no existe");

		}
		while(grl_MenuSN("\n¿Ingresar otro id?") == 1);
	}

	return isError;
}


void eEmpleado_MostrarUno(eEmpleado one)
{

	printf("%10d %10s %10s %10.2f %5d\n", one.id, one.name, one.lastName, one.salary, one.sector);
}

int eEmpleado_MostrarTodos(eEmpleado array[], int len)
{
	int isError;
	int i;
	int cantidad = 0;

	isError = -1;


	if (array != NULL && len > 0)
	{

		puts("\n\t> LISTADO Gen");
		printf("%10s %10s %10s %10s %10s\n\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)


		for (i = 0; i < len; i++)
		{

			if (array[i].isEmpty == OCUPADO)
			{
				eEmpleado_MostrarUno(array[i]);

				cantidad++;
			}
		}
	}


	if (cantidad > 0)
	{
		isError = 0;
	}

	return isError;
}

int eEmpleado_Contador(eEmpleado* array, int len, int* total)
{
	int isError;
	int i;

	isError = -1;

	if(array != NULL && len > 0)
	{
		*total = 0;

		for(i = 0; i < len; i++)
		{
			if(array[i].isEmpty == OCUPADO)
			{
				(*total) ++;
			}
		}

		isError = 0;
	}

	return isError;
}

int eEmpleado_Acumulador(eEmpleado* array, int len, float* total)
{
	int isError;
	int i;

	isError = -1;

	if(array != NULL && len > 0)
	{
		*total = 0;
		for(i = 0; i < len; i++)
		{
			if(array[i].isEmpty == OCUPADO)
			{
				(*total) += array[i].salary;
			}
		}

		isError = 0;
	}

	return isError;
}

int eEmpleado_PromedioSalario(eEmpleado* array, int len, float* promedio)
{
	int isError;
	int totalEmpleados;
	float totalSalario;

	isError =- 1;

	if(array != NULL && len > 0)
	{
		isError = 1;
		eEmpleado_Contador(array, len, &totalEmpleados);
		eEmpleado_Acumulador(array, len, &totalSalario);

		if(totalEmpleados > 0)
		{
			*promedio = totalSalario / totalEmpleados;
			isError = 0;
		}
	}

	return isError;
}

int eEmpleado_ContadorMayor(eEmpleado* array, int len, float promedio, int* total)
{
	int isError;
	int i;

	isError = -1;

	if(array != NULL && len > 0)
	{
		*total = 0;
		for(i = 0; i < len; i++)
		{
			if(array[i].isEmpty == OCUPADO)
			{
				if(array[i].salary > promedio)
				{
					(*total) ++;
				}
			}
		}

		isError = 0;
	}

	return isError;
}

void eEmpleado_MostrarPromedio(eEmpleado* array, int len)
{
	float promedio;
	int superiores;

	eEmpleado_PromedioSalario(array, len, &promedio);
	eEmpleado_ContadorMayor(array, len, promedio, &superiores);

	printf("\nEl salario promedio es: %.2f", promedio);
	printf("\nLa cantidad de empleados superiores es de: %d", superiores);


}

int eEmpleado_Sort(eEmpleado array[], int len, int criterio)
{
	int	isError;
	int i;
	int j;
	eEmpleado aux;

	isError = -1;

	if (array != NULL && len > 0)
	{
		isError = 1;

		switch (criterio)
		{
			case -1:
				for (i = 0; i < len - 1; i++)
				{
					for (j = i + 1; j < len; j++)
					{
						if (array[i].isEmpty == OCUPADO && array[j].isEmpty == OCUPADO)
						{
							if (stricmp(array[i].lastName, array[j].lastName) > 0)
							{
								aux = array[i];
								array[i] = array[j];
								array[j] = aux;
							}
							if (stricmp(array[i].lastName, array[j].lastName) == 0)
							{
								if(array[i].sector > array[j].sector)
								{
									aux = array[i];
									array[i] = array[j];
									array[j] = aux;

								}
							}
						}
					}
				}
				isError = 0;
			break;
		case 1:
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if (array[i].isEmpty == OCUPADO && array[j].isEmpty == OCUPADO)
					{
						if (stricmp(array[i].lastName, array[j].lastName) < 0)
						{
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
						if (stricmp(array[i].lastName, array[j].lastName) == 0)
						{
							if(array[i].sector < array[j].sector)
							{
								aux = array[i];
								array[i] = array[j];
								array[j] = aux;

							}
						}
					}
				}
			}
			isError = 0;
			break;
		default:
			isError = 1;
			break;
		}
	}
	return isError;
}

int eEmpleado_cadgaForzada(eEmpleado* array, int len)
{
	int isError;

	isError = -1;

	if(array != NULL && len > 0)
	{
		isError = 1;
		int i;
		char name[5][51] = {"Lotus", "Teshin", "Nef", "Cressa", "Khal"};
		char lastName[5][51] = {"Spacemom", "Dax", "Anyo", "Tal", "Garrison"};
		float salary[5] = {500, 100, 200, 300, 100};
		int sector[5] = {400, 200, 100, 200, 200};

		for(i = 0;  i < 5; i++)
		{
			array[i].id = eEmpleado_ObtenerID();
			strcpy(array[i].name, name[i]);
			strcpy(array[i].lastName, lastName[i]);
			array[i].salary = salary[i];
			array[i].sector = sector[i];
			array[i].isEmpty = OCUPADO;
		}

		isError = 0;
	}

	return isError;
}
