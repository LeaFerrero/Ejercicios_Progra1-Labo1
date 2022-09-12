	/*
 ============================================================================
 Name        : ejercicio_4-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 4-3: Realizar un programa que permita la carga de temperaturas en Celsius y
Fahrenheit, validando las temperaturas ingresadas estén entre el punto de congelación y de
ebullición del agua para cada tipo de escala. Las validaciones se hacen en una biblioteca. Las
funciones de conversión de Fahrenheit a Celsius y de Celsius a Fahrenheit se hacen en otra.

 */

#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"
#include "conversor.h"

int main(void) {

	setbuf(stdout, NULL);

	float tempC;
	float tempF;
	float tempCovertidaCelcius;
	float tempComvertidaFahrenheit;


	printf("Ingrese una temperatura en Celcius entre el punto de congelación y de ebullición del agua: ");
	scanf("%f", &tempC);
	while(validarCelcius(tempC))
	{
		printf("Error. Ingrese una temperatura en Celcius: ");
		scanf("%f", &tempC);
	}

	printf("Ingrese una temperatura en Fahrenheit entre el punto de congelación y de ebullición del agua: ");
	scanf("%f", &tempF);
	while(validarFahrenheit(tempF))
	{
		printf("Error. Ingrese una temperatura en Fahrenheit: ");
		scanf("%f", &tempF);
	}

	if(!celciusAFahrenheit(tempC, &tempComvertidaFahrenheit))
	{
		printf("\n%.2f grados Celcius son: %.2f grados Fahrenheit", tempC, tempComvertidaFahrenheit);
	}

	if(!fahrenheitACelcius(tempF, &tempCovertidaCelcius))
	{
		printf("\n%.2f grados Fahrenheit son: %.2f grados Celcius", tempF, tempCovertidaCelcius);
	}

	return EXIT_SUCCESS;
}
