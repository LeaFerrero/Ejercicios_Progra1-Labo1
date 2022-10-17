/*
 * eEmpleado.h
 *
 *  Created on: 4 oct. 2022
 *      Author: wilo waiko
 */
#include "general.h"
#define LIBRE 0
#define OCUPADO 1
#define LEN_NAME 51
#define LEN_LASTNAME 51
#define MIN_FLOAT 1.00
#define MAX_FLOAT 100.00

#ifndef EEMPLEADO_H_
#define EEMPLEADO_H_


typedef struct{

	int id;
	char name[LEN_NAME];
	char lastName[LEN_LASTNAME];
	float salary;
	int sector;
	int isEmpty;

}eEmpleado;

int eEmpleado_GetID(void);
int eEmpleado_Inicializar(eEmpleado* array, int len);
int eEmpleado_ObtenerIndexLibre(eEmpleado* array, int len);
int eEmpleado_BuscarPorID(eEmpleado* array, int len, int ID);
int eEmpleado_ValidID(eEmpleado*,int, int*);
void eEmpleado_MostrarUno(eEmpleado one);
int eEmpleado_MostrarTodos(eEmpleado* array, int len);

//ABM
eEmpleado eEmpleado_CargarDatos(void);
int eEmpleado_Alta(eEmpleado* array, int len);
int eEmpleado_Baja(eEmpleado* array, int len);

int eEmpleado_Contador(eEmpleado* array, int len, int* total);
int eEmpleado_Acumulador(eEmpleado* array, int len, float* total);
int eEmpleado_PromedioSalario(eEmpleado* array, int len, float* promedio);
int eEmpleado_ContadorMayor(eEmpleado* array, int len, float promedio, int* total);
void eEmpleado_MostrarPromedio(eEmpleado* array, int len);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eEmpleado_Sort(eEmpleado array[], int len, int criterio);

int eEmpleado_cadgaForzada(eEmpleado* array, int len);



#endif /* EEMPLEADO_H_ */
