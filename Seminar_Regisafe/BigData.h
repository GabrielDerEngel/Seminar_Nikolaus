namespace BigDataExample {

    class BigData
    {
    private:
        // private member data
        size_t m_size;  // current number of elements
        int* m_data;    // array of elements

    public:
        // c'tors and d'tor
        BigData();
        BigData(size_t, int);

    public:
        // getter
        size_t size() const;
        bool isEmpty() const;

        // output operator
        friend std::ostream& operator<< (std::ostream&, const BigData&);
    };
}