#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <iostream>
#include <cstring>

const int MAX_SIZE = 10001;

class BigIntegerOverflow : public std::exception {
    const char* what() const noexcept override {
        return "Result is too large";
    }
};


class DivideByZero : public std::exception {
    const char* what() const noexcept override {
        return "You tried to divide by zero";
    }
};

class BigInteger {
    int* number_ = new int[MAX_SIZE];
    int size_ = 1;
    bool isNegative_ = false;
    int Size() const;

public:

    ~BigInteger();

    BigInteger();
    BigInteger(const BigInteger& other);

    BigInteger(const int& other);
    BigInteger& operator=(const BigInteger& other);
    BigInteger(const char* input);

    friend std::istream& operator>>(std::istream& is, BigInteger& value);
    friend std::ostream& operator<<(std::ostream& os, const BigInteger& value);

    friend BigInteger operator+(const BigInteger& a, const BigInteger& b);
    friend BigInteger operator-(const BigInteger& a, const BigInteger& b);
    friend BigInteger operator*(const BigInteger& a, const BigInteger& b);
    friend BigInteger operator/(const BigInteger& a, const BigInteger& b);
    friend BigInteger operator%(const BigInteger& a, const BigInteger& b);

    int& operator[](const int index) const;
    int& operator[](const int index);

    friend bool operator<(const BigInteger& a, const BigInteger& b);
    friend bool operator>(const BigInteger& a, const BigInteger& b);
    friend bool operator==(const BigInteger& a, const BigInteger& b);
    friend bool operator!=(const BigInteger& a, const BigInteger& b);
    friend bool operator<=(const BigInteger& a, const BigInteger& b);
    friend bool operator>=(const BigInteger& a, const BigInteger& b);

    friend BigInteger gcd(const BigInteger& a, const BigInteger& b);
    BigInteger sqrt() const;
};

#endif
