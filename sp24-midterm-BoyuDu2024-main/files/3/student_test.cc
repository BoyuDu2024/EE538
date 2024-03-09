#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Writing student test is optional!
//-----------------------------------------------------------------------------

TEST(CalculatorTest, Add) {
    Calculator calc; //
    EXPECT_EQ(5, calc.Calculate(2, 3, Operation::kAdd));
}

TEST(CalculatorTest, Subtract) {
    Calculator calc; // 
    EXPECT_EQ(1, calc.Calculate(3, 2, Operation::kSubtract));
}

TEST(CalculatorTest, Division) {
    Calculator calc; // 
    EXPECT_FLOAT_EQ(2.0, calc.Calculate(4, 2, Operation::kDivision)); // 
    calc.Calculate(4, 0, Operation::kDivision); // 
    EXPECT_EQ(ErrorCode::kDivisionByZero, calc.error_code); // 
}

TEST(CalculatorTest, Multi) {
    Calculator calc; // 
    EXPECT_EQ(6, calc.Calculate(2, 3, Operation::kMultiplication));
}

TEST(CalculatorTest, History) {
    Calculator calc; // 
    calc.Calculate(1, 2, Operation::kAdd); // 3
    calc.Calculate(5, 3, Operation::kSubtract); // 2
    auto record = calc.History(0); //
    EXPECT_FLOAT_EQ(2, record.result); 
}