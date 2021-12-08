#include <iostream>

namespace AccountsSeminar {

    // Reduktion / Beschreibung einer Rolle / eines Aspekts
    // Schnitttelle / Interface
    class IAccount
    {
    public:
        // virtuelle Basisklassendestruktor
        virtual ~IAccount() = default;  // Call-to-Action: IMMER 
        //virtual ~IAccount() { std::cout << "in ~IAccount" << std::endl; }

        // getter/setter
        virtual double getAccountNumber() const = 0;
        virtual double getBalance() const = 0;

        // public interface
        virtual void deposit(double amount) = 0;
        virtual bool withdraw(double amount) = 0;
        virtual bool transfer(double amount, int from, int to) = 0;  // nicht perfekt :(
        virtual void print(std::ostream& os) = 0;

        // https://stackoverflow.com/questions/2059058/c-abstract-class-operator-overloading-and-interface-enforcement-question
        friend std::ostream& operator<< (std::ostream& os, const IAccount& da);
    };

    // ===========================================================

    // Abstrakte Basisklasse / Unvollständige Klasse
    // a) Einige Teile des Kontrakts (Vertrag IAccount) werden realisiert
    // b) Instanzvariablen, die für alle Kindklassen relevant sind, werden definiert (protected)
    class Account : public IAccount
    {
    protected:
        double m_accountNumber;
        double m_balance;

    public:
        // default c'tor / d'tor
        Account(int account);

        // virtual ~Account() = default;
        virtual ~Account() { std::cout << "in ~Account" << std::endl; }

        // getter / setter
        virtual double getAccountNumber() const override final;
        virtual double getBalance() const final override;

        // public interface
        virtual void deposit(double amount) final override;

        // 
        virtual bool transfer(double amount, int from, int to) final override;
    };

    Account::Account(int accountNumber) : m_accountNumber(accountNumber) {
        m_balance = 0;
    }

    void Account::deposit(double amount) {
        m_balance += amount;
    }

    // Design Pattern: Template Method Pattern
    // Schablone einer Methode: transfer
    // Sollte NICHT verändert werden 
    // Abgeleitete Klassen stellen die Realisierungsmethoden bereit
    bool Account::transfer(double amount, int from, int to) {

        if (! withdraw(amount))
            return false;

        deposit(to); 
        return true;
    }

    double Account::getAccountNumber() const {
        return m_accountNumber;
    }

    double Account::getBalance() const {
        return m_balance;
    }

    // ===========================================================

    class CurrentAccount final : public Account
    {
        friend std::ostream& operator<< (std::ostream&, const CurrentAccount&);

    private:
        double m_limit;

    public:
        // c'tors
        CurrentAccount(int account);
        CurrentAccount(int account, double limit);
         ~CurrentAccount() { std::cout << "in ~CurrentAccount" << std::endl; }

        // getter / setter
        double getLimit();
        void setLimit(double limit);

        // public interface
        bool withdraw(double amount) override;
        void print(std::ostream& os) override;
    };

    CurrentAccount::CurrentAccount(int accountNumber)
        : CurrentAccount(accountNumber, 1000.0) {}

    CurrentAccount::CurrentAccount(int account, double limit)
        : Account(account) {
        m_limit = limit;
    }

    bool CurrentAccount::withdraw(double amount) {
        if (m_balance + m_limit < amount)
            return false;

        m_balance -= amount;
        return true;
    }

    double CurrentAccount::getLimit() {
        return m_limit;
    }

    void CurrentAccount::setLimit(double limit) {
        m_limit = limit;
    }

    void CurrentAccount::print(std::ostream& os) {
        os << *this;
    }

    std::ostream& operator<< (std::ostream& os, const CurrentAccount& ca) {
        os << "CurrentAccount [Nr. " << ca.m_accountNumber << "]:" << std::endl;
        os << "   Balance=" << ca.m_balance << ";" << std::endl;
        os << "   Limit=" << ca.m_limit << "." << std::endl;
        return os;
    }

    // ===========================================================

    class DepositAccount final : public Account
    {
        friend std::ostream& operator<< (std::ostream&, const DepositAccount&);

    private:
        double m_interestRate;

    public:
        // c'tors
        DepositAccount(int account);
        DepositAccount(int account, double interestRate);
        virtual ~DepositAccount() = default;

        // public interface
        bool withdraw(double amount) override;
        void print(std::ostream& os) override;

        void computeInterest(int days);

        // getter / setter
        double getInterestRate();
    };

    DepositAccount::DepositAccount(int accountNumber)
        : Account(accountNumber), m_interestRate(3.0) {}

    DepositAccount::DepositAccount(int accountNumber, double interestRate)
        : Account(accountNumber), m_interestRate(interestRate) {}

    bool DepositAccount::withdraw(double amount) {
        if (m_balance < amount)
            return false;

        m_balance -= amount;
        return true;
    }

    void DepositAccount::computeInterest(int days) {
        double interest =
            (days * m_interestRate * m_balance) / 365.0 / 100.0;

        m_balance += interest;
    }

    double DepositAccount::getInterestRate() {
        return m_interestRate;
    }

    void DepositAccount::print(std::ostream& os) {
        os << *this;
    }

    std::ostream& operator<< (std::ostream& os, const DepositAccount& da) {
        os << "DepositAccount [Nr. " << da.m_accountNumber << "]:" << std::endl;
        os << "   Balance=" << da.m_balance << ";" << std::endl;
        os << "   InterestRate=" << da.m_interestRate << "." << std::endl;
        return os;
    }
}

void test_accounts() 
{
    using namespace AccountsSeminar;

    std::cout << "Testing accounts:" << std::endl;

    //CurrentAccount ca(123456, 1000);
    //ca.deposit(100);
    //ca.withdraw(40);
    //ca.transfer(1, 2, 3);
    //std::cout << ca << std::endl;

    //DepositAccount da(654321, 4.0);
    //da.deposit(200);
    //da.withdraw(120);
    //da.computeInterest(31);
    //std::cout << da << std::endl;

    IAccount* pIA = new CurrentAccount (123456, 1000);
    delete pIA;
}