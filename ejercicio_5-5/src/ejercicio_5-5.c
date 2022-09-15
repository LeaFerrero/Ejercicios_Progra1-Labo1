/*
 ============================================================================
 Name        : ejercicio_5-5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 5-5: Pedir 10 números enteros distintos de cero entre -50 y 75. La carga
deberá ser aleatoria (todos los elementos se inicializan en cero por default).
Determinar el promedio de los positivos. Desde el mayor de los negativos los
números negativos hasta llegar a cero.

 */

#include <stdio.h>
#include <stdlib.h>

#define TAM 2

int main(void) {

	setbuf(stdout, NULL);

	int arrayInt[TAM];
	int i;
	int indice;
	char respuesta;
	int suma;
	float promedio;
	int mayorNeg;
	int flagMayorNeg;

	suma = 0;
	respuesta = 's';
	flagMayorNeg = 0;

	for(i=0; i < TAM; i++)
	{
		arrayInt[i] = 0;
	}

	i = 0;

	do
	{
		printf("Elija el indice donde lo quiere guardar entre 0 y 9: ");
		scanf("%d", &indice);
		while(indice < 0 || indice > 9)
		{
			printf("Error. Elija el indice donde lo quiere guardar entre 0 y 9 ");
			scanf("%d", &indice);
		}

		printf("Ingrese un numero entero distinto de cero, entre -50 y 75: ");
		scanf("%d", &arrayInt[indice]);
		while(arrayInt[indice] == 0 && (arrayInt[indice] < -50 || arrayInt[indice] > 75))
		{
			printf("Error. Ingrese un numero entero distinto de cero, entre -50 y 75: ");
			scanf("%d", &arrayInt[indice]);
		}

		i++;

		if(i<TAM)
		{
			printf("¿Seguir ingresando numeros?(s/n): ");
			fflush(stdin);
			scanf("%c", &respuesta);
			while(respuesta != 's' && respuesta != 'n')
			{
				printf("¿Seguir ingresando numeros?(s/n): ");
				scanf("%c", &respuesta);
			}
		}
		else
		{
			respuesta = 'n';
		}

	}while(respuesta != 'n');

	for(i=0; i < TAM; i++)
	{

		printf("\nEL ARRAY ES ESTE: %d", arrayInt[i]);

		if(arrayInt[i] > 0)
		{
			suma += arrayInt[i];
		}
		else
		{
			if(flagMayorNeg == 0 || arrayInt[i] > respuesta)
			{
				mayorNeg = arrayInt[i];
				flagMayorNeg = 1;
			}
		}
	}

	promedio = (float)suma/TAM;

	printf("\nEl promedio de los positivos es: %.2f", promedio);
	printf("\nEl mayor de los negativos es: %d", mayorNeg);


	return EXIT_SUCCESS;
}
