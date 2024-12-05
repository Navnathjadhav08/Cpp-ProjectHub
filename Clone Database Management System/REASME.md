# Student Management System with C++

## Overview
This project is a simple Database Management System (DBMS) implemented in C++ that allows managing student records. It supports operations such as inserting, selecting, updating, and deleting records, along with basic aggregation and sorting functionalities. The system uses a CSV file for persistent storage and supports SQL-like queries for interacting with the data.

## Functionality
The DBMS supports the following operations:

1. **Insert Records**: Add new student records.
2. **Select Records**: Retrieve student records based on criteria or list all records.
3. **Update Records**: Modify existing student records.
4. **Delete Records**: Remove student records.
5. **Aggregate Functions**: Perform calculations like maximum, minimum, average, and sum of student marks.
6. **Sorting**: Sort student records by age or marks.
7. **File Storage**: Save and load records from a CSV file for data persistence.

## Features
- **SQL-like Query Interface**: Intuitive commands for interacting with the database.
- **File Persistence**: Records are saved and loaded from a CSV file.
- **Aggregate Functions**: Perform statistical operations on student data.
- **Sorting**: Retrieve data in sorted order based on specific attributes.
- **Duplicate Detection**: Prevents duplicate records during insertion.

## Advantages
- **Easy to Use**: The interface is simple and user-friendly.
- **Persistent Storage**: Records are stored in a file for later use.
- **Efficient Management**: Supports basic database operations.
- **Customizable**: Can be extended to include additional features.

## What You Will Learn
- File handling in C++ using streams.
- Implementing SQL-like query parsing.
- Basic database management concepts.
- Vector operations and memory management.
- Using classes and objects for structured programming.

## How to Run
### Prerequisites
- A C++ compiler (e.g., GCC, Clang, or Visual Studio).
- A text editor or IDE for writing and running C++ code.

### Steps to Run
1. **Clone or Download the Repository**:
   ```
   git clone <repository-url>
   ```
2. **Compile the Code**:
   ```
   g++ -o dbms dbms.cpp
   ```
3. **Run the Executable**:
   ```
   ./dbms
   ```
4. **Interact with the DBMS**: Type queries in the console to perform various operations.

### Supported Queries
- **Insert Record**:
  ```
  insert into student values <name> <age> <marks>
  ```
  Example:
  ```
  insert into student values John 20 85
  ```

- **Select All Records**:
  ```
  select * from student
  ```

- **Update Record**:
  ```
  update student set age=<new_age> marks=<new_marks> where rno=<rno>
  ```
  Example:
  ```
  update student set age=21 marks=90 where rno=1
  ```

- **Delete Record**:
  ```
  delete from student where rno=<rno>
  ```
  Example:
  ```
  delete from student where rno=2
  ```

- **Aggregate Functions**:
  ```
  max marks
  min marks
  avg marks
  sum marks
  ```
  Example:
  ```
  max marks
  ```

- **Sort Records**:
  ```
  sort by age
  sort by marks
  ```
  Example:
  ```
  sort by marks
  ```

- **Exit the DBMS**:
  ```
  exit
  ```

## Sample Input and Output
### Sample Input:
```plaintext
DBMS : insert into student values Ram 19 92
DBMS : insert into student values Sham 21 78
DBMS : select * from student
DBMS : max marks
DBMS : sort by age
DBMS : exit
```

### Sample Output:
```plaintext
Record inserted successfully.
Record inserted successfully.
Records from the student table are:
1 Ram 19 92
2 Sham 21 78
Maximum marks: 92
Records from the student table are:
1 Ram 19 92
2 Sham 21 78
Thank you for using DBMS...
```

## File Structure
- **dbms.cpp**: Main source code file.
- **students.txt**: CSV file for storing student records.

## Future Enhancements
- Add support for more complex queries.
- Include indexing for faster retrieval.
- Integrate a graphical user interface (GUI).
- Extend to support more data types and constraints.

---

Feel free to contribute to this project by submitting pull requests or reporting issues.

