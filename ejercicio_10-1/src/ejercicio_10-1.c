/*
 ============================================================================
 Name        : ejercicio_10-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 10-1: Crear las siguientes estructuras en c, y definir la manera más óptima de relacionarlas.
Producto-Proveedor (Donde el producto solo puede tener un único proveedor
Producto(1,1) Proveedor(1,n)
idProducto (int) idProveedor(int)
descripcion(string) razonSocial(string)
precio(float)
idProveedore

direccion(eDireccion)

Dueño Mascota
idDueño(int) idMascota(int)
nombre(string) nombre(string)
edad (int) raza(eRaza)
sexo(char) sexo(char)
idDueño

Alumno Localidad
idAlumno(int) idLocalida(int)
nombre(string) descripcion(string)
idLocalidad codigoPostal(int)
Dueño-Mascota (Donde la mascota solo puede tener un único dueño

 */

#include <stdio.h>
#include <stdlib.h>

//PRIMERA

typedef struct{

	char calle[51];
	int altura;

}eDireccion;

typedef struct{

	int idProveedor;
	char razonSocial[51];
	eDireccion direccion;

}eProveedor;

typedef struct{
	int idProducto;
	char descripcion[51];
	float precio;
	int idProveedor;

}eProductop;

//SEGUNDA

typedef struct{

	int idDuenio;
	char nombre[51];
	int edad;
	char sexo;

}eDuenio;

typedef struct{

	char raza[51];

}eRaza;

typedef struct{

	int idMascota;
	char nombre[51];
	eRaza raza;
	char sexo;
	int idDuenio;

}eMascota;

//TERCERA

typedef struct{

	int idLocalidad;
	char descripcion[51];
	int codigoPostal;

}eLocalidad;

typedef struct{

	int idAlumno;
	char nobre[51];
	int idLocalidad;

}eAlumno;
int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
