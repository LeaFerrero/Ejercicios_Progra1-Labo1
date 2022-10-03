/*
 * menu.c
 *
 *  Created on: 8 sep. 2022
 *      Author: Leandro Ferrero
 */

#include <stdio.h>
#include <stdlib.h>
#include "entradas.h"

/// \fn int menu(char*, char*, char*, char*, char*, char*)
/// \brief Imprime por pantalla un menu con 7 printf, que van a contener las opciones,
/// despues pide un numero entero al usuario que sea valido, dependiendo de las opciones del menu,
/// y si lo es, lo retorna.
///
/// \param titulo El titulo a mostrar en el menu
/// \param opcionUno Primera opcion del menu
/// \param opcionDos Segunda opcion del menu
/// \param opcionTres Tercera opcion del menu
/// \param opcionCuatro Cuarta opcion del menu
/// \param opcionCinco Quinta opcion del menu
/// \param opcionSeis Sexta opcion del menu
/// \param maximo Numero maximo a ser aceptado
/// \return El numero que el usuario eligio.
int menu(int* opcion, char* titulo, char* opcionUno, char* opcionDos, char* opcionTres,
		char* opcionCuatro, char* opcionCinco, char* opcionSeis)
{
	int bufferInt;
	int retorno;

	retorno = 0;

	printf("%s", titulo);
	printf("%s", opcionUno);
	printf("%s", opcionDos);
	printf("%s", opcionTres);
	printf("%s", opcionCuatro);
	printf("%s", opcionCinco);
	printf("%s\n", opcionSeis);

	if(getInt(&bufferInt))
	{
		*opcion = bufferInt;
		retorno = 1;
	}

	return retorno;
}
