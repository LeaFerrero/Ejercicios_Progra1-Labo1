/*
 ============================================================================
 Name        : ejercicio_11-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 11-3: Realizar una funci�n que reciba como par�metros un array de enteros
y un entero por referencia. La funci�n calcular� el valor m�ximo de ese array y
utilizar� el valor por referencia para retornar ese valor. Utilizar aritm�tica de
punteros

 */

#include <stdio.h>
#include <stdlib.h>

int calcularMayor(int*, int, int*);

int main(void) {

	int array[5] = {1,2,100,4,5};
	int maximo;

	calcularMayor(array, 5, &maximo);

	printf("EL MAXIMO ES: %d", maximo);

	return EXIT_SUCCESS;
}

int calcularMayor(int* array, int lenArray, int* maximo)
{
	int isError;
	int i;

	isError = -1;

	if(array != NULL && lenArray > 0)
	{
		*maximo = *(array+0);

		for(i = 0; i < lenArray; i++)
		{
			if(*(array+i) > *maximo)
			{
				*maximo = *(array+i);
			}

			isError = 0;
		}
	}

	return isError;
}
