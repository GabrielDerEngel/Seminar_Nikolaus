#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <type_traits>

namespace STLSeminar
{

}

// function
template <typename T>
void tueWasMitElement(const T& n)
{
    std::cout << n << " ";
}

// functor:  "callabe object" : Eine Klasse, die den operator() implementiert

class Worker
{
private:
    int m_data;

public:
    // Stelligkeit: Der operator() hat eine beliebige Stelligkeit
    // void operator() (int a, int b, int c) { m_data++;  return; }
    void operator() (int n) { std::cout << n << " "; }
};


bool treffer(int n) {
    std::cout << "bin in treffer " << n << std::endl;
    return (n == 3) ? true : false;
}

void test_STL()
{
    // Flexibel langes Array:   std::vector

    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(0);
    vec.push_back(9);

    // Traversieren

    // a) VERY, very old style ... don't do that ... C-Stil
    for (size_t i = 0; i != vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // b) Looks like C++, very classic style
    std::for_each(
        std::next(vec.begin()),    // Iteratoren-Objekt für den Anfang
        std::prev(vec.end()),      // Iteratoren-Objekt für das Ende
        tueWasMitElement<int>      // Funktion, die pro Element ausgeführt wird
        // tueWasMitElement<std::vector<int>::value_type>
        // tueWasMitElement< std::remove_reference<decltype (vec[0])>::type >  // Beachte: Typ von vec[0]: int&
    );
    std::cout << std::endl;

    std::for_each(
        vec.begin(),           // Iteratoren-Objekt für den Anfang
        vec.end(),             // Iteratoren-Objekt für das Ende
        tueWasMitElement<int>  // Funktion, die pro Element ausgeführt wird
        // tueWasMitElement<std::vector<int>::value_type>
        // tueWasMitElement< std::remove_reference<decltype (vec[0])>::type >  // Beachte: Typ von vec[0]: int&
    );
    std::cout << std::endl;

    // c) Functor: Looks like C++, classic style
    std::for_each(
        vec.begin(),           // Iteratoren-Objekt für den Anfang
        vec.end(),             // Iteratoren-Objekt für das Ende
        Worker()               // Klasse, die den operator() pro Element ausführt
    );
    std::cout << std::endl;

    int local = 100;

    // d) Lambda: Looks like C++, modern style (anonyme Methoden)
    std::for_each(
        vec.begin(),           // Iteratoren-Objekt für den Anfang
        vec.end(),             // Iteratoren-Objekt für das Ende
        [&local, wert = 10] (int n) mutable {        // anonyme Methode -  per default: const // Type Deduction
            wert++;
            std::cout << n << " [" << wert << "] " << " [" << ++local << "] ";
        }
    );
    std::cout << std::endl << local << std::endl;

    // e) Foreach: Looks like C++, very modern style
    for (int n : vec) {
        std::cout << n << " ";
        if (n == 2)
            break;
    }
    std::cout << std::endl;

    // f) Real C++, you never do this !!!!
    // this is a range based loop inside :)

    // std::vector<int>::iterator anfang = vec.begin();
    // std::vector<int>::iterator ende = vec.end();

    // oder

    auto anfang = vec.begin();
    auto ende = vec.end();

    // auto n = static_cast<short>(124);

    while (anfang != ende) {

        int wert = *anfang;
        std::cout << "[" << wert << "] ";
        ++anfang;
    }
    std::cout << std::endl;

    // ===================================================

    // Wir suchen im Vektor
    std::vector<int>::iterator result = std::find_if(
        vec.begin(),           // Iteratoren-Objekt für den Anfang
        vec.end(),             // Iteratoren-Objekt für das Ende
        treffer                //  function
    );

    if (result == vec.end()) {
        std::cout << "Not Found !!!" << std::endl;
    }
    else {
        std::cout << "Found: " << *result << std::endl;
    }

    // ------------------------------------
    // callable object // functor

    class Treffer
    {
    private:
        int m_gesucht;

    public:
        Treffer(int wert) { m_gesucht = wert; }

        bool operator() (int n) { return m_gesucht == n; }
    };

    result = std::find_if(
        vec.begin(),           // Iteratoren-Objekt für den Anfang
        vec.end(),             // Iteratoren-Objekt für das Ende
        Treffer(2)
    );

    if (result == vec.end()) {
        std::cout << "Not Found !!!" << std::endl;
    }
    else {
        std::cout << "Found: " << *result << std::endl;
    }

    // ------------------------------------
    // lambda

    int local_Gesucht = 4;

    result = std::find_if(
        vec.begin(),           // Iteratoren-Objekt für den Anfang
        vec.end(),             // Iteratoren-Objekt für das Ende
        [gesucht = local_Gesucht] (int n) { return gesucht == n; }  // Lambda
    );

    if (result == vec.end()) {
        std::cout << "Not Found !!!" << std::endl;
    }
    else {
        std::cout << "Found: " << *result << std::endl;
    }

    // ========================================================
    // Sortieren

    std::copy(
        vec.begin(),           // Iteratoren-Objekt für den Anfang
        vec.end(),             // Iteratoren-Objekt für das Ende
        std::ostream_iterator<int>(std::cout, " ")
    );
    std::cout << std::endl;

    std::sort(
        vec.begin(),           // Iteratoren-Objekt für den Anfang
        vec.end()              // Iteratoren-Objekt für das Ende
    );

    std::copy(
        vec.begin(),           // Iteratoren-Objekt für den Anfang
        vec.end(),             // Iteratoren-Objekt für das Ende
        std::ostream_iterator<int>(std::cout, " ")
    );
    std::cout << std::endl;

    // absteigend
    // bool cmp(const Type1 &a, const Type2 &b);
    std::sort(
        vec.begin(),           // Iteratoren-Objekt für den Anfang
        vec.end(),              // Iteratoren-Objekt für das Ende
        [](int a, int b) {
            std::cout << "vergleiche " << a << " mit " << b << std::endl;
            return a > b;   // automatic type deduction von "a < b" - hier vom Typ bool
        }
    );

    std::copy(
        vec.begin(),           // Iteratoren-Objekt für den Anfang
        vec.end(),             // Iteratoren-Objekt für das Ende
        std::ostream_iterator<int>(std::cout, " ")
    );
    std::cout << std::endl;
}

