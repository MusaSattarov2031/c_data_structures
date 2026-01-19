# C Data Structures
A collection of fundamental data structures implemented from scratch in C, focusing on manual memory management and performance.
## 📦 Implemented Structures1. 

### Dynamic Array (Vector)
A growable array that mimics the behavior of a Python list or C++ std::vector.
#### Features: 
- Amortized O(1) insertion
- O(n) removal/insertion at index, and automatic resizing.
- Memory Management: Uses malloc, realloc, and free for heap safety.

### Linked List
This section contains a custom implementation of a Singly Linked List in C. Unlike the previous Vector implementation, this structure uses non-contiguous memory allocation on the Heap, linked via self-referential pointers.
#### Features:
 - Dynamic Sizing: Allocates memory node-by-node, avoiding the need for realloc overhead.
 - Pointer-Based Logic: Utilizes Double Pointers (**) for operations that modify the head of the list, ensuring memory safety across function scopes.
 - Memory Managed: Includes a robust list_free function verified with Valgrind to ensure zero memory leaks.

### Doubly Linked List
A bidirectional linear data structure where each node contains pointers to both the next and the previous nodes. This implementation focuses on the trade-off between increased memory usage and improved flexibility in traversal.
#### Features:
 - Bidirectional Traversal: Support for both forward and backward iteration.
 - Enhanced Node Deletion: Ability to remove a node in O(1) time if the node pointer is already known, as the previous neighbor is directly accessible.
 - Boundary Safety: Robust handling of edge cases, such as updating pointers when the list contains only a single node or when the head is modified.
 - Zero Memory Leaks: Full heap cleanup logic verified with Valgrind.


### 🚀 How to Run
To compile and run the tests for any structure, navigate to its folder and use the provided Makefile:
```bash
cd vector
make
make run
#to clean compiled file
make clean
```
🛠 PrerequisitesCompiler: GCC (MinGW for Windows).

Build Tool: GNU Make (mingw32-make on Windows).
