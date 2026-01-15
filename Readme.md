# C Data Structures
A collection of fundamental data structures implemented from scratch in C, focusing on manual memory management and performance.
## 📦 Implemented Structures1. D
### Dynamic Array (Vector)
A growable array that mimics the behavior of a Python list or C++ std::vector.
#### Features: 
- Amortized O(1) insertion
- O(n) removal/insertion at index, and automatic resizing.
- Memory Management: Uses malloc, realloc, and free for heap safety.
#### 🚀 How to Run
To compile and run the tests for any structure, navigate to its folder and use the provided Makefile:
'''bash
cd vector
make run
'''
🛠 PrerequisitesCompiler: GCC (MinGW for Windows).Build Tool: GNU Make (mingw32-make on Windows).
