/*
 ============================================================================
 Name        : ejercicio_11-5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 11-5: Utilizar aritmética de punteros. Dada la siguiente estructura:
int legajo;
char nombre[20];
int edad;
Realizar una función que cargue un array de 3 estudiantes.
Recibe un puntero al array de estudiantes, lo carga.
Retorna 0 si funcionó correctamente -1 mal.
Una vez cargados los estudiantes mostrar el array cargado.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int legajo;
	char nombre[20];
	int edad;
}eEstudiante;

int eEstudiante_Cargar(eEstudiante*);

int main(void) {

	setbuf(stdout, NULL);

	int i;

	eEstudiante list[3];
	eEstudiante* pEstudiante;

	pEstudiante = list;

	for(i = 0; i<3; i++)
	{
		if(!eEstudiante_Cargar((pEstudiante+i)))
		{
			printf("\nSe cargo %d\n", i+1);
		}
	}

	for(i = 0; i<3; i++)
	{
		printf("Legajo: %d  Nombre: %s  Edad: %d\n", (list+i)->legajo, (list+i)->nombre, (list+i)->edad);
	}

	return EXIT_SUCCESS;
}

int eEstudiante_Cargar(eEstudiante* uno)
{
	int isError;
	isError = -1;

	printf("\nIngrese el legajo: ");
	scanf("%d", &uno->legajo);
	printf("\nIngrese el nombre: ");
	fflush(stdin);
	scanf("%[^\n]", uno->nombre);
	printf("\nIngrese el edad: ");
	scanf("%d", &uno->edad);

	isError = 0;

	return isError;;
}
