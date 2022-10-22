/*
 ============================================================================
 Name        : ejercicio_13-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 13-2: Realizar una funci�n que reciba como par�metro un array de enteros,
su tama�o, un valor entero y un �ndice. La funci�n se encargar� de insertar el valor
entero en el �ndice especificado. El array deber� reestructurarse din�micamente.
Ejemplo: �ndice=2 valor=10
1 5 4 9
0 1 2 3
1 5 10 4 9
0 1 2 3 4

 */

int array_Push(int*, int*, int, int);

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	int i;
	int len;
	int* array;
	int number;
	int index;

	len = 4;
	array = (int*) malloc(sizeof(int) * len);

	for(i = 0; i < len; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", array+i);
	}

	printf("\nIngrese un indice: ");
	scanf("%d", &index);

	printf("\nIngrese un nuevo numero: ");
	scanf("%d", &number);

	printf("\nAntes del push: ");

	for(i = 0; i < len; i++)
	{
		printf("%d ", *(array+i));
	}

	if(!array_Push(array, &len, index, number))
	{
		printf("\nDespues del push: ");

		for(i = 0; i < len; i++)
		{
			printf("%d ", *(array+i));
		}
	}
	else
	{
		printf("\nNope ");

	}

	return EXIT_SUCCESS;
}

int array_Push(int* array, int* len, int index, int number)
{
	int i;
	int isError;
	int* pAux;

	isError = -1;

	if(index <= *len)
	{
		pAux  = (int*) realloc(array, sizeof(int) * ((*len) + 1));

		if (pAux != NULL)
		{
			array = pAux;
			(*len) ++;

			isError = 1;
		}

		for(i = *len; i != index; i--)
		{
			*(array+i) = *(array+(i-1));
		}

		*(array+index) = number;

		isError = 0;
	}

	return isError;
}
