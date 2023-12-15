/** @file hw_main.c
  * Plik gwny programu
  * $Id$
  */

#include "hw_defs.h"
#include "hw_hello.h"
#include "hw_power.h"

/**
 * Gwna funkcja programu
 * @param argc liczba argumentw wywoania
 * @param argv lista argumentw wywoania
 * @returns rezultat pracy, ew. numer bdu
 */
int main (int argc, char *argv[])
{
    int r;

    r = hello();
    r = calc_pow3(4);

    return r;
}
