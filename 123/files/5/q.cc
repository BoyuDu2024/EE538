#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

DoubleStack::DoubleStack() {
  // Constructor initializes empty vectors, no additional code needed
}

void DoubleStack::push(int num) {
  if (num % 2 == 0) {
    evenVec_.push_back(num);
  } else {
    oddVec_.push_back(num);
  }
}

void DoubleStack::pop() {
  if (!evenVec_.empty() || !oddVec_.empty()) {
    if (!evenVec_.empty() && !oddVec_.empty()) {
      if (evenVec_.back() > oddVec_.back()) {
        evenVec_.pop_back();
      } else {
        oddVec_.pop_back(); // if equal pop odd top
      }
    } else if (!evenVec_.empty()) {
      evenVec_.pop_back();
    } else {
      oddVec_.pop_back();
    }
  }
}

int DoubleStack::top() {
  if (evenVec_.empty() && oddVec_.empty()) {
    return -1;
  }

  int maxTop = -1;
  if (!evenVec_.empty()) {
    maxTop = evenVec_.back();
  }
  if (!oddVec_.empty() && oddVec_.back() > maxTop) {
    maxTop = oddVec_.back();
  }
  return maxTop;
}

int DoubleStack::size() {
  return evenVec_.size() + oddVec_.size();
}

bool DoubleStack::empty() {
  return evenVec_.empty() && oddVec_.empty();
}
