/** @file hw_hello.c
  * Plik funkcji wypisujcych powitania
  * $Id$
  */

#include <stdio.h>
#include "hw_defs.h"

/**
 * Funkcja wypisuje (prawie) klasyczne powitanie
 * @returns rezultat pracy, ew. numer b��du
 */
int hello (void)
{
    printf("hello(v%d): \tHello cruel world!\n", WERSJA);

    return 0;
}
