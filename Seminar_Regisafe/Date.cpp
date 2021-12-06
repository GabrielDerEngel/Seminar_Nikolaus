// Implementierung / Realisierung

#include "Date.h"

//Date::Date()
//{
//    m_day = 1;
//    m_month = 1;
//    m_year = 1970;
//}

// Verketten von Konstruktoren // Wiederverwenden
Date::Date() : Date (1, 1, 1970)
{ 
}

void tueWasAnderes(Date d)
{
}

//Date::Date() 
//{
//    Date (1, 1, 1970);  // Hier wird in LOKALES Objekt erstellt / mit oder ohne Namen
//
//     tueWasAnderes(Date(1, 1, 1970));
//}

// Wegen der Vererbung // Initialisierung der Vaterklasse
Date::Date(int day, int month) : Date (day, month, 2021) {}

Date::Date(int day, int month, int year)
{
    // Nicht gut
    // m_day = day;

    // besser:
    setDay(day);

    // Optimal
    // (day, month, year);

    // schlecht, wenig Zeit:
    m_month = month;
    m_year = year;
}

void Date::print()
{
    // console output
    std::cout << m_day << ":" << m_month << ":"  << m_year;
}

int Date::diff(const Date& other)   // Security
{
    // int tmp = ++ other.m_day;

    int result = m_day - other.m_day;

    return result;  // sometimes correct result
}

bool Date::operator == (const Date& other)
{
    return 
        m_day == other.m_day and
        m_month == other.m_month and 
        m_year == other.m_year;
}

bool operator == (const Date& left, const Date& right)
{
    return 
        left.getDay() == right.getDay() and
        left.m_month == right.m_month and
        left.m_year == right.m_year;
}

//void Date::setDay(int day)
//{
//    // nicht ganz korrekt, aber besser .............
//    if (day <= 0 || day >= 32)
//        throw std::exception("Illegal day");
//
//    this->day = day;  // Java / C#: this.day = day;
//}

void Date::setDay(int day)
{
    // nicht ganz korrekt, aber besser .............
    if (day <= 0 || day >= 32)
        throw std::exception("Illegal day");

    m_day = day;
}
