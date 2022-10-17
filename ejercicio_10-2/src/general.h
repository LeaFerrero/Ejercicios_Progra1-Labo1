/*
 * general.h
 *
 *  Created on: 1 may. 2022
 *      Author: Leandro Ferrero
 */

#ifndef GENERAL_H_
#define GENERAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void grl_Format_Name(char*);
void grl_Format_Text(char*);

int grl_grl_Verify_IsNumeric(char*, int);
int grl_Verify_IsNumericFloat(char*, int);
int grl_Verify_IsInRangeInt(int, int, int);
int grl_Verify_IsInRangeIntFloat(float, float, float);
int grl_Verify_IsPositiveNegativeZero(int);
int grl_Verify_IsAlphanumeric(char*, int);
int grl_Verify_IsLetters(char*, int);
int grl_Verify_IsLettersWithSpaces(char*, int);
int grl_Verify_Date(int, int, int);

int grl_MyGets(char*, int);
int grl_Get_Int(int*);
int grl_Get_Float(float*);
int grl_Get_StringLettters(char*, int);
int grl_Get_StringLetttersWithSpaces(char*, int);
int grl_Get_StringAlphanumeric(char*, int);

int grl_Get_ValidInt(int*, char*, char*);
int grl_Get_ValidIntPositive(int*, char*, char*);
int grl_Get_ValidFloatPositive(float*, char*, char*);
int grl_Get_ValidIntRange(int*, char*, char*, int, int);
int grl_Get_ValidFloat(float*, char*, char*);
int grl_Get_ValidFloatRange(float*, char*, char*, float, float);
int grl_Get_ValidStingAlphanumeric(char*, int, char*, char*);
int grl_Get_ValidStingLetters(char*, int, char*, char*);
int grl_Get_ValidStingLettersWithSpaces(char*, int, char*, char*);
int grl_Get_ValidName(char*, int, char*, char*);
int grl_Get_ValidIntRetries(int*, char*, char*, int, int, int);
int grl_Get_ValidFloatRetries(float*, char*, char*, float, float, int);
int grl_Get_ValidStingAlphanumericRetries(char*, int, char*, char*, int);
int grl_Get_ValidStingLettersRetries(char*, int, char*, char*, int);
int grl_Get_ValidNameRetries(char*, int, char*, char*, int);
int grl_Get_ValidDate(int*, int*, int*, char*, char*, int, int);

int grl_Menu(int*, char*, char*, char*, char*, char*, char*, char*, char*, char*, char*, char*);
int grl_MenuSN(char*);

#endif /* GENERAL_H_ */
