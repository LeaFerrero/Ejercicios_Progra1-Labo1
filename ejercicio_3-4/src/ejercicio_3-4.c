/*
 ============================================================================
 Name        : ejercicio_3-4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 3-4: Especializar la función del punto 3.1 y 3.2 para que valide el número en
un rango determinado.

Ejercicio 3-1: Crear una función que muestre por pantalla el número entero que
recibe como parámetro.
Ejercicio 3-2: Crear una función que pida el ingreso de un flotante y lo retorne.

 */

#include <stdio.h>
#include <stdlib.h>

void mostrarResultado(int);
float pedirNumeroFlotante(void);

int main(void) {

	setbuf(stdout, NULL);

	int numeroEntero;
	float numeroFlotante;

	printf("Ingrese un numero entero: ");
	scanf("%d", &numeroEntero);

	mostrarResultado(numeroEntero);

	numeroFlotante = pedirNumeroFlotante();

	printf("El numero flotante es: %.2f", numeroFlotante);

	return EXIT_SUCCESS;
}

//No puedo validar con un while si la funcion no vuelve a pedir datos, porque buclearia infinitamente.
void mostrarResultado(int numero)
{
	if(numero < 0 || numero > 10)
	{
		printf("El numero entero es: %d", numero);
	}
	else
	{
		printf("Numero no valido.");
	}
}

float pedirNumeroFlotante(void)
{
	float numero;

	printf("\nIngrese un numero flotante: ");
	scanf("%f", &numero);

	while(numero < 0 || numero > 10)
	{
		printf("Error. Ingrese un numero flotante: ");
		scanf("%f", &numero);
	}

	return numero;
}
