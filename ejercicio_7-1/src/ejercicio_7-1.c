/*
 ============================================================================
 Name        : ejercicio_7-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 7-1: Pedirle al usuario su nombre y apellido (en variables separadas, una
para el nombre y otra para el apellido). Ninguna de las dos variables se puede
modificar. Debemos lograr guardar en una tercer variable el apellido y el nombre con
el siguiente formato: Perez, Juan Ignacio usando la siguiente función

void FormarApellidoNombre(char* pNombre,char* pApellido,char* pCompleto);

 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM 100

void formarApellidoNombre(char* pNombre,char* pApellido,char* pCompleto);

int main(void) {

	setbuf(stdout, NULL);

	char nombre[TAM];
	char apellido[TAM];
	char nombreYApeliddo[TAM];
	int largoNombre;
	int largoApellido;

	printf("Ingrese su nombre: ");
	fflush(stdin);
	fgets(nombre, TAM, stdin);
	largoNombre = strlen(nombre);
	nombre[largoNombre-1] = '\0';

	printf("Ingrese su apellido: ");
	fflush(stdin);
	fgets(apellido, TAM, stdin);
	largoApellido = strlen(apellido);
	apellido[largoApellido-1] = '\0';

	FormarApellidoNombre(nombre, apellido, nombreYApeliddo);

	printf("EL nombre completo es: %s", nombreYApeliddo);

	return EXIT_SUCCESS;
}

void formarApellidoNombre(char* pNombre,char* pApellido,char* pCompleto)
{
	int i;
	int cantidad;

	strcpy(pCompleto, pApellido);
	strcat(pCompleto, ", ");
	strcat(pCompleto, pNombre);

	strlwr(pCompleto);
	pCompleto[0] = toupper(pCompleto[0]);

	cantidad = strlen(pCompleto);

	for(i = 0; i < cantidad; i++ )
	{
		if(isspace(pCompleto[i]))
		{
			pCompleto[i+1] = toupper(pCompleto[i+1]);
		}
	}

}
