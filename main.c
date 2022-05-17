// Tag im Jahr Berechnung
// Refakturierung am 10.05.2021
// erstellt von Fabio Scholle
#include <stdio.h>
#include <stdlib.h>

int tage_im_jahr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int jahr;
int monat;
int tag;
int tageInsgesamt = 0;
int check = 0;

// Datumsberechnung
// Eingabe: Day - Tag in einem Jahr. Month - Monat in einem Jahr. Year - Jahr
// Rückgabe: Tage im Jahr. Wenn ungültig, -1
int day_of_the_year(int day, int month, int year)
{
    if(exists_date(day, month, year) == 0)
        return -1;
    for(int i = 0; i < month-1; i++)
    {
        tageInsgesamt += tage_im_jahr[i];
    }
    tageInsgesamt += day;
    if(monat > 2)
        tageInsgesamt += is_leapyear(year);

    return tageInsgesamt;
}

// Datumseingabe. Reine Scanf // Printff-Funktion zur Eingabe von Daten
// Eingabe: ---
// Ausgabe: Nur in der Konsole.
int input_date()
{
    //Jahreseingabe
    do
    {
        printf("Geben Sie das Jahr ein: ");
        scanf("%i", &jahr);
        if(exists_date(1, 1, jahr) == 0)
        {
            printf("Das Jahr ist ungueltig!\n");
            check = 1;
            continue;
        }
        check = 0;
    } while(check);

    //Monatseingabe
    do
    {
        printf("Geben Sie den Monat ein: ");
        scanf("%i", &monat);
        if(exists_date(1,monat,jahr) == 0)
        {
            printf("Der Monat ist ungueltig!\n");
            check = 1;
            continue;
        }
        check = 0;
    } while(check);

    //Tageseingabe
    do
    {
        printf("Geben Sie den Tag ein: ");
        scanf("%i", &tag);
        if(exists_date(tag, monat, jahr) == 0)
        {
            printf("Der Tag ist ungueltig!\n");
            check = 1;
            continue;
        }
        check = 0;

    } while(check);
    printf("Es ist der %i. Tag im Jahr", day_of_the_year(tag, monat, jahr));
    return 0;
}

// Funktion zur Schaltjahrbestimmung
// Eingabe: year - Ein Jahr
// Ausgabe: Vor Jahr 1582: -1 // Ansonsten 0 wenn kein Schaltjahr oder 1 wenn ein Schaltjahr vorliegt
int is_leapyear(int year)
{
    if(year < 1582)
        return -1;

    if(year%4 != 0)
        return 0;

    else if(year%100 != 0)
        return 1;

    else if(year%400 != 0)
        return 0;

    else
        return 1;
}

// Bestimmt wieviele Tage ein bestimmter Monat hat
// Eingabe: month - Monat // year - Jahr
// Ausgabe: Tage im Monat anhand der vorliegenden Monatstabelle
int get_days_for_month(int month, int year)
{
        if(month < 1 || month > 12 || is_leapyear(year) == -1)
            return -1;
        if(month == 2)
            return (tage_im_jahr[month-1] + is_leapyear(year));
        else
            return tage_im_jahr[month-1];
}

// Datumsüberprüfung
// Eingabe: day - ein Tag // month - ein Monat // year - ein Jahr
// Ausgabe: 0 wenn invalid, 1 wenn valid
int exists_date(int day, int month, int year)
{
    if(year < 1582 || year > 2400||
       month < 1 || month > 12||
       day < 1 || day > get_days_for_month(month, year))
       return 0;
    else
        return 1;
}



// Funktion zur Bestimmung der Kleineren von zwei Zahlen
int min(int a, int b)
{
    int result;
    if(a>b)
        result = b;
    else
        result = a;
    return result;
}

// Funktion zur Bestimmung der Größeren von zwei Zahlen
int max(int a, int b)
{
    int result;
    if(a<b)
        result = b;
    else
        result = a;
    return result;
}

// Gibt -1 zurück bei einer negativen und 1 bei einer positiven Zahl. 0 bei Null.
int vorzeichen(int c)
{
    int result = 0;
    if(c > 0)
        result = 1;
    else if(c < 0)
        result = -1;
    return c;
}

int main()
{
    input_date();

    return 0;
}
