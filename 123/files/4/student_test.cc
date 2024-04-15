#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(SinglyLinkedList, BasicFunctions) {
  SinglyLinkedList list;
  EXPECT_TRUE(list.empty());  // 初始状态为空

  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  EXPECT_EQ(list.size(), 3);  // 检查大小是否正确
  EXPECT_FALSE(list.empty()); // 检查链表不为空
  std::vector<int> expected = {1, 2, 3};
  auto vector = list.convert_to_vector();
  EXPECT_EQ(vector, expected);  // 验证元素顺序
  EXPECT_EQ(list[5], -1);
  EXPECT_EQ(list[200], -1);
}

TEST(SinglyLinkedList, PopBackWorks) {
  SinglyLinkedList list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  EXPECT_TRUE(list.pop_back());

  EXPECT_EQ(list[0], 1);
  EXPECT_EQ(list[1], 2);
  EXPECT_EQ(list.size(), 2);
}

TEST(SinglyLinkedList, PopBackEmpty) {
  SinglyLinkedList list;
  EXPECT_FALSE(list.pop_back());
  EXPECT_TRUE(list.empty());
}

TEST(SinglyLinkedList, Erase) {
  SinglyLinkedList list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  ListNode* actual = list.erase(0);

  EXPECT_EQ(list[0], 2);
  EXPECT_EQ(list[1], 3);
  EXPECT_EQ(list.size(), 2);
  EXPECT_EQ(actual, nullptr);
}

TEST(SinglyLinkedList, EraseWrongIndex) {
  SinglyLinkedList list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  ListNode* actual = list.erase(3);

  EXPECT_EQ(list[0], 1);
  EXPECT_EQ(list[1], 2);
  EXPECT_EQ(list[2], 3);
  EXPECT_EQ(list.size(), 3);
  EXPECT_EQ(actual, nullptr);
}

TEST(SinglyLinkedList, ConvertToVectorEmpty) {
  SinglyLinkedList list;

  std::vector<int> act = list.convert_to_vector();
  EXPECT_TRUE(act.empty());
}

TEST(SinglyLinkedList, ConvertToVectorNonEmpty) {
  SinglyLinkedList list;
  list.push_back(1);
  std::vector<int> actual = list.convert_to_vector();
  std::vector<int> expected = {1};
  EXPECT_EQ(actual,expected);
}

TEST(SinglyLinkedList, Constructor) {
  SinglyLinkedList list({ 1, 2, 3});

  std::vector<int> actual = list.convert_to_vector();
  std::vector<int> expected = {1, 2, 3};
  EXPECT_EQ(actual, expected);
}


TEST(SinglyLinkedList, CopyConstructorEmpty) {
  SinglyLinkedList list1;
  SinglyLinkedList list2 = list1;
  std::vector<int> actual = list2.convert_to_vector();
  EXPECT_TRUE(actual.empty());
}


TEST(SinglyLinkedList, CopyConstructor) {
  SinglyLinkedList l1({1, 2, 3});
  SinglyLinkedList l2 = l1;
  std::vector<int> expected = {1, 2, 3};
  std::vector<int> actual = l2.convert_to_vector();
  EXPECT_EQ(actual, expected);
}

TEST(SinglyLinkedList, RemoveDuplicates) {
  SinglyLinkedList list({1, 2, 3, 1});
  list.remove_duplicates();
  std::vector<int> expected = {1, 2, 3};
  auto actual = list.convert_to_vector();
  EXPECT_EQ(actual, expected);
}

