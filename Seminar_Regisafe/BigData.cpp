// =====================================================================================
// Move Semantics
// =====================================================================================

#include <iostream>

#include "BigData.h"


// Namensraum ohne Namen:
// Sein Inhalt ist NUR IN DIESER Datei verfügbar
namespace {
    void tueWas() {

    }
}


namespace BigDataExample {

    // c'tors and d'tor
    BigData::BigData() {
        // empty buffer
        m_size = 0;
        m_data = nullptr;

        std::cout << "c'tor BigData" << std::endl;
    }

    BigData::BigData(size_t size, int preset) {
        // empty buffer
        m_size = size;
        m_data = new int[size]; // Array der Länge size
        // m_data = new int;

        std::cout << "user defined c'tor BigData" << std::endl;

        // initialize storage
        std::fill(m_data, m_data + m_size, preset);
    }

    BigData::BigData(const BigData& other)
    {
        m_size = other.m_size;

        // neuen Speicher anlegen
        m_data = new int[other.m_size];   // jetzt habe ich neuen Speicher auf dem Heap

        // umkopieren
        for (size_t i = 0; i != m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    BigData::~BigData()
    {
        delete[] m_data;
    }

    // getter
    size_t BigData::size() const {
        return m_size;
    }

    bool BigData::isEmpty() const {
        return m_size == 0;
    }

    // a = b;
    BigData& BigData::operator= (const BigData& other)
    {
        // if (this)  // VÖLLIGER BLÖDSINN 

        // Beteiligte: this,  other
        if ( this != &other ) {  // Yes / Perfekt !!!

            // kurze Variante
            m_size = other.m_size;
            // m_data = other.m_data;  // NEIN: das ist eine flache Kopie

            // RICHTIG:

            // alte linke Seite freigeben
            delete[] m_data;

            // neuen Speicher anlegen
            m_data = new int[other.m_size];   // jetzt habe ich neuen Speicher auf dem Heap

            // umkopieren
            for (size_t i = 0; i != m_size; ++i) {
                m_data[i] = other.m_data[i];
            }
        }

        return *this;   // BigData*  // Wert des Objekts bezeichen
    }

    // output operator
    
    // BigData bd, bd1, bd2;
    // bd = bd1 + bd2;
    // std::cout << bd;
    // operator<< (std::ostream& os, const BigData& data
    
    std::ostream& operator<< (std::ostream& os, const BigData& data) {
        constexpr bool verbose  = false;
        const     bool verbose2 = false;

        os << "Size: " << data.m_size << " - Data at " << data.m_data;
        if constexpr (verbose)    // a) false   / b) true
        {
            os << std::endl;
            os << "{";
            for (size_t i = 0; i < data.m_size; i++) {
                os << data.m_data[i];
                if (i < data.m_size - 1)
                    os << ',';
            }
            os << "}";
        }
        return os;
    }

    // test methods
    BigData createHugeData() {
        BigData data(10, 1);
        return data;
    }

    void test_01_move_semantics() {

        BigData data;

        // std::cout.write("sdfsdf");

        // printf // C++ 20
        // std::fmt("%d"), std::format

        std::cout << data << std::endl;
        data = createHugeData();
        std::cout << data << std::endl;
    }

    void test_01_big_data() {

        BigData data1(10, 1); // C++ / Objekt am Stack / NICHT EXISTENT IN JAVA /
                              // EXISTENT IN C# : Nicht mit class / struct Objekte liegen in C# am STACK  

        BigData* data2 = new BigData(10, 1); // C++ / Objekt am Heap

        BigData* data22 = new BigData[3]; // C++ / 10 Objekte am Heap / 10 Mal der Def-C'tor

        BigData* data23 = new BigData[6]{ { 1, 2},  { },  { 1, 2} };
        BigData* data24 = new BigData[3]{ };

        // BigData data3 = new BigData(10, 1); // == Java / C#

        std::cout << data1 << std::endl;

        delete data2;  // !!!!!!!!!!!!!!!!!!!!
        // Java / C#:  Wird automatisch gemacht
    }

    void test_02_big_data()
    {
        BigData data(2, 1);  // lokal

        BigData* dataDyn = new BigData(3, 1);  // dynamisches

        delete dataDyn;
    }

    void test_03_big_data()
    {
        BigData data(2, 1);  // lokal
        BigData tmp(3, 5);

        bool result = tmp.isEmpty();

        // Maschinencode:  Aufruf -- call // 

        // isEmpty(& tmp);  // Ein Methodenaufruf 

        tmp = data;  // okay

        int a, b, c, d, e;
        a = b = c = d = e = 1;

        a = a;
        tmp = tmp;   // Suizid  // Wiederauferstehung

        // tmp = tmp + 1;   // temporäres Objekt  // mutable / immutable

        tmp = (tmp = data);  // Mehrfachwertzuweisung
    }

    void test_04_big_data()
    {
        BigData data(2, 1); 
        BigData tmp(data);  // tmp ist eine KOPIE von data
    }
}

// BigDataExample::BigData g_data(1, 1);  // global

void test_big_data()
{
    using namespace BigDataExample;

    test_03_big_data();
}

// =====================================================================================
// End-of-File
// =====================================================================================