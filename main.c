// Tag im Jahr Berechnung
// Refakturierung am 10.05.2021
// erstellt von Fabio Scholle
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bibliothek.h"

int main()
{
    struct Datum date;
    date.month = 1;
    date.day = 1;

    input_date(date);

    return 0;
}
