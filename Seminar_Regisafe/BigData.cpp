// =====================================================================================
// Move Semantics
// =====================================================================================

#include <iostream>

#include "BigData.h"

namespace BigDataExample {

    // c'tors and d'tor
    BigData::BigData() {
        // empty buffer
        m_size = 0;
        m_data = nullptr;
    }

    BigData::BigData(size_t size, int preset) {
        // empty buffer
        m_size = size;
        m_data = new int[m_size];

        // initialize storage
        std::fill(m_data, m_data + m_size, preset);
    }

    // getter
    size_t BigData::size() const {
        return m_size;
    }

    bool BigData::isEmpty() const {
        return m_size == 0;
    }

    // output operator
    std::ostream& operator<< (std::ostream& os, const BigData& data) {
        constexpr bool verbose = false;

        os << "Size: " << data.m_size << " - Data at " << data.m_data;
        if constexpr (verbose) {
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
        std::cout << data << std::endl;
        data = createHugeData();
        std::cout << data << std::endl;
    }

    void test_01_big_data() {

        // copy constructing
        BigData data1(10, 1);
        std::cout << data1 << std::endl;

        BigData data2;
        data2 = data1;
    }
}

void test_big_data()
{
    using namespace BigDataExample;

    test_01_big_data();
}

// =====================================================================================
// End-of-File
// =====================================================================================