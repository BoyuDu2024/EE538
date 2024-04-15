#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
SinglyLinkedList::SinglyLinkedList(const std::vector<int> &v){
  head_ = nullptr;
  size_ = 0; 
  for (int value : v) {
    push_back(value);
  }
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList &rhs) {
  head_ = nullptr;
  size_ = 0;
  ListNode* current = rhs.head_;
  while (current != nullptr) {
    push_back(current->val);
    current = current->next;
  }
}

SinglyLinkedList::~SinglyLinkedList() {
  while (head_ != nullptr) {
    ListNode* next = head_->next;
    delete head_;
    head_ = next;
  }
  size_ = 0;
}

bool SinglyLinkedList::empty() {
  return head_ == nullptr;
}

int SinglyLinkedList::size() {
  return size_;
}

ListNode* SinglyLinkedList::head() {
  return head_;
}


void SinglyLinkedList::push_back(int i) {
  ListNode* newNode = new ListNode(i);
  if (head_ == nullptr) {
    head_ = newNode;
  } else {
    ListNode* current = head_;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = newNode;
  }
  size_++;
}


bool SinglyLinkedList::pop_back() {
  if (head_ == nullptr) return false;
  
  if (head_->next == nullptr) {
    delete head_;
    head_ = nullptr;
  } else {
    ListNode* current = head_;
    while (current->next->next != nullptr) {
      current = current->next;
    }
    delete current->next;
    current->next = nullptr;
  }
  size_--;
  return true;
}

ListNode* SinglyLinkedList::GetBackPointer() {
  if (!head_) return nullptr;
  ListNode* curr = head_;
  while (curr->next != nullptr) {
    curr = curr->next;
  }
  return curr;
}

ListNode* SinglyLinkedList::GetIthPointer(int i) {
  if (i < 0 || i >= size_) return nullptr;
  ListNode* cur = head_;
  while (i-- > 0) {
    cur = cur->next;
  }
  return cur;
}

int SinglyLinkedList::back() {
  if (head_ == nullptr) return minusOne_;

  ListNode* current = head_;
  while (current->next != nullptr) {
    current = current->next;
  }
  return current->val;
}

int& SinglyLinkedList::operator[](int i) {
  if (i < 0 || i >= size_) {
    return minusOne_;
  }
  ListNode* curr = GetIthPointer(i);
  return curr->val;
}

void SinglyLinkedList::print() {
  ListNode* curr = head_;
  while (curr != nullptr) {
    std::cout << curr->val << " -> ";
    curr = curr->next;
  }
  std::cout << "nullptr\n";
}

std::vector<int> SinglyLinkedList::convert_to_vector() {
  std::vector<int> result;
  ListNode* curr = head_;
  while (curr != nullptr) {
    result.push_back(curr->val);
    curr = curr->next;
  }
  return result;
}

ListNode* SinglyLinkedList::erase(int i) {
  if (i < 0 || i >= size_ || !head_) return nullptr;

  ListNode *toDelete = nullptr;
  if (i == 0) { // Erasing the first element
    toDelete = head_;
    head_ = head_->next;
    delete toDelete;
    size_--;
    return nullptr; // Return nullptr explicitly as expected by the test case
  } else { // Erasing a non-first element
    ListNode *prev = GetIthPointer(i - 1);
    if (!prev || !prev->next) return nullptr; // Additional check for safety
    toDelete = prev->next;
    prev->next = toDelete->next;
    delete toDelete;
    size_--;
    return prev; // Return pointer to the previous element of the erased one
  }
}

ListNode* SinglyLinkedList::erase(ListNode *p) {
     // Check if the input node is nullptr
    if (!p) return nullptr;

    // Special case: removing the head node
    if (p == head_) {
        ListNode* nextNode = head_->next;
        delete head_; // Free the memory of the current head
        head_ = nextNode; // Update the head to the next node
        size_--; // Decrease the size of the list
        return nullptr; // No previous node in this case
    }

    // General case: removing a node that is not the head
    ListNode* curr = head_;
    ListNode* prev = nullptr;
    while (curr != nullptr && curr != p) {
        prev = curr; // Keep track of the previous node
        curr = curr->next;
    }

    // If the node to be removed was found
    if (curr == p) {
        if (prev) {
            prev->next = curr->next; // Bypass the node to be removed
        }
        delete curr; // Free the memory of the node to be removed
        size_--; // Decrease the size of the list
    }

    // Return the previous node, or nullptr if the node was not found
    return prev;
}

ListNode* SinglyLinkedList::GetPrevious(ListNode *p) {
  if (!p || p == head_) return nullptr;
  ListNode* curr = head_;
  while (curr && curr->next != p) {
    curr = curr->next;
  }
  return curr;
}

void SinglyLinkedList::remove_duplicates() {
    if (!head_ || !head_->next) {
        return; // Early return if list is empty or has only one element.
    }

    std::set<int> seen;
    ListNode* curr = head_;
    ListNode* prev = nullptr; // Keep track of the previous node to adjust links.
    
    while (curr != nullptr) {
        // Check if the current value has been seen.
        if (!seen.insert(curr->val).second) {
        // Duplicate found, remove the current node.
            prev->next = curr->next;
            delete curr; // Free memory of the removed node.
            curr = prev->next; // Move to the next node.
        } else {
        // No duplicate, move to the next node.
            prev = curr;
            curr = curr->next;
    }
  }
  
}

void SinglyLinkedList::reverse() {
  ListNode *prev = nullptr, *curr = head_, *next = nullptr;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head_ = prev;
}
