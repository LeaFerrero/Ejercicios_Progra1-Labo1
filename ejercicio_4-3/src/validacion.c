/*
 * validacion.c
 *
 *  Created on: 12 sep. 2022
 *      Author: wilo waiko
 */

int validarCelcius(float temp)
{
	int retorno;

	retorno = 1;

	if(temp >= 0 && temp <= 100)
	{
		retorno = 0;
	}

	return retorno;
}

int validarFahrenheit(float temp)
{
	int retorno;

	retorno = 1;

	if(temp >= 32 && temp <= 212)
	{
		retorno = 0;
	}

	return retorno;
}
