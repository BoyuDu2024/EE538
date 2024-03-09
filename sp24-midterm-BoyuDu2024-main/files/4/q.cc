#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

    MyVector::MyVector() {
        size_ = 0;
        data_ = new int[size_];
        error_ = ErrorCode::kNoError;
    }
    MyVector::MyVector(int size) {
        size_ = size;
        data_ = nullptr;
        error_ = ErrorCode::kNoError;
    }

    MyVector::MyVector(const MyVector& rhs) {
        size_ = rhs.size_;
        data_ = new int[size_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = rhs.data_[i];
        }
        error_ = ErrorCode::kNoError;
    }

    MyVector::~MyVector() {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
    }

   void  MyVector::push_back(int value) {
        int* newData = new int[size_ + 1];
        for (int i = 0; i < size_; ++i) {
            newData[i] = data_[i];
        }
        newData[size_] = value;
        ++size_;
        delete[] data_;
        data_ = newData;
        error_ = ErrorCode::kNoError;
    }

    int MyVector::pop_back() {
        // Implementation here
        // Remember to handle the empty vector case
        if (size_ == 0) {
            error_ = ErrorCode::kPopFromEmptyVector;
            return -1; // Assuming -1 is not a valid data, otherwise use a different error handling strategy
        }
        int value = data_[size_ - 1];
        --size_;
        int* newData = new int[size_];
        for (int i = 0; i < size_; ++i) {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
        error_ = ErrorCode::kNoError;
        return value;
    }

    void MyVector::push_front(int value) {
        // Implementation here
        
        int* newData = new int[size_ + 1];
        for (int i = 0; i < size_; ++i) {
            newData[i + 1] = data_[i];
        }
        newData[0] = value;
        ++size_;
        delete[] data_;
        data_ = newData;
        error_ = ErrorCode::kNoError;
    }

    int MyVector::pop_front() {
        // Implementation here
        // Remember to handle the empty vector case
        if (size_ == 0) {
            error_ = ErrorCode::kPopFromEmptyVector;
            return -1; // Assuming -1 is not a valid data, otherwise use a different error handling strategy
        }
        int value = data_[0];
        --size_;
        int* newData = new int[size_];
        for (int i = 0; i < size_; ++i) {
            newData[i] = data_[i + 1];
        }
        delete[] data_;
        data_ = newData;
        error_ = ErrorCode::kNoError;
        return value;
    }

    void MyVector::insert(int value, int index) {
        // Implementation here
        // Handle invalid index and index -1 for insertion at the beginning
        if (index < -1 || index >= size_) {
            error_ = ErrorCode::kIndexError;
            return;
        }
        int* newData = new int[size_ + 1];
        for (int i = 0, j = 0; i < size_ + 1; ++i) {
            if (i == index + 1) {
                newData[i] = value;
            } else {
                newData[i] = data_[j++];
            }
        }
        ++size_;
        delete[] data_;
        data_ = newData;
        error_ = ErrorCode::kNoError;
    }

    int MyVector::at(int index) {
        // Implementation here
        // Return value at index if valid, otherwise handle error
        if (index <= -1 || index >= size_) {
            error_ = ErrorCode::kIndexError;
            return -1;
        }
        return data_[index];
    }

    int MyVector::find(int item) {
        // Implementation here
        // Return first index of item or -1 if not found
        for (int i = 0; i < size_; ++i) {
            if(data_[i] == item) {
                error_ = ErrorCode::kNoError;
                return i;
            }
        }
        error_ = ErrorCode::kNotFound;
        return -1;
    }
   
   //return error kind
    ErrorCode  MyVector::get_error() const {
        return error_;
    }

    // return size
    int MyVector::size() const {
        return size_;
    }

    // convert to std::vector
    std::vector<int> MyVector::ConvertToStdVector() {
        std::vector<int> vec(data_, data_ + size_);
        error_ = ErrorCode::kNoError;
        return vec;
    }
