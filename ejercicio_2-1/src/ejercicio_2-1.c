/*
 ============================================================================
 Name        : ejercicio_2-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 2-1: Ingresar 7 n�meros negativos distintos de 0 calcular y mostrar el
promedio de los n�meros. Probar la aplicaci�n con distintos valores.
Ejemplo 1: (-7)( - 5)( - 12) (- 1)( - 2)
Ejemplo 2: (-9)( - 15)( - 12) (- 1)( - 21)

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int numeroIngresado;
	int acumuladorNegativos;
	int i;
	float promedio;

	acumuladorNegativos = 0;

	setbuf(stdout, NULL);

	for(i = 0; i < 8; i++)
	{
		printf("Ingrese un numero negaativo: ");
		scanf("%d", &numeroIngresado);

		while(numeroIngresado > -1)
		{
			printf("\nError. Ingrese un numero negaativo: ");
			scanf("%d", &numeroIngresado);
		}

		acumuladorNegativos += numeroIngresado;
	}

	promedio = (float)acumuladorNegativos / i;

	printf("El promedio de los numeros es: %.2f", promedio);

	return EXIT_SUCCESS;
}
