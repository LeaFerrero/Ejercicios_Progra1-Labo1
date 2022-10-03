/*
 ============================================================================
 Name        : ejercicio_6-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 6-3: Realizar un programa que permita el ingreso de datos de 15 empleados
legajo (coincidente con el índice), edad, salario, sexo (1-Femenino, 2-Masculino, 3-No
binario). Realizar carga secuencial. Calcular el sueldo promedio. Listar a los
empleados no binarios.

 */

#include <stdio.h>
#include <stdlib.h>

#define TAM 2

int main(void) {

	setbuf(stdout, NULL);

	int legajo[TAM];
	int edad[TAM];
	float salario[TAM];
	int sexo[TAM];
	int i;
	float promedioSalario;
	float sumaSalario;


	sumaSalario = 0;

	for(i = 0; i < TAM; i++)
	{
		do
		{
			printf("Ingrese el legajo: ");
			scanf("%d", &legajo[i]);

		}while(i != legajo[i]);

		printf("Ingrese la edad: ");
		scanf("%d", &edad[i]);

		printf("Ingrese el salario: ");
		scanf("%f", &salario[i]);

		do
		{
			printf("Ingrese el sexo (1-Femenino, 2-Masculino, 3-No binario): ");
			scanf("%d", &sexo[i]);

		}while(sexo[i] != 1 && sexo[i] != 2 && sexo[i] != 3);

		sumaSalario += salario[i];
	}

	promedioSalario = sumaSalario / TAM;

	printf("\nEl salario promedio es: %.2f", promedioSalario);

	printf("\n\nLos empleados no binarios son: ");

	for(i = 0; i < TAM; i++)
	{
		if(sexo[i] == 3)
		{
			printf("\nEl legajo es: %d", legajo[i]);
			printf("\nLa edad es: %d", edad[i]);
			printf("\nEl salario es: %2.f", salario[i]);
			printf("\nSexo: No binario");
		}
	}

	return EXIT_SUCCESS;
}
