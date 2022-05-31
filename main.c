// Tag im Jahr Berechnung
// Refakturierung am 31.05.2022
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

    // Aufruf von input_date, welches direkt den Tag im Jahres ausgibt
    printf("Es ist der %i. Tag im Jahr", input_date(date));

    return 0;
}
