# Linked List Demonstration

A C++ console application that demonstrates various operations on a singly linked list data structure.

## Features

The program demonstrates the following linked list operations:

- **Insertion**: Add elements to front, back, or at specific positions
- **Deletion**: Remove elements from front, back, or at specific positions
- **Search**: Find elements in the list
- **Access**: Get elements at specific positions
- **Utility**: Display list, get size, reverse list, clear list
- **Memory Management**: Proper cleanup with destructor and copy semantics

## Project Structure

```
LinkedList/
├── LinkedList.h      # Header file with LinkedList class template
├── main.cpp         # Main program with interactive menu
├── CMakeLists.txt   # CMake build configuration
├── Makefile         # Alternative build option
└── README.md        # This file
```

## Building the Project

### Option 1: Using CMake (Recommended)

1. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```

2. Configure the project:
   ```bash
   cmake ..
   ```

3. Build the project:
   ```bash
   cmake --build .
   ```

4. The executable will be created in `build/bin/` directory.

### Option 2: Using Makefile

1. Simply run:
   ```bash
   make
   ```

2. Or to build and run in one command:
   ```bash
   make run
   ```

### Option 3: Direct Compilation

1. Compile directly with g++:
   ```bash
   g++ -std=c++17 -Wall -Wextra -O2 -o LinkedList main.cpp
   ```

## Running the Program

1. Navigate to the directory containing the executable
2. Run the program:
   ```bash
   ./LinkedList          # On Unix-like systems
   LinkedList.exe        # On Windows
   ```

## Program Features

The interactive menu allows you to:

1. **Add element to front** - Insert a new element at the beginning
2. **Add element to back** - Append a new element at the end
3. **Insert element at position** - Insert at a specific index
4. **Remove element from front** - Delete the first element
5. **Remove element from back** - Delete the last element
6. **Remove element at position** - Delete element at specific index
7. **Search for element** - Check if a value exists in the list
8. **Get element at position** - Retrieve value at specific index
9. **Reverse the list** - Reverse the order of all elements
10. **Clear the list** - Remove all elements
11. **Display the list** - Show current list contents
12. **Show list size** - Display current number of elements
0. **Exit** - Quit the program

## Example Usage

```
=== Linked List Demonstration ===
1. Add element to front
2. Add element to back
3. Insert element at position
4. Remove element from front
5. Remove element from back
6. Remove element at position
7. Search for element
8. Get element at position
9. Reverse the list
10. Clear the list
11. Display the list
12. Show list size
0. Exit
Enter your choice: 1
Enter value to add to front: 10
Added 10 to front of list.

Current list: List contents: 10
```

## Technical Details

- **Template Class**: The LinkedList is implemented as a template class, allowing it to work with any data type
- **Memory Management**: Proper memory cleanup with destructor, copy constructor, and assignment operator
- **Error Handling**: Bounds checking and exception handling for invalid operations
- **Efficiency**: O(1) operations for front/back operations, O(n) for position-based operations
- **C++17 Standard**: Uses modern C++ features for better code quality

## Requirements

- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.10+ (if using CMake build)
- Make (if using Makefile build)

## Learning Objectives

This project demonstrates:

- **Data Structures**: Implementation of a linked list
- **Memory Management**: Dynamic allocation and cleanup
- **Template Programming**: Generic data structure implementation
- **Error Handling**: Input validation and exception handling
- **User Interface**: Console-based interactive program
- **C++ Best Practices**: Modern C++ idioms and patterns

## Contributing

Feel free to extend this project with additional features such as:
- Doubly linked list implementation
- Circular linked list
- Additional algorithms (sorting, merging, etc.)
- Performance optimizations
- Unit tests

## License

This project is open source and available under the MIT License.
