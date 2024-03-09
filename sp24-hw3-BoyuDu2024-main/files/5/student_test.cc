#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
// Test the DoubleStack constructor

TEST(DoubleStackTest, Constructor) {
  DoubleStack doubleStack;
  EXPECT_EQ(doubleStack.size(), 0);
  EXPECT_TRUE(doubleStack.empty());
}

TEST(DoubleStackTest, Even) {
  DoubleStack doubleStack;
  doubleStack.push(4);
  EXPECT_EQ(doubleStack.size(), 1);
  EXPECT_FALSE(doubleStack.empty());
  EXPECT_EQ(doubleStack.top(), 4);
}

TEST(DoubleStackTest, PushOdd) {
  DoubleStack doubleStack;
  doubleStack.push(5);
  EXPECT_EQ(doubleStack.size(), 1);
  EXPECT_FALSE(doubleStack.empty());
  EXPECT_EQ(doubleStack.top(), 5);
}

TEST(DoubleStackTest, PushMix) {
  DoubleStack doubleStack;
  doubleStack.push(1);
  doubleStack.push(2);
  doubleStack.push(3);
  EXPECT_EQ(doubleStack.size(), 3);
  EXPECT_FALSE(doubleStack.empty());
  EXPECT_EQ(doubleStack.top(), 3);  // Assuming top returns the most recently pushed highest value
}

// Test the DoubleStack pop function
TEST(DoubleStackTest, Pop) {
  DoubleStack doubleStack;
  doubleStack.push(2);
  doubleStack.push(3);
  doubleStack.pop();  // Assuming pop removes the highest number
  EXPECT_EQ(doubleStack.size(), 1);
  EXPECT_EQ(doubleStack.top(), 2);
}

// Test the DoubleStack pop function with only even numbers
TEST(DoubleStackTest, PopEven) {
  DoubleStack doubleStack;
  doubleStack.push(2);
  doubleStack.push(4);
  EXPECT_EQ(doubleStack.size(), 2);
  EXPECT_EQ(doubleStack.top(), 4);

  doubleStack.pop();
  EXPECT_EQ(doubleStack.size(), 1);
  EXPECT_EQ(doubleStack.top(), 2);
  doubleStack.pop();
  EXPECT_EQ(doubleStack.size(), 0);
  EXPECT_EQ(doubleStack.top(), -1);
}


// Test the DoubleStack top function
TEST(DoubleStackTest, Top) {
  DoubleStack doubleStack;
  doubleStack.push(2);
  doubleStack.push(3);
  EXPECT_EQ(doubleStack.top(), 3);
}

// Test the DoubleStack size function
TEST(DoubleStackTest, Size) {
  DoubleStack doubleStack;
  doubleStack.push(1);
  doubleStack.push(2);
  EXPECT_EQ(doubleStack.size(), 2);
}

// Test the DoubleStack empty function
TEST(DoubleStackTest, EmptyTest) {
  DoubleStack doubleStack;
  EXPECT_TRUE(doubleStack.empty());
  doubleStack.push(2);
  EXPECT_FALSE(doubleStack.empty());
}

TEST(DoubleStackTest, EmptyTest2) {
  DoubleStack doubleStack;
  EXPECT_TRUE(doubleStack.empty());
  doubleStack.push(1);
  EXPECT_FALSE(doubleStack.empty());
  doubleStack.pop();
  EXPECT_TRUE(doubleStack.empty());
}
