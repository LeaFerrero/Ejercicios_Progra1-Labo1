/*
 * nexo.c
 *
 *  Created on: 7 oct. 2022
 *      Author: wilo waiko
 */
#include "nexo.h"


int nexo_CargarDatos(eEmpleado* pAuxilliar, eSector* eSectorList, int eSectorLen)
{
	int isError;

	isError = -1;

	if(pAuxilliar != NULL && eSectorList != NULL && eSectorLen > 0)
	{
		isError = 1;

		if(!grl_Get_ValidName(pAuxilliar->name, LEN_NAME, "\nIngrese un nombre", "Error. Nombre no valido") &&
			!grl_Get_ValidName(pAuxilliar->lastName, LEN_LASTNAME, "\nIngrese un apellido", "Error. apellido no valido") &&
			!eSector_ShowAll(eSectorList, eSectorLen))
		{
			puts("\nIngrese un tipo");
			if(!eSector_ObtainValidID(eSectorList, eSectorLen, &pAuxilliar->sector))
			{
				isError = 0;
			}
		}
	}

	return isError;
}


int nexo_eEmpleado_Alta(eEmpleado* eEmpleadoList, int eEmpleadoLen, eSector* eSectorList, int eSectorLen)
{
	eEmpleado auxilliar;
	int isError;
	int index;

	isError = -1;

	if(eEmpleadoList != NULL && eEmpleadoLen > 0 && eSectorList != NULL && eSectorLen > 0)
	{
		isError = 1;

		index = eEmpleado_ObtenerIndexLibre(eEmpleadoList, eEmpleadoLen);

		if (index != -1)
		{
			isError = 2;

			if(!nexo_CargarDatos(&auxilliar, eSectorList, eSectorLen))
			{
				auxilliar.id = eEmpleado_GetID();

				auxilliar.isEmpty = OCUPADO;

				eEmpleadoList[index] = auxilliar;

				isError = 0;
			}
		}
	}

	return isError;
}


void nexo_MostrarUno(eEmpleado unEmpleado, eSector* arraySector, int lenSector)
{
	int id;
	int aux;

	id = unEmpleado.sector;
	aux = nexo_BuscarPorID(arraySector, lenSector, id);
	printf("%d", id);

	printf("%10d %10s %10s %10.2f %5s\n", unEmpleado.id, unEmpleado.name, unEmpleado.lastName, unEmpleado.salary, arraySector[aux].descripcion);
}

int nexo_MostrarTodos(eEmpleado* array, int len, eSector* arraySector, int lenSectorr)
{
	int isError;
	int i;
	int cantidad = 0;

	isError = -1;


	if (array != NULL && len > 0)
	{

		puts("\n\t> LISTADO");
		printf("%10s %10s %10s %10s %10s\n\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
		//Recorro todo el array
		for (i = 0; i < len; i++)
		{

			if (array[i].isEmpty == OCUPADO)
			{

				nexo_MostrarUno(array[i], arraySector, lenSectorr);

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

int nexo_BuscarPorID(eSector* array, int len, int id)
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

int nexo_Baja(eEmpleado* arrayEmpleados, int lenEmpleados, eSector* arrayEsector, int lenSector)
{
	int isError;
	int idAux;
	int index;
	int flag = 0;

	isError = -1;

	if(arrayEmpleados != NULL && lenEmpleados > 0)
	{
		isError = 1;
		if (!nexo_MostrarTodos(arrayEmpleados, lenEmpleados, arrayEsector, lenSector))
		{
			flag = 1;
		}

		if (flag)
		{
			if(eEmpleado_ValidID(arrayEmpleados, lenEmpleados, &idAux) == 0)
			{
				index = eEmpleado_BuscarPorID(arrayEmpleados, lenEmpleados, idAux);

				if(grl_MenuSN("¿Confirmar Baja?") == 1)
				{
					arrayEmpleados[index].isEmpty = LIBRE;
					isError = 0;
				}
			}
		}
	}

	return isError;
}


eEmpleado nexo_ModificarUno(eEmpleado one, eSector* arraySector, int lenSector)
{
	eEmpleado auxiliar = one;

	int opcion;

	grl_Menu(&opcion, "Seleccione que quiere modificar", "\n1. Nombre", "\n2. Apellido", "\n3. Salario", "\n4. Sector", "", "", "", "", "", "Elija una opcion");

	switch(opcion)
	{
		case 1: //Nombre
			grl_Get_ValidName(auxiliar.name, LEN_NAME, "\nIngrese un nombre", "Error, nombre no valido");
		break;

		case 2: //Apellido
			grl_Get_ValidName(auxiliar.lastName, LEN_LASTNAME, "Ingrese un Apellido", "Error, apellido no valido");
		break;

		case 3: //Salario
			grl_Get_ValidFloatRange(&auxiliar.salary, "Ingrese un salario", "Error, salario no valido", MIN_FLOAT, MAX_FLOAT);
		break;

		case 4: //Sector

			eSector_ShowAll(arraySector, lenSector);
			puts("\nIngrese un tipo");
			eSector_ObtainValidID(arraySector, lenSector, &auxiliar.sector);

		break;
	}
	return auxiliar;
}

int nexo_Modificacion(eEmpleado* arrayEmpleado, int lenEmpleado, eSector* arraySector, int lenSector)
{
	int isError;
	int idGen;
	int index;
	int flag = 0;
	eEmpleado auxiliar;

	isError = -1;

	if(arrayEmpleado != NULL && lenEmpleado > 0)
	{
		isError = 1;

		if (!nexo_MostrarTodos(arrayEmpleado, lenEmpleado, arraySector, lenSector))
		{
			flag = 1;
		}

		if (flag)
		{
			if(!eEmpleado_ValidID(arrayEmpleado, lenEmpleado, &idGen))
			{
				index = eEmpleado_BuscarPorID(arrayEmpleado, lenEmpleado, idGen);

				auxiliar = nexo_ModificarUno(arrayEmpleado[index], arraySector, lenSector);

				if(grl_MenuSN("¿Guardar cambios?") == 1)
				{
					arrayEmpleado[index] = auxiliar;
					isError = 0;

				}
			}
		}
	}
	return isError;
}

int nexo_contar(eSector* arraySector, int lenSector, eEmpleado* arrayEmpleado, int lenEmpleado, int* max, int* sector)
{
	int isError;
	int i;
	int j;
	int contador;
	*max = 0;

	if(arraySector != NULL && lenSector > 0 && arrayEmpleado != NULL && lenSector > 0)
	{
		for(i = 0; i < lenSector; i++)
		{
			if(arraySector[i].isEmpty == OCUPADO)
			{
				contador = 0;
				for(j = 0; j < lenEmpleado; j++)
				{
					if(arrayEmpleado[j].isEmpty == OCUPADO && arraySector[i].id == arrayEmpleado[j].sector)
					{
						contador ++;
					}
				}

				if(*max < contador)
				{
					*max = contador;
					*sector = arraySector[i].id;
					isError = 0;
				}
			}
		}
	}

	return isError;
}

int nexo_infeorme(eSector* arraySector, int lenSector, eEmpleado* arrayEmpleado, int lenEmpleado)
{
	int isError;
	int max;
	int sectorMax;
	int i;
	int index;

	isError = -1;


	if(arraySector != NULL && lenSector > 0 && arrayEmpleado != NULL && lenSector > 0)
	{
		isError = 1;

		if(!nexo_contar(arraySector, lenSector, arrayEmpleado, lenEmpleado, &max, &sectorMax))
		{
			index = nexo_BuscarPorID(arraySector, lenSector, sectorMax);
			printf("\nEl sector con mas empleados es: %s", arraySector[index].descripcion);
			printf("\nY sus integrantes son: \n");
			for(i = 0; i < lenEmpleado; i++)
			{
				if(arrayEmpleado[i].sector == sectorMax && arrayEmpleado[i].isEmpty == OCUPADO)
				{
					nexo_MostrarUno(arrayEmpleado[i], arraySector, lenSector);
				}
			}
			isError = 0;
		}

	}


	return isError;
}
