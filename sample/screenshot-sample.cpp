/**
 * C/C++ Pro Theme - Feature Showcase
 * A compact demonstration of enhanced semantic highlighting
 */

#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Global variables with different attributes
int globalVar = 42;
static int staticGlobalVar = 100;
constexpr double MAX_VALUE = 999.99;
#define BUFFER_SIZE 1024

/**
 * Complex number class - demonstrates operator overloading
 */
class Complex {
public:
    Complex(double r, double i) : re(r), im(i) {}
    
    // Operator overload
    Complex operator+(const Complex& other) const {
        return Complex(re + other.re, im + other.im);
    }
    
    void Display() const { 
        cout << re << " + " << im << "i" << endl; 
    }
    
    // Static member
    static const double EPSILON;
    
private:
    double re, im;  // Member variables
};

const double Complex::EPSILON = 1e-10;

// Template function
template <typename T>
T minimum(const T& lhs, const T& rhs) {
    return lhs < rhs ? lhs : rhs;
}

// Base class with virtual functions
class Account {
public:
    explicit Account(double balance) : _balance(balance) {}
    virtual ~Account() = default;
    
    virtual void PrintBalance() const { 
        cout << "Balance: " << _balance << endl; 
    }
    
    // Static method
    static int Calculate(int a, int b) {
        return a + b;
    }
    
protected:
    double _balance;
};

// Derived class
class CheckingAccount : public Account {
public:
    explicit CheckingAccount(double balance) : Account(balance) {}
    
    void PrintBalance() const override { 
        cout << "Checking: " << _balance << endl; 
    }
    
private:
    int transactionCount = 0;
};

int main() {
    cout << "=== C/C++ Pro Theme Demo ===" << endl;
    
    // Variables and operators
    int value = 10;
    int* ptr = &value;
    if (ptr != nullptr && *ptr > 0) {
        cout << "Valid pointer" << endl;
    }
    
    // Objects and operators
    Complex a(1.2, 3.4);
    Complex b(5.6, 7.8);
    Complex c = a + b;
    c.Display();
    
    // Template usage
    auto minVal = minimum<int>(5, 10);
    
    // Polymorphism
    CheckingAccount account(100.00);
    account.PrintBalance();
    
    // Enum class
    enum class Status { None, Started, Completed };
    Status current = Status::Started;
    
    // Smart pointer
    shared_ptr<string> smartPtr = make_shared<string>("demo");
    
    cout << "Demo completed!" << endl;
    return 0;
}
