#include <iostream>
#include <stdexcept>

// The fractionType class represents a rational fraction a/b where a and b are integers and b != 0.
class fractionType {
private:
    int numerator;   // Numerator of the fraction
    int denominator; // Denominator of the fraction

public:
    // Constructor: Initializes the fraction with a numerator and a denominator.
    // Throws std::invalid_argument if the denominator is zero.
    fractionType(int num = 0, int denom = 1) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        numerator = num;
        denominator = denom;
    }

    // Returns the numerator of the fraction.
    int getNumerator() const {
        return numerator;
    }

    // Returns the denominator of the fraction.
    int getDenominator() const {
        return denominator;
    }

    // Sets the numerator of the fraction.
    void setNumerator(int num) {
        numerator = num;
    }

    // Sets the denominator of the fraction.
    // Throws std::invalid_argument if the denominator is zero.
    void setDenominator(int denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        denominator = denom;
    }

    // Operator overload for adding two fractions.
    fractionType operator+(const fractionType& other) const {
        int newNumerator = (numerator * other.denominator) + (other.numerator * denominator);
        int newDenominator = denominator * other.denominator;
        return fractionType(newNumerator, newDenominator);
    }

    // Operator overload for subtracting two fractions.
    fractionType operator-(const fractionType& other) const {
        int newNumerator = (numerator * other.denominator) - (other.numerator * denominator);
        int newDenominator = denominator * other.denominator;
        return fractionType(newNumerator, newDenominator);
    }

    // Operator overload for multiplying two fractions.
    fractionType operator*(const fractionType& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return fractionType(newNumerator, newDenominator);
    }

    // Operator overload for dividing two fractions.
    // Throws std::invalid_argument if the denominator of the other fraction is zero.
    fractionType operator/(const fractionType& other) const {
        if (other.denominator == 0) {
            throw std::invalid_argument("Denominator of the other fraction cannot be zero.");
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return fractionType(newNumerator, newDenominator);
    }

    // Operator overload for comparing two fractions for equality.
    bool operator==(const fractionType& other) const {
        return (numerator * other.denominator) == (other.numerator * denominator);
    }

    // Operator overload for comparing two fractions for inequality.
    bool operator!=(const fractionType& other) const {
        return !(*this == other);
    }

    // Operator overload for comparing if one fraction is less than another.
    bool operator<(const fractionType& other) const {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }

    // Operator overload for comparing if one fraction is less than or equal to another.
    bool operator<=(const fractionType& other) const {
        return (*this < other) || (*this == other);
    }

    // Operator overload for comparing if one fraction is greater than another.
    bool operator>(const fractionType& other) const {
        return !(*this <= other);
    }

    // Operator overload for comparing if one fraction is greater than or equal to another.
    bool operator>=(const fractionType& other) const {
        return !(*this < other);
    }

    // Stream insertion operator overload for printing the fraction.
    friend std::ostream& operator<<(std::ostream& os, const fractionType& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }

    // Stream extraction operator overload for reading the fraction.
    // Throws std::invalid_argument if the input format is invalid or the denominator is zero.
    friend std::istream& operator>>(std::istream& is, fractionType& fraction) {
        char slash;
        is >> fraction.numerator >> slash >> fraction.denominator;
        if (fraction.denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        if (slash != '/') {
            throw std::invalid_argument("Invalid input format. Expected a/b.");
        }
        return is;
    }
};

