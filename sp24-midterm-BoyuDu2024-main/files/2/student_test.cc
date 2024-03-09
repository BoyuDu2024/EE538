#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Writing student test is optional!
//-----------------------------------------------------------------------------

TEST(LinkedListTest, PushBackAndFrontBack) {
    LinkedList list;
    EXPECT_EQ(list.front(), -1); // Empty list
    EXPECT_EQ(list.back(), -1); // Empty list

    list.push_back(1);
    EXPECT_EQ(list.front(), 1);
    EXPECT_EQ(list.back(), 1); // Only one element

    list.push_back(2);
    EXPECT_EQ(list.front(), 1); // Still first element is 1
    EXPECT_EQ(list.back(), 2); // Last element is now 2

    list.push_back(3);
    EXPECT_EQ(list.front(), 1); // Still first element is 1
    EXPECT_EQ(list.back(), 3); // Last element is now 2
}

TEST(LinkedListTest, PopBack) {
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    EXPECT_EQ(list.back(), 2); // two element left
    
    list.pop_back();
    EXPECT_EQ(list.back(), 1); // one element left

    list.pop_back();
    EXPECT_EQ(list.back(), -1); // List is empty now
}


