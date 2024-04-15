[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/CIyb1SNe)
# HW3 EE538

## University of Southern California

## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

## Important:

- Use address sanitizer!
- Every time that you use a dereferencing operator (* or ->) make sure your pointer is valid!

Also note that:

- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc. We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Rubrics:

| Question | Points |
| -------- | ------ |
| 1        | 16     |
| 2        | 20     |
| 3        | 15     |
| 4        | 15     |
| 5        | 20     |
| 6        | 30     |

- 100 points is considered full credit.

See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.


Q1
1
output:
Q1
Non-parameterized constructor 
o1.v_.size(): 0
Destructor
---------------------------------------------------------------
explanation:
41 A Myclass instance o1 was created using non-parameterized constructor, initializing a_ = 0,b_ = 0, ptr_ = new int, but not changing "v_", so v_size() is 0.
42 v_size() is 0.
43 Upon exiting the scope, o1 is destroyed, calling the destructor.

2
output:
Non-parameterized constructor
Parameterized constructor
Non-parameterized constructor
Copy constructor
Destructor
Destructor
Destructor
---------------------------------------------------------------
explanation:
53 o1 was created with the non-parameterized constructor.
54 o2 was created with the parameterized constructor with two integers.
55 o3 was created by copying o1 with the copy constructor.
57-59 Upon exiting the scope, destructors are called for o3, o2, and o1 in this order.

3
Q3
Non-parameterized constructor
Copy constructor
Something 1.
Destructor
Destructor
---------------------------------------------------------------
explanation:
69: A Myclass instance o was created with non-parameterized constructor..
70: Calling DoSomething1 which accepts a MyClass instance by value using copy constructor. 
71: Inside DoSomething1, the message is printed.
72: The copy used in DoSomething1 is destroyed when the function returns, 
73: Upon exiting the scope, destructors are called

4
output:
Q4
Non-parameterized constructor
Something 2.
Destructor
---------------------------------------------------------------
explanation:
85 A Myclass instance o was created with non-parameterized constructor..
86 DoSomething2 is called with a reference to the object, so no copy is made, and thus no copy constructor is called.
87 Upon exiting the scope, destructors are called

5
output:
Q5
Non-parameterized constructor
Something 3.
Destructor
---------------------------------------------------------------
explanation:
97 A Myclass instance o was created with non-parameterized constructor..
98 DoSomething3 is called with a reference to the object, so no copy is made, and thus no copy constructor is called.
99 Upon exiting the scope, destructors are called

6
output:
Q6
Non-parameterized constructor
Copy constructor
Something 4.
Destructor
Destructor
---------------------------------------------------------------
explanation:
109 A Myclass instance o was created with non-parameterized constructor.
110 DoSomething4 is called with a reference to the object, so no copy is made, and thus no copy constructor is called. Inside DoSomething4, o2 was created by copying o with the copy constructor.
111 print 
112 o2 is destroyed at the end of DoSomething4
113 Upon exiting the scope, o1 destructors are called

7
output:
Q7
Parameterized constructor
Copy constructor
Destructor
p1.first.v_.size(): 0
p1.second: 0
Copy constructor
p2.first.v_.size(): 0
p2.second: 0
Destructor
Destructor
---------------------------------------------------------------
explanation:
125: the pair p1 is initialized with MyClass(1, 2), the parameterized constructor of MyClass is called for the temporary object that is being created and passed to the pair.
126：The temporary MyClass object is copied into p1.first using the copy constructor.
127: The temporary object's destructor is called immediately after it's copied
128: Since the vector was not modified in the constructor, it's size is 0;
129: p1.second was 0 because it doesn't change
130: When initializing p2 with p1, the copy constructor of MyClass is called again to copy p1.first to p2.first.
131：p2.first.v_size() = p1.first.v_size() = 0
132: p2.second = p1.second = 0
133 Upon exiting the scope, destructors for p2.first and then p1.first are called

8
output:
Q8
Parameterized constructor
Copy constructor
Destructor
Something 2.
Something 2.
Something 2.
Destructor
---------------------------------------------------------------
explanation:
150: The pair p1 is initialized with MyClass(1, 2), the parameterized constructor of MyClass is called for the temporary object that is being created and passed to the pair.
151：The temporary MyClass object is copied into p1.first using the copy constructor.
152: The temporary object's destructor is called immediately after it's copied
153-155: call DoSomething2 3times : DoSomething2 is called with a reference to the object, so no copy is made, and thus no copy constructor is called.
156: The destructor is called when the loop's scope ends.

9
output:
Q9
Parameterized constructor
---------------------------------------------------------------
explanation:
168: MyClass(1, 2) was created with the parameterized constructor with two integers.
Q9 does not call the destructor because the object is dynamically allocated and not deleted.

10 
output:
Q10
Parameterized constructor
Destructor
---------------------------------------------------------------
explanation:
176: MyClass(1, 2) was created with the parameterized constructor with two integers.
177: delete o hence caling delete and calling Destructor
Q10 explicitly calls delete, using the destructor.

11
output:
---------------------------------------------------------------
Q11
Non-parameterized constructor
Copy constructor
Parameterized constructor
Copy constructor
Parameterized constructor
Copy constructor
Copy constructor
Copy constructor
Copy constructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Copy constructor
Destructor
Copy constructor
Destructor
Copy constructor
Destructor
Destructor
Destructor
Destructor
---------------------------------------------------------------
explanation:
189: The pair {0, MyClass()} was initialized with MyClass(), the Non-parameterized constructor of MyClass is called for the temporary object that is being created and passed to the pair.
190: The temporary MyClass object is copied into {0, MyClass()} using the copy constructor.
191: The pair {3, MyClass(1, 2)} was initialized with MyClass(), the parameterized constructor of MyClass is called for the temporary object that is being created and passed to the pair.
192: The temporary MyClass object is copied into {3, MyClass(1, 2)} using the copy constructor.
193: The pair {5, MyClass(3, 4)} was initialized with MyClass(), the parameterized constructor of MyClass is called for the temporary object that is being created and passed to the pair.
194: The temporary MyClass object is copied into {5, MyClass(3, 4)} using the copy constructor.
195-197: Once the key-value pair objects are constructed, since std::map stores copies of key-value pairs rather than references to the original objects, during insertion the copy constructors of the key and value objects are called to create these copies. For values ​​of type MyClass, this means that each insertion operation triggers a call to the copy constructor.(3 times)
198-200: The destructor is called when the std::map has stored all pairs ends.(3 times)
201-203:  The destructor is called with order of parameterized constructor(MyClass(3, 4)), parameterized constructor(MyClass(1, 2)), Non-parameterized constructor(MyClass())
204-209: This loop iterates over my_map and inserts each key into my_set. Since the loop iterates by value (auto e instead of auto& e or const auto& e), each loop use one copy constructorand and calls the destructor after the loop ends as temporary object.
210-212 The destructor is called  in order copy constructor(MyClass(3, 4)) copy constructor(MyClass(1, 2)) copy constructor(MyClass())

12
output:
Q12
Non-parameterized constructor
Copy constructor
Parameterized constructor
Copy constructor
Parameterized constructor
Copy constructor
Copy constructor
Copy constructor
Copy constructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
---------------------------------------------------------------
explanation:
230: The pair {0, MyClass()} was initialized with MyClass(), the Non-parameterized constructor of MyClass is called for the temporary object that is being created and passed to the pair.
231: The temporary MyClass object is copied into {0, MyClass()} using the copy constructor.
232: The pair {3, MyClass(1, 2)} was initialized with MyClass(), the parameterized constructor of MyClass is called for the temporary object that is being created and passed to the pair.
233: The temporary MyClass object is copied into {3, MyClass(1, 2)} using the copy constructor.
234: The pair {5, MyClass(3, 4)} was initialized with MyClass(), the parameterized constructor of MyClass is called for the temporary object that is being created and passed to the pair.
235: The temporary MyClass object is copied into {5, MyClass(3, 4)} using the copy constructor.
236-238: Once the key-value pair objects are constructed, since std::map stores copies of key-value pairs rather than references to the original objects, during insertion the copy constructors of the key and value objects are called to create these copies. For values ​​of type MyClass, this means that each insertion operation triggers a call to the copy constructor.(3 times)
239-241: The destructor is called when the std::map has stored all pairs ends.(3 times)
242-244: The destructor is called with order of parameterized constructor(MyClass(3, 4)), parameterized constructor(MyClass(1, 2)), Non-parameterized constructor(MyClass())
245-247: This loop iterates over my_map and inserts each key into my_set. Since the loop iterates use const auto& e instead of auto e, each loop doesn't call constructor.And the destructor is called in order copy constructor(MyClass(3, 4)) copy constructor(MyClass(1, 2)) copy constructor(MyClass())

13
output:
Q13
Parameterized constructor
Destructor
---------------------------------------------------------------
explanation:
264: MyClass(1, 2) was created with the parameterized constructor with two integers.
265: delete o hence caling delete and then calling Destructor
Q13 explicitly calls delete, using the destructor.

14
output:
Q14
Parameterized constructor
Operation took: 7528 milliseconds
Copy constructor
Copy constructor
Something 1.
Destructor
o2.v_.size(): 100000000
Destructor
Copy constructor
Copy constructor
Something 1.
Destructor
o2.v_.size(): 100000000
Destructor
Operation took: 2382 milliseconds
Destructor
---------------------------------------------------------------
explanation:
275: A MyClass instance o(100000000) was created with the parameterized constructor with one integer(v_.size()).
276: print initialize o(100000000) time
277: A MyClass instance o2 was created copying o by Copy constructor.
278: Inside DoSomething2 we need to create a copy of o2 by Copy constructor.
279: print something 1
280: Upon exiting the function, destructors are called for o 
281: print o2.v_.size()
282: Upon exiting the a loop, destructors are called for o2
283: A MyClass instance o2 was created copying o by Copy constructor.
284: Inside DoSomething2 we need to create a copy of o2 by Copy constructor.
285: print something 1
286: Upon exiting the function, destructors are called for o
287: print o2.v_.size()
288: Upon exiting the a loop, destructors are called for o2
289: print time for loop
290: Upon exiting the scope, destructors are called for o

15:
Q15
Parameterized constructor
Operation took: 7445 milliseconds
Copy constructor
Something 2.
o2.v_.size(): 100000000
Destructor
Copy constructor
Something 2.
o2.v_.size(): 100000000
Destructor
Operation took: 1022 milliseconds
Destructor
---------------------------------------------------------------
explanation:
312: A MyClass instance o(100000000) was created with the parameterized constructor with one integer(v_.size()).
313: print initialize o(100000000) time
314: A MyClass instance o2 was created copying o by Copy constructor.
315: print something 1, since DoSomething2 is called with a reference to the object, so no copy is made, and thus no copy constructor is called.
316: print o2.v_.size()
317: Upon exiting the a loop, destructors are called for o2
318: A MyClass instance o2 was created copying o by Copy constructor.
319: print something 1, since DoSomething2 is called with a reference to the object, so no copy is made, and thus no copy constructor is called.
320: print o2.v_.size()
321: Upon exiting the a loop, destructors are called for o2
322: print time for loop
323: Upon exiting the scope, destructors are called for o

16
Q16
Parameterized constructor
Parameterized constructor
Parameterized constructor
Parameterized constructor
Parameterized constructor
Parameterized constructor
Parameterized constructor
Copy constructor
Copy constructor
Copy constructor
Copy constructor
Copy constructor
Copy constructor
Copy constructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Operation took: 24070 milliseconds
Copy constructor
e.v_.size(): 10000000
Destructor
Copy constructor
e.v_.size(): 20000000
Destructor
Copy constructor
e.v_.size(): 30000000
Destructor
Copy constructor
e.v_.size(): 40000000
Destructor
Copy constructor
e.v_.size(): 50000000
Destructor
Copy constructor
e.v_.size(): 60000000
Destructor
Copy constructor
e.v_.size(): 70000000
Destructor
Operation took: 1625 milliseconds
e.v_.size(): 10000000
e.v_.size(): 20000000
e.v_.size(): 30000000
e.v_.size(): 40000000
e.v_.size(): 50000000
e.v_.size(): 60000000
e.v_.size(): 70000000
Operation took: 0 milliseconds
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
---------------------------------------------------------------
341-347:MyClass(10000000), MyClass(20000000),MyClass(30000000), MyClass(40000000),MyClass(50000000), MyClass(60000000),MyClass(70000000) were created by Parameterized constructor
348-354 my_vector was initialized by using Copy constructor
355-361 destructors are called for MyClass(70000000), MyClass(60000000),MyClass(50000000), MyClass(40000000),MyClass(30000000), MyClass(20000000),MyClass(10000000)
362 print time for initialize vector
363-383 Iterating over the my_vector by value (for (auto e : my_vector)) in each loop: 1.create a copy of vector in my_vector by Copy constructor 2 print size 3 when this time loop ends, calling Destructor
384: print Operation time
385-391: Iterating by reference (for (const auto &e : my_vector)) in each loop:  print size
392: print Operation time
393-399: 361 destructors are called for Myclass in vector (MyClass(70000000), MyClass(60000000),MyClass(50000000), MyClass(40000000),MyClass(30000000), MyClass(20000000),MyClass(10000000)) which were created by copy constructor.
Explain the time of the measured operations:
Constructing the initial vector of MyClass objects takes time proportional to the size and number of vectors being initialized.
Iterating by value significantly increases the operation time due to copying.
Iterating by reference is much quicker, demonstrating the efficiency of avoiding unnecessary copies.