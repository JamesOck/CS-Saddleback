#include "hw09.h"

int main() {
    fractionType x, y, z;
 
    std::cout << "Enter a fraction in the form a/b: ";
    std::cin >> x;
 
    std::cout << "Enter another fraction in the form a/b: ";
    std::cin >> y;
 
    z = x + y;
    std::cout << "Sum of " << x << " and " << y << " is: " << z << std::endl;
 
    z = x - y;
    std::cout << "Difference between " << x << " and " << y << " is: " << z << std::endl;
 
    z = x * y;
    std::cout << "Product of " << x << " and " << y << " is: " << z << std::endl;
 
    try {
        z = x / y;
        std::cout << "Quotient of " << x << " and " << y << " is: " << z << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
 
    std::cout << x << " == " << y << " ? " << (x == y) << std::endl;
    std::cout << x << " != " << y << " ? " << (x != y) << std::endl;
    std::cout << x << " < " << y << " ? " << (x < y) << std::endl;
    std::cout << x << " <= " << y << " ? " << (x <= y) << std::endl;
    std::cout << x << " > " << y << " ? " << (x > y) << std::endl;
    std::cout << x << " >= " << y << " ? " << (x >= y) << std::endl;
 
    return 0;
}
