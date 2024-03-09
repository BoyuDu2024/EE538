#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(Queue, EmptyQueue) {
  Queue q;
  EXPECT_TRUE(q.IsEmpty());
  EXPECT_FALSE(q.Dequeue());
  EXPECT_EQ(q.Front(), -1);
}

TEST(Queue, Operations) {
  Queue q;
  q.Enqueue(2);
  q.Enqueue(3);
  q.Enqueue(4);
  q.Enqueue(5);
  q.Dequeue();
  q.Dequeue();
  EXPECT_EQ(q.Front(), 4);
}

TEST(Queue, CopyConstructor) {
  Queue q1;
  q1.Enqueue(2);
  q1.Enqueue(3);
  q1.Enqueue(4);

  Queue q2 = q1;
  EXPECT_EQ(q2.Front(), 2);

  q1.Dequeue();
  EXPECT_EQ(q1.Front(), 3);
  EXPECT_EQ(q2.Front(), 2);
}

TEST(Queue, AddOperator) {
  Queue q1;
  q1.Enqueue(1);
  q1.Enqueue(2);
  q1.Enqueue(3);
  
  std::vector<int> expected = {4, 5, 1, 2, 3};
  
  Queue q2;
  q2.Enqueue(4);
  q2.Enqueue(5);

  Queue q3 = q1 + q2;

  EXPECT_EQ(q3.GetData(), expected);
}

TEST(Queue, Q1Empty) {
  Queue q1;

  Queue q2;
  q2.Enqueue(1);
  q2.Enqueue(2);

  std::vector<int> expected = {1, 2};
  Queue q3 = q1 + q2;

  EXPECT_EQ(q3.GetData(), expected);
}

TEST(Queue, Q2Empty) {
  Queue q1;
  q1.Enqueue(1);
  q1.Enqueue(2);

  std::vector<int> expected = {1, 2};
  
  Queue q2;

  Queue q3 = q1 + q2;

  EXPECT_EQ(q3.GetData(), expected);
}

TEST(Queue, BothEmpty) {
  Queue q1;
  Queue q2;

  Queue q3 = q1 + q2;

  EXPECT_TRUE(q3.IsEmpty());
}
