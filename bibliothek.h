// Header für DayOfTheYear
// Bearbeitet am 31.05.2022
// Von Fabio Scholle

struct Datum {
    int day;
    int month;
    int year;};

int day_of_the_year(struct Datum date);
int input_date(struct Datum date);
int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(struct Datum date);

int min(int a, int b);
int max(int a, int b);
int vorzeichen(int c);
