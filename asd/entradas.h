/*
 * entradas.h
 *
 *  Created on: 1 may. 2022
 *      Author: wilo waiko
 */

#ifndef ENTRADAS_H_
#define ENTRADAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

int getString(char*, int);
int getInt(void);
int estaEnRangoInt(int numero, int minimo, int maximo);
int getValidInt(char mensaje[], char mensajeError[], float minimo, float maximo);
float getFloat(void);
float getValidFloat(char mensaje[], char mensajeError[], int minimo, int maximo);
int getStringLetras(char str[], int longitud);
void getValidStingLetras(char cadena[], int longitud, char mensaje[], char mensajeError[]);
int getStringAlfaNumerico(char cadena[], int longitud);
void getValidStingAlfanumerico(char cadena[], int longitud, char mensaje[], char mensajeError[]);
int getStringNombre(char cadena[], int longitud);
void primeraMayuscula(char cadena[]);
void getValidStingLetrasNombre(char cadena[], int longitud, char mensaje[], char mensajeError[]);

#endif /* ENTRADAS_H_ */
