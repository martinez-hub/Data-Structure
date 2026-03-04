# Data-Structure Fix Log

## Scope
This document records the fixes applied to compile errors, runtime correctness bugs, memory-safety issues, and repo hygiene in this repository.

## 1) Compile blockers fixed

- `doubleLinkedlist/IntDLList.h`
  - Removed stray token at file start that broke parsing.
  - Fixed `addToTail` typo (`tail = tail->getNext();`).
  - Reworked `sortInsert` and `insert` to use valid node construction and safe pointer flow.

- `BinarySearchTree/BSTNode.h`
  - Removed duplicate default arguments from out-of-class `setLeft`/`setRight` definitions.

- `circleLinkedList/circDLList.h`
  - Fixed `searchNode` declaration/definition mismatch.
  - Replaced malformed loop condition in search routine.
  - Updated insertion helpers to avoid uninitialized pointer usage.

- `Digital-Library-Database`
  - `BSTNode.h`: changed `getInfo` to reference-returning overloads (mutable + const).
  - `intDLLNode.h`: changed `getInfo` to reference-returning overloads (mutable + const).
  - This unblocked `Library.cpp` mutations that previously took addresses of temporaries.

## 2) Runtime correctness fixes

- `SingleLinkedList/IntSLList.h`
  - Rewrote `sortInsert` to avoid uninitialized predecessor pointer and preserve ordering logic.
  - Rewrote `insert` branching to prevent invalid dereference and tail corruption.

- `BinarySearchTree/BSTree.h`
  - Fixed missing return in `isEmpty()`.
  - Replaced broken `recursiveSearchForRemove` right-branch logic that used uninitialized `found`.

- `Digital-Library-Database/BSTree.h`
  - Fixed missing return in `isEmpty()`.
  - Reworked `recursiveSearchForRemove` to compare via `.getName()` consistently and avoid invalid pointers.

- `circleLinkedList/circDLList.h`
  - Fixed memory leak in `deleteFromHead()` one-node path by always deleting removed node.

- `Digital-Library-Database/circDLList.h`
  - Fixed memory leak in `deleteFromHead()` one-node path.
  - Reworked `searchNode()` to stop correctly in circular traversal when item is absent.
  - Reworked `deleteNode()` to avoid undefined behavior and handle all head/middle/tail/singleton cases safely.
  - Replaced `free()` calls on `new`-allocated nodes with `delete`.

## 3) Ownership/copy safety improvements

- `operatorOverloading/Arrays.h/.cpp`
  - Copy constructor now deep-copies array storage.
  - Assignment operator now handles self-assignment and reallocates when sizes differ.
  - Prevents aliasing/double-free and out-of-bounds writes.

- `polymorphism/Arrays.cpp`
  - Copy constructor now deep-copies array storage (was shallow).

- `polynomial/Polynomial.cpp`
  - Multiplication accumulator changed from `int` to `double` in `operator*` and `operator*=` to prevent precision loss.

## 4) Repository hygiene

- Added `.gitignore` at repo root for:
  - `*.o`, `*.out`, `*.exe`
  - `*.gch`
  - `.DS_Store`

- Removed committed precompiled headers:
  - `SingleLinkedList/IntSLLNode.h.gch`
  - `doubleLinkedlist/IntSLList.h.gch`

## 5) Verification

All major modules compile successfully after the fixes.

Commands used:

```bash
g++ -std=c++11 SingleLinkedList/singleLinkedList.cpp -o /tmp/sll.out
g++ -std=c++11 doubleLinkedlist/doubleLinkedList.cpp -o /tmp/dll.out
g++ -std=c++11 circleLinkedList/circularDblLinkedList.cpp -o /tmp/cdll.out
g++ -std=c++11 BinarySearchTree/usingBSTree.cpp -o /tmp/bst.out
g++ -std=c++11 operatorOverloading/userArrays.cpp operatorOverloading/Arrays.cpp -o /tmp/op_arr.out
g++ -std=c++11 polymorphism/userArrays.cpp polymorphism/Arrays.cpp -o /tmp/poly_arr.out
g++ -std=c++11 polynomial/usingPolynomial.cpp polynomial/Polynomial.cpp -o /tmp/poly.out
g++ -std=c++11 timeExample/manageTime.cpp timeExample/Time.cpp -o /tmp/time.out
g++ -std=c++11 timeExample/manageExtTime.cpp timeExample/Time.cpp timeExample/ExtTime.cpp -o /tmp/exttime.out
g++ -std=c++11 Digital-Library-Database/Library.cpp Digital-Library-Database/Author.cpp Digital-Library-Database/Genre.cpp Digital-Library-Database/Book.cpp -o /tmp/library.out
```

Result: all commands succeeded.
