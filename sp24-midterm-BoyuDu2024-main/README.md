[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/2kQVh_x5)
# EE538 Midterm Exam 

## University of Southern California

## Instructor: Arash Saifhashemi

## Important:

- A lot of time and effort has been spent to design this exam for you. Please use this as a great learning opportunity and take this exam seriously.
- Please make sure you abide by the academic integrity rules and only submit your original work. All the rules described in Q1 of the Gradescope exam applies here as well.
- Make sure you use address sanitizer! (Use --config=asan with your bazel test commands.)
- Every time that you use a dereferencing operator (* or ->) make sure your pointer is valid!

Also note that:

- Important: Don't modify the header files. Your implementation should go in .cc files.
- Please find each question in a separate folder under [files](/files).
- For coding questions, edit the files and check them in.
- Writing student tests is optional. Your code must pass grader test.
- For your convenience the grader tests are provided in this repo and you can run them locally.
- For submission, please push your answers to Github before the deadline.

| Question | Points |
| -------- | ------ |
| 1        | 15     |
| 2        | 20     |
| 3        | 20     |
| 4        | 20     |
| 5        | 20     |

- Getting 100 points from the sum of the points in this repo plus the points in Gradescope exam is considered full credit.
- - For example, if you get 80 from this repo and 25 from Gradescope, your total would be 105, which means you received full credit!

See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.

Q5:
findInsertionIndex
Time Complexity: o(logn)
Explanation:a binary search on a sorted vector to find the insertion index of a given value, which takes logarithmic time relative to the size of the vector.

Constructor MySet(std::vector<int>& elements)
Time Complexity: O(nlogn)
Explanation: Sorts the input vector, which takes O(nlogn) time, and then iterates over the vector to remove duplicates, which takes O(n) time. The dominating factor is the sorting operation.

Copy Constructor MySet(const MySet& rhs)
Time Complexity: O(n)
Explanation: Performs a shallow copy of the internal vector, which takes linear time relative to the size of the vector.

insert
Time Complexity: O(n) wrost 
Explanation: Finds the insertion index using binary search, which is O(logn), but the insertion operation could require shifting all elements by one position in the worst case, making it O(n).

is_in
Time Complexity: 

O(logn)
Explanation: Utilizes findInsertionIndex to perform a binary search, making it logarithmic time in relation to the size of the vector.

size
Time Complexity: 
O(1)
Explanation: Returns the size of the internal vector, which is a constant-time operation.
ConvertToStdVector
Time Complexity: O(n)
Explanation: Returns a copy of the internal vector, which requires iterating over all elements, making it linear time in relation to the size of the vector.