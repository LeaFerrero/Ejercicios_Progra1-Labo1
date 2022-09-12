/*
 ============================================================================
 Name        : ejercicio_3-6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 3-6: Realizar un programa que: asigne a la variable numero1 un valor
solicitado al usuario, valide el mismo entre 10 y 100, realice un descuento del 5% a
dicho valor a través de una función llamada realizarDescuento(). Mostrar el resultado
por pantalla.

 */

#include <stdio.h>
#include <stdlib.h>

float realizarDescuento(int);

int main(void) {

	setbuf(stdout, NULL);

	int numero1;
	float resultado;

	printf("Ingrese un numero entre 10 y 100: ");
	scanf("%d", &numero1);

	while(numero1 < 10 || numero1 > 100)
	{
		printf("Error. Ingrese un numero entre 10 y 100: ");
		scanf("%d", &numero1);
	}

	resultado = realizarDescuento(numero1);

	printf("El valor con descuento del 5 es: %.2f", resultado);

	return EXIT_SUCCESS;
}

float realizarDescuento(int numero1)
{
	int descuento;
	float valorDescontado;
	float valorConDescuento;

	descuento = 5;

	valorDescontado = (float)numero1 * descuento / 100;
	valorConDescuento = (float)numero1 - valorDescontado;

	return valorConDescuento;
}
