/*
 ============================================================================
 Name        : ejercicio_13-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 13-1: Realizar una función que reciba como parámetro un array de enteros,
su tamaño y un entero. La función se encargará de buscar el valor y borrará la primera
ocurrencia del mismo, el array deberá reestructurarse dinámicamente.
Ejemplo: valor 2
5 4 2 1 3
0 1 2 3 4
5 4 1 3
0 1 2 3

 */

#include <stdio.h>
#include <stdlib.h>

int array_Search(int*, int, int, int*);
int array_Remove(int*, int*, int);

int main(void)
{
	setbuf(stdout, NULL);

	int i;
	int len = 5;
	int* array;
	int remove;
	int index;

	remove = 2;
	len = 5;
	array = (int*) malloc(sizeof(int) * len);

	for(i = 0; i < len; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", array+i);
	}

	printf("\nAntes de remover: ");

	for(i = 0; i < len; i++)
	{
		printf("%d ", *(array+i));
	}

	if(!array_Search(array, len, remove, &index))
	{
		if(!array_Remove(array, &len, index))
		{
			printf("\nDespues de remover: ");

			for(i = 0; i < len; i++)
			{
				printf("%d ", *(array+i));
			}
		}
	}




	return EXIT_SUCCESS;
}



int array_Search(int* array, int len, int remove, int* index)
{
	int isError;
	int i;

	isError = -1;

	for(i = 0; i < len; i++)
	{
		isError = 1;

		if(*(array+i) == remove)
		{
			*index = i;
			isError = 0;
			break;
		}
	}

	return isError;
}

int array_Remove(int* array, int* len, int index)
{
	int i;
	int isError;

	isError = -1;

	for(i = index; i < *len-1; i++)
	{
		*(array+i) = *(array+(i+1));
	}

	int* pAux;

	pAux  = (int*) realloc(array, sizeof(int) * ((*len) - 1));

	if (pAux != NULL)
	{

		array = pAux;
		(*len)--;

		isError = 0;
	}

	return isError;
}
