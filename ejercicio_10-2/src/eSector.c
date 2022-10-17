/*
 * eSector.c
 *
 *  Created on: 7 oct. 2022
 *      Author: wilo waiko
 */


#include "eSector.h"

int eSector_Inicializar(eSector* array, int len)
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


int eSector_CargaForzada(eSector* array, int len)
{
	int isError;

	isError = -1;

	if(array != NULL && len > 0)
	{
		int i;
		isError = 1;
		int id[4] = {100, 200, 300, 400};
		char descripcion[4][51] = {"Sistemas", "RecursosHumanos", "Administracion", "Gerencia"};

		for(i = 0;  i < 4; i++)
		{
			array[i].id = id[i];
			strcpy(array[i].descripcion, descripcion[i]);
			array[i].isEmpty = OCUPADO;
		}

		isError = 0;
	}

	return isError;
}

void eSector_ShowHeader(void)
{
	printf("%10s", "N°");
	printf("%20s", "DESCRIPCION");
	printf("\n\n");

}

void eSector_ShowOne(int index, eSector one)
{

	printf("%10d.", index+1);
	printf("%20s", one.descripcion);
	printf("\n");
}

int eSector_ShowAll(eSector* eSectorList, int eSectorLen)
{
	int isError;
	int cantidad;
	int i;

	isError = -1;


	if (eSectorList != NULL && eSectorLen > 0)
	{
		cantidad = 0;

		puts("\n>LISTADO DE SECTOR");
		eSector_ShowHeader();

		for (i = 0; i < eSectorLen; i++)
		{
			if (eSectorList[i].isEmpty == OCUPADO)
			{
				eSector_ShowOne(i, eSectorList[i]);

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

int eSector_ObtainValidID(eSector* list, int len, int* pId)
{
	int isError;;
	int index;
	int auxilliar;

	isError = -1;


	if(list != NULL && len > 0)
	{
		isError = 1;
		do
		{

			if(!grl_Get_ValidInt(&index, "\nSeleccione un numero de la lista", "Error, no valido"))
			{
				auxilliar = eSector_SearchIDByIndex(list, len, index-1);

				if(auxilliar != -1)
				{
					*pId = auxilliar;
					isError = 0;
					break;
				}
			}
			printf("Ese elemento no existe");

		}
		while(grl_MenuSN("\n¿Reitentar?"));
	}

	return isError;
}

int eSector_SearchIDByIndex(eSector* list, int len, int index)
{
	int i;
	int id;

	id = -1;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{

			if((list+index)->id == (list+i)->id && (list+i)->isEmpty == 0)
			{

				id = (list+i)->id;
				break;
			}
		}
	}

	return id;
}
