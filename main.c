#include <stdio.h>
#include <stdlib.h>

int tage_im_jahr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int jahr;
int monat;
int tag;
int tageInsgesamt = 0;
int check = 0;

// Funktion zur Schaltjahrbestimmung
int schaltjahr(int aJahr)
{
    if(aJahr%4 != 0)
        return 0;

    else if(aJahr%100 != 0)
        return 1;

    else if(aJahr%400 != 0)
        return 0;

    else
        return 1;
}

int min(int a, int b)
{
    int result;
    if(a>b)
        result = b;
    else
        result = a;
    return result;
}

int max(int a, int b)
{
    int result;
    if(a<b)
        result = b;
    else
        result = a;
    return result;
}

int main()
{
    //Jahreseingabe
    do
    {
        printf("Geben Sie das Jahr ein: ");
        scanf("%i", &jahr);
        if(jahr < 0 || jahr > 9999)
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
        if(monat < 1 || monat > 12)
        {
            printf("Der Monat ist ungueltig!\n");
            check = 1;
            continue;
        }
        check = 0;
        // Schaltjahrcheck
        if(monat >= 2)
        {
            tage_im_jahr[1] += schaltjahr(jahr);
        }

    } while(check);

    //Tageseingabe
    do
    {
        printf("Geben Sie den Tag ein: ");
        scanf("%i", &tag);
        if(tag < 1 || tag > tage_im_jahr[monat-1])
        {
            printf("Der Tag ist ungueltig!\n");
            check = 1;
            continue;
        }
        check = 0;

    } while(check);

    // HIER WEITERMACHEN!!!!
    for(int i = 0; i < monat-1; i++)
    {
        tageInsgesamt += tage_im_jahr[i];
    }
    tageInsgesamt += tag;
    printf("Es ist der %i. Tag im Jahr", tageInsgesamt);



    return 0;
}
