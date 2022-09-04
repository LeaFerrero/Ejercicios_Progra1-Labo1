/*
 ============================================================================
 Name        : ejercicio_3-7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 3-7: Realizar un programa que: asigne a las variables numero1 y numero2
los valores solicitados al usuario, valide los mismos entre 10 y 100, asigne a la
variable operacion el valor solicitado al usuario, valide el mismo 's'-sumar, 'r'-restar,
realice la operación de dichos valores a través de una función. Mostrar el resultado
por pantalla.

 */

#include <stdio.h>
#include <stdlib.h>

int realizarOperacion(int, int, char);

int main(void) {

	setbuf(stdout, NULL);

	int numero1;
	int numero2;
	char operacion;
	int resultado;

	printf("Ingrese el primer numero entre 10 y 100: ");
	scanf("%d", &numero1);

	while(numero1 < 10 || numero1 > 100)
	{
		printf("Error. Ingrese el primer numero entre 10 y 100: ");
		scanf("%d", &numero1);
	}

	printf("Ingrese el segundo numero entre 10 y 100: ");
	scanf("%d", &numero2);

	while(numero2 < 10 || numero2 > 100)
	{
		printf("Error. Ingrese el segundo numero entre 10 y 100: ");
		scanf("%d", &numero2);
	}

	printf("Ingrese una operacion 's'-sumar, 'r'-restar: ");
	fflush(stdin);
	scanf("%c", &operacion);

	while(operacion != 's' && operacion != 'r')
	{
		printf("Error. Ingrese una operacion 's' sumar, 'r' restar: ");
		fflush(stdin);
		scanf("%c", &operacion);
	}

	resultado = realizarOperacion(numero1, numero2, operacion);

	if(operacion == 's')
	{
		printf("El resultado de la suma entre %d y %d es: %d", numero1, numero2, resultado);
	}
	else
	{
		printf("El resultado de la resta entre %d y %d es: %d", numero1, numero2, resultado);
	}

	return EXIT_SUCCESS;
}

int realizarOperacion(int numero1, int numero2, char operacion)
{
	int resultado;

	if(operacion == 's')
	{
		resultado = numero1 + numero2;
	}
	else
	{
		resultado = numero1 - numero2;
	}

	return resultado;
}
