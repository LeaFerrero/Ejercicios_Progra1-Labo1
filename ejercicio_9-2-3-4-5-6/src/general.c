/*
 * general.c
 *
 *  Created on: 1 may. 2022
 *      Author: Lenadro Ferrero
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// \fn void format_Name(char*)
/// \brief Pasa la cadena a minisculas, luyego pasa la primera letra a mayuscula
/// y la letra que se encuentre despues de un espacio
///
/// \param string Cadena a convertir
void format_Name(char* string)
{
	int i;
	int len;
	strlwr(string);
	string[0] = toupper(string[0]);

	len = strlen(string);

	for(i = 0; i < len; i++ )
	{
		if(isspace(string[i]))
		{
			string[i+1] = toupper(string[i+1]);
		}
	}
}

/// \fn int myGets(char*, int)
/// @brief Read from the input buffer until it finds a '\n' or until it has copied to string
/// a max value of 'len - 1' characters.
///
/// @param string Array where the entered text will be loaded
/// @param len len which defines the size of string
/// @return Retorna -1 si hay un error, 1 si no obtuvo la cadena y 0 si la pudo obtener
int myGets(char* string, int len)
{
	int isError;;
	char auxilliar[5099];

	isError = -1;

	if(string != NULL && len > 0)
	{
		isError = 1;
		fflush(stdin);

		if(fgets(auxilliar, sizeof(auxilliar), stdin) != NULL)
		{
			if(auxilliar[strnlen(auxilliar, sizeof(auxilliar)) - 1] == '\n')
			{
				auxilliar[strnlen(auxilliar, sizeof(auxilliar)) - 1] = '\0';
			}
			if(strnlen(auxilliar, sizeof(auxilliar)) <= len)
			{
				strncpy(string, auxilliar, len);
				isError = 0;
			}
		 }
	 }
	return isError;
}

/// \fn int verify_IsNumeric(char*, int)
/// \brief Verifica que la cadena sea numerica
///
/// \param string Array con la cadena a ser analizada
/// \param len Tamaño del array con la cadena a ser analizada
/// \return Retorna -1 en caso de error, 1 si la cadena es numerica y 0 si no
int verify_IsNumeric(char* string, int len)
{
	int rtn;
   	int i;

   	rtn = -1;

   	if(string != NULL && len > 0)
 	{
   		rtn = 1;

		for(i = 0; i < len && string[i] != '\0'; i++)
		{
			if(i == 0 && string[i] == '-')
			{
				continue;
			}
			if(!isdigit(string[i]))
			{
				rtn = 0;
				break;
			}
		}
 	}

   	return rtn;
}

/// \fn int verify_IsNumeric(char*, int)
/// \brief Verifica que la cadena sea numerica flotante
///
/// \param string Array con la cadena a ser analizada
/// \param len Tamaño del array con la cadena a ser analizada
/// \return Retorna -1 en caso de error, 1 si la cadena es numerica flotante y 0 si no
int verify_IsNumericFloat(char* string, int len)
{
	int rtn;
	int flagPoint;

	rtn = -1;
	flagPoint = 0;

	if(string != NULL && len > 0)
	{
		rtn = 1;

		for(int i = 0; i < len && string[i] != '\0'; i++)
		{
			if(i == 0 && string[i] == '-')
			{
				continue;
			}
			if (string[i] == '.' && flagPoint == 0)
			{
				flagPoint = 1;
				continue;
			}
			if(!isdigit(string[i]))
			{
				rtn = 0;
				break;
			}
		}
	}

	return rtn;
}

/// \fn int verify_IsInRangeInt(int, int, int)
/// \brief Verifica que el numero este denro del rango
///
/// \param number El numero a analizar
/// \param min El numero minimo a ser aceptado
/// \param max El numero maximo a ser aceptado
/// \return Retorna 1 si esta en el rango y 0 si no
int verify_IsInRangeInt(int number, int min, int max)
{
	int rtn;

	rtn = 1;

	if(number < min || number > max)
	{
		rtn = 0;
	}

	return rtn;
}

/// \fn int verify_IsInRangeFloat(float, float, float)
/// \brief Verifica que el numero flotante este denro del rango
///
/// \param number El numero a analizar
/// \param min El numero minimo a ser aceptado
/// \param max El numero maximo a ser aceptado
/// \return Retorna 1 si esta en el rango y 0 si no
int verify_IsInRangeFloat(float number, float min, float max)
{
	int rtn;

	rtn = 1;

	if(number < min || number > max)
	{
		rtn = 0;
	}

	return rtn;
}

/// \fn int verify_IsPositiveNegativeZero(int)
/// \brief Verifica que el numero es negativo, positivo o cero
///
/// \param number El numero a ser analizado
/// \return Retorna -1 si el numero es negativo, 1 si es positivo o 0 si es 0
int verify_IsPositiveNegativeZero(int number)
{
	int rtn;

	if(number < 0)
	{
		rtn = -1;
	}
	else
	{
		if(number > 0)
		{
			rtn = 1;
		}
		else
		{
			rtn = 0;
		}
	}

	return rtn;
}

/// \fn int verify_IsAlphanumeric(char[], int)
/// \brief Verifica que la cadena sea alfanumerica
///
/// \param string Array con la cadena a ser analizada
/// \param len Tamaño del array con la cadena a ser analizada
/// \return Retorna -1 en caso de error, 1 si la cadena es alfanumerica y 0 si no
int verify_IsAlphanumeric(char string[], int len)
{
    int rtn;
    int i;

    rtn = -1;

    if(string != NULL && len > 0)
    {
		rtn = 1;

    	for(i = 0; i < len && string[i] != '\0'; i++)
		{
			if(!isalpha(string[i]) && !isdigit(string[i]))
			{
				rtn = 0;
				break;
			}
		}
    }

    return rtn;
}

/// \fn int verify_IsLetters(char*, int)
/// \brief Verifica que la cadena este compuesta solo por letras
///
/// \param string Array con la cadena a ser analizada
/// \param len Tamaño del array con la cadena a ser analizada
/// \return Retorna -1 en caso de error, 1 si la cadena esta compuesta por letras y 0 si no
int verify_IsLetters(char* string, int len)
{
    int rtn;
    int i;

    rtn = -1;

    if(string != NULL)
    {
    	rtn = 1;

		for(i = 0; i < len && string[i] != '\0'; i++)
		{
			if(string [i] == 'ñ')
			{
				continue;
			}
			if(!isalpha(string[i]))
			{
				rtn = 0;
				break;
			}
		}
    }

    return rtn;
}

/// \fn int verify_IsLettersWithSpace(char*, int)
/// \brief Verifica que la cadena este compuesta solo por letras aceptando un espacio
///
/// \param string Array con la cadena a ser analizada
/// \param len Tamaño del array con la cadena a ser analizad
/// \return Retorna -1 en caso de error, 1 si la cadena esta compuesta por letras y 0 si no
int verify_IsLettersWithSpace(char* string, int len)
{
    int rtn;
    int i;
    int flagSpace;

    rtn = -1;
    flagSpace = 0;

    if(string != NULL)
    {
    	rtn = 1;

		for(i = 0; i < len && string[i] != '\0'; i++)
		{
			if(string [i] == 'ñ')
			{
				continue;
			}
			if(isspace(string[i]) && flagSpace == 0)
			{
				flagSpace = 1;
				continue;
			}
			if(!isalpha(string[i]))
			{
				rtn = 0;
				break;
			}
		}
    }

    return rtn;
}

/// \fn int verify_IsLettersName(char*, int)
/// \brief Verifica que la cadena esta compuesta solo por letras y si tiene mas de 3
///
/// \param string Array con la cadena a ser analizada
/// \param len Tamaño del array con la cadena a ser analizad
/// \return Retorna -1 en caso de error, 1 si la cadena esta compuesta por letras y tiene mas de 3, y 0 si no
int verify_IsLettersName(char* string, int len)
{
    int rtn;
    int i;

    rtn = -1;

    if(string != NULL && len > 0)
    {
    	rtn = 1;

   		for(i = 0; i < len && string[i] != '\0'; i++)
		{
			if(string [i] == 'ñ' || string[i] == 'Ñ')
			{
				continue;
			}
			if(!isalpha(string[i]))
			{
				rtn = 0;
				break;
			}
		}

   		if(strlen(string) < 4)
		{
			rtn = 0;
		}
    }

    return rtn;
}
/// \fn int get_Int(int*)
/// \brief Obtiene un entero
///
/// \param pNumber Puntero al espacio de memoria donde se dejara el entero
/// @return Retorna -1 si hubo un error, 1 si no obtuvo el entero y 0 si lo pudo obtener
int get_Int(int* pNumber)
{
	int isError;;
	char auxilliar[50];

	isError = -1;

	if(pNumber != NULL)
	{
		isError = 1;

		if(!myGets(auxilliar, sizeof(auxilliar)) && verify_IsNumeric(auxilliar, sizeof(auxilliar)) == 1)
		{
			*pNumber  = atoi(auxilliar);
			isError = 0;
		}
	}

	return isError;
}

/// \fn int get_Int(int*)
/// \brief Obtiene un flotante
///
/// \param pNumber Puntero al espacio de memoria donde se dejara el flotante
/// @return Retorna -1 si hay un error, 1 si no obtuvo el flotante y 0 si lo pudo obtener
int get_Float(float* pNumber)
{
	int isError;;
	char auxilliar[50];

	isError = -1;

	if(pNumber != NULL)
	{
		isError = 1;

		if(!myGets(auxilliar, sizeof(auxilliar)) && verify_IsNumericFloat(auxilliar, sizeof(auxilliar)) == 1)
		{
			*pNumber = atof(auxilliar);
			isError = 0;
		}
	}

	return isError;
}

/// \fn int get_StringLettters(char*, int)
/// \brief  Obtiene una cadena de letras
///
/// \param string Array donde la cadena va a ser copiada
/// \param len Tamaño del array donde la cadena va a ser copiada
/// @return Retorna -1 si hay un error, 1 si no obtuvo la cadena y 0 si la pudo obtener
int get_StringLettters(char* string, int len)
{
	int isError;
	char auxilliar[51];

	isError = -1;

	if(string != NULL && len > 0)
	{
		isError = 0;

		if(!myGets(auxilliar, sizeof(auxilliar)) && verify_IsLetters(auxilliar, sizeof(auxilliar)) == 1)
		{
			if(strnlen(auxilliar, sizeof(auxilliar)) <= len)
			{
				strncpy(string, auxilliar, len);
				isError = 0;
			}
		}
	}
	return isError;
}

/// \fn int get_StringAlphanumeric(char*, int)
/// \brief  Obtiene una alfanumerica
///
/// \param string Array donde la cadena va a ser copiada
/// \param len Tamaño del array donde la cadena va a ser copiada
/// @return Retorna -1 si hay un error, 1 si no obtuvo la cadena y 0 si la pudo obtener
int get_StringAlphanumeric(char* string, int len)
{
	int isError;
	char auxilliar[51];

	isError = -1;

	if(string != NULL && len > 0)
	{
		isError = 0;

		if(!myGets(auxilliar, sizeof(auxilliar)) && verify_IsAlphanumeric(auxilliar, sizeof(auxilliar)) == 1)
		{
			if(strnlen(auxilliar, sizeof(auxilliar)) <= len)
			{
				strncpy(string, auxilliar, len);
				isError = 1;
			}
		}
	}

	return isError;
}

/// \fn int get_StringName(char*, int)
/// \brief Obtiene una cadena compuesta solo por letras y que tenga mas de 3
///
/// \param string Array donde la cadena sera copiada
/// \param len Longitud de la del array donde sera copiada
/// @return Retorna -1 en caso de error, 1 si no obtuvo la cadena y 0 si la pudo obtener
int get_StringName(char* string, int len)
{
	int isError;
	char auxilliar[51];

	isError = -1;

	if(string != NULL && len > 0)
	{
		isError = 1;

		if(!myGets(auxilliar, sizeof(auxilliar)) && verify_IsLettersName(auxilliar, sizeof(auxilliar)) == 1)
		{
			if(strnlen(auxilliar, sizeof(auxilliar)) <= len)
			{
				strncpy(string, auxilliar, len);
				isError = 0;
			}
		}
	}

	return isError;
}

/// \fn int get_ValidInt(int*, char*, char*, int, int)
/// \brief Le pide un numero entero al usuario
///
/// \param pNumber Puntero al espacio de memoria donde el entero sera dejado
/// \param message Mensaje a mostrar
/// \param errorMessage Mensaje de error a mostrar
/// @return Retorna -1 en caso de error, 1 si no obtuvo el nummro y 0 si lo pudo obtener
int get_ValidInt(int* pNumber, char* message , char* errorMessage)
{
	int isError;;
	int auxilliar;

	isError = -1;

	if(pNumber != NULL)
	{
		isError = 1;

		do
		{
			printf("%s: ", message);
			if(!get_Int(&auxilliar))
			{
				*pNumber = auxilliar;
				isError = 0;
				break;
			}

			printf("%s\n", errorMessage);

		}while(isError == 1);
	}

	return isError;
}

/// \fn int get_ValidIntPositive(int*, char*)
/// \brief Le pide al usuario un nummero entero positivo y lo devuelve
///
/// \param pNumber Puntero al espacio de memoria donde se va a dejar el numero
/// \param message El mensaje a ser mostrado
/// \param errorMessage El mensaje a ser mostrado
/// @return Retorna -1 en caso de error, 1 si no obtuvo el numero y 0 si lo pudo obtener
int get_ValidIntPositive(int* pNumber, char* message, char* errorMessage)
{
	int isError;
	int auxilliar;

	isError = -1;

	if(pNumber != NULL)
	{
		isError = 1;

		do
		{
			printf("%s: ", message);
			if(!get_Int(&auxilliar) && verify_IsPositiveNegativeZero(auxilliar) == 1)
			{
				*pNumber = auxilliar;
				isError = 0;
				break;
			}

			printf("%s\n", errorMessage);

		}while(isError == 1);
	}

	return isError;
}

/// \fn int get_ValidIntRange(int*, char*, char*, int, int)
/// \brief Le pide un numero entero al usuario luego de verificarlo devuelve el resultado
///
/// \param pNumber Puntero al espacio de memoria donde el entero sera dejado
/// \param message Mensaje a mostrar
/// \param errorMessage Mensaje de error a mostrar
/// \param min El numero minimo a ser aceptado
/// \param max El numero maximo a ser aceptado
/// @return Retorna -1 en caso de error, 1 si no obtuvo el numero y 0 si lo pudo obtener
int get_ValidIntRange(int* pNumber, char* message , char* errorMessage , int min, int max)
{
	int isError;
	int auxilliar;

	isError = -1;

	if(pNumber != NULL)
	{
		isError = 1;

		do
		{
			printf("%s (min %d, max %d): ", message , min, max);
			if(!get_Int(&auxilliar) && verify_IsInRangeInt(auxilliar, min, max))
			{
				*pNumber = auxilliar;
				isError = 0;
				break;
			}

			printf("%s\n", errorMessage);

		}while(isError == 0);
	}

	return isError;
}

/// @fn float get_ValidFloat(char[], char[], int, int)
/// \brief Le pide un numero flotante al usuario
///
/// \param pNumber Puntero al espacio de memoria donde el entero sera dejado
/// \param message Mensaje a mostrar
/// \param errorMessage Mensaje de error a mostrar
/// @return Retorna -1 en caso de error, 1 si no obtuvo el numero y 0 si lo pudo obtener
int get_ValidFloat(float* pNumber, char* message , char* errorMessage)
{
	int isError;
	float auxilliar;

	isError = -1;

	if(pNumber != NULL)
	{
		isError = 1;

		do
		{
			printf("%s: ", message);
			if(!get_Float(&auxilliar))
			{
				*pNumber = auxilliar;
				isError = 0;
				break;
			}

			printf("%s\n", errorMessage );

		}while(isError == 1);
	}

	return isError;
}


/// @fn float get_ValidFloat(char[], char[], int, int)
/// \brief Le pide un numero flotante al usuario luego de verificarlo devuelve el resultado
///
/// \param pNumber Puntero al espacio de memoria donde el entero sera dejado
/// \param message Mensaje a mostrar
/// \param errorMessage Mensaje de error a mostrar
/// \param min El numero minimo a ser aceptado
/// \param max El numero maximo a ser aceptado
/// @return Retorna -1 en caso de error, 1 si no obtuvo el numero y 0 si lo pudo obtener
int get_ValidFloatRange(float* pNumber, char* message , char* errorMessage , float min, float max)
{
	int isError;
	float auxilliar;

	isError = -1;

	if(pNumber != NULL)
	{
		isError = 1;

		do
		{
			printf("%s (min %.2f, max %.2f): ", message , min, max);
			if(!get_Float(&auxilliar) && verify_IsInRangeFloat(auxilliar, min, max))
			{
				*pNumber = auxilliar;
				isError = 0;
				break;
			}

			printf("%s\n", errorMessage );

		}while(isError == 1);
	}

	return isError;
}

/// @fn void get_ValidStingLetras(char[], int, char[], char[])
/// @brief Solicita una cadena del usuario que consta solo de caracteres aflanumericos
///
/// \param string Array donde la cadena sera copiada
/// \param len Longitud de la del array donde sera copiada
/// @param mensaje El mensaje a mostrar
/// @param errorMessage El mensaje de error a mostrar
/// \return Devuelve -1 en caso de error, 1 en caso de no poder obtener la cadena y 0 si la obtuvo
int get_ValidStingAlphanumeric(char* string, int len, char message [], char errorMessage [])
{
	int isError;

	isError = -1;

	if(string != NULL)
	{
		isError = 0;

		do
		{
			printf("%s: ", message );

			if(!get_StringAlphanumeric(string, len))
			{
				isError = 1;
				break;
			}

			printf("%s\n", errorMessage );
		}
		while(isError == 0);
	}

	return isError;
}

/// @fn void get_ValidStingLetras(char[], int, char[], char[])
/// @brief Solicita una cadena del usuario que consta solo de letras
///
/// \param string Array donde la cadena sera copiada
/// \param len Longitud de la del array donde sera copiada
/// @param mensaje El mensaje a mostrar
/// @param errorMessage El mensaje de error a mostrar
/// \return Devuelve -1 en caso de error, 1 en caso de no poder obtener la cadena y 0 si la obtuvo
int get_ValidStingLetters(char* string, int len, char message [], char errorMessage [])
{
	int isError;

	isError = -1;

	if(string != NULL)
	{
		isError = 1;

		do
		{
			printf("%s: ", message );

			if(!get_StringLettters(string, len))
			{
				isError = 0;
				break;
			}

			printf("%s\n", errorMessage );
		}
		while(isError == 1);
	}

	return isError;
}

/// @fn void get_ValidStingLetras(char[], int, char[], char[])
/// @brief Solicita una cadena del usuario que tenga solo letras y sean mas de 3,
/// si lo  logra formata el  nombre para que este la primer letra en mayuscula y el resto en minuscula
///
/// \param string Array donde la cadena sera copiada
/// \param len Longitud de la del array donde sera copiada
/// @param message El mensaje a mostrar
/// @param errorMessage El mensaje de error a mostrar
/// \return Devuelve -1 en caso de error, 1 en caso de no poder obtener la cadena y 0 si la obtuvo
int get_ValidName(char* string, int len, char* message, char* errorMessage)
{
	int isError;

	isError = -1;

	if(string != NULL)
	{
		isError = 1;

		do
		{
			printf("%s: ", message );

			if(!get_StringName(string, len))
			{
				format_Name(string);
				isError = 0;
				break;
			}

			printf("%s\n", errorMessage );
		}
		while(isError == 1);
	}

	return isError;
}

/// \fn int get_ValidIntRetries(int*, char*, char*, int, int, int)
/// \brief Le pide un numero entero al usuario luego de verificarlo devuelve el resultado
/// el usuario tiene una determinada cantidad de reintentos para ingresar un numero valido
///
/// \param pNumber Puntero al espacio de memoria donde el entero sera dejado
/// \param message Mensaje a mostrar
/// \param errorMessage Mensaje de error a mostrar
/// \param min El numero minimo a ser aceptado
/// \param max El numero maximo a ser aceptado
/// \param retries Cantidad de reintentos que tiene el usuario
/// \return Retorna -1 en caso de error, 1 si no obtuvo el numero y 0 si lo obtuvo
int get_ValidIntRetries(int* pNumber, char* message , char* errorMessage , int min, int max, int retries)
{
	int isError;
	int auxilliar;

	isError = -1;

	if(pNumber != NULL && retries > 0)
	{
		isError = 1;

		do
		{
			printf("%s (min %d, max %d): ", message , min, max);
			if(!get_Int(&auxilliar) && verify_IsInRangeInt(auxilliar, min, max))
			{
				*pNumber = auxilliar;
				isError = 0;
				break;
			}

			printf("%s\n", errorMessage );
			retries --;

		}while(retries >= 0);
	}

	return isError;
}

/// \fn int get_ValidFloatRetries(float*, char*, char*, float, float, int)
/// \brief Le pide un numero flotante al usuario luego de verificarlo devuelve el resultado
/// el usuario tiene una determinada cantidad de reintentos para ingresar un numero valido
///
/// \param pNumber Puntero al espacio de memoria donde el entero sera dejado
/// \param message Mensaje a mostrar
/// \param errorMessage Mensaje de error a mostrar
/// \param min El numero minimo a ser aceptado
/// \param max El numero maximo a ser aceptado
/// \param retries Cantidad de reintentos que tiene el usuario
/// \return Retorna -1 en caso de error, 1 si no obtuvo el numero y 0 si lo obtuvo
int get_ValidFloatRetries(float* pNumber, char* message , char* errorMessage , float min, float max, int retries)
{
	int isError;
	float auxilliar;

	isError = -1;

	if(pNumber != NULL && retries > 0)
	{
		isError = 1;

		do
		{
			printf("%s (min %.2f, max %.2f): ", message , min, max);
			if(!get_Float(&auxilliar) && verify_IsInRangeFloat(auxilliar, min, max))
			{
				*pNumber = auxilliar;
				isError = 0;
				break;
			}

			printf("%s\n", errorMessage );
			retries --;

		}while(retries >= 0);
	}

	return isError;
}

/// @fn void get_ValidStingLetras(char[], int, char[], char[])
/// @brief Solicita una cadena del usuario que consta solo de caracteres alfanumericos
/// el usuario tiene una determinada cantidad de reintentos para ingresar una cadena
///
/// \param string Array donde la cadena sera copiada
/// \param len Longitud de la del array donde sera copiada
/// @param message El mensaje a mostrar
/// @param errorMessage El mensaje de error a mostrar
/// \param retries Cantidad de reintentos que tiene el usuario
/// \return Retorna -1 en caso de error, 1 si no obtuvo la cadena y 0 si la obtuvo
int get_ValidStingAlphanumericRetries(char* string, int len, char* message, char* errorMessage, int retries)
{
	int isError;

	isError = -1;

	if(string != NULL && retries > 0)
	{
		isError = 1;

		do
		{
			printf("%s: ", message );

			if(!get_StringLettters(string, len))
			{
				isError = 0;
				break;
			}

			printf("%s\n", errorMessage );
			retries --;
		}
		while(retries >= 0);
	}

	return isError;
}

/// @fn void get_ValidStingLetras(char[], int, char[], char[])
/// @brief Solicita una cadena del usuario que consta solo de letras
/// el usuario tiene una determinada cantidad de reintentos para ingresar una cadena
///
/// \param string Array donde la cadena sera copiada
/// \param len Longitud de la del array donde sera copiada
/// @param message El mensaje a mostrar
/// @param errorMessage El mensaje de error a mostrar
/// \param retries Cantidad de reintentos que tiene el usuario
/// \return Retorna -1 en caso de error, 1 si no obtuvo la cadena y 0 si la obtuvo
int get_ValidStingLettersRetries(char* string, int len, char* message, char* errorMessage, int retries)
{
	int isError;

	isError = -1;

	if(string != NULL && retries > 0)
	{
		isError = 1;

		do
		{
			printf("%s: ", message );

			if(get_StringLettters(string, len) == 1)
			{
				isError = 0;
				break;
			}

			printf("%s\n", errorMessage );
			retries --;
		}
		while(retries >= 0);
	}

	return isError;
}

/// @fn void get_ValidStingLetras(char[], int, char[], char[])
/// @brief Solicita una cadena del usuario que tenga solo letras y sean mas de 3,
/// si lo  logra formata el  nombre para que este la primer letra en mayuscula y el resto en minuscula
/// el usuario tiene una determinada cantidad de reintentos para ingresar un nombre valido
///
/// \param string Array donde la cadena sera copiada
/// \param len Longitud de la del array donde sera copiada
/// @param message El mensaje a mostrar
/// @param errorMessage El mensaje de error a mostrar
/// \param retries Cantidad de reintentos que tiene el usuario
/// \return Retorna -1 en caso de error, 1 si no obtuvo la cadena y 0 si la obtuvo
int get_ValidNameRetries(char* string, int len, char* message, char* errorMessage, int retries)
{
	int isError;

	isError = -1;

	if(string != NULL && retries > 0)
	{
		isError = 1;

		do
		{
			printf("%s: ", message );

			if(get_StringName(string, len) == 1)
			{
				format_Name(string);
				isError = 0;
				break;
			}

			printf("%s\n", errorMessage );
			retries --;
		}
		while(retries >= 0);
	}

	return isError;
}

/// \fn int menu(int*, char*, char*, char*, char*, char*, char*, char*, char*)
/// \brief Imprime un menu que permite mostrar el titulo y hasta 7 opciones,
/// luego le pide al usuario ingresar un numero entero y lo devuelve
///
/// \param pOption Pntero al espacio de memoria en el que se va a dejar el numero entero
/// \param title Titulo del menu
/// \param optionOne Opcion uno del menu
/// \param optionTwo Opcion dos del menu
/// \param optionThree Opcion tres del menu
/// \param optionFour Opcion cuatro del menu
/// \param optionFive Opcion cinco del menu
/// \param optionSix Opcion seis del menu
/// \param message Mensaje a mostrar
/// \return Retorna -1 en caso de error, 1 si obtuvo el entero y 0 si no
int menu(int* pOption, char* title, char* optionOne, char* optionTwo, char* optionThree,
		char* optionFour, char* optionFive, char* optionSix, char* optionSeven, char* message)
{
	int auxilliar;
	int isError;

	isError = -1;

	if(pOption != NULL)
	{
		isError = 1;

		printf("\n%s", title);
		printf("%s", optionOne);
		printf("%s", optionTwo);
		printf("%s", optionThree);
		printf("%s", optionFour);
		printf("%s", optionFive);
		printf("%s", optionSix);
		printf("%s\n", optionSeven);
		printf("\n%s", message);

		if(!get_Int(&auxilliar))
		{
			*pOption = auxilliar;
			isError = 0;
		}
	}

	return isError;
}

int menuSN(char* message)
{
	int option;

	do
	{
		printf("\n%s", message);
		printf("\n1. Si");
		printf("\n2. NO\n");

		printf("\nIngrese una opcion: ");
		get_Int(&option);

		switch(option)
		{
			case 1:
				option = 1;
			break;

			case 2:
				option = 0;
			break;

			default:
			printf("Opcion no valida");
		}

	}while(option != 1 && option != 0);

	return option;
}
