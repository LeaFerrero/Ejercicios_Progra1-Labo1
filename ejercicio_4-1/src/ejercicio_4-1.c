/*
 ============================================================================
 Name        : ejercicio_4-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 4-1: Realizar un programa en el MAIN que permita calcular y mostrar el factorial de
un número. Utilizar la función de PedirNumero de la ejercitación 3. Por ejemplo:
5! = 5*4*3*2*1 = 120

 */

#include <stdio.h>
#include <stdlib.h>

int factorial(int);

int main(void) {

	setbuf(stdout, NULL);

	int result;
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    result = factorial(num);

    printf("El resultado es: %d", result);

	return EXIT_SUCCESS;
}

int factorial(int num)
{
	int retorno;

    if (num == 1)
    {
    	retorno = 1;
	}
    else
    {
    	retorno = num * factorial(num - 1);
    }

    return retorno;
}
