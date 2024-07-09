#include <iostream>
#include <stdexcept>
 
// The fractionType class represents a rational fraction of the form a/b,
// where a and b are integers and b != 0.
class fractionType {
private:
    int numerator;   // Numerator of the fraction
    int denominator; // Denominator of the fraction
 
public:
    /*
    * Constructs a fractionType object with the given numerator and denominator.
    * @param num The numerator of the fraction.
    * @param denom The denominator of the fraction.
    * @throws std::invalid_argument if the denominator is zero.
    */
    fractionType(int num = 0, int denom = 1) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
 
        numerator = num;
        denominator = denom;
    }
 
    /*
    * Returns the numerator of the fraction.
    * @return int The numerator of the fraction.
    */
    int getNumerator() const {
        return numerator;
    }
 
    /*
    * Returns the denominator of the fraction.
    * @return int The denominator of the fraction.
    */
    int getDenominator() const {
        return denominator;
    }
 
    /*
    * Sets the numerator of the fraction.
    * @param num The new numerator value.
    */
    void setNumerator(int num) {
        numerator = num;
    }
 
    /*
    * Sets the denominator of the fraction.
    * @param denom The new denominator value.
    * @throws std::invalid_argument if the denominator is zero.
    */
    void setDenominator(int denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
 
        denominator = denom;
    }
 
    /*
    * Adds two fractions and returns the result as a new fraction.
    * @param other The fraction to be added.
    * @return fractionType The sum of the two fractions.
    */
    fractionType operator+(const fractionType& other) const {
        int newNumerator = (numerator * other.denominator) + (other.numerator * denominator);
        int newDenominator = denominator * other.denominator;
 
        return fractionType(newNumerator, newDenominator);
    }
 
    /*
    * Subtracts a fraction from another fraction and returns the result as a new fraction.
    * @param other The fraction to be subtracted.
    * @return fractionType The difference between the two fractions.
    */
    fractionType operator-(const fractionType& other) const {
        int newNumerator = (numerator * other.denominator) - (other.numerator * denominator);
        int newDenominator = denominator * other.denominator;
 
        return fractionType(newNumerator, newDenominator);
    }
 
    /*
    * Multiplies two fractions and returns the result as a new fraction.
    * @param other The fraction to be multiplied.
    * @return fractionType The product of the two fractions.
    */
    fractionType operator*(const fractionType& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
 
        return fractionType(newNumerator, newDenominator);
    }
 
    /*
    * Divides a fraction by another fraction and returns the result as a new fraction.
    * @param other The fraction to be divided by.
    * @return fractionType The quotient of the two fractions.
    * @throws std::invalid_argument if the denominator of the other fraction is zero.
    */
    fractionType operator/(const fractionType& other) const {
        if (other.denominator == 0) {
            throw std::invalid_argument("Denominator of the other fraction cannot be zero.");
        }
 
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
 
        return fractionType(newNumerator, newDenominator);
    }
 
    /*
    * Compares two fractions for equality.
    * @param other The fraction to be compared with.
    * @return bool True if the fractions are equal, false otherwise.
    */
    bool operator==(const fractionType& other) const {
        return (numerator * other.denominator) == (other.numerator * denominator);
    }
 
    /*
    * Compares two fractions for inequality.
    * @param other The fraction to be compared with.
    * @return bool True if the fractions are not equal, false otherwise.
    */
    bool operator!=(const fractionType& other) const {
        return !(*this == other);
    }
 
    /*
    * Compares two fractions for less than.
    * @param other The fraction to be compared with.
    * @return bool True if this fraction is less than the other fraction, false otherwise.
    */
    bool operator<(const fractionType& other) const {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }
 
    /*
    * Compares two fractions for less than or equal to.
    * @param other The fraction to be compared with.
    * @return bool True if this fraction is less than or equal to the other fraction, false otherwise.
    */
    bool operator<=(const fractionType& other) const {
        return (*this < other) || (*this == other);
    }
 
    /*
    * Compares two fractions for greater than.
    * @param other The fraction to be compared with.
    * @return bool True if this fraction is greater than the other fraction, false otherwise.
    */
    bool operator>(const fractionType& other) const {
        return !(*this <= other);
    }
 
    /*
    * Compares two fractions for greater than or equal to.
    * @param other The fraction to be compared with.
    * @return bool True if this fraction is greater than or equal to the other fraction, false otherwise.
    */
    bool operator>=(const fractionType& other) const {
        return !(*this < other);
    }
 
    /*
    * Overloads the stream insertion operator to output the fraction in the form a/b.
    * @param os The output stream.
    * @param fraction The fraction to be output.
    * @return std::ostream& The output stream.
    */
    friend std::ostream& operator<<(std::ostream& os, const fractionType& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }
 
    /*
    * Overloads the stream extraction operator to input the fraction in the form a/b.
    * @param is The input stream.
    * @param fraction The fraction to be input.
    * @return std::istream& The input stream.
    * @throws std::invalid_argument if the denominator is zero or the input is invalid.
    */
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
