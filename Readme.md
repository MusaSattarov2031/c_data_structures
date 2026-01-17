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


### 🚀 How to Run
To compile and run the tests for any structure, navigate to its folder and use the provided Makefile:
```bash
#navigate to needed folder
make
make run
#to clean compiled file
make clean
```
🛠 PrerequisitesCompiler: GCC (MinGW for Windows).

Build Tool: GNU Make (mingw32-make on Windows).
