#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
int evaluateExpression(const std::string &expr) {
    int res = 0;
    char sign = '+'; // for first number, sign = '+'
    
    for (char c : expr) {
        if (c == ' ') continue; // Ignore spaces
        if (c == '+' || c == '-') {
            sign = c; // Update the sign
        } else {
            // when meet 0 or 1, we need to calculate the result
            int val = c - '0'; // Convert value to int form
            if (sign == '+') {
                res += val; // for sign == '+', plus value
            } else if (sign == '-') {
                res -= val; // for sign == '-', minus value
            }
        }
    }
    return res;
}