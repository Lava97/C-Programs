/*
Description : This file contains function prototypes, structures etc.
Author : Lalit D. Chandwani
Version : 1.0 , 2nd January 2018
Last Modified : 12th January 2018
*/
#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef DATE_H
#define DATE_H
//Boolean constant
typedef enum {FALSE, TRUE} boolean;
//Structure of DATE, represents date, month, year and validity of date.
typedef struct
{
  char dd, mm;
  short yy;
  boolean isValid;
} DATE;

//Function prototypes
boolean IS_LEAP(DATE dt);
boolean validateDATE(DATE *dtPointer);
short year(DATE dt);
short month(DATE dt);
short day(DATE dt);
char * cmonth(DATE dt);
boolean setDATE(DATE *dtPointer, char days, char months, short years);
#endif
