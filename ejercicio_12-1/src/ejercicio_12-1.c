/*
 ============================================================================
 Name        : ejercicio_12-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 12-1: Realizar una función que respete el siguiente prototipo:
int Calculador(int, int(*pFunc)(int, int), int, int*);
Dicha función deberá recibir dos operandos y un operador representado mediante la
función pasada como parámetro. El puntero a entero, servirá como parámetro de
salida y guardará el resultado de la operación.

*/

#include <stdio.h>
#include <stdlib.h>

int Calculador(int, int(*pFunc)(int, int), int, int*);
int sumar(int, int);
int restar(int, int);

int main(void) {

	setbuf(stdout, NULL);

	int(*pFunc)(int, int);

	int resultado;

	pFunc = sumar;

	Calculador(5, pFunc, 2, &resultado);

	printf("RESULTADO 1: %d", resultado);

	pFunc = restar;

	Calculador(5, pFunc, 2, &resultado);

	printf("\nRESULTADO 2: %d", resultado);

	return EXIT_SUCCESS;
}

int Calculador(int numeroUno, int(*pFunc)(int, int), int numeroDos, int* pResultado)
{
	int isError;

	isError = -1;

	*pResultado = pFunc(numeroUno, numeroDos);

	isError = 0;

	return isError;
}

int sumar(int numeroUno, int numeroDos)
{
	int resultado;

	resultado = numeroUno + numeroDos;

	return resultado;
}

int restar(int numeroUno, int numeroDos)
{
	int resultado;

	resultado = numeroUno - numeroDos;

	return resultado;
}
