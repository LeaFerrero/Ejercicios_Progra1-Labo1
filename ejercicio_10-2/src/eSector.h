/*
 * eSector.h
 *
 *  Created on: 7 oct. 2022
 *      Author: wilo waiko
 */

#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "general.h"

#define LIBRE 0
#define OCUPADO 1

#ifndef ESECTOR_H_
#define ESECTOR_H_

typedef struct{

	int id;
	char descripcion[51];
	int isEmpty;

}eSector;

int eSector_Inicializar(eSector*, int);
int eSector_CargaForzada(eSector*, int);
void eSector_ShowHeader(void);
void eSector_ShowOne(int, eSector);
int eSector_ShowAll(eSector*, int);
int eSector_ObtainValidID(eSector*, int, int*);
int eSector_SearchIDByIndex(eSector*, int, int);

#endif /* ESECTOR_H_ */
