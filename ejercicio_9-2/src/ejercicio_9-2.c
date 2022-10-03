/*
 ============================================================================
 Name        : ejercicio_9-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 9-2:Una empresa requiere un sistema para administrar su nómina de
empleados. Se sabe que dicha nómina bajo ninguna circunstancia superara los 300
empleados.

 */

#include <stdio.h>
#include <stdlib.h>

#define TAM 300

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;
}eEmpleado;

int main(void) {

	eEmpleado arrayEmpleados[TAM];

	return EXIT_SUCCESS;
}
