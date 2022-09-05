/*
 ============================================================================
 Name        : ejercicio_2-5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 2-5:
Debemos generar el pedido de libretas universitarias a la imprenta para los alumnos
al regreso a la presencialidad. De cada persona debemos obtener los siguientes
datos:
número de legajo (4 cifras sin ceros a la derecha),
estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
edad (más de 17),
año de ingreso (validar por favor)
y género ('f' para femenino, 'm' para masculino, 'o' para no binario).
NOTA: El precio por libreta universitaria es de $450.
Se debe informar (solo si corresponde):
a) La cantidad de personas mayores de 60 años.
b) El legajo y edad de la mujer que ingreso hace más tiempo.
c) Cuanto debe abonar la facultad por las libretas sin el descuento
d) Si se solicitan mas de 5 libretas hay un 5% de descuento, si se solicitan más de
10 libretas se hace 10%. Además, por cada alumno mayor de 60 años al valor original
de la libreta se le hace un 25%. Informar los valores si corresponde.

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	int legajo;
	char estadoCivil;
	int edad;
	int anio;
	char genero;
	int precioLibreta;
	char respuesta;
	int contadorMayor;
	int flagMujerAntigua;
	int anioAntigua;
	int legajoAntigua;
	int edadAntigua;
	int contadorMujeres;
	int contadorLibretas;
	float totalLibretas;
	int descuento;
	float montoDescontado;
	float montoConDescuento;
	float montoDescontadoMayores;
	int totalMayores;

	precioLibreta = 450;
	montoDescontadoMayores = 0;
	respuesta = 's';
	contadorMayor = 0;
	contadorMujeres = 0;
	contadorLibretas = 0;
	flagMujerAntigua = 1;

	while(respuesta == 's')
	{
		printf("Ingrse el numero de legajo: ");
		scanf("%d", &legajo);

		while(legajo < 1111 || legajo > 9999)
		{
			printf("Error. Ingrse el numero de legajo: ");
			scanf("%d", &legajo);
		}

		printf("Ingrese el estado civil ('s' para soltero, 'c' para casado o 'v' viudo): ");
		fflush(stdin);
		scanf("%c", &estadoCivil);

		while(estadoCivil != 's' && estadoCivil != 'c' && estadoCivil != 'v')
		{
			printf("Error. Ingrese el estado civil ('s' para soltero, 'c' para casado o 'v' viudo): ");
			fflush(stdin);
			scanf("%c", &estadoCivil);
		}

		printf("Ingrse la edad: ");
		scanf("%d", &edad);

		while(edad < 17 || edad > 130)
		{
			printf("Error. Ingrse la edad: ");
			scanf("%d", &edad);
		}

		printf("Ingrse el año de ingreso: ");
		scanf("%d", &anio);

		while(anio < 2010 || anio > 2022)
		{
			printf("Error. Ingrse el año de ingreso: ");
			scanf("%d", &anio);
		}

		printf("Ingrese el genero ('f' para femenino, 'm' para masculino, 'o' para no binario): ");
		fflush(stdin);
		scanf("%c", &genero);

		while(genero != 'f' && genero != 'm' && genero != 'o')
		{
			printf("Ingrese el genero ('f' para femenino, 'm' para masculino, 'o' para no binario): ");
			fflush(stdin);
			scanf("%c", &genero);
		}

		if(edad > 60)
		{
			contadorMayor ++;

		}

		if(genero == 'f')
		{
			contadorMujeres ++;

			if(flagMujerAntigua == 0 || anio < anioAntigua)
			{
				anioAntigua = anio;
				legajoAntigua = legajo;
				edadAntigua = edad;
				flagMujerAntigua = 1;
			}
		}

		contadorLibretas ++;

		printf("Seguir ingresando datos?(s/n): ");
		fflush(stdin);
		scanf("%c", &respuesta);
	}


	if(contadorMujeres > 0)
	{
		printf("\nEl legajo de la mujer mque ingreso hace mas tiempo es: Legajo %d, edad %d años.", legajoAntigua, edadAntigua) ;
	}

	totalLibretas = contadorLibretas * precioLibreta;

	printf("\nLa cantidad a abonar por la facultd sin el descuento es de: $%.2f.", totalLibretas);


	if(contadorMayor > 0)
	{
		printf("\nLa cantidad de alumnos mayores a 60 es de: %d.", contadorMayor);

		descuento = 25;

		totalMayores = contadorMayor * precioLibreta;
		montoDescontadoMayores = (float)totalMayores * descuento / 100;
		totalLibretas = totalLibretas - montoDescontadoMayores;

		printf("\nSe desconto 25 porciento a las libretas pertenecientes a las peronas mayores de 60 quedado en total: %.2f.", totalLibretas);
	}

	if(contadorLibretas > 5)
	{
		descuento = 5;
		montoDescontado = (float)totalLibretas * descuento / 100;
		montoConDescuento = (float)totalLibretas - montoDescontado;

		printf("\nEl precio de las libretas con un descuento del 5 porciento es de: %.2f.", montoConDescuento);

	}
	else
	{
		if(contadorLibretas > 10)
		{
			descuento = 10;
			montoDescontado = (float)totalLibretas * descuento / 100;
			montoConDescuento = (float)totalLibretas - montoDescontado;

			printf("\nEl precio de las libretas con un descuento del 10 porciento es de: %.2f.", montoConDescuento);
		}

	}

	return EXIT_SUCCESS;
}
