/*
 ============================================================================
 Name        : ejercicio_11-4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 11-4: Utilizar aritmética de punteros. Dada la siguiente estructura:
int legajo;
char nombre[20];
int edad;
Realizar una función que cargue un array de 3 estudiantes. Recibe un entero. Retorna
el estudiante dado de alta y por parámetro 0 si funcionó correctamente -1 mal. Una
vez devuelto el estudiante cargarlo en una posición del array. Al final mostrar el array
cargado.


 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int legajo;
	char nombre[20];
	int edad;
}eEstudiante;

eEstudiante eEstudiante_Cargar(int*);

int main(void) {

	setbuf(stdout, NULL);

	int i;
	int isError;

	eEstudiante list[3];
	eEstudiante auxiliar;

	for(i = 0; i<3; i++)
	{
		auxiliar = eEstudiante_Cargar(&isError);
		if(!isError)
		{
			*(list+i) = auxiliar;
		}
	}

	for(i = 0; i<3; i++)
	{
		printf("Legajo: %d  Nombre: %s  Edad: %d\n", (*(list+i)).edad, (*(list+i)).nombre, (*(list+i)).edad );
	}

	return EXIT_SUCCESS;
}

eEstudiante eEstudiante_Cargar(int* isError)
{
	eEstudiante estudiante;
	*isError = -1;

	printf("\nIngrese el legajo: ");
	scanf("%d", &estudiante.legajo);
	printf("\nIngrese el nombre: ");
	fflush(stdin);
	scanf("%[^\n]", estudiante.nombre);
	printf("\nIngrese el edad: ");
	scanf("%d", &estudiante.edad);

	*isError = 0;

	return estudiante;
}
