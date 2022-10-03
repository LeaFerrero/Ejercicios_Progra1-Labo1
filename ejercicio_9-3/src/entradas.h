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

int myGets(char*, int);

int esNumerico(char*, int);
int getInt(int*);
int estaEnRangoInt(int, int, int);
int getValidIntReintentos(int*, char*, char*, int, int, int);
int getValidInt(int*, char*, char*, int, int);

int esNumericoFlotante(char*, int);
int getFloat(float*);
int estaEnRangoFloat(float, float, float);
int getValidFloat(float*, char*, char*, float, float, int);

int esSoloLetras(char str[], int limite);
int getStringLetras(char str[], int longitud);
void getValidStingLetras(char cadena[], int longitud, char mensaje[], char mensajeError[]);
int getStringAlfaNumerico(char cadena[], int longitud);
int esAlfaNumerico(char cadena[], int longitud);
void getValidStingAlfanumerico(char cadena[], int longitud, char mensaje[], char mensajeError[]);
int esSoloLetrasNombre(char cadena[], int longitud);
int getStringNombre(char cadena[], int longitud);
void primeraMayuscula(char cadena[]);
void getValidStingLetrasNombre(char cadena[], int longitud, char mensaje[], char mensajeError[]);

#endif /* ENTRADAS_H_ */
