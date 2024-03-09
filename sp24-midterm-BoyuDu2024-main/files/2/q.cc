#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
// Node Constructor to initialize a Node with value
Node::Node(int val){
    value = val;
    next = nullptr;
}

// LinkedList Constructor to initialize an empty list
LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr; 
}

// LinkedList Destructor to free the allocated memory
LinkedList::~LinkedList() {
    Node* cur = head;
    while (cur != nullptr) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
    head = tail = nullptr;
}

// Adds a value to the end of the list. O(1).
void LinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

// Returns the value of the last element or -1 if the list is empty. O(1).
int LinkedList::back() {
  return tail ? tail->value : -1;
}

// Returns the value of the first element or -1 if the list is empty. SO(1).
int LinkedList::front() {
  return head ? head->value : -1;
}

// Removes the last element from the list
void LinkedList::pop_back() {
  if (head == nullptr) return; // List is empty

  // only one element in LinkedList
  if (head == tail) {
    delete head;
    head = tail = nullptr;
    return;
  }

  // Find the second to last node
  Node* cur = head;
  while (cur->next != tail) {
    cur = cur->next;
  }

  // Remove the last node
  delete tail;
  tail = cur;
  tail->next = nullptr;
}