# Data-Structure

Collection of C++ data structure and OOP practice projects.

## Requirements

- `g++` with C++11 support
- macOS/Linux terminal (commands below use POSIX shell)

## Quick Start

```bash
cd /Users/josuemartinez/Documents/PersonalProjects/Data-Structure
```

## Projects and How to Run

### 1) Singly Linked List

```bash
g++ -std=c++11 SingleLinkedList/singleLinkedList.cpp -o /tmp/sll.out
/tmp/sll.out
```

### 2) Doubly Linked List

```bash
g++ -std=c++11 doubleLinkedlist/doubleLinkedList.cpp -o /tmp/dll.out
/tmp/dll.out
```

### 3) Circular Doubly Linked List

```bash
g++ -std=c++11 circleLinkedList/circularDblLinkedList.cpp -o /tmp/cdll.out
/tmp/cdll.out
```

### 4) Binary Search Tree

```bash
g++ -std=c++11 BinarySearchTree/usingBSTree.cpp -o /tmp/bst.out
/tmp/bst.out
```

### 5) Operator Overloading (Arrays)

```bash
g++ -std=c++11 operatorOverloading/userArrays.cpp operatorOverloading/Arrays.cpp -o /tmp/op_arr.out
/tmp/op_arr.out
```

### 6) Polymorphism (Arrays)

```bash
g++ -std=c++11 polymorphism/userArrays.cpp polymorphism/Arrays.cpp -o /tmp/poly_arr.out
/tmp/poly_arr.out
```

### 7) Polynomial Operators

```bash
g++ -std=c++11 polynomial/usingPolynomial.cpp polynomial/Polynomial.cpp -o /tmp/poly.out
/tmp/poly.out
```

### 8) Time / Extended Time

```bash
g++ -std=c++11 timeExample/manageTime.cpp timeExample/Time.cpp -o /tmp/time.out
/tmp/time.out

g++ -std=c++11 timeExample/manageExtTime.cpp timeExample/Time.cpp timeExample/ExtTime.cpp -o /tmp/exttime.out
/tmp/exttime.out
```

### 9) Digital Library Database

```bash
g++ -std=c++11 Digital-Library-Database/Library.cpp Digital-Library-Database/Author.cpp Digital-Library-Database/Genre.cpp Digital-Library-Database/Book.cpp -o /tmp/library.out
/tmp/library.out
```

## Notes

- Most programs are interactive console demos.
- Output binaries in examples are placed in `/tmp` to avoid polluting the repo.
- Build/repo cleanup and bug-fix details are documented in `FIXES.md`.
