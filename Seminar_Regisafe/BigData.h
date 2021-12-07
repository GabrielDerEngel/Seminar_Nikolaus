namespace BigDataExample {

    class BigData
    {
    private:
        // private member data
        size_t m_size;  // current number of elements
        int* m_data;    // array of elements

    public:
        // c'tors and d'tor (destructor)
        BigData();
        BigData(size_t, int);
        BigData(const BigData&);
        ~BigData();

    public:
        // getter
        size_t size() const;
        bool isEmpty() const;

        // operators
        void operator= (const BigData&);

        // output operator
        friend std::ostream& operator<< (std::ostream&, const BigData&);
    };
}