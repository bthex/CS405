// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>

// Custom Exception
class CustomException : public std::exception {
public:
    const char* what() const noexcept override {
        return "My Custom exception occurred";
    }
};

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    throw std::runtime_error("An error occurred in do_even_more_custom_application_logic");
}

void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    try {
        // Try to call do_even_more_custom_logic
        if(do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    // If call fails catch exception
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    // Check denominator for zero
    if (den == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.
    try {
        float numerator = 10.0f;
        float denominator = 0;

        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    // If divide() throws exception
    catch (const std::invalid_argument& e) {
        std::cout << "Exception caught in do_division: " << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception
    //  that wraps the whole main function, and displays a message to the console.
    try {
        do_division();
        do_custom_application_logic();

    }
    catch (const CustomException& e) {
        std::cout << "Caught with my custom exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Standard exception from main: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "Unknown exception." << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menug > Start Debugging menu