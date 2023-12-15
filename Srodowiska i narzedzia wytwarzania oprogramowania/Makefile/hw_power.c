/** @file hw_power.c
  * Plik funkcji wypisujcych wyniki operacji mat
  * $Id$
  */

#include <stdio.h>
#include <math.h>
#include "hw_defs.h"

/**
 * Funkcja wylicza i wypisuje 3. potg danej liczby
 * @param   n liczba ktrej potg naley wyliczy
 * @returns   rezultat pracy, ew. numer bdu
 */
int calc_pow3 (int n)
{
    printf("calc_pow3(v%d): \t%d ^ 3 to jest %.2f\n",
	   WERSJA, n, (float)n*n*n);

    return 0;
}
