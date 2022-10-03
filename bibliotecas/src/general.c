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

/// @fn void primeraMayuscula(char[])
/// @brief Lowercase the entire string, then capitalize the first letter of the string and the first letter following a space
///
/// @param str which is going to capitalize the first letter.
void format_Name(char* str)
{
	int i;
	int len;
	strlwr(str);
	str[0] = toupper(str[0]);

	len = strlen(str);

	for(i = 0; i < len; i++ )
	{
		if(str[i] == ' ')
		{
			str[i+1] = toupper(str[i+1]);
		}
	}
}

/// \fn int myGets(char*, int)
/// @brief Read from the input buffer until it finds a '\n' or until it has copied to str
/// a max value of 'len - 1' characters.
///
/// @param str Array where the entered text will be loaded
/// @param len len which defines the size of str
/// @return Returns -1 if there is an error, a  1 if the sitring is obteined and 0 if not
int myGets(char* str, int len)
{
	int rtn;
	char aux[5099];

	rtn = -1;

	if(str != NULL && len > 0)
	{
		rtn = 0;
		fflush(stdin);

		if(fgets(aux, sizeof(aux), stdin) != NULL)
		{
			if(aux[strnlen(aux, sizeof(aux)) - 1] == '\n')
			{
				aux[strnlen(aux, sizeof(aux)) - 1] = '\0';
			}
			if(strnlen(aux, sizeof(aux)) <= len)
			{
				strncpy(str, aux, len);
				rtn = 1;
			}
		 }
	 }
	return rtn;
}

/// \fn int verify_IsNumeric(char*, int)
/// @brief Verifies if the inputted string is numeric
///
/// @param str Array with the string to be analyzed
/// @param len Length of string
/// @return Returns -1 if there is an error, a  1 if the sitring is numeric and 0 if not
int verify_IsNumeric(char* str, int len)
{
	int rtn;
   	int i;

   	rtn = -1;

   	if(str != NULL && len > 0)
 	{
   		rtn = 1;

		for(i = 0; i < len && str[i] != '\0'; i++)
		{
			if(i == 0 && str[i] == '-')
			{
				continue;
			}
			if(!isdigit(str[i]))
			{
				rtn = 0;
				break;
			}
		}
 	}

   	return rtn;
}

/// \fn int verify_IsNumeric(char*, int)
/// @brief Verifies if the inputted string is numeric float
///
/// @param str Array with the string to be analyzed
/// @param len Length of string
/// @return Returns -1 if there is an error, a  1 if the sitring is numeric float and 0 if not
int verify_IsNumericFloat(char* str, int len)
{
	int rtn;
	int flagPoint;

	rtn = -1;
	flagPoint = 0;

	if(str != NULL && len > 0)
	{
		rtn = 1;

		for(int i = 0; i < len && str[i] != '\0'; i++)
		{
			if(i == 0 && str[i] == '-')
			{
				continue;
			}
			if (str[i] == '.' && flagPoint == 0)
			{
				flagPoint = 1;
				continue;
			}
			if(!isdigit(str[i]))
			{
				rtn = 0;
				break;
			}
		}
	}

	return rtn;
}

/// @fn verify_IsInRangeInt(int, int, int)
/// @brief Verifies that the integer number is in the range
///
/// @param number The number to be validated
/// @param min Is the minimum number to be accepted
/// @param max Is the maxaximum to be accepted
/// @return Returns 1 if it is in the range and 0 if it is not
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

/// @fn verify_IsInRangeInt(int, int, int)
/// @brief Verifies that the float number is in the range
///
/// @param number The number to be validated
/// @param min Is the minimum number to be accepted
/// @param max Is the maxaximum to be accepted
/// @return Returns 1 if it is in the range and 0 if it is not
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

/// \fn int verify_IsPositiveNegativeCero(int)
/// \brief Verify if the number is positive, negative or zero
///
/// \param number The number to verify
/// \return -1 if the number is negative, 1 if the number is positive, 0 if the number is 0
int verify_IsPositiveNegativeZero(int number)
{
	int rtn;

	if(number < 1)
	{
		rtn = -1;
	}
	else
	{
		if(number > 1)
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

/// \fn int verify_IsNumeric(char*, int)
/// @brief Verifies if the inputted string is alphanumeric
///
/// @param str Array with the string to be analyzed
/// @param len Length of string
/// @return Returns -1 if there is an error, a  1 if the sitring is alphanumeric and 0 if not
int verify_IsAlphanumeric(char str[], int len)
{
    int rtn;
    int i;

    rtn = -1;

    if(str != NULL && len > 0)
    {
		rtn = 0;

    	for(i = 0; i < len && str[i] != '\0'; i++)
		{
			if(!isalpha(str[i]) && !isdigit(str[i]))
			{
				rtn = 0;
				break;
			}
		}
    }

    return rtn;
}

/// \fn int verify_IsNumeric(char*, int)
/// @brief Verifies if the inputted string contains only letters
///
/// @param str Array with the string to be analyzed
/// @param len Length of string
/// @return Returns -1 if there is an error, a  1 if the sitring is only letters and 0 if not
int verify_IsLetters(char* str, int len)
{
    int rtn;
    int i;

    rtn = -1;

    if(str != NULL)
    {
    	rtn = 1;

		for(i = 0; i < len && str[i] != '\0'; i++)
		{
			if(str [i] == 'ñ')
			{
				continue;
			}
			if(!isalpha(str[i]))
			{
				rtn = 0;
				break;
			}
		}
    }

    return rtn;
}

/// \fn int verify_IsNumeric(char*, int)
/// @brief Verifies if the inputted string contains only letters, accepting one one space
///
/// @param str Array with the string to be analyzed
/// @param len Length of string
/// @return Returns -1 if there is an error, a  1 if the sitring contains only letters with or without one space and 0 if not
int verify_IsLettersWithSpace(char* str, int len)
{
    int rtn;
    int i;
    int flagSpace;

    rtn = -1;
    flagSpace = 0;

    if(str != NULL)
    {
    	rtn = 1;

		for(i = 0; i < len && str[i] != '\0'; i++)
		{
			if(str [i] == 'ñ')
			{
				continue;
			}
			if(isspace(str[i]) && flagSpace == 0)
			{
				flagSpace = 1;
			}
			if(!isalpha(str[i]))
			{
				rtn = 0;
				break;
			}
		}
    }

    return rtn;
}

/// @fn verify_IsLettersName(char[], int)
/// @fn int check_IsLetters(char[], int)
/// @brief Verifies if the string is composed only of letters and has more than 3. Accepting periods and ñ
///
/// @param str Array with the string to parse
/// @param len len of the string.
/// @return Returns -1 if there is an error, it's just letters and 0 if it's not
int verify_IsLettersName(char* str, int len)
{
    int rtn;
    int i;

    rtn = -1;

    if(str != NULL && len > 0)
    {
    	rtn = 1;

   		for(i = 0; i < len && str[i] != '\0'; i++)
		{
			if(str [i] == 'ñ' || str[i] == 'Ñ')
			{
				continue;
			}
			if(!isalpha(str[i]))
			{
				rtn = 0;
				break;
			}
		}

   		if(strlen(str) < 4)
		{
			rtn = 0;
		}
    }

    return rtn;
}

/// \fn int get_Int(int*)
/// \brief Get an integer number
///
/// \param pNumber Pointer to the memory space where the result of the function will be placed
/// \return Returns -1 if there is an error, 1 if the integer number is obteined, 0 if not
int get_Int(int* pNumber)
{
	int rtn;
	char aux[50];

	rtn = -1;

	if(pNumber != NULL)
	{
		rtn = 0;

		if(myGets(aux, sizeof(aux)) == 1 && verify_IsNumeric(aux, sizeof(aux)) == 1)
		{
			*pNumber  = atoi(aux);
			rtn = 1;
		}
	}

	return rtn;
}

/// \fn int get_Int(int*)
/// \brief Get an float number
///
/// \param pNumber Pointer to the memory space where the result of the function will be placed
/// \return Returns -1 if there is an error, 1 if the float number is obteined, 0 if not
int get_Float(float* pNumber)
{
	float rtn;
	char aux[50];

	rtn = -1;

	if(pNumber != NULL)
	{
		rtn = 0;

		if(myGets(aux, sizeof(aux)) == 1 && verify_IsNumericFloat(aux, sizeof(aux)) == 1)
		{
			*pNumber = atof(aux);
			rtn = 1;
		}
	}

	return rtn;
}

/// \fn int get_StringLettters(char*, int)
/// \brief Get a sting containing only letters
///
/// \param str Array where the string will be copied
/// \param len Length of the array where the string will be copied
/// \return Returns -1 if there is an error, 1 if the string has been copied, 0 if not
int get_StringLettters(char* str, int len)
{
	int rtn;
	char aux[51];

	rtn = -1;

	if(str != NULL && len > 0)
	{
		rtn = 0;

		if(myGets(aux, sizeof(aux)) == 1 && verify_IsLetters(aux, sizeof(aux)) == 1)
		{
			if(strnlen(aux, sizeof(aux)) <= len)
			{
				strncpy(str, aux, len);
				rtn = 1;
			}
		}
	}
	return rtn;
}

/// \fn int get_ValidInt(int*, char*, char*, int, int, int)
/// \brief Requests an integer number from the user, after verifying it returns it
///
/// \param pNumber Pointer to the memory space where the result of the function will be placed
/// \param message Message to be displayed
/// \param errorMessage The error message to be displayed
/// \param min The minimum number to be accepted
/// \param max The maximum number to be accepted
/// \return Returns -1 if there is an error, 1 if the integer number is obteined,  and 0 if not
int get_ValidInt(int* pNumber, char* message , char* errorMessage , int min, int max)
{
	int rtn;
	int aux;

	rtn = -1;

	if(pNumber != NULL)
	{
		rtn = 0;

		do
		{
			printf("%s (min %d, max %d): ", message , min, max);
			if(get_Int(&aux) == 1 && verify_IsInRangeInt(aux, min, max))
			{
				*pNumber = aux;
				rtn = 1;
				break;
			}

			printf("%s\n", errorMessage );

		}while(rtn == 0);
	}

	return rtn;
}


/// \fn int get_ValidIntRetries(int*, char*, char*, int, int, int)
/// \brief Requests an integer number from the user, after verifying it returns it
/// the user has a certain amount of attempts to enter a valid number
///
/// \param pNumber Pointer to the memory space where the result of the function will be placed
/// \param message Message to be displayed
/// \param errorMessage The error message to be displayed
/// \param min The minimum number to be accepted
/// \param max The maximum number to be accepted
/// \param retries The number of retries the user has
/// \return Returns -1 if there is an error, 1 if the integer number is obteined,  and 0 if not
int get_ValidIntRetries(int* pNumber, char* message , char* errorMessage , int min, int max, int retries)
{
	int rtn;
	int aux;

	rtn = -1;

	if(pNumber != NULL && retries > 0)
	{
		rtn = 0;

		do
		{
			printf("%s (min %d, max %d): ", message , min, max);
			if(get_Int(&aux) == 1 && verify_IsInRangeInt(aux, min, max))
			{
				*pNumber = aux;
				rtn = 1;
				break;
			}

			printf("%s\n", errorMessage );
			retries --;

		}while(retries >= 0);
	}

	return rtn;
}


/// @fn float get_ValidFloat(char[], char[], int, int)
/// \brief Requests an float number from the user, after verifying it returns it
///
/// \param pNumber Pointer to the memory space where the result of the function will be placed
/// \param message Message to be displayed
/// \param errorMessage The error message to be displayed
/// \param min The minimum number to be accepted
/// \param max The maximum number to be accepted
/// \return Returns -1 if there is an error, 1 if the float number is obteined,  and 0 if not
int get_ValidFloat(float* pNumber, char* message , char* errorMessage , float min, float max)
{
	int rtn;
	float aux;

	rtn = -1;

	if(pNumber != NULL)
	{
		rtn = 0;

		do
		{
			printf("%s (min %.2f, max %.2f): ", message , min, max);
			if(get_Float(&aux) == 1 && verify_IsInRangeFloat(aux, min, max))
			{
				*pNumber = aux;
				rtn = 1;
				break;
			}

			printf("%s\n", errorMessage );

		}while(rtn == 0);
	}

	return rtn;
}

/// \fn int get_ValidFloatRetries(float*, char*, char*, float, float, int)
/// \brief Requests an float number from the user, after verifying it returns it
/// the user has a certain amount of attempts to enter a valid number
///
/// \param pNumber Pointer to the memory space where the result of the function will be placed
/// \param message Message to be displayed
/// \param errorMessage The error message to be displayed
/// \param min The minimum number to be accepted
/// \param max The maximum number to be accepted
/// \param retries The number of retries the user has
/// \return Returns -1 if there is an error, 1 if the integer float is obteined,  and 0 if not
int get_ValidFloatRetries(float* pNumber, char* message , char* errorMessage , float min, float max, int retries)
{
	int rtn;
	float aux;

	rtn = -1;

	if(pNumber != NULL && retries > 0)
	{
		rtn = 0;

		do
		{
			printf("%s (min %.2f, max %.2f): ", message , min, max);
			if(get_Float(&aux) == 1 && verify_IsInRangeFloat(aux, min, max)==1)
			{
				*pNumber = aux;
				rtn = 1;
				break;
			}

			printf("%s\n", errorMessage );
			retries --;

		}while(retries >= 0);
	}

	return rtn;
}

/// @fn void get_ValidStingLetras(char[], int, char[], char[])
/// @brief Requests a string from the user consisting only of letters
///
/// \param str Array where the string will be copied
/// \param len Length of the array where the string will be copied
/// @param message The message to be displayed
/// @param errorMessage The error message to be displayed
/// \return Returns -1 in case of error, 1 in case of being able to obtain the string and 0 if not
int get_ValidStingLetters(char* str, int len, char message [], char errorMessage [])
{
	int rtn;

	rtn = -1;

	if(str != NULL)
	{
		rtn = 0;

		do
		{
			printf("%s: ", message );

			if(get_StringLettters(str, len) == 1)
			{
				rtn = 1;
				break;
			}

			printf("%s\n", errorMessage );
		}
		while(rtn == 0);
	}

	return rtn;
}

/// @fn void get_ValidStingLetras(char[], int, char[], char[])
/// @brief Requests a string from the user consisting only of letters
///
/// \param str Array where the string will be copied
/// \param len Length of the array where the string will be copied
/// @param message The message to be displayed
/// @param errorMessage The error message to be displayed
/// \param retries The number of retries the user has
/// \return Returns -1 in case of error, 1 in case of being able to obtain the string and 0 if not
int get_ValidStingLettersRetries(char* str, int len, char* message, char* errorMessage, int retries)
{
	int rtn;

	rtn = -1;

	if(str != NULL && retries > 0)
	{
		rtn = 0;

		do
		{
			printf("%s: ", message );

			if(get_StringLettters(str, len) == 1)
			{
				rtn = 1;
				break;
			}

			printf("%s\n", errorMessage );
			retries --;
		}
		while(retries >= 0);
	}

	return rtn;
}


/// @fn int get_StringLettters(char[], int)
/// \brief Get a sting containing only alphanumeric characters
///
/// \param str Array where the string will be copied
/// \param len Length of the array where the string will be copied
/// \return Returns -1 if there is an error, 1 if the string has been copied, 0 if not
int get_StringAlphanumeric(char* str, int len)
{
	int rtn;
	char aux[51];
	rtn = 0;

	if(str != NULL && len > 0)
	{
		rtn = 0;

		if(myGets(aux, sizeof(aux)) == 1 && verify_IsAlphanumeric(aux, sizeof(aux)) == 1)
		{
			if(strnlen(aux, sizeof(aux)) <= len)
			{
				strncpy(str, aux, len);
				rtn = 1;
			}
		}
	}

	return rtn;
}

/// @fn void get_ValidStingLetras(char[], int, char[], char[])
/// @brief Requests a string from the user consisting only alphanumeric characters
///
/// \param str Array where the string will be copied
/// \param len Length of the array where the string will be copied
/// @param message The message to be displayed
/// @param errorMessage The error message to be displayed
/// \return Returns -1 in case of error, 1 in case of being able to obtain the string and 0 if not
int get_ValidStingAlphanumeric(char* str, int len, char message [], char errorMessage [])
{
	int rtn;

	rtn = -1;

	if(str != NULL)
	{
		rtn = 0;

		do
		{
			printf("%s: ", message );

			if(get_StringAlphanumeric(str, len) == 1)
			{
				rtn = 1;
				break;
			}

			printf("%s\n", errorMessage );
		}
		while(rtn == 0);
	}

	return rtn;
}

/// @fn void get_ValidStingLetras(char[], int, char[], char[])
/// @brief Requests a string from the user consisting only of alphanumeric characters
///
/// \param str Array where the string will be copied
/// \param len Length of the array where the string will be copied
/// @param message The message to be displayed
/// @param errorMessage The error message to be displayed
/// \param retries The number of retries the user has
/// \return Returns -1 in case of error, 1 in case of being able to obtain the string and 0 if not
int get_ValidStingAlphanumericRetries(char* str, int len, char* message, char* errorMessage, int retries)
{
	int rtn;

	rtn = -1;

	if(str != NULL && retries > 0)
	{
		rtn = 0;

		do
		{
			printf("%s: ", message );

			if(get_StringLettters(str, len) == 1)
			{
				rtn = 1;
				break;
			}

			printf("%s\n", errorMessage );
			retries --;
		}
		while(retries >= 0);
	}

	return rtn;
}

/// @fn int get_StringLettters(char[], int)
/// \brief Get a sting containing only letters and has more than 3. Accepting periods and ñ
///
/// \param str Array where the string will be copied
/// \param len Length of the array where the string will be copied
/// \return Returns -1 if there is an error, 1 if the string has been copied, 0 if not
int get_StringName(char* str, int len)
{
	int rtn;
	char aux[51];
	rtn = -1;

	if(str != NULL && len > 0)
	{
		rtn = 0;

		if(myGets(aux, sizeof(aux)) == 1 && verify_IsLettersName(aux, sizeof(aux)) == 1)
		{
			if(strnlen(aux, sizeof(aux)) <= len)
			{
				strncpy(str, aux, len);
				rtn = 1;
			}
		}
	}

	return rtn;
}

/// @fn void get_ValidStingLetras(char[], int, char[], char[])
/// @brief Requests a string from the user consisting only of letters
///
/// \param str Array where the string will be copied
/// \param len Length of the array where the string will be copied
/// @param message The message to be displayed
/// @param errorMessage The error message to be displayed
/// \return Returns -1 in case of error, 1 in case of being able to obtain the string and 0 if not
int get_ValidName(char* str, int len, char* message, char* errorMessage)
{
	int rtn;

	rtn = -1;

	if(str != NULL)
	{
		rtn = 0;

		do
		{
			printf("%s: ", message );

			if(get_StringName(str, len) == 1)
			{
				format_Name(str);
				rtn = 1;
				break;
			}

			printf("%s\n", errorMessage );
		}
		while(rtn == 0);
	}

	return rtn;
}

/// @fn void get_ValidStingLetras(char[], int, char[], char[])
/// @brief Requests a string from the user consisting only of letters and has more than 3. Accepting periods and ñ
///
/// \param str Array where the string will be copied
/// \param len Length of the array where the string will be copied
/// @param message The message to be displayed
/// @param errorMessage The error message to be displayed
/// \param retries The number of retries the user has
/// \return Returns -1 in case of error, 1 in case of being able to obtain the string and 0 if not
int get_ValidNameRetries(char* str, int len, char* message, char* errorMessage, int retries)
{
	int rtn;

	rtn = -1;

	if(str != NULL && retries > 0)
	{
		rtn = 0;

		do
		{
			printf("%s: ", message );

			if(get_StringName(str, len) == 1)
			{
				format_Name(str);
				rtn = 1;
				break;
			}

			printf("%s\n", errorMessage );
			retries --;
		}
		while(retries >= 0);
	}

	return rtn;
}



/// \fn int menu(char*, char*, char*, char*, char*, char*)
/// \brief Imprime por pantalla un menu con 7 printf, que van a contener las opciones,
/// despues pide un numero entero al usuario que sea valido, dependiendo de las opciones del menu,
/// y si lo es, lo retorna.
///
/// \param titulo El titulo a mostrar en el menu
/// \param opcionUno Primera opcion del menu
/// \param opcionDos Segunda opcion del menu
/// \param opcionTres Tercera opcion del menu
/// \param opcionCuatro Cuarta opcion del menu
/// \param opcionCinco Quinta opcion del menu
/// \param opcionSeis Sexta opcion del menu
/// \param maximo Numero maximo a ser aceptado
/// \return El numero que el usuario eligio.
int menu(int* pOption, char* title, char* optionOne, char* optionTwo, char* optionThree,
		char* optionFour, char* optionFive, char* optionSix)
{
	int aux;
	int rtn;

	rtn = -1;

	if(pOption != NULL)
	{
		printf("%s", title);
		printf("%s", optionOne);
		printf("%s", optionTwo);
		printf("%s", optionThree);
		printf("%s", optionFour);
		printf("%s", optionFive);
		printf("%s\n", optionSix);

		if(get_Int(&aux))
		{
			*pOption = aux;
			rtn = 1;
		}
	}

	return rtn;
}
