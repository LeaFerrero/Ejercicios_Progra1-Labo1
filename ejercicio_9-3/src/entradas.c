/*
 * entradas.c
 *
 *  Created on: 1 may. 2022
 *      Author: wilo waiko
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// \fn int myGets(char*, int)
/// @brief Lee del buffer de entrada hasta que encuantra un '\n' o hasta que haya copiado en cadena
/// un valor maximo de 'longitud - 1' caracteres.
///
/// @param cadena Array donde se cargar el texto ingresado
/// @param longitud Longitud que define el tamaño de cadena
/// @return Retorna 1 si se obtiene una cadena y 0 si no
int myGets(char* cadena, int longitud)
{
	int retorno;

	retorno = 0;
	char bufferString[5099];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) < longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno = 1;
			}
		 }
	 }
	return retorno;
}

/// \fn int esNumerico(char*, int)
/// @brief Verifica si la cadena ingresada es numnerica
///
/// @param cadena cadena Array con la cadena a ser analizada
/// @param longitud Longitud de la cadena
/// @return Retorna 1 si es nœmerico y 0 si no lo es
int esNumerico(char* cadena, int longitud)
{
	int retorno;
   	int i;

   	retorno = 1;
 	if(cadena != NULL && longitud > 0)
 	{
		for(i = 0; i < longitud && cadena[i] != '\0'; i++)
		{
			if(i == 0 && cadena[i] == '-')
			{
				continue;
			}
			if(!isdigit(cadena[i]))
			{
				retorno = 0;
				break;
			}
	   }
 	}
 	else
 	{
 		retorno = 0;
 	}

   return retorno;
}

/// \fn int getInt(int*)
/// \brief Obtiene un numero entero
///
/// \param pNumero Puntero al espacio de memoria donde se dejara el resultado
/// \return Retorna 1 si logro obtener un entero  y 0 si no
int getInt(int* pNumero)
{
	int retorno;
	char bufferInt[50];

	retorno = 0;

	if(pNumero != NULL)
	{
		if(myGets(bufferInt, sizeof(bufferInt)) && esNumerico(bufferInt, sizeof(bufferInt)))
		{
			*pNumero  = atoi(bufferInt);
			retorno = 1;
		}
	}


	return retorno;
}

/// @fn int estaEnRango(int, int, int)
/// @brief Verifica que el numero este debtro del rango
///
/// @param numero El numero a ser validado
/// @param minimo Es el numero minimo a ser aceptado
/// @param maximo Es el minimo maximo a ser aceptado
/// @return Retorna 1 si esta en el rango y 0 si no lo esta
int estaEnRangoInt(int numero, int minimo, int maximo)
{
	int retorno;

	retorno = 1;

	if(numero < minimo || numero > maximo)
	{
		retorno = 0;
	}

	return retorno;
}

/// \fn int getValidIntReintentos(int*, char*, char*, int, int, int)
/// \brief Solicita un numero entero al usuario, luego de veruficarlo lo devuelve,
/// el usuario tiene una determiada cantidad de intentos para ingresar un numero valido
///
/// \param pNumero Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// \param mensaje Mensaje a ser mostrado
/// \param mensajeError El mesaje de error a ser mostrado
/// \param minimo El numero minimo a ser aceptado
/// \param maximo El numero maximo a ser aceptado
/// \param reintentos La cantidad de reintentos que tiene el usuario
/// \return Retorna 1 si obtuvo el numero y 0 si no
int getValidIntReintentos(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno;
	int bufferInt;

	retorno = 0;

	do
	{
		printf("%s", mensaje);
		if(getInt(&bufferInt) && estaEnRangoInt(bufferInt, minimo, maximo))
		{
			*pNumero = bufferInt;
			retorno = 1;
			break;
		}

		printf("%s\n", mensajeError);
		reintentos --;

	}while(reintentos >= 0);

	return retorno;
}

/// \fn int getValidInt(int*, char*, char*, int, int, int)
/// \brief Solicita un numero entero al usuario, luego de veruficarlo lo devuelve
///
/// \param pNumero Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// \param mensaje Mensaje a ser mostrado
/// \param mensajeError El mesaje de error a ser mostrado
/// \param minimo El numero minimo a ser aceptado
/// \param maximo El numero maximo a ser aceptado
/// \param reintentos La cantidad de reintentos que tiene el usuario
/// \return Retorna 1 si obtuvo el numero y 0 si no
int getValidInt(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorno;
	int bufferInt;

	retorno = 0;

	do
	{
		printf("%s", mensaje);
		if(getInt(&bufferInt) && estaEnRangoInt(bufferInt, minimo, maximo))
		{
			*pNumero = bufferInt;
			retorno = 1;
			break;
		}

		printf("%s\n", mensajeError);

	}while(retorno == 0);

	return retorno;
}

/// @fn int esNumericoFlotante(char*, int)
/// @brief Verifica si el valor recibido es numérico flotantes, positivo o negativo
///
/// @param cadena Array con la cadena a ser analizada
/// @param longitud
/// @return 1 si es númerico y 0 si no lo es
int esNumericoFlotante(char* cadena, int longitud)
{
	int retorno;
	int flagPunto;

	retorno = 1;
	flagPunto = 0;

	for(int i = 0; i < longitud && cadena[i] != '\0'; i++)
	{
    	if(i == 0 && cadena[i] == '-')
    	{
    		continue;
    	}
		if (cadena[i] == '.' && flagPunto == 0)
		{
			flagPunto = 1;
			continue;
		}
		if(!isdigit(cadena[i]))
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}

/// @fn int getInt(void)
/// @brief Verifica si la cadena ingresada es numerica flotante, si lo es,
/// convierte la cadena en flotante y la retorna.
///
/// @return  El numero entero.
int getFloat(float* pNumero)
{
	float retorno;
	char bufferFloat[50];

	if(myGets(bufferFloat, sizeof(bufferFloat)) && esNumericoFlotante(bufferFloat, sizeof(bufferFloat)))
	{
		*pNumero = atof(bufferFloat);
		retorno = 1;
	}

	return retorno;
}

/// @fn int estaEnRango(float, float, float)
/// @brief Verifica que el numero este debtro del rango
///
/// @param numero El numero a er abalizado
/// @param minimo Es el numero minimo a ser aceptado
/// @param maximo Es el minimo maximo a ser aceptado
/// @return
int estaEnRangoFloat(float numero, float minimo, float maximo)
{
	int retorno;

	retorno = 1;

	if(numero < minimo || numero > maximo)
	{
		retorno = 0;
	}

	return retorno;
}


/// @fn float getValidFloat(char[], char[], int, int)
/// @brief  Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
///
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje de Error a ser mostrado
/// @param minimo Es el numero maximo a ser aceptado
/// @param maximo Es el minimo minimo a ser aceptado
/// @return Retorna el numero flotante
int getValidFloat(float* pNumero, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno;
	float bufferFloat;

	retorno = 0;

	do
	{
		printf("%s", mensaje);
		if(getFloat(&bufferFloat) && estaEnRangoFloat(bufferFloat, minimo, maximo))
		{
			*pNumero = bufferFloat;
			retorno = 1;
			break;
		}

		printf("%s\n", mensajeError);
		reintentos --;

	}while(reintentos >= 0);

	return retorno;
}
/// @fn int esSoloLetras(char[], int)
/// @brief Verifica si la cadena esta compuesta solo por letras.
///
/// @param cadena Array con la cadena a ser analizada
/// @param longitud Longitud de la cadena.
/// @return 1 si es nœmerico y 0 si no lo es
int esSoloLetras(char cadena[], int longitud)
{
    int retorno;
    int i;
    retorno = 1;
    for(i = 0; i < longitud && cadena[i] != '\0'; i++)
    {
    	if(cadena [i] == 'ñ')
    	{
    		continue;
    	}
        if(!isalpha(cadena[i]))
        {
           	retorno = 0;
        	break;
        }
    }

    return retorno;
}

/// @fn int getStringLetras(char[], int)
/// @brief Verifica si la cadena esta compuesta solo por letras,
/// de ser asi la copia.
///
/// @param cadena Array con la cadena a ser analizada
/// @param longitud Longitud de la cadena
/// @return Retorna 1 si la cadena esta compuesta solo por letras y 0 si no
int getStringLetras(char cadena[], int longitud)
{
	int retorno;
	char auxiliar[51];
	retorno = 0;
	if(myGets(auxiliar, sizeof(auxiliar)) == 0 && esSoloLetras(auxiliar, sizeof(auxiliar)))
	{
		if(strnlen(auxiliar, sizeof(auxiliar)) <= longitud)
		{
			strncpy(cadena, auxiliar, longitud);
			retorno = 1;
		}
	}
	return retorno;
}

/// @fn void getValidStingLetras(char[], int, char[], char[])
/// @brief Solicita una cadena al usuario compuesta solo por letras
///
/// @param cadena
/// @param longitud Longitud de la cadena.
/// @param mensaje El mensaje a ser mostrado
/// @param mensajeError El mensaje de error a ser mostrado
void getValidStingLetras(char cadena[], int longitud, char mensaje[], char mensajeError[])
{
	printf("%s: ", mensaje);
	while(!getStringLetras(cadena, longitud))
	{
		printf("%s", mensajeError);
		printf("\n%s: ", mensaje);

	}
}

/// @fn int esAlfaNumerico(char[], int)
/// @brief Verifica si la cadena esta compuesta solo por letras y/o numeros.
///
/// @param cadena Array con la cadena a ser analizada
/// @param longitud Longitud de la cadena.
/// @return 1 si es alfa nœmerica y 0 si no lo es
int esAlfaNumerico(char cadena[], int longitud)
{
    int retorno;
    int i;

    retorno = 1;
    for(i = 0; i < longitud && cadena[i] != '\0'; i++)
    {
        if(!isalpha(cadena[i]) && !isdigit(cadena[i]))
        {
        	retorno = 0;
        	break;
        }
    }

    return retorno;
}

/// @fn int getStringLetras(char[], int)
/// @brief Verifica si la cadena esta compuesta por letras y/o numeros,
/// de ser asi la copia.
///
/// @param cadena Array con la cadena a ser analizada
/// @param longitud Longitud de la cadena
/// @return Retorna 1 si la cadena esta compuesta solo por letras y 0 si no
int getStringAlfaNumerico(char cadena[], int longitud)
{
	int retorno;
	char auxiliar[51];
	retorno = 0;
	if(myGets(auxiliar, sizeof(auxiliar)) == 0 && esAlfaNumerico(auxiliar, sizeof(auxiliar)))
	{
		if(strnlen(auxiliar, sizeof(auxiliar)) <= longitud)
		{
			strncpy(cadena, auxiliar, longitud);
			retorno = 1;
		}
	}
	return retorno;
}

/// @fn void getValidStingLetras(char[], int, char[], char[])
/// @brief Solicita una cadena alfanumerica al usuario al usuario.
///
/// @param cadena
/// @param longitud Longitud de la cadena.
/// @param mensaje El mensaje a ser mostrado
/// @param mensajeError El mensaje de error a ser mostrado
void getValidStingAlfanumerico(char cadena[], int longitud, char mensaje[], char mensajeError[])
{
	printf("%s: ", mensaje);
	while(!getStringAlfaNumerico(cadena, longitud))
	{
		printf("%s", mensajeError);
		printf("\n%s: ", mensaje);
	}
}

/// @fn void primeraMayuscula(char[])
/// @brief Pasa a mayuscula la primera letra de la cadena
///
/// @param cadena Cadena a la que le va a poner en mayuscula la primer letra.
void primeraMayuscula(char cadena[])
{
	int i;
	int cantidad;
	strlwr(cadena);
	cadena[0] = toupper(cadena[0]);

	cantidad = strlen(cadena);

	for(i = 0; i < cantidad; i++ )
	{
		if(cadena[i] == ' ')
		{
			cadena[i+1] = toupper(cadena[i+1]);
		}
	}
}

/// @fn int esSoloLetras(char[], int)
/// @brief Verifica si la cadena esta compuesta solo por letrasy tiene mas de 3. aceptando puntos y ñ,
///
/// @param cadena Array con la cadena a ser analizada
/// @param longitud Longitud de la cadena.
/// @return 1 si es solo letras y 0 si no lo es
int esSoloLetrasNombre(char cadena[], int longitud)
{
    int retorno;
    int i;
    int contador;

    retorno = 1;
    contador = 0;
    for(i = 0; i < longitud && cadena[i] != '\0'; i++)
    {
    	if(isalpha(cadena[i]) || cadena[i] == 'ñ' || cadena[i] == 'Ñ' )
    	{
    		contador ++;
    	}
    	if(cadena [i] == 'ñ' || cadena[i] == 'Ñ' || cadena[i] == '.')
    	{
    		continue;
    	}
        if(cadena[i] != ' ' && !isalpha(cadena[i]))
        {
           	retorno = 0;
        	break;
        }
    }
    if(contador < 2)
    {
    	retorno = 0;
    }
    return retorno;
}

/// @fn int getStringLetras(char[], int)
/// @brief Verifica si la cadena esta compuesta por letras y tenga mas de 3 caracteres,
/// de ser asi la copia.
///
/// @param cadena Array con la cadena a ser analizada
/// @param longitud Longitud de la cadena
/// @return Retorna 1 si la cadena esta compuesta solo por letras y 0 si no
int getStringNombre(char cadena[], int longitud)
{
	int retorno;
	char auxiliar[51];
	retorno = 0;
	if(myGets(auxiliar, sizeof(auxiliar)) == 0 && esSoloLetrasNombre(auxiliar, sizeof(auxiliar)))
	{
		if(strnlen(auxiliar, sizeof(auxiliar)) <= longitud)
		{
			strncpy(cadena, auxiliar, longitud);
			retorno = 1;
		}
	}
	return retorno;
}

/// @fn void getValidStingLetras(char[], int, char[], char[])
/// @brief Solicita una cadena al usuario compuesta solo por letras y que contenga mas de 3 caracteres y pasa la primera letra a mayuscula
///
/// @param cadena Array con la cadena.
/// @param longitud Longitud de la cadena.
/// @param mensaje El mensaje a ser mostrado
/// @param mensajeError El mensaje de error a ser mostrado
void getValidStingLetrasNombre(char cadena[], int longitud, char mensaje[], char mensajeError[])
{
	printf("%s: ", mensaje);
	while(!getStringNombre(cadena, longitud))
	{
		printf("%s", mensajeError);
		printf("\n%s: ", mensaje);
	}
	primeraMayuscula(cadena);
}

