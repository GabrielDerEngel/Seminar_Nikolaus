// Definition / Aussehen der Klasse

#pragma once

#include <iostream>

class Date
{
private:

    int m_day;
    int m_month;
    int m_year;

public:
    Date();  // Standard-Konstruktor / Default-Konstruktor
    Date(int day, int month);
    Date(int day, int month, int year);


    // spez. Methoden zum Verändern von Instanzvariablen:
    // setter / getter
    inline void setDay(int day);

    void print();

    friend std::ostream& operator<< (std::ostream&, const Date&);
};
