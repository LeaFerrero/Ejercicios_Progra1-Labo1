/*
 ============================================================================
 Name        : ejercicio_9-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 9-1: Crear la estructura Alumno (nombre, materias aprobadas, suma de
notas, promedio). Crear una función que permita cargar los datos de un alumno y
otra que los muestre. Una tercera función calculará el promedio de notas.

 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char nombre[20];
	int materiasAprobadas;
	int sumaNotas;
	float promedio;

}eAlumno;

eAlumno cargarAlumno(void);

float calcularPromedio(eAlumno);

void mostrarAlumno(eAlumno);

int main(void) {

	setbuf(stdout, NULL);

	eAlumno alumno;

	alumno = cargarAlumno();

	alumno.promedio = calcularPromedio(alumno);

	mostrarAlumno(alumno);


	return EXIT_SUCCESS;
}

eAlumno cargarAlumno(void)
{
	eAlumno alumno;

	printf("Ingrese el nombre: ");
	scanf("%[^\n]", alumno.nombre);
	printf("Ingrese las materias aprobadas: ");
	scanf("%d", &alumno.materiasAprobadas);
	printf("Ingrese la suma de notas: ");
	scanf("%d", &alumno.sumaNotas);

	return alumno;
}

float calcularPromedio(eAlumno alumno)
{
	float promedio;

	promedio = (float)alumno.sumaNotas / alumno.materiasAprobadas;

	return promedio;
}

void mostrarAlumno(eAlumno alumno)
{
	printf("\nEl nombre es: %s", alumno.nombre);
	printf("\nLas materias aprobadas: %d", alumno.materiasAprobadas);
	printf("\nLa sumatoria de notas es: %d", alumno.sumaNotas);
	printf("\nEl promedio es: %.2f", alumno.promedio);
}
