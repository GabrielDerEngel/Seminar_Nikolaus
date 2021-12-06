#include "Date.h"

void test_big_data();

// (globale) Funktion im Stile von C
void test_date()
{
    Date zero;
    zero.print();

    Date nikolaus (6, 12);

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
    test_date();
    return 0;
}
