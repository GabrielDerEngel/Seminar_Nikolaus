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
    // öffentlich Schnittstelle / public interface
    inline void setDay(int day);
    inline int getDay() const { return m_day; }

    int diff( const Date& other );

    Date increment(const Date& other);  // 90% Fall  // 6.12 ==> 7.12

    void print();

    // operators
    // bool operator ! ();  // unärer Operator

    // in der Klasse
    bool operator == (const Date& other);

    friend std::ostream& operator<< (std::ostream&, const Date&);

private:
    // private Schnittstelle / private interface / Hilfsmethoden
    int helper();
    int helper(int para);

    friend bool operator == (const Date& left, const Date& right);
};

// ODER als globale Funktion
bool operator == (const Date& left, const Date& right);

