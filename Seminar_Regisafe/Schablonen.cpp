#include <iostream>
#include <complex>

namespace SchablonenSeminar
{
    //class Calculator
    //{
    //public:
    //    double add(double n, double m) { return n + m; }
    //    double sub(double n, double m) { return n - m; }
    //    double mul(double n, double m) { return n * m; }
    //    double div(double n, double m) { return n / m; }
    //};

    // blueprint / Schablone / template
    template <typename T>
    class Calculator
    {
    public:
        T add(T n, T m) { return n + m; }
        T sub(T n, T m) { return n - m; }
        T mul(T n, T m) { return n * m; }
        T div(T n, T m) { return n / m; }
    };

    // Explizite Template Spezialisierung
    template <>
    class Calculator<int>
    {
    public:
        int add(int n, int m) { return n + m; }
        int sub(int n, int m) { return n - m; }
        int mul(int n, int m) { return n * m; }
        // int div(int n, int m) { return static_cast<int>(n + 0.5 / m); }   // runden !!!!!
        int div(int n, int m) { return static_cast<int>( ( (double) n / m) + 0.5 ) ; }
    };

    // 6 / 10 = 0   // abschneiden / truncate
    // 6 / 10 = 1   // runden !!!

    // C: cast : Typ Wandlung sehr freizügig: Es ist möglich, eine unzulässige Typwandlung vorzunehmen
    
    // C++: Neue Typ Wandlungen: static_cast<>, dynamic_cast<>: Ptr: ==> nullptr


    // Funktionen 
    int minimum(int n, int m)
    {
        return (n < m) ? n : m;
    }

    template <typename T>
    T minimum(T n, T m)
    {
        return (n < m) ? n : m;
    }
}

void test_schablonen()
{
    using namespace SchablonenSeminar;

    // Funktionsschablonen
    int result = minimum(10, 11);

    int result1 = minimum<int>(10, 11);

    double result2 = minimum(100.0, 111.0);   // Automatic Type Deduction  / Automatische Typableitung

    double result3 = minimum<double>(100.0, 111.0);
}


void test_schablonen_klassen()
{
    using namespace SchablonenSeminar;
    using namespace std::complex_literals;

    // nur konzeptionell ....
    Calculator<int> calc10;
    Calculator<int> calc11;

    calc10 = calc11;

    typedef double MyType_;  // classic C++
    using MyType = double;   // modern C++

    using AnotherType = int;   // modern C++

    Calculator<MyType> calc;
    MyType result = calc.add(1.0, 2.0);

    Calculator<AnotherType> calc2;
    AnotherType result2 = calc2.add(10, 11);
    result2 = calc2.div(4, 10);

    Calculator<std::complex<double>> calc3;
    std::complex<double> z1 = 1. + 2i;
    std::complex<double> z2 = 1. - 2i;

    std::complex<double> result3 = calc3.add(z1, z2);
}