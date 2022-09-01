/*
 ============================================================================
 Name        : ejercicio_1-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Ejercicio 1-3: ingresar 3 números y mostrar el número del medio, sólo si existe. En
caso de que no exista también informarlo.
Ejemplo:

1 5 3 el 3 es del medio
5 1 5 no hay número del medio
3 5 1 el 3 es del medio
3 1 5 el 3 es del medio
5 3 1 el 3 es del medio

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	int primerNumero;
	int segundoNumero;
	int tercerNumero;

	printf("Ingrese el primer numero: ");
	scanf("%d", &primerNumero);

	printf("Ingrese el segundo numero: ");
	scanf("%d", &segundoNumero);

	printf("Ingrese el tercer numero: ");
	scanf("%d", &tercerNumero);

	if((primerNumero > segundoNumero && primerNumero < tercerNumero) || (primerNumero > tercerNumero && primerNumero < segundoNumero))
	{
		printf("%d %d %d el %d es el del medio", primerNumero, segundoNumero, tercerNumero, primerNumero);
	}
	else
	{
		if((segundoNumero > tercerNumero && segundoNumero < primerNumero) || (segundoNumero > primerNumero && segundoNumero < tercerNumero))
		{
			printf("%d %d %d el %d es el del medio", primerNumero, segundoNumero, tercerNumero, segundoNumero);
		}
		else
		{
			if((tercerNumero > primerNumero && tercerNumero < segundoNumero) || (tercerNumero > segundoNumero && tercerNumero < primerNumero))
			{
				printf("%d %d %d el %d es el del medio", primerNumero, segundoNumero, tercerNumero, tercerNumero);
			}
			else
			{
				printf("%d %d %d no hay numero del medio", primerNumero, segundoNumero, tercerNumero);
			}
		}
	}



	return EXIT_SUCCESS;
}
