#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Writing student test is optional!
//-----------------------------------------------------------------------------

TEST(EvaluateExpressionTest, Empty) {
    EXPECT_EQ(evaluateExpression(" "), 0);
    EXPECT_EQ(evaluateExpression(""), 0);
}

TEST(EvaluateExpressionTest, Basic) {
    EXPECT_EQ(evaluateExpression("1+1+1+1"), 4);
    EXPECT_EQ(evaluateExpression("-1+1"), 0);
    EXPECT_EQ(evaluateExpression("1-1-1+1"), 0);
}

TEST(EvaluateExpressionTest,Spaces) {
    EXPECT_EQ(evaluateExpression(" 1 + 1 + 1 - 1 "), 2);
    EXPECT_EQ(evaluateExpression(" - 1 + 1 "), 0);
}

TEST(EvaluateExpressionTest, ZerosOrOnes) {
    EXPECT_EQ(evaluateExpression("0+0+0-0"), 0);
    EXPECT_EQ(evaluateExpression("-1+1-1+1"), 0);
}