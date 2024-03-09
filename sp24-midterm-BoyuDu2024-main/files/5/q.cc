#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

int findInsertionIndex(const std::vector<int>& sortedVector, int n) {
    int left = 0;
    int right = sortedVector.size() - 1;
    
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        if (sortedVector[mid] == n) {
            return mid; // Found n, return its index.
        } else if (sortedVector[mid] < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return left; // Left is the correct insertion point.
}

MySet::MySet(std::vector<int>& elements) {
    std::sort(elements.begin(), elements.end());
    for (int i = 0; i < elements.size(); ++i) {
        if (i == 0 || elements[i] != elements[i - 1]) {
            elements_.push_back(elements[i]);
        }
    }
}

MySet::MySet(const MySet& rhs) {
    elements_ = rhs.elements_;
}

void MySet::insert(int value) {
    int index = findInsertionIndex(elements_, value);
    if (index == elements_.size() || elements_[index] != value) {
        elements_.insert(elements_.begin() + index, value);
    }
}

bool MySet::is_in(int item) {
    int index = findInsertionIndex(elements_, item); // Use the function to find the potential index of the item.
    // Check if the index is within the bounds of the vector and the item at that index matches the searched item.
    if (index < elements_.size() && elements_[index] == item) {
        return true; // The item is in the set.
    }
    return false; // The item is not in the set.
}

int MySet::size() const {
    return elements_.size();
}

std::vector<int> MySet::ConvertToStdVector() {
    return elements_;
}
