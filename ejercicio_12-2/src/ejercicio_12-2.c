/*
 ============================================================================
 Name        : ejercicio_12-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Tema 12 (Punteros-Función)
Ejercicio 12-1: Realizar una función que respete el siguiente prototipo:
int Calculador(int, int(*pFunc)(int, int), int, int*);
Dicha función deberá recibir dos operandos y un operador representado mediante la
función pasada como parámetro. El puntero a entero, servirá como parámetro de
salida y guardará el resultado de la operación.
Ejercicio 12-2: Utilizando la siguiente estructura y su hardcodeo

typedef struct{
int precio;
char marca[20];
int id;
}eProducto;
eProducto productos[4]={

{150, "Playadito", 1},
{100, "Pampero", 2},
{120, "Amanda", 3},
{180, "Rosamonte", 4},

};

Realizar una función que respete el siguiente prototipo:
int Ordenador(eProducto*,int , int(*pFunc)(eProducto*, eProducto*));
La función Ordenador recibirá como parámetros:
 el array de productos, dado por el puntero a eProducto
 la cantidad de elementos del array
 el criterio de ordenamiento, dado por la función pFunc.
Veamos un ejemplo de la función criterio:
intCompararPorMarca(eProducto*,eProducto*);
int ComparaPorPrecio(eProducto*,eProducto*);

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

	int precio;
	char marca[20];
	int id;

}eProducto;

int Ordenador(eProducto*,int , int(*pFunc)(eProducto*, eProducto*));
int ordenarMarca(eProducto*, eProducto*);
int ordenarPrecio(eProducto*, eProducto*);

int main()
{
    eProducto productos[4]={
                                {150, "Playadito", 1},
                                {100, "Pampero", 2},
                                {120, "Amanda", 3},
                                {180, "Rosamonte", 4},
                            };

    int i;

    int (*pFunc)(eProducto*, eProducto*);

    pFunc = ordenarPrecio;
    Ordenador(productos, 4, pFunc);

    puts("\nPrecio \t  Marca \t ID");
    for(i = 0; i < 4; i++)
    {
        printf("\n%d \t  %5s \t %d",(productos+i)->precio, (productos+i)->marca, (productos+i)->id);
    }

    pFunc = ordenarMarca;
    Ordenador(productos, 4, pFunc);

    puts("\n\nPrecio \t  Marca \t ID");
    for(i = 0; i < 4; i++)
    {
        printf("\n%d \t  %5s \t %d", (productos+i)->precio, (productos+i)->marca, (productos+i)->id);
    }

    return EXIT_SUCCESS;
}

int ordenarMarca(eProducto* one, eProducto* two)
{
	int compare;

    if(one != NULL && two!= NULL)
    {
        if(stricmp((one)->marca,(two)->marca) < 0)
        {
        	compare = -1;
        }
        else
        {
        	 if(stricmp((one)->marca,(two)->marca) > 0)
        	 {
        		 compare = 1;
        	 }
        	 else
        	 {
        		 compare = 0;
        	 }
        }
    }
    return compare;
}

int ordenarPrecio(eProducto* one, eProducto* two)
{
	int compare;

    if(one != NULL && two!= NULL)
    {
        if((one)->precio < (two)->precio)
        {
        	compare = -1;
        }
        else
        {
        	if((one)->precio > (two)->precio)
        	{
        		compare = 1;
        	}
        	else
        	{
        		compare = 0;
        	}
        }
    }
    return compare;
}

int Ordenador(eProducto* listaProductos,int cantidad, int(*pFunc)(eProducto*, eProducto*)){

	int isError;
	int i;
	int j;

	isError = -1;
    eProducto auxiliar;

    if(listaProductos!=NULL)
    {
        for(i = 0; i < 4-1; i++)
        {
            for(j = i + 1 ; j < 4; j++)
            {
                if(pFunc((listaProductos+i),(listaProductos+j)) == 1)
                {
                    auxiliar = *(listaProductos+i);
                    *(listaProductos+i) = *(listaProductos+j);
                    *(listaProductos+j) = auxiliar;
                }
            }

            isError = 0;
        }
    }

    return isError;
}



