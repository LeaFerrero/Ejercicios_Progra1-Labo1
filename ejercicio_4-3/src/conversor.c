/*
 * conversor.c
 *
 *  Created on: 12 sep. 2022
 *      Author: wilo waiko
 */


int celciusAFahrenheit(float temp, float* resultado)
{
	int retorno;

	retorno = 1;

	*resultado = (temp * 9/5) + 32;

	retorno = 0;

	return retorno;
}
int fahrenheitACelcius(float temp, float* resultado)
{
	int retorno;

	retorno = 1;

	*resultado = (temp - 32) * 5/9;

	retorno = 0;

	return retorno;
}
