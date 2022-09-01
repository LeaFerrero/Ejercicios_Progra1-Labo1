/*
 ============================================================================
 Name        : ejercicio_2-4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 2-4:
Ingresar 8 n�meros enteros, distintos de cero. Mostrar:
a. El menor n�mero ingresado.
b. De los pares el mayor n�mero ingresado.
c. Producto de los negativos.
d. En qu� lugarMaximo fue ingresado el mayor numero

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	int numero;
	int minimoNumero;
	int maximoNumero;
	int maximoPar;
	int productoNegativos;
	int i;
	int flagMinimoNumero;
	int flagMaximoPar;
	int flagMaximoNumero;
	int lugarMaximo;

	flagMinimoNumero = 0;
	flagMaximoPar = 0;
	flagMaximoNumero = 0;
	productoNegativos = 1;

	for(i = 0; i < 8; i++)
	{
		printf("Ingrese un numero entero distinto a cero: ");
		scanf("%d", &numero);

		while(numero == 0)
		{
			printf("Error. Ingrese un numero entero distinto a cero : ");
			scanf("%d", &numero);
		}

		if(flagMinimoNumero == 0 || numero < minimoNumero)
		{
			minimoNumero = numero;
			flagMinimoNumero = 1;
		}

		if(numero % 2 == 0)
		{
			if(flagMaximoPar == 0 || numero > maximoPar)
			{
				maximoPar = numero;
				flagMaximoPar = 1;
			}
		}

		if(numero < 0)
		{
			productoNegativos *= numero;
		}

		if(flagMaximoNumero == 0 || numero > maximoNumero)
		{
			lugarMaximo = i;
			maximoNumero = numero;
			flagMaximoNumero = 1;
		}

	}

	printf("\nEl menor numero ingresado es: %d", minimoNumero);
	printf("\nEl mayor numero par ingresado es: %d", maximoPar);
	printf("\nEl producto de los negativos es: %d", productoNegativos);
	printf("\nEl mayor numero fue ingresado en el lugarMaximo numero: %d", lugarMaximo);


	return EXIT_SUCCESS;
}
