#include "Date.h"

extern void test_big_data();

void swap_with_copy(int n, int m)
{
    int tmp = n;
    n = m;
    m = tmp;
}

// C-style
void swap_with_C_pointer(int* n, int* m)
{
    int tmp = *n;  // * Gib mit Wert, auf den die Adresse zeigt
    *n = *m;
    *m = tmp;  
}

// C++ Style
void swap(int& n, int& m)
{
    int tmp = n;
    n = m;
    m = tmp;
}

void test_parameter()
{
    int x = 123;
    int y = 456;

    swap(x, y);
}

void test_references()
{
    int n = 123;

    // Zeiger / Pointer / C-Style:
    int* ip;
    ip = &n;
    ++ip;         // es wird der ZEIGER inkrementiert
    ++ (*ip);     // es wird die VARIABLE inkrementiert, auf die pi verweist
                  // Wenn 12 und 13 beide ausgeführt werden, korrumpiere ich den Speicher

    // Referenz / C++ Style
    int& ri = n;
    ++ri;         // es wird die VARIABLE inkrementiert, auf die ri verweist
}

// (globale) Funktion im Stile von C
void test_date_02()
{
    Date nikolaus(6, 12);
    Date christmas(24, 12);

    // int diff = nikolaus - christmas;

    bool cmp = (nikolaus == christmas);
    cmp = nikolaus.operator== (christmas);   // don't do that
    cmp = operator== (nikolaus, christmas);  // don't do that
}


void test_date()
{
    Date zero;
    zero.print();

    Date nikolaus (6, 12);

    Date zeroCopy = zero;  // Laufzeit, ist umsonst

    int result = nikolaus.diff(zeroCopy);
    int result2 = nikolaus.diff(Date (24, 12));  // anonymes Objekt / temp. Objekt

    // nikolaus = nikolaus + 1;

    Date today (6, 12, 2021);
    // today.day = 66666;

    try
    {
        today.setDay(6);
    }
    catch (std::exception ex)
    {
        std::cout << "Ein Fehler ist aufgetreten: " << ex.what();
    }

    std::cout << "Hier geht es normal weiter" << std::endl;

    today.print();
}

int main() 
{
    test_date_02();
    //test_date();
    return 0;
}
