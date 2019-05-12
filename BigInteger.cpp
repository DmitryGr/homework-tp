#include "BigInteger.h"

int BigInteger::Size() const {
    for (int i = MAX_SIZE - 1; i >= 0; --i) {
        if (number_[i] != 0) {
            return i + 1;
        }
    }
    return 1;
}

BigInteger::~BigInteger() {
    delete[] number_;
}

BigInteger::BigInteger() {
    size_ = 0;
    isNegative_ = false;
    for (int i = 0; i < MAX_SIZE; ++i) {
        number_[i] = 0;
    }
}
BigInteger::BigInteger(const BigInteger& other) {
    if (other.number_ != this->number_) {
        isNegative_ = other.isNegative_;
        size_ = other.size_;
        for (int i = 0; i < MAX_SIZE; ++i) {
            number_[i] = other.number_[i];
        }
    }
}
BigInteger::BigInteger(const int& other) {
    if (other < 0) {
        isNegative_ = true;
    }

    int copy = other;
    size_ = 0;
    for (int i = 0; i < 1000; ++i) {
        number_[i] = copy % 10;
        ++size_;
        copy /= 10;
        if (copy == 0) {
            break;
        }
    }
    for (int i = size_; i < MAX_SIZE; ++i) {
        number_[i] = 0;
    }
}
BigInteger& BigInteger::operator=(const BigInteger& other) {
    if (this->number_ != other.number_) {
        int needSize = std::max(size_, other.size_);
        size_ = other.size_;
        isNegative_ = other.isNegative_;
        for (int i = 0; i < needSize; ++i) {
            number_[i] = other.number_[i];
        }
    }
    return *this;
}
BigInteger::BigInteger(const char* input) {
    int size = static_cast<int>(strlen(input));
    this->size_ = size;
    if (input[0] == '-') {
        this->isNegative_ = true;
        --this->size_;
    }
    for (int i = 0; i < size; ++i) {
        this->number_[i] = input[size- 1 - i] - '0' ;
    }
    for (int i = size; i < MAX_SIZE; ++i) {
        this->number_[i] = 0;
    }
}

std::istream& operator>>(std::istream& is, BigInteger& value) {
    char* input = new char[MAX_SIZE];
    is >> input;
    value = BigInteger(input);
    delete[] input;
    return is;
}
std::ostream& operator<<(std::ostream& os, const BigInteger& value) {
    if (value.isNegative_) {
        std::cout << '-';
    }
    for (int i = value.size_ - 1; i >= 0; --i) {
        std::cout << value.number_[i];
    }
    return os;
}

BigInteger operator+(const BigInteger& a, const BigInteger& b) {
    BigInteger result;
    int transfer = 0;
    for (int i = 0; i < MAX_SIZE; ++i) {
        if ((i == std::max(a.size_, b.size_) && transfer > 0) || (i < std::max(a.size_, b.size_))) {
            ++result.size_;
        }
        result.number_[i] = (a.number_[i] + b.number_[i] + transfer) % 10;
        transfer = (a.number_[i] + b.number_[i] + transfer) / 10;
    }
    if (transfer > 0) {
        throw BigIntegerOverflow();
    }
    return result;
}
BigInteger operator-(const BigInteger& a, const BigInteger& b) {
    BigInteger result;
    int transfer = 0;
    BigInteger aCopy = a;
    BigInteger bCopy = b;

    for (int i = 0; i < std::max(a.size_, b.size_); ++i) {
        transfer = 0;
        if (aCopy.number_[i] < bCopy.number_[i]) {
            transfer = 10;
            --aCopy.number_[i + 1];
        }
        result.number_[i] = aCopy.number_[i] + transfer - bCopy.number_[i];
    }
    result.size_ = result.Size();
    return result;
}
BigInteger operator*(const BigInteger& a, const BigInteger& b) {
    BigInteger aCopy(a);
    BigInteger bCopy(b);
    BigInteger result = 0;

    for (int i = 0; i < a.size_ + 1; ++i) {
        int transfer = 0;
        for (int j = 0; j < b.size_ + 1; ++j) {
            long long current_composition = result[i + j] + aCopy[i] * bCopy[j] + transfer;
            result[i + j] = current_composition % 10;
            transfer = current_composition / 10;

            if (transfer > 0 && (i + j) == MAX_SIZE) {
                throw BigIntegerOverflow();
            }
        }
    }

    result.size_ = result.Size();
    result.isNegative_ = a.isNegative_ ^ b.isNegative_;
    return result;
}
BigInteger operator/(const BigInteger& a, const BigInteger& b) {
    BigInteger aCopy(a);
    BigInteger bCopy(b);
    BigInteger result = 0;
    BigInteger current = 0;
    if (b == 0) {
        throw DivideByZero();
    }

    int i = 1;
    while (i <= a.size_) {
        if (!(current == 0 && a[a.size_ - i] == 0)) {
            bool more_than_one_digit_required = false;
            while (current < b) {
                if (i <= a.size_) {
                    current = current * 10 + a[a.size_ - i];
                    ++i;
                    if (more_than_one_digit_required) {
                        result = result * 10;
                    }
                    more_than_one_digit_required = true;
                } else {
                    break;
                }
            }
        } else {
            while (a[a.size_ - i] == 0) {
                if (i > a.size_) {
                    return result;
                }
                result = result * 10;
                ++i;
            }
            continue;
        }

        int left = 0, right = 10, x = 0;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (bCopy * middle <= current) {
                x = middle;
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        current = current - b * x;
        result = result * 10 + x;
    }
    if (a < 0 ^ b < 0) {
        result.isNegative_ = true;
    } else {
        result.isNegative_ = false;
    }
    return result;
}
BigInteger operator%(const BigInteger& a, const BigInteger& b) {
    BigInteger result = a - (a / b) * b;
    if (result.isNegative_) {
        result = result + b;
    }
    return result;
}

int& BigInteger::operator[](const int index) const {
    return number_[index];
}
int& BigInteger::operator[](const int index) {
    return number_[index];
}

bool operator<(const BigInteger& a, const BigInteger& b) {
    if (a.size_ > b.size_) {
        return false;
    } else if (a.size_ < b.size_) {
        return true;
    } else {
        for (int i = a.size_ - 1; i >= 0; --i) {
            if (a[i] > b[i]) {
                return false;
            } else if (a[i] < b[i]) {
                return true;
            }
        }
    }
    return false;
}
bool operator>(const BigInteger& a, const BigInteger& b) {
    return b < a;
}
bool operator==(const BigInteger& a, const BigInteger& b) {
    return !(a > b || a < b);
}
bool operator!=(const BigInteger& a, const BigInteger& b) {
    return a > b || a < b;
}
bool operator<=(const BigInteger& a, const BigInteger& b) {
    return a == b || a < b;
}
bool operator>=(const BigInteger& a, const BigInteger& b) {
    return a == b || a > b;
}

BigInteger gcd(const BigInteger& a, const BigInteger& b) {
    BigInteger aCopy = a;
    BigInteger bCopy = b;
    if (a == 0 || b == 0) {
        throw DivideByZero();
    }
    while (aCopy > 0 && bCopy > 0) {
        if (aCopy > bCopy) {
            aCopy = aCopy % bCopy;
        } else {
            bCopy = bCopy % aCopy;
        }
    }
    return (aCopy + bCopy);
}
BigInteger BigInteger::sqrt() const {
    BigInteger left = 0;
    BigInteger right = *this;

    BigInteger x = 0;
    while (left <= right) {
        BigInteger middle = (left + right) / 2;
        if (middle * middle <= *this) {
            x = middle;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return x;
}