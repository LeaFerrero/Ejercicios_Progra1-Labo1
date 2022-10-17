/*
 ============================================================================
 Name        : ejercicio_puncero_CA.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int mayorNegativo(int*, int, int*);

int main(void) {

	setbuf(stdout, NULL);

	int max;
	int array[3] = {55, 1, 7};

	if(mayorNegativo(array, 3, &max))
	{
		printf("El mayor negativo es: %d", max);
	}
	else
	{
		printf("No hay mayor negativo");
	}
	return EXIT_SUCCESS;
}

int mayorNegativo(int* array, int len, int* max)
{
	int hayNegativo;
	int i;
	int flag;
	int auxMax;

	flag = 0;

	if(array != NULL && len > 0)
	{
		hayNegativo = 0;
		for(i = 0; i < len; i++)
		{
			if(*(array+i) < 0)
			{
				if(!flag)
				{
					auxMax = *(array+i);
					flag = 1;
				}
				if(flag && *(array+i) > auxMax)
				{
					auxMax = *(array+i);
				}
				*max = auxMax;
				hayNegativo = 1;
			}
		}
	}

	return hayNegativo;
}
