// Bibliothek zu DayOfTheYear
// Zuletzt bearbeitet am 31.05.2022
// von Fabio Scholle

#include "bibliothek.h"
#include <stdio.h>

// Rechnung für den Tag des Jahres
// Eingabe: Struct Date
// Ausgabe: Int-Wert mit dem Wert des Tag des Jahres
int day_of_the_year(struct Datum date)
{
    // Deklaration der Zählervariable
    int tageInsgesamt = 0;

    // Check: Existiert das Datum?
    if(exists_date(date) == 0)
        return -1;

    // Zählende for-Schleife für alle Monate, die nicht der momentane sind
    for(int i = 0; i < date.month-1; i++)
    {
        tageInsgesamt += get_days_for_month(i+1, date.year);
    }
    // Alle Tage des derzeitigen Monats werden mitgezählt
    tageInsgesamt += date.day;

    // Wenn der Monat nach Februar ist muss das Schaltjahr berücksichtigt werden
    if(date.month > 2)
        tageInsgesamt += is_leapyear(date.year);

    return tageInsgesamt;
}
// Datumseingabe. Reine Scanf // Printff-Funktion zur Eingabe von Daten
// Eingabe: Date-struct, welches befüllt wird
// Ausgabe: Der errechnete Tag des Jahres
int input_date(struct Datum date)
{
    int check = 0;

    //Es folgen die Eingaben für Jahr, Monat und Tag. Die sind immer wieder in Do-While-Schleifen gewrappt um falsche EIngaben abzufangen

    // Jahreseingabe
    do
    {
        printf("Geben Sie das Jahr ein: ");
        scanf("%i", &date.year);
        if(exists_date(date) == 0)
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
        scanf("%i", &date.month);
        if(exists_date(date) == 0)
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
        scanf("%i", &date.day);
        if(exists_date(date) == 0)
        {
            printf("Der Tag ist ungueltig!\n");
            check = 1;
            continue;
        }
        check = 0;

    } while(check);
    return day_of_the_year(date);

}


// Funktion zur Schaltjahrbestimmung
// Eingabe: year - Ein Jahr
// Ausgabe: Vor Jahr 1582: -1 // Ansonsten 0 wenn kein Schaltjahr oder 1 wenn ein Schaltjahr vorliegt
int is_leapyear(int year)
{

    // Berechnung des Algorithmus. Das Schema wurde gefunden auf Wikipedia: https://en.wikipedia.org/wiki/Leap_year#Algorithm
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
        // Definition der Monatstabelle
        int tage_im_jahr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

        // Abfangen von ungültigen Werten
        if(month < 1 || month > 12 || is_leapyear(year) == -1)
            return -1;

        // Rückgabe von Februar mit eventuellen Schalttagen
        if(month == 2)
            return (tage_im_jahr[month-1] + is_leapyear(year));

        //Rückgabe von allen anderen Monaten
        else
            return tage_im_jahr[month-1];
}

// Datumsüberprüfung
// Eingabe: ein date-struct
// Ausgabe: 0 wenn invalid, 1 wenn valid
int exists_date(struct Datum date)
{
    // Abfangen von invaliden Daten
    if(date.year < 1582 || date.year > 2400||
       date.month < 1 || date.month > 12||
       date.day < 1 || date.day > get_days_for_month(date.month, date.year))
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

// WIP
// Gibt den Tag der Woche zurück. "0" für Sonntag und "6" für Samstag
// Eingabe: Day - Tag. Month - Monat. Year - Jahr.
// Rückgabe:
/*int day_of_the_week(int day, int month, int year)
{
    // Check, ob das Datum valide ist
    if(day_of_the_year == -1)
        return -1;

    // Deklaration von Rechenvariablen
    //  Hier: Die Zehnerstellen. Bei Januar oder Februar wird die Zehnerstelle aus dem Vorjahr genommen
    double tens = year % 100;
    if(month == 1 || month == 2)
        tens = (year%100)-1;
    if(tens == -1)
        tens = 99;

    //  Hier: Die Hunderterstellen. Bei Januar oder Februar werden die Hunderterstellen aus dem Vorjahr genommen
    double hundreds;
    if (month == 1 || month == 2)
        hundreds = (year-1) - ((year-1) % 100);
    else
        hundreds = year - (year % 100);

        // WIP: 2.6*month // tens/4 // hundreds/4 braucht ROUNDUP()
    int Wochentag = (day + (2.6*month)-0.2)+tens+(tens/4)+(hundreds/4)-2*hundreds)%7
}
*/

// Gibt den Tag im Jahr zurück
// Eingabe: Day - Tag in einem Jahr. Month - Monat in einem Jahr. Year - Jahr
// Rückgabe: Tage im Jahr. Wenn ungültig, -1
