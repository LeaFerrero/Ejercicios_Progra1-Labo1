/*
 * eEmpleado.c
 *
 *  Created on: 4 oct. 2022
 *      Author: wilo waiko
 */

#include "eEmpleado.h"

static int eEmpleado_ObtenerID(void);
static int eEmpleado_ObtenerID(void) {
	//ID autoincremental provado global
	//Inicializado una unica vez al comiendo del programa con alcance unicamente en la funcion eEmpleado_ObtenerID
	static int eEmpleado_idIncremental = 1;
	return eEmpleado_idIncremental++;
}

int eEmpleado_Inicializar(eEmpleado array[], int len)
{
	int isError;
	int i;

	isError = -1;

	//Si el array existe y tiene un tamaño valido
	if (array != NULL && len > 0)
	{
		isError = 1;
		//Recorro todo el array
		for (i = 0; i < len; i++)
		{
			//Lo seteo en LIBRE
			array[i].isEmpty = LIBRE;
			isError = 0;
		}
	}

	return isError;
}

int eEmpleado_ObtenerIndexLibre(eEmpleado array[], int len)
{
	int index = -1;
	int i;

	//Si el array existe y tiene un tamaño valido
	if (array != NULL && len > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < len; i++)
		{
			//Pregunto por el estado LIBRE
			if (array[i].isEmpty == LIBRE)
			{
				//Obtengo el primer indice libre y salgo
				index = i;
				break;
			}
		}
	}

	return index;
}

int eEmpleado_BuscarPorID(eEmpleado array[], int len, int id)
{
	int index = -1;
	int i;

	//Si el array existe y tiene un tamaño valido
	if (array != NULL && len > 0)
	{
		//Recorro todo el array
		for (i = 0; i < len; i++)
		{
			//Busco que este OCUPADO y que coincida con el id que estoy buscando
			if (array[i].id == id && array[i].isEmpty == OCUPADO)
			{
				//Si encuentro el ID
				//Devuelvo el index de donde esta el id buscado y salgo
				index = i;
				break;
			}
		}
	}

	return index;
}

int eEmpleado_ValidID(eEmpleado* array, int len, int* idAux)
{
	int isError;;
	int auxilliar;

	isError = -1;

	if(array != NULL && len > 0)
	{
		isError = 1;
		do
		{
			//Busco un id que sea valido y que exista
			if(!get_ValidInt(&auxilliar, "Ingrese el id a buscar", "Error, id no valido") && eEmpleado_BuscarPorID(array, len, auxilliar) != -1)
			{
				*idAux = auxilliar;
				isError = 0;
				break;
			}
			printf("El id no existe");

		}//Si no pregunto si quiere volver a buscar
		while(menuSN("\n¿Ingresar otro id?") == 1);
	}

	return isError;
}


void eEmpleado_MostrarUno(eEmpleado one)
{
	//Muestro un solo elemento
	printf("%10d %10s %10s %10.2f %5d\n", one.id, one.name, one.lastName, one.salary, one.sector);
}

int eEmpleado_MostrarTodos(eEmpleado array[], int len)
{
	int isError;
	int i;
	int cantidad = 0;

	isError = -1;

	//Si el array existe y tiene un tamaño valido
	if (array != NULL && len > 0)
	{
		//CABECERA
		puts("\n\t> LISTADO Gen");
		printf("%10s %10s %10s %10s %10s\n\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

		//Recorro todo el array
		for (i = 0; i < len; i++)
		{
			//Pregunto por el estado OCUPADO
			if (array[i].isEmpty == OCUPADO)
			{
				//Muestro uno solo
				eEmpleado_MostrarUno(array[i]);
				//contador ++
				cantidad++;
			}
		}
	}

	//Si cantidad == 0 - No hubo nada que mostrar (ARRAY SIN ALTAS)
	if (cantidad > 0)
	{
		isError = 0;
	}

	return isError;
}

eEmpleado eEmpleado_CargarDatos(void)
{
	eEmpleado auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	get_ValidName(auxiliar.name, LEN_NAME, "\nIngrese un nombre", "Error, nombre no valido");
	get_ValidName(auxiliar.lastName, LEN_LASTNAME, "Ingrese un Apellido", "Error, apellido no valido");
	get_ValidFloatRange(&auxiliar.salary, "Ingrese un salario", "Error, salario no valido", MIN_FLOAT, MAX_FLOAT);
	get_ValidIntPositive(&auxiliar.sector, "Ingrese el sector", "Error, sector no valido");

	return auxiliar;
}

eEmpleado eEmpleado_ModificarUno(eEmpleado Gen) {
	eEmpleado auxiliar = Gen;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	int opcion;

	//Muestro menu con opciones con los campos a modificar
	menu(&opcion, "Seleccione que quiere modificar", "\n1. Nombre", "\n2. Apellido", "\n3. Salario", "\n4. Sector", "", "", "", "Elija una opcion");

	switch(opcion)
	{
		case 1: //Nombre
			get_ValidName(auxiliar.name, LEN_NAME, "\nIngrese un nombre", "Error, nombre no valido");
		break;
		case 2: //Apellido
			get_ValidName(auxiliar.lastName, LEN_LASTNAME, "Ingrese un Apellido", "Error, apellido no valido");
		break;
		case 3: //Salario
			get_ValidFloatRange(&auxiliar.salary, "Ingrese un salario", "Error, salario no valido", MIN_FLOAT, MAX_FLOAT);
		break;
		case 4: //Sector
			get_ValidIntPositive(&auxiliar.sector, "Ingrese el sector", "Error, sector no valido");
		break;
	}

	return auxiliar;
}

int eEmpleado_Alta(eEmpleado array[], int len)
{
	eEmpleado auxGen;
	int isError;
	int index;

	isError = -1;
	//Si el array existe y tiene un tamaño valido
	if(array != NULL && len > 0)
	{
		isError = 1;
		//Busco espacio en el array
		index = eEmpleado_ObtenerIndexLibre(array, len);

		//Si index == -1 array lleno
		//Si index != -1 tengo en index la posicion de array libre
		if (index != -1)
		{
			//Pido datos y cargo en auxiliar
			auxGen = eEmpleado_CargarDatos();

			//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
			auxGen.id = eEmpleado_ObtenerID();
			//Cambio el estado a ocupado
			auxGen.isEmpty = OCUPADO;
			//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
			array[index] = auxGen;

			//Retorno 0 para indicar que no hubo errores
			isError = 0;
		}
	}

	return isError;
}

int eEmpleado_Baja(eEmpleado array[], int len)
{
	int isError;
	int idAux;
	int index;
	int flag = 0;

	isError = -1;

	//Si el array existe y el tamaño es aceptable
	if(array != NULL && len > 0)
	{
		isError = 1;
		//Lista todos los elementos
		if (!eEmpleado_MostrarTodos(array, len))
		{
			//Bandera en 1 si pudo listar
			flag = 1;
		}

		//Si hay elemento a dar de baja
		if (flag)
		{
			//Pido id Valido
			if(eEmpleado_ValidID(array, len, &idAux) == 0)
			{
				//Si el id es valido busco el indice
				index = eEmpleado_BuscarPorID(array, len, idAux);

				/**PREGUNTAR SI DESEA CONTINUAR*/
				//Pregunto si quiere confirmar los datos
				if(menuSN("¿Confirmar Baja?") == 1)
				{
					//Baja aceptada cambio el estado a "BAJA"
					array[index].isEmpty = BAJA;
					//Retorno 0 si no hubo errores
					isError = 0;
				}
			}
		}
	}

	return isError;
}

int eEmpleado_Modificacion(eEmpleado array[], int len)
{
	int isError;
	int idGen;
	int index;
	int flag = 0;
	eEmpleado auxiliar;

	isError = -1;

	//Si el array existe y el tamaño es aceptable
	if(array != NULL && len > 0)
	{
		isError = 1;

		//Listo todo
		if (!eEmpleado_MostrarTodos(array, len))
		{
			//Bandera en uno si se listo
			flag = 1;
		}

		//Si hay algo que modificar
		if (flag)
		{
			//Pido id
			if(eEmpleado_ValidID(array, len, &idGen) == 0)
			{
				//Si el id es valido busco en indice
				index = eEmpleado_BuscarPorID(array, len, idGen);

				//Llamo a la funcion que hace las modificaciones
				auxiliar = eEmpleado_ModificarUno(array[index]);

				//Pregunto si quiere guardar los cambios
				if(menuSN("¿Guardar cambios?") == 1)
				{
					//Modificacion aceptada
					array[index] = auxiliar;
					//Retorno 0 para informar que no hubo errores
					isError = 0;

				}
			}
		}
	}
	return isError;
}

int eEmpleado_Contador(eEmpleado* array, int len, int* total)
{
	int isError;
	int i;

	isError = -1;

	if(array != NULL && len > 0)
	{
		*total = 0;
		for(i = 0; i < len; i++)
		{
			if(array[i].isEmpty == OCUPADO)
			{
				(*total) ++;
			}
		}

		isError = 0;
	}

	return isError;
}

int eEmpleado_Acumulador(eEmpleado* array, int len, float* total)
{
	int isError;
	int i;

	isError = -1;

	if(array != NULL && len > 0)
	{
		*total = 0;
		for(i = 0; i < len; i++)
		{
			if(array[i].isEmpty == OCUPADO)
			{
				(*total) += array[i].salary;
			}
		}

		isError = 0;
	}

	return isError;
}

int eEmpleado_PromedioSalario(eEmpleado* array, int len, float* promedio)
{
	int isError;
	int totalEmpleados;
	float totalSalario;

	isError =- 1;

	if(array != NULL && len > 0)
	{
		isError = 1;
		eEmpleado_Contador(array, len, &totalEmpleados);
		eEmpleado_Acumulador(array, len, &totalSalario);

		if(totalEmpleados > 0)
		{
			*promedio = totalSalario / totalEmpleados;
			isError = 0;
		}
	}

	return isError;
}

int eEmpleado_ContadorMayor(eEmpleado* array, int len, float promedio, int* total)
{
	int isError;
	int i;

	isError = -1;

	if(array != NULL && len > 0)
	{
		*total = 0;
		for(i = 0; i < len; i++)
		{
			if(array[i].isEmpty == OCUPADO)
			{
				if(array[i].salary > promedio)
				{
					(*total) ++;
				}
			}
		}

		isError = 0;
	}

	return isError;
}

void eEmpleado_MostrarPromedio(eEmpleado* array, int len)
{
	float promedio;
	int superiores;

	eEmpleado_PromedioSalario(array, len, &promedio);
	eEmpleado_ContadorMayor(array, len, promedio, &superiores);

	printf("\nEl salario promedio es: %.2f", promedio);
	printf("\nLa cantidad de empleados superiores es de: %d", superiores);


}

int eEmpleado_Sort(eEmpleado array[], int len, int criterio)
{
	int	isError;
	int i;
	int j;
	eEmpleado aux;

	isError = -1;
	/** EJEMPLO DE SORT CON ID DE Gen
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)
	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//Si existe el array y tiene un limite valido
	if (array != NULL && len > 0)
	{
		isError = 1;

		switch (criterio)
		{
			case -1:
				for (i = 0; i < len - 1; i++)
				{
					for (j = i + 1; j < len; j++)
					{
						//Pregunto si ambas posiciones estan ocupadas
						if (array[i].isEmpty == OCUPADO && array[j].isEmpty == OCUPADO)
						{
							//Criterio de ordenamiento apellido
							if (stricmp(array[i].lastName, array[j].lastName) > 0)
							{
								//Intercambio posiciones
								aux = array[i];
								array[i] = array[j];
								array[j] = aux;
							}
								//Si hay dos apellidos iguales
							if (stricmp(array[i].lastName, array[j].lastName) == 0)
							{
								//Segundo criterio
								if(array[i].sector > array[j].sector)
								{
									//Intercambio posiciones
									aux = array[i];
									array[i] = array[j];
									array[j] = aux;

								}
							}
						}
					}
				}
				isError = 0;
			break;
		case 1:
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					//Pregunto si ambas posiciones estan ocupadas
					if (array[i].isEmpty == OCUPADO && array[j].isEmpty == OCUPADO)
					{
						//Criterio de ordenamiento apellido
						if (stricmp(array[i].lastName, array[j].lastName) < 0)
						{
							//Intercambio posiciones
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
							//Si hay dos apellidos iguales
						if (stricmp(array[i].lastName, array[j].lastName) == 0)
						{
							//Segundo criterio
							if(array[i].sector < array[j].sector)
							{
								//Intercambio posiciones
								aux = array[i];
								array[i] = array[j];
								array[j] = aux;

							}
						}
					}
				}
			}
			isError = 0;
			break;
		default:
			//Criterio mal ingresado
			isError = 1;
			break;
		}
	}
	return isError;
}

int eEmpleado_cadgaForzada(eEmpleado* array, int len)
{
	int isError;

	isError = -1;

	if(array != NULL && len > 0)
	{
		isError = 1;
		int i;
		char name[5][51] = {"Lotus", "Teshin", "Nef", "Cressa", "Khal"};
		char lastName[5][51] = {"Spacemom", "Dax", "Anyo", "Tal", "Garrison"};
		float salary[5] = {500, 100, 200, 300, 100};
		int sector[5] = {1, 2, 4, 3, 2};

		for(i = 0;  i < 5; i++)
		{
			array[i].id = eEmpleado_ObtenerID();
			strcpy(array[i].name, name[i]);
			strcpy(array[i].lastName, lastName[i]);
			array[i].salary = salary[i];
			array[i].sector = sector[i];
			array[i].isEmpty = OCUPADO;
		}

		isError = 0;
	}

	return isError;
}
