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

#define TAM 15

int main(void) {

	setbuf(stdout, NULL);

	int legajo[TAM];
	int edad[TAM];
	float salario[TAM];
	char sexo[TAM];
	int i;

	for(i = 0; i < TAM; i++)
	{
		printf("Ingrese el legajo: ");
		scanf("%d", legajo[]);
	}

	return EXIT_SUCCESS;
}
