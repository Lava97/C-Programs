/*
Description : This file contains definitions of function prototypes.
Author : Lalit D. Chandwani
Version : 1.0 , 2nd January 2018
Last Modified : 12th January 2018
*/
#include "date.h"

boolean IS_LEAP(DATE dt)
{
  short year = dt.yy;

  if (year % 4 != 0){
    return FALSE;
  }
  else{
    if (year % 100 != 0){
      return TRUE;
    }
    else{
      if (year % 400 != 0) {
        return FALSE;
      }
      else{
        return TRUE;
      }
    }
  }
}

char daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char * monthNames[13] = {"\0", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

boolean validateDATE(DATE *dtPointer)
{
  char days = dtPointer->dd;
  char months = dtPointer->mm;
  short years = dtPointer->yy;

  dtPointer->isValid = FALSE;

  if(months == 2 && days > daysOfMonth[months] + IS_LEAP(*dtPointer)){
    return FALSE;
  }
  if(days < 1 || years < 1 || months < 1 || months > 12){
    return FALSE;
  }
  if(months != 2 && days > daysOfMonth[months]){
    return FALSE;
  }
  dtPointer->isValid = TRUE;
  return TRUE;
}

short year(DATE dt)
{
  return dt.isValid ? dt.yy : FALSE;
}

short month(DATE dt)
{
  return dt.isValid ? dt.mm : FALSE;
}

short day(DATE dt)
{
  return dt.isValid ? dt.dd : FALSE;
}

char * cmonth(DATE dt){
  return dt.isValid ? monthNames[dt.mm] : NULL;
}

boolean setDATE(DATE *dtPointer, char days, char months, short years){
  dtPointer->dd = days;
  dtPointer->mm = months;
  dtPointer->yy = years;
  return validateDATE(dtPointer);
}
