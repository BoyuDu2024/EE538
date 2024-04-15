#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

    Queue::Queue(const Queue& rhs) : v_(rhs.v_) {}

    Queue&  Queue::operator=(const Queue& rhs) {
        if (this != &rhs) {
            v_ = rhs.v_;
        }
        return *this;
    }

    Queue  Queue::operator+(const Queue& rhs) {
        Queue newQueue;
        newQueue.v_.insert(newQueue.v_.end(), rhs.v_.begin(), rhs.v_.end());
        newQueue.v_.insert(newQueue.v_.end(), v_.begin(), v_.end());
        return newQueue;
    }

    bool Queue::Enqueue(int value) {
        v_.push_back(value);
        return true;
    }

    bool  Queue::Dequeue() {
        if (IsEmpty()) {
            return false;
        }
        v_.erase(v_.begin());
        return true;
    }

    bool  Queue::IsEmpty() {
        return v_.empty();
    }

    int  Queue::Front() {
        if (IsEmpty()) {
            return -1;
        }
        return *v_.begin();
    }


