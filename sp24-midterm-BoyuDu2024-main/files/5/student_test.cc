#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Writing student test is optional!
//-----------------------------------------------------------------------------

TEST(FindInsertionIndexTest, InsertInEmptyVector) {
    std::vector<int> vec = {};
    EXPECT_EQ(0, findInsertionIndex(vec, 1));
}

TEST(FindInsertionIndexTest, InsertInSingleElementVector) {
    std::vector<int> vec = {2};
    EXPECT_EQ(0, findInsertionIndex(vec, 1));
    EXPECT_EQ(1, findInsertionIndex(vec, 3));
}

TEST(FindInsertionIndexTest, InsertInMultiElementVector) {
    std::vector<int> vec = {1, 3, 5};
    EXPECT_EQ(1, findInsertionIndex(vec, 2));
    EXPECT_EQ(3, findInsertionIndex(vec, 6));
}

// Tests for MySet class
TEST(MySetTest, HandlesInsertAndIsIn) {
    MySet set;
    EXPECT_FALSE(set.is_in(1));
    set.insert(1);
    EXPECT_TRUE(set.is_in(1));
    set.insert(1); // Test idempotency
    EXPECT_EQ(1, set.size());
}

TEST(MySetTest, HandlesSize) {
    MySet set;
    set.insert(1);
    set.insert(2);
    EXPECT_EQ(2, set.size());
    set.insert(2); // Should not affect size due to idempotency
    EXPECT_EQ(2, set.size());
}

TEST(MySetTest, ConvertToStdVector) {
    MySet set;
    set.insert(3);
    set.insert(1);
    set.insert(2);
    std::vector<int> expectedVec = {1, 2, 3};
    EXPECT_EQ(expectedVec, set.ConvertToStdVector());
}

TEST(MySetTest, HandlesConstructorWithElements) {
    std::vector<int> initialElements = {3, 1, 2};
    MySet set(initialElements);
    EXPECT_TRUE(set.is_in(1));
    EXPECT_TRUE(set.is_in(2));
    EXPECT_TRUE(set.is_in(3));
    EXPECT_EQ(3, set.size());
}

TEST(MySetTest, HandlesConstructorWithReaptedElements) {
    std::vector<int> initialElements = {3, 1, 2, 3};
    MySet set(initialElements);
    EXPECT_TRUE(set.is_in(1));
    EXPECT_TRUE(set.is_in(2));
    EXPECT_TRUE(set.is_in(3));
    EXPECT_EQ(3, set.size());
}

TEST(MySetTest, HandlesCopyConstructor) {
    MySet originalSet;
    originalSet.insert(1);
    MySet copiedSet = originalSet;
    EXPECT_TRUE(copiedSet.is_in(1));
    EXPECT_EQ(1, copiedSet.size());
}