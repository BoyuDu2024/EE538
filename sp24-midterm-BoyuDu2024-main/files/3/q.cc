#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// Default constructor
Calculator::Calculator() {
    // Initialization if needed
}

// Copy constructor
Calculator::Calculator(const Calculator &other) {
    history = other.history;
    error_code = other.error_code;
}

// Performs a calculation using if-else statements
float Calculator::Calculate(int a, int b, Operation operation) {
    float result = 0;
    if (operation == Operation::kAdd) {
        result = a + b;
    } else if (operation == Operation::kSubtract) {
        result = a - b;
    } else if (operation == Operation::kDivision) {
        if (b == 0) {
            error_code = ErrorCode::kDivisionByZero;
            return 0;
        }
        result = (float(a)) / b;
    } else if (operation == Operation::kMultiplication) {
        result = a * b;
    }

    // Update history and error code
    history.push_back({a, b, operation, result});
    error_code = ErrorCode::kNoError;
    return result;
}

// Overloaded Calculate method
float Calculator::Calculate(int a, Operation operation) {
    int b = history.empty() ? 0 : (int)history.back().result;
    return Calculate(a, b, operation);
}

// Retrieves a specific calculation record from the history
CalculationRecord Calculator::History(int index) {
    if (index < 0 || index >= history.size()) {
        error_code = ErrorCode::kInvalidIndex;
        return {0, 0, Operation::kAdd, 0.0f}; // Returning error record
    }
    // Correcting for requested behavior; history is managed in chronological order
    error_code = ErrorCode::kNoError;
    return history[history.size() - 1 - index];
}