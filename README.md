# C++ Project Hub

Welcome to the C++ Project Hub! This repository showcases two comprehensive C++ projects that highlight advanced programming techniques, efficient data management, and modular software design. Dive into the details of each project below.

---

## 1. Dbms Clone System

### Overview
The Dbms System is a robust application designed to manage student records. It offers functionalities for inserting, updating, and deleting student data stored in a text file. The application ensures data persistence and efficient record handling through the following key features:

### Features
- **Insert Records:** Add new student records with fields such as name, age, and marks.
- **Update Records:** Modify existing records based on the student’s roll number.
- **Delete Records:** Remove records by roll number.
- **File Persistence:** Store and retrieve data from a text file (`students.txt`) for long-term storage.

### Key Functions
1. **Insert Record:** Adds a new student to the system and assigns a unique roll number.
2. **Update Record:** Updates the marks of a student identified by their roll number.
3. **Delete Record:** Deletes a student record based on roll number.
4. **File Operations:** Reads and writes student data to and from the `students.txt` file in CSV format.

### Knowledge Gained
- File handling and parsing in C++.
- Efficient use of STL containers like `vector`.
- Implementation of CRUD operations.
- Modular programming design.

---

## 2. Customized Standard Template Data Structure Library (Cstdsl.cpp)

### Overview
The Customized Standard Template Data Structure Library is a collection of linear and non-linear data structures implemented in C++ using templates. This library provides flexible, type-independent data structures that can be easily integrated into various C++ projects.

### Contents
This library includes the following data structures:
- **Class SingyLL:** Implementation of a Singly Linked List.
- **Class DoublyLL:** Implementation of a Doubly Linked List.
- **Class SinglyCircular:** Implementation of a Singly Circular Linked List.
- **Class DoublyCircular:** Implementation of a Doubly Circular Linked List.
- **Class Stack:** Implementation of a Stack using linked list structure.
- **Class Queue:** Implementation of a Queue using linked list structure.
- **Class BinarySearchTree:** Implementation of a Binary Search Tree.

### Features
- **Template-Based Design:** Type-independent data structures using C++ templates.
- **Memory Efficient:** Linked list-based implementations for dynamic data management.
- **Modular Classes:** Encapsulated design for each data structure.
- **Comprehensive Functionality:** Operations such as insertion, deletion, traversal, and searching.

### Advantages
- **Flexibility:** Supports any data type, from basic to user-defined types.
- **Reusability:** Modular design for easy integration into projects.
- **Performance:** Optimized algorithms for common operations.
- **Learning Resource:** Educational tool for advanced data structures in C++.

### Installation
To use the Customized Standard Template Data Structure Library, include the `Cstdsl.cpp` file in your C++ project and instantiate the desired data structures:

```cpp
#include "Cstdsl.cpp"

// Example usage
SinglyLL<int> l1;
l1.InsertFirst(11);
l1.InsertLast(21);
l1.InsertLast(51);
l1.InsertLast(111);
l1.InsertLast(110);
l1.Display();

SinglyLL<int> intList;
Stack<float> floatStack;
BinarySearchTree<string> stringTree;
```

### Knowledge Gained
- Understanding of advanced data structures and their applications.
- Template programming in C++ for type-independent code.
- Algorithm optimization for efficient operations.
- Dynamic memory management in C++.
- Modular software design principles.

### Future Enhancements
- Improved documentation for each class and method.
- Robust error handling and exception management.

---

## Conclusion
These projects reflect the versatility and power of C++ in building efficient and modular applications. Whether you're exploring student management systems or delving into customized data structures, this repository offers a wealth of learning and utility. Happy coding!

