/*
 * nexo.h
 *
 *  Created on: 7 oct. 2022
 *      Author: wilo waiko
 */

#include "eEmpleado.h"
#include "eSector.h"
#include "general.h"


#ifndef NEXO_H_
#define NEXO_H_

int nexo_CargarDatos(eEmpleado*, eSector*, int);
int nexo_eEmpleado_Alta(eEmpleado*, int, eSector*, int);
void nexo_MostrarUno(eEmpleado, eSector*, int);
int nexo_MostrarTodos(eEmpleado*, int, eSector*, int);
int nexo_BuscarPorID(eSector*, int, int);
int nexo_Baja(eEmpleado*, int, eSector*, int);

eEmpleado nexo_ModificarUno(eEmpleado, eSector* , int);
int nexo_Modificacion(eEmpleado*, int, eSector*, int);

int nexo_contar(eSector*, int, eEmpleado*, int, int*, int*);
int nexo_infeorme(eSector*, int, eEmpleado*, int);

#endif /* NEXO_H_ */
