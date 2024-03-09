#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(MyVector, PopBackFromEmpty) {
  MyVector v;
  v.pop_back();
  EXPECT_EQ(v.get_error(), ErrorCode::kPopFromEmptyVector);
}

TEST(MyVector, PopFrontFromEmpty) {
  MyVector v;
  v.pop_front();
  EXPECT_EQ(v.get_error(), ErrorCode::kPopFromEmptyVector);
}

TEST(MyVector, InsertIntoEmptyAtInvalidIndex) {
  MyVector v;
  v.insert(10, 1); // 尝试在非法位置插入
  EXPECT_EQ(v.get_error(), ErrorCode::kIndexError);
}

TEST(MyVector, AtInvalidIndex) {
  MyVector v;
  v.push_back(5);
  v.at(1); // 越界访问
  EXPECT_EQ(v.get_error(), ErrorCode::kIndexError);
}

TEST(MyVector, InsertAtStart) {
  MyVector v;
  v.insert(10, -1); // 在开始处插入
  EXPECT_EQ(v.at(0), 10);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, InsertAtEnd) {
  MyVector v;
  v.push_back(1);
  v.insert(10, 0); // 在末尾插入
  EXPECT_EQ(v.at(1), 10);
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, MultipleInsertsAndDeletes) {
  MyVector v;
  std::vector<int> expected = {1, 2, 10, 3};
  for (int i = 0; i < 5; ++i) {
    v.push_back(i);
  }
  v.insert(10, 2);
  v.pop_back();
  v.pop_front();
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v.ConvertToStdVector(), expected);
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, RepeatedInsertsAndPops) {
  MyVector v;
  std::vector<int> expected = {10, 10};
  v.push_back(1);
  v.push_back(2);
  for (int i = 0; i < 3; ++i) {
    v.insert(10, 1); // 将10重复插入到索引1的位置
    v.pop_front(); // 删除前端元素
  }
  EXPECT_EQ(v.size(), 2); // 预期大小
  EXPECT_EQ(v.ConvertToStdVector(), expected);
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, HandleErrorAfterPopBackFromEmpty) {
  MyVector v;
  v.pop_back();
  EXPECT_EQ(v.get_error(), ErrorCode::kPopFromEmptyVector);
  v.push_back(1); // 检查是否能恢复正常操作
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, HandleErrorAfterInvalidInsert) {
  MyVector v;
  v.insert(10, 100); // 尝试在无效位置插入
  EXPECT_EQ(v.get_error(), ErrorCode::kIndexError);
  v.push_back(5); // 检查是否恢复正常
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}
