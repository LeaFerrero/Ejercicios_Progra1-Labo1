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

/// \fn void grl_Format_Name(char*)
/// \brief Pasa la cadena a minisculas, luyego pasa la primera letra a mayuscula
/// y la letra que se encuentre despues de un espacio
///
/// \param string Cadena a convertir
void grl_Format_Name(char* string)
{
	int i;
	int len;
	strlwr(string);
	*(string+0) = toupper(*(string+0));

	len = strlen(string);

	for(i = 0; i < len; i++ )
	{
		if(isspace(*(string+i)))
		{
			*(string+i+1) = toupper(*(string+i+1));
		}
	}
}

/// \fn void grl_Format_Text(char*)
/// \brief Pasa la cadena a minisculas, luego pasa la primera letra a mayuscula
///
/// \param string Cadena a convertir
void grl_Format_Text(char* string)
{
	int i;
	int len;
	strlwr(string);

	len = strlen(string);

	for(i = 0; i < len; i++ )
	{
		if(isspace(*(string+i)))
		{
			*(string+i+1) = toupper(*(string+i+1));
			break;
		}
		else
		{
			*(string+0) = toupper(*(string+0));
			break;
		}
	}
}

/// \fn int grl_MyGets(char*, int)
/// @brief Lee desde el bufer de entrada hasta que encuentre un '\n' o hasta que se haya copiado en una cadena
/// un valor máximo de 'len - 1' caracteres.
///
/// @param string Array de caracteres donde se cargara el texto ingresado
/// @param len Tamaño que define el tamaño de la cadena
/// @return Retorna -1 si hay un error, 1 si no obtuvo la cadena y 0 si la pudo obtener
int grl_MyGets(char* string, int len)
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
			if(*(auxilliar+strnlen(auxilliar, sizeof(auxilliar)) - 1) == '\n')
			{
				*(auxilliar+strnlen(auxilliar, sizeof(auxilliar)) - 1) = '\0';
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

/// \fn int grl_Verify_IsNumeric(char*, int)
/// \brief Verifica que la cadena sea numerica
///
/// \param string Array con la cadena a ser analizada
/// \param len Tamaño del array con la cadena a ser analizada
/// \return Retorna -1 en caso de error, 1 si la cadena es numerica y 0 si no
int grl_Verify_IsNumeric(char* string, int len)
{
	int isNumeric;
   	int i;

   	isNumeric = -1;

   	if(string != NULL && len > 0)
 	{
   		isNumeric = 1;

		for(i = 0; i < len && *(string+i) != '\0'; i++)
		{
			if(i == 0 && *(string+i) == '-')
			{
				continue;
			}
			if(!isdigit(*(string+i)))
			{
				isNumeric = 0;
				break;
			}
		}
 	}

   	return isNumeric;
}

/// \fn int grl_Verify_IsNumeric(char*, int)
/// \brief Verifica que la cadena sea numerica flotante
///
/// \param string Array con la cadena a ser analizada
/// \param len Tamaño del array con la cadena a ser analizada
/// \return Retorna -1 en caso de error, 1 si la cadena es numerica flotante y 0 si no
int grl_Verify_IsNumericFloat(char* string, int len)
{
	int isFloat;
	int flagPoint;

	isFloat = -1;
	flagPoint = 0;

	if(string != NULL && len > 0)
	{
		isFloat = 1;

		for(int i = 0; i < len && *(string+i) != '\0'; i++)
		{
			if(i == 0 && *(string+i) == '-')
			{
				continue;
			}
			if (*(string+i) == '.' && flagPoint == 0)
			{
				flagPoint = 1;
				continue;
			}
			if(!isdigit(*(string+i)))
			{
				isFloat = 0;
				break;
			}
		}
	}

	return isFloat;
}

/// \fn int grl_Verify_IsInRangeInt(int, int, int)
/// \brief Verifica que el numero este denro del rango
///
/// \param number El numero a analizar
/// \param min El numero minimo a ser aceptado
/// \param max El numero maximo a ser aceptado
/// \return Retorna 1 si esta en el rango y 0 si no
int grl_Verify_IsInRangeInt(int number, int min, int max)
{
	int isInRange;

	isInRange = 1;

	if(number < min || number > max)
	{
		isInRange = 0;
	}

	return isInRange;
}

/// \fn int grl_Verify_IsInRangeFloat(float, float, float)
/// \brief Verifica que el numero flotante este denro del rango
///
/// \param number El numero a analizar
/// \param min El numero minimo a ser aceptado
/// \param max El numero maximo a ser aceptado
/// \return Retorna 1 si esta en el rango y 0 si no
int grl_Verify_IsInRangeFloat(float number, float min, float max)
{
	int isInRange;

	isInRange = 1;

	if(number < min || number > max)
	{
		isInRange = 0;
	}

	return isInRange;
}

/// \fn int grl_Verify_IsPositiveNegativeZero(int)
/// \brief Verifica que el numero es negativo, positivo o cero
///
/// \param number El numero a ser analizado
/// \return Retorna -1 si el numero es negativo, 1 si es positivo o 0 si es 0
int grl_Verify_IsPositiveNegativeZero(float number)
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

/// \fn int grl_Verify_IsAlphanumeric(char[], int)
/// \brief Verifica que la cadena sea alfanumerica
///
/// \param string Array con la cadena a ser analizada
/// \param len Tamaño del array con la cadena a ser analizada
/// \return Retorna -1 en caso de error, 1 si la cadena es alfanumerica y 0 si no
int grl_Verify_IsAlphanumeric(char string[], int len)
{
    int isAlphanumeric;
    int i;

    isAlphanumeric = -1;

    if(string != NULL && len > 0)
    {
    	isAlphanumeric = 1;

    	for(i = 0; i < len && *(string+i) != '\0'; i++)
		{
			if(!isalpha(*(string+i)) && !isdigit(*(string+i)))
			{
				isAlphanumeric = 0;
				break;
			}
		}
    }

    return isAlphanumeric;
}

/// \fn int grl_Verify_IsLetters(char*, int)
/// \brief Verifica que la cadena este compuesta solo por letras
///
/// \param string Array con la cadena a ser analizada
/// \param len Tamaño del array con la cadena a ser analizada
/// \return Retorna -1 en caso de error, 1 si la cadena esta compuesta por letras y 0 si no
int grl_Verify_IsLetters(char* string, int len)
{
    int isLetters;
    int i;

    isLetters = -1;

    if(string != NULL && len > 0)
    {
    	isLetters = 1;

		for(i = 0; i < len && *(string+i) != '\0'; i++)
		{
			if(string [i] == 'ñ')
			{
				continue;
			}
			if(!isalpha(*(string+i)))
			{
				isLetters = 0;
				break;
			}
		}
    }

    return isLetters;
}

/// \fn int grl_Verify_IsLettersWithSpaces(char*, int)
/// \brief Verifica que la cadena este compuesta solo por letras aceptando un espacio
///
/// \param string Array con la cadena a ser analizada
/// \param len Tamaño del array con la cadena a ser analizad
/// \return Retorna -1 en caso de error, 1 si la cadena esta compuesta por letras y 0 si no
int grl_Verify_IsLettersWithSpaces(char* string, int len)
{
    int isLetters;
    int i;

    isLetters = -1;

    if(string != NULL && len > 0)
    {
    	isLetters = 1;

		for(i = 0; i < len && *(string+i) != '\0'; i++)
		{
			if(*(string+i) == 'ñ' || *(string+i) == 'Ñ')
			{
				continue;
			}
			if(isspace(*(string+i)))
			{
				continue;
			}
			if(!isalpha(*(string+i)))
			{
				isLetters = 0;
				break;
			}
		}
    }

    return isLetters;
}

/// \fn int grl_Get_Int(int*)
/// \brief Obtiene un entero
///
/// \param pNumber Puntero al espacio de memoria donde se dejara el entero
/// @return Retorna -1 si hubo un error, 1 si no obtuvo el entero y 0 si lo pudo obtener
int grl_Get_Int(int* pNumber)
{
	int isError;;
	char auxilliar[50];

	isError = -1;

	if(pNumber != NULL)
	{
		isError = 1;

		if(!grl_MyGets(auxilliar, sizeof(auxilliar)) && grl_Verify_IsNumeric(auxilliar, sizeof(auxilliar)) == 1)
		{
			*pNumber  = atoi(auxilliar);
			isError = 0;
		}
	}

	return isError;
}

/// \fn int grl_Get_Int(int*)
/// \brief Obtiene un flotante
///
/// \param pNumber Puntero al espacio de memoria donde se dejara el flotante
/// @return Retorna -1 si hay un error, 1 si no obtuvo el flotante y 0 si lo pudo obtener
int grl_Get_Float(float* pNumber)
{
	int isError;;
	char auxilliar[50];

	isError = -1;

	if(pNumber != NULL)
	{
		isError = 1;

		if(!grl_MyGets(auxilliar, sizeof(auxilliar)) && grl_Verify_IsNumericFloat(auxilliar, sizeof(auxilliar)) == 1)
		{
			*pNumber = atof(auxilliar);
			isError = 0;
		}
	}

	return isError;
}

/// \fn int grl_Get_StringLettters(char*, int)
/// \brief  Obtiene una cadena de letras
///
/// \param string Array donde la cadena va a ser copiada
/// \param len Tamaño del array donde la cadena va a ser copiada
/// @return Retorna -1 si hay un error, 1 si no obtuvo la cadena y 0 si la pudo obtener
int grl_Get_StringLettters(char* string, int len)
{
	int isError;
	char auxilliar[51];

	isError = -1;

	if(string != NULL && len > 0)
	{
		isError = 1;

		if(!grl_MyGets(auxilliar, sizeof(auxilliar)) && grl_Verify_IsLetters(auxilliar, sizeof(auxilliar)) == 1)
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

/// \fn int grl_Get_StringLetttersWithSpaces(char*, int)
/// \brief  Obtiene una cadena de letras con espacios
///
/// \param string Array donde la cadena va a ser copiada
/// \param len Tamaño del array donde la cadena va a ser copiada
/// @return Retorna -1 si hay un error, 1 si no obtuvo la cadena y 0 si la pudo obtener
int grl_Get_StringLetttersWithSpaces(char* string, int len)
{
	int isError;
	char auxilliar[51];

	isError = -1;

	if(string != NULL && len > 0)
	{
		isError = 1;

		if(!grl_MyGets(auxilliar, sizeof(auxilliar)) && grl_Verify_IsLettersWithSpaces(auxilliar, sizeof(auxilliar)) == 1)
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

/// \fn int grl_Get_StringAlphanumeric(char*, int)
/// \brief  Obtiene una alfanumerica
///
/// \param string Array donde la cadena va a ser copiada
/// \param len Tamaño del array donde la cadena va a ser copiada
/// @return Retorna -1 si hay un error, 1 si no obtuvo la cadena y 0 si la pudo obtener
int grl_Get_StringAlphanumeric(char* string, int len)
{
	int isError;
	char auxilliar[51];

	isError = -1;

	if(string != NULL && len > 0)
	{
		isError = 0;

		if(!grl_MyGets(auxilliar, sizeof(auxilliar)) && grl_Verify_IsAlphanumeric(auxilliar, sizeof(auxilliar)) == 1)
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

/// \fn int grl_Get_ValidInt(int*, char*, char*, int, int)
/// \brief Le pide un numero entero al usuario
///
/// \param pNumber Puntero al espacio de memoria donde el entero sera dejado
/// \param message Mensaje a mostrar
/// \param errorMessage Mensaje de error a mostrar
/// @return Retorna -1 en caso de error, 1 si no obtuvo el nummro y 0 si lo pudo obtener
int grl_Get_ValidInt(int* pNumber, char* message , char* errorMessage)
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
			if(!grl_Get_Int(&auxilliar))
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

/// \fn int grl_Get_ValidIntPositive(int*, char*)
/// \brief Le pide al usuario un nummero entero positivo y lo devuelve
///
/// \param pNumber Puntero al espacio de memoria donde se va a dejar el numero
/// \param message El mensaje a ser mostrado
/// \param errorMessage El mensaje a ser mostrado
/// @return Retorna -1 en caso de error, 1 si no obtuvo el numero y 0 si lo pudo obtener
int grl_Get_ValidIntPositive(int* pNumber, char* message, char* errorMessage)
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
			if(!grl_Get_Int(&auxilliar) && grl_Verify_IsPositiveNegativeZero((float)auxilliar) == 1)
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

/// \fn int grl_Get_ValidFloatPositive(int*, char*)
/// \brief Le pide al usuario un nummero flotante positivo y lo devuelve
///
/// \param pNumber Puntero al espacio de memoria donde se va a dejar el numero
/// \param message El mensaje a ser mostrado
/// \param errorMessage El mensaje a ser mostrado
/// @return Retorna -1 en caso de error, 1 si no obtuvo el numero y 0 si lo pudo obtener
int grl_Get_ValidFloatPositive(float* pNumber, char* message, char* errorMessage)
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
			if(!grl_Get_Float(&auxilliar) && grl_Verify_IsPositiveNegativeZero(auxilliar) == 1)
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

/// \fn int grl_Get_ValidIntRange(int*, char*, char*, int, int)
/// \brief Le pide un numero entero al usuario luego de verificarlo devuelve el resultado
///
/// \param pNumber Puntero al espacio de memoria donde el entero sera dejado
/// \param message Mensaje a mostrar
/// \param errorMessage Mensaje de error a mostrar
/// \param min El numero minimo a ser aceptado
/// \param max El numero maximo a ser aceptado
/// @return Retorna -1 en caso de error, 1 si no obtuvo el numero y 0 si lo pudo obtener
int grl_Get_ValidIntRange(int* pNumber, char* message , char* errorMessage , int min, int max)
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
			if(!grl_Get_Int(&auxilliar) && grl_Verify_IsInRangeInt(auxilliar, min, max))
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

/// @fn float grl_Get_ValidFloat(char[], char[], int, int)
/// \brief Le pide un numero flotante al usuario
///
/// \param pNumber Puntero al espacio de memoria donde el entero sera dejado
/// \param message Mensaje a mostrar
/// \param errorMessage Mensaje de error a mostrar
/// @return Retorna -1 en caso de error, 1 si no obtuvo el numero y 0 si lo pudo obtener
int grl_Get_ValidFloat(float* pNumber, char* message , char* errorMessage)
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
			if(!grl_Get_Float(&auxilliar))
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


/// @fn float grl_Get_ValidFloat(char[], char[], int, int)
/// \brief Le pide un numero flotante al usuario luego de verificarlo devuelve el resultado
///
/// \param pNumber Puntero al espacio de memoria donde el entero sera dejado
/// \param message Mensaje a mostrar
/// \param errorMessage Mensaje de error a mostrar
/// \param min El numero minimo a ser aceptado
/// \param max El numero maximo a ser aceptado
/// @return Retorna -1 en caso de error, 1 si no obtuvo el numero y 0 si lo pudo obtener
int grl_Get_ValidFloatRange(float* pNumber, char* message , char* errorMessage , float min, float max)
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
			if(!grl_Get_Float(&auxilliar) && grl_Verify_IsInRangeFloat(auxilliar, min, max))
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

/// @fn void grl_Get_ValidStingLetras(char[], int, char[], char[])
/// @brief Solicita una cadena del usuario que consta solo de caracteres aflanumericos
///
/// \param string Array donde la cadena sera copiada
/// \param len Longitud de la del array donde sera copiada
/// @param mensaje El mensaje a mostrar
/// @param errorMessage El mensaje de error a mostrar
/// \return Devuelve -1 en caso de error, 1 en caso de no poder obtener la cadena y 0 si la obtuvo
int grl_Get_ValidStingAlphanumeric(char* string, int len, char message [], char errorMessage [])
{
	int isError;

	isError = -1;

	if(string != NULL)
	{
		isError = 0;

		do
		{
			printf("%s: ", message );

			if(!grl_Get_StringAlphanumeric(string, len))
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

/// @fn void grl_Get_ValidStingLetras(char[], int, char[], char[])
/// @brief Solicita una cadena del usuario que consta solo de letras
///
/// \param string Array donde la cadena sera copiada
/// \param len Longitud de la del array donde sera copiada
/// @param mensaje El mensaje a mostrar
/// @param errorMessage El mensaje de error a mostrar
/// \return Devuelve -1 en caso de error, 1 en caso de no poder obtener la cadena y 0 si la obtuvo
int grl_Get_ValidStingLetters(char* string, int len, char message [], char errorMessage [])
{
	int isError;

	isError = -1;

	if(string != NULL)
	{
		isError = 1;

		do
		{
			printf("%s (max %d caracteres): ", message, len-1 );

			if(!grl_Get_StringLettters(string, len))
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

/// @fn void grl_Get_ValidStingLettersWithSpaces(char*, int, char*, char[])
/// @brief Solicita una cadena del usuario que este formada solo por letras, puede contener espacios
///
/// \param string Array donde la cadena sera copiada
/// \param len Longitud de la del array donde sera copiada
/// @param mensaje El mensaje a mostrar
/// @param errorMessage El mensaje de error a mostrar
/// \return Devuelve -1 en caso de error, 1 en caso de no poder obtener la cadena y 0 si la obtuvo
int grl_Get_ValidStingLettersWithSpaces(char* string, int len, char* message, char* errorMessage)
{
	int isError;

	isError = -1;

	if(string != NULL)
	{
		isError = 1;

		do
		{
			printf("%s (max %d caracteres): ", message, len-1 );

			if(!grl_Get_StringLetttersWithSpaces(string, len))
			{
				grl_Format_Text(string);
				isError = 0;
				break;
			}

			printf("%s\n", errorMessage );
		}
		while(isError == 1);
	}

	return isError;
}

/// @fn void grl_Get_ValidName(char*, int, char*, char*)
/// @brief Solicita una cadena del usuario que tenga solo letras y sean mas de 3,
/// si lo  logra formata el  nombre para que este la primer letra en mayuscula y el resto en minuscula
///
/// \param string Array donde la cadena sera copiada
/// \param len Longitud de la del array donde sera copiada
/// @param message El mensaje a mostrar
/// @param errorMessage El mensaje de error a mostrar
/// \return Devuelve -1 en caso de error, 1 en caso de no poder obtener la cadena y 0 si la obtuvo
int grl_Get_ValidName(char* string, int len, char* message, char* errorMessage)
{
	int isError;
	int min;

	min = 3;
	isError = -1;

	if(string != NULL)
	{
		isError = 1;

		do
		{
			printf("%s (min %d max %d caracteres): ", message, min, len-1 );

			if(!grl_Get_StringLetttersWithSpaces(string, len))
			{
				if(strlen(string) > min)
				{
					grl_Format_Name(string);
					isError = 0;
					break;
				}
			}

			printf("%s\n", errorMessage );
		}
		while(isError == 1);
	}

	return isError;
}

/// \fn int grl_Get_ValidIntRetries(int*, char*, char*, int, int, int)
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
int grl_Get_ValidIntRetries(int* pNumber, char* message , char* errorMessage , int min, int max, int retries)
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
			if(!grl_Get_Int(&auxilliar) && grl_Verify_IsInRangeInt(auxilliar, min, max))
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

/// \fn int grl_Get_ValidFloatRetries(float*, char*, char*, float, float, int)
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
int grl_Get_ValidFloatRetries(float* pNumber, char* message , char* errorMessage , float min, float max, int retries)
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
			if(!grl_Get_Float(&auxilliar) && grl_Verify_IsInRangeFloat(auxilliar, min, max))
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

/// @fn void grl_Get_ValidStingLetras(char[], int, char[], char[])
/// @brief Solicita una cadena del usuario que consta solo de caracteres alfanumericos
/// el usuario tiene una determinada cantidad de reintentos para ingresar una cadena
///
/// \param string Array donde la cadena sera copiada
/// \param len Longitud de la del array donde sera copiada
/// @param message El mensaje a mostrar
/// @param errorMessage El mensaje de error a mostrar
/// \param retries Cantidad de reintentos que tiene el usuario
/// \return Retorna -1 en caso de error, 1 si no obtuvo la cadena y 0 si la obtuvo
int grl_Get_ValidStingAlphanumericRetries(char* string, int len, char* message, char* errorMessage, int retries)
{
	int isError;

	isError = -1;

	if(string != NULL && retries > 0)
	{
		isError = 1;

		do
		{
			printf("%s: ", message );

			if(!grl_Get_StringLettters(string, len))
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

/// @fn void grl_Get_ValidStingLetras(char[], int, char[], char[])
/// @brief Solicita una cadena del usuario que consta solo de letras
/// el usuario tiene una determinada cantidad de reintentos para ingresar una cadena
///
/// \param string Array donde la cadena sera copiada
/// \param len Longitud de la del array donde sera copiada
/// @param message El mensaje a mostrar
/// @param errorMessage El mensaje de error a mostrar
/// \param retries Cantidad de reintentos que tiene el usuario
/// \return Retorna -1 en caso de error, 1 si no obtuvo la cadena y 0 si la obtuvo
int grl_Get_ValidStingLettersRetries(char* string, int len, char* message, char* errorMessage, int retries)
{
	int isError;

	isError = -1;

	if(string != NULL && retries > 0)
	{
		isError = 1;

		do
		{
			printf("%s: ", message );

			if(grl_Get_StringLettters(string, len) == 1)
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

/// @fn void grl_Get_ValidStingLetras(char[], int, char[], char[])
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
int grl_Get_ValidNameRetries(char* string, int len, char* message, char* errorMessage, int retries)
{
	int isError;

	isError = -1;

	if(string != NULL && retries > 0)
	{
		isError = 1;

		do
		{
			printf("%s: ", message );

			if(!grl_Get_StringLetttersWithSpaces(string, len))
			{
				if(strlen(string) > 4)
				{
					grl_Format_Name(string);
					isError = 0;
					break;
				}
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
/// \param optionSeven Opcion siete del menu
/// \param optionEight Opcion ocho del menu
/// \param optionNine Opcion nueve del menu
/// \param message Mensaje a mostrar
/// \return Retorna -1 en caso de error, 1 si obtuvo el entero y 0 si no
int grl_Menu(int* pOption, char* title, char* optionOne, char* optionTwo, char* optionThree,
		char* optionFour, char* optionFive, char* optionSix, char* optionSeven, char* optionEight,
		char* optionNine, char* message)
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
		printf("%s", optionSeven);
		printf("%s", optionEight);
		printf("%s\n", optionNine);

		if(!grl_Get_ValidInt(&auxilliar, message, "Error."))
		{
			*pOption = auxilliar;
			isError = 0;
		}
	}

	return isError;
}


/// \fn int grl_MenuSN(char*)
/// \brief Muestra un menu para que el usuario elija entre "si" y "no"
///
/// \param message El mensaje a ser mostrado
/// \return 1 si el usuario ingreso 1, 0 si el usuario ingreso 2
int grl_MenuSN(char* message)
{
	int option;

	do
	{
		printf("\n%s", message);
		printf("\n1. Si");
		printf("\n2. NO\n");

		grl_Get_ValidInt(&option, "\nIngrese una opcion", "Error.");

		switch(option)
		{
			case 1:
				option = 1;
			break;

			case 2:
				option = 0;
			break;

			default:
			printf("Opcion no valida\n");
		}

	}while(option != 1 && option != 0);

	return option;
}

/// \fn int grl_Verify_Date(int, int, int)
/// \brief Verifica que la fecha sea valida
///
/// \param day Dia
/// \param month Mes
/// \param year Año
/// \return Retorna 0 si no es valida y 1 si lo es
int grl_Verify_Date(int day, int month, int year)
{
	int isDate;

	isDate = 0;

	switch(month)
	{
		case 2:
			if(day <= 28 && day > 0)
			{
				isDate = 1;
			}
			else
			{
				if(day == 29 && day > 0)
				{
					if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
					{
						isDate = 1;
					}
					else
					{
						isDate = -1;
					}

				}
			}
		break;

		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(day <= 31 && day > 0)
			{
				isDate = 1;
			}
			else
			{
				isDate = -2;
			}
		break;

		case 4:
		case 6:
		case 9:
		case 11:
			if(day <= 30 && day > 0)
			{
				isDate = 1;
			}
		break;

	}

	return isDate;
}

/// \fn int grl_Get_ValidDate(int*, int*, int*, char*, char*, int, int)
/// \brief Le pide al usuario una fecha valida
/// (Febrero tiene maximo 28 dias a menos que el año sea bisiesto y el maximo es de 29)
/// (Enero, Marzo, Mayo, Julio, Agosto, Octunre y Diciembre tiene  como maximo 31 dias)
///(Abril, )
/// \param day Dia
/// \param month Mes
/// \param year Año
/// \param message Mensaje a ser mostrado
/// \param errorMessage Mensaje de error a ser mostrado
/// \param minYear El año minimo aceptado
/// \param maxYear El año maximo aceptado
/// \return Retorna -1 en caso de error y 0 si pudo obtener la fecha
int grl_Get_ValidDate(int* day, int* month, int* year, char* message, char* errorMessage, int minYear, int maxYear)
{
	int isError;
	int auxilliarDay;
	int auxilliarMonth;
	int auxilliarYear;
	int minDay;
	int minMonth;
	int maxDay;
	int maxMonth;

	isError = -1;
	minDay = 1;
	minMonth = 1;
	maxDay = 31;
	maxMonth = 12;

	if(day != NULL && month != NULL && year != NULL)
	{
		isError = 1;

		do
		{
			printf("%s: ", message);
			if(!grl_Get_ValidIntRange(&auxilliarDay, "Dia", "Error.", minDay, maxDay))
			{
				if(!grl_Get_ValidIntRange(&auxilliarMonth, "Mes", "Error.", minMonth, maxMonth))
				{
					if(!grl_Get_ValidIntRange(&auxilliarYear, "Año", "Error." , minYear, maxYear))
					{
						if(grl_Verify_Date(auxilliarDay, auxilliarMonth, auxilliarYear))
						{
							*day = auxilliarDay;
							*month = auxilliarMonth;
							*year = auxilliarYear;
							isError = 0;

						}
						else
						{
							printf("%s", errorMessage);
						}
					}
				}
			}

		}while(isError == 1);
	}

	return isError;
}
