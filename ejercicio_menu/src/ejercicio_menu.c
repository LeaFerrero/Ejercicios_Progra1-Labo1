/*
 ============================================================================
 Name        : ejercicio_menu.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Realizar un Menú que muestre las opciones:
        a-Iniciar
        b-Procesar
        c-Finalizar
        d-Salir
Nota:
-Antes de salir preguntar si "esta seguro que desea salir?s/n"
-Si Procesa sin haber Iniciado, debe avisar "Debe Iniciar antes de Procesar" y no deja continuar
-Si se Finaliza antes de Iniciar debe avisar "Debe Iniciar antes de Finalizar" y no deja continuar
-Si se Finaliza antes de Procesar debe avisar "Debe Procesar antes de Finalizar" y no deja continuar

 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main(void) {

	setbuf(stdout, NULL);

	char opcion;
	char salir;
	int flagIniciar;
	int flagProcesar;

	salir = 'n';
	flagIniciar = 0;
	flagProcesar = 0;

	do
	{

		opcion = menu();

		switch(opcion)
		{
			case 'a':
				printf("\nSe Inicializo.");
				flagIniciar = 1;
			break;

			case 'b':
				if(flagIniciar == 1)
				{
					printf("\nSe Proceso.");
					flagProcesar = 1;
				}
				else
				{
					printf("\nDebe Iniciar antes de Procesar.");
				}
			break;

			case 'c':
				if(flagProcesar == 1)
				{
					printf("\nSe Finalizo.");
					flagIniciar = 0;
					flagProcesar = 0;
				}
				else
				{
					if(flagIniciar == 0)
					{
						printf("\nDebe Iniciar antes de Finalizar" );
					}
					else
					{
						printf("\nDebe Procesar antes de Finalizar" );
					}
				}
			break;

			case 'd':
				printf("\n¿Desea salir?(s/n): ");
				fflush(stdin);
				scanf("%c", &salir);
			break;
		}

	}
	while(salir == 'n');

	return EXIT_SUCCESS;
}
