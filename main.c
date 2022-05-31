// Tag im Jahr Berechnung
// Refakturierung am 24.05.2021
// erstellt von Fabio Scholle
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bibliothek.h"

int main()
{
    // Deklaration des Structs. Jahr ist absichtlich nicht deklariert.
    struct Datum date;
    date.month = 1;
    date.day = 1;

    // Aufruf von input_date.
    printf("Es ist der %i. Tag im Jahr", input_date(date));

    return 0;
}
