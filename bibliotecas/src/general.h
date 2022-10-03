/*
 * entradas.h
 *
 *  Created on: 1 may. 2022
 *      Author: wilo waiko
 */

#ifndef GENERAL_H_
#define GENERAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void format_Name(char*);

int verify_IsNumeric(char*, int);
int verify_IsNumericFloat(char*, int);
int verify_IsInRangeInt(int, int, int);
int verify_IsInRangeIntFloat(float, float, float);
int verify_IsPositiveNegativeZero(int);
int verify_IsAlphanumeric(char*, int);
int verify_IsLetters(char*, int);
int verify_IsLettersWithSpace(char*, int);
int verify_IsLettersName(char*, int);

int myGets(char*, int);
int get_Int(int*);
int get_Float(float*);
int get_StringLettters(char*, int);
int get_StringAlphanumeric(char*, int);
int get_StringName(char*, int);

int get_ValidInt(int*, char*, char*, int, int);
int get_ValidFloat(float*, char*, char*, float, float);
int get_ValidIntRetries(int*, char*, char*, int, int, int);
int get_ValidFloatRetries(float*, char*, char*, float, float, int);
int get_ValidStingLetters(char*, int, char*, char*);
int get_ValidStingLettersRetries(char*, int, char*, char*, int);
int get_ValidStingAlphanumeric(char*, int, char*, char*);
int get_ValidStingAlphanumericRetries(char*, int, char*, char*, int);
int get_ValidName(char*, int, char*, char*);
int get_ValidNameRetries(char*, int, char*, char*, int);


int menu(int*, char*, char*, char*, char*, char*, char*, char*, int);

#endif /* GENERAL_H_ */
