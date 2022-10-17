/*
 ============================================================================
 Name        : puntero_a_estructura.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}EFecha;

typedef struct{
    long int dni;
    char nombre[31];
    EFecha fechaNac;
}EPersona;

int main()
{
	setbuf(stdout, NULL);
    EPersona per;
    EPersona *ptrPer;
    EPersona personas[2];
    EPersona *ptrPersonas;
    int i;

    ptrPer = &per;

    ptrPersonas = personas;

    printf("\n\nESTRUCTURA SIMPLE:");

    printf("DNI: ");
    scanf("%ld", &per.dni);

    printf("\nNOMBRE: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", per.nombre);

    printf("FECHA NACIMIENTO\n");

    printf("\nDIA: ");
    scanf("%d", &per.fechaNac.dia);

    printf("\nMES: ");
    scanf("%d", &per.fechaNac.mes);

    printf("\nANIO: ");
    scanf("%d", &per.fechaNac.anio);

    printf("%s - %ld - %d/%d/%d", per.nombre, per.dni, per.fechaNac.dia, per.fechaNac.mes, per.fechaNac.anio);


    printf("\n\nPUNTERO A ESTRUCTURA OPERADOR FLECHA:");

    printf("DNI: ");
    scanf("%ld", &ptrPer->dni);

    printf("\nNOMBRE: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", ptrPer->nombre);

    printf("FECHA NACIMIENTO\n");

    printf("\nDIA: ");
    scanf("%d", &ptrPer->fechaNac.dia);

    printf("\nMES: ");
    scanf("%d", &ptrPer->fechaNac.mes);

    printf("\nANIO: ");
    scanf("%d", &ptrPer->fechaNac.anio);

    printf("%s - %ld - %d/%d/%d", ptrPer->nombre, ptrPer->dni, ptrPer->fechaNac.dia, ptrPer->fechaNac.mes, ptrPer->fechaNac.anio);


    printf("\n\nPUNTERO A ESTRUCTURA NOTACION PUNTERO:");

    printf("DNI: ");
    scanf("%ld", &(*ptrPer).dni);

    printf("\nNOMBRE: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", (*ptrPer).nombre);

    printf("FECHA NACIMIENTO\n");

    printf("\nDIA: ");
    scanf("%d", &(*ptrPer).fechaNac.dia);

    printf("\nMES: ");
    scanf("%d", &(*ptrPer).fechaNac.mes);

    printf("\nANIO: ");
    scanf("%d", &(*ptrPer).fechaNac.anio);

    printf("%s - %ld - %d/%d/%d", (*ptrPer).nombre, (*ptrPer).dni, (*ptrPer).fechaNac.dia, (*ptrPer).fechaNac.mes, (*ptrPer).fechaNac.anio);

    //
    printf("\n\nPUNTERO A ARRAY DE ESTRUCTURA:");

    for(i=0; i<2; i++){
        printf("DNI: ");
        scanf("%ld", &(*(ptrPersonas+i)).dni);

        printf("\nNOMBRE: ");
        setbuf(stdin, NULL);
        //scanf("%[^\n]", (*(ptrPersonas+i)).nombre);
        scanf("%s",&(*(ptrPersonas+i)->nombre));

        printf("FECHA NACIMIENTO\n");

        printf("\nDIA: ");
        scanf("%d", &(*(ptrPersonas+i)).fechaNac.dia);

        printf("\nMES: ");
        scanf("%d", &(*(ptrPersonas+i)).fechaNac.mes);

        printf("\nANIO: ");
        scanf("%d", &(*(ptrPersonas+i)).fechaNac.anio);
    }

    for(i=0; i<2; i++){
       /* printf("%s - %ld - %d/%d/%d", (*(ptrPersonas+i)).nombre, (*(ptrPersonas+i)).dni, (*(ptrPersonas+i)).fechaNac.dia, (*(ptrPersonas+i)).fechaNac.mes, (*(ptrPersonas+i)).fechaNac.anio); */

        printf("\n%s - %ld - %d/%d/%d\n", (ptrPersonas+i)->nombre, (ptrPersonas+i)->dni, (ptrPersonas+i)->fechaNac.dia, (ptrPersonas+i)->fechaNac.mes, (ptrPersonas+i)->fechaNac.anio);
    }

    return 0;
}
