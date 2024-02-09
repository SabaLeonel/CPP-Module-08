#include <iostream>
#include "Span.hpp"
#include <vector>

int main() {
    // Test default constructor
    Span defaultSpan;
    std::cout << "Testing default constructor:" << std::endl;
    try {
        defaultSpan.addNumber(1); // Should fail due to size 0
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test parametric constructor and adding numbers beyond capacity
    Span fixedSpan(3);
    std::cout << "\nTesting parametric constructor and adding beyond capacity:" << std::endl;
    try {
        fixedSpan.addNumber(5);
        fixedSpan.addNumber(10);
        fixedSpan.addNumber(15);
        fixedSpan.addNumber(20); // Should throw an exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test computing spans with insufficient elements
    Span smallSpan(2);
    std::cout << "\nTesting span calculation with insufficient elements:" << std::endl;
    smallSpan.addNumber(100); // Only one element added
    try {
        std::cout << "Shortest span: " << smallSpan.shortestSpan() << std::endl; // Should fail
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Demonstrate successful span calculations
    Span successfulSpan(10);
    successfulSpan.fill_random(10); // Assume it fills with random numbers correctly
    try {
        std::cout << "\nSuccessful span calculations:" << std::endl;
        std::cout << "Shortest span: " << successfulSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << successfulSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
