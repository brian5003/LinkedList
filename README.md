# Linked List Demonstration

A comprehensive C++ console application that demonstrates various operations on a singly linked list data structure. This project showcases modern C++ programming practices, memory management, and data structure implementation.

## 🚀 Features

The program demonstrates the following linked list operations:

- **Insertion Operations**
  - Add elements to front (`pushFront`)
  - Add elements to back (`pushBack`) 
  - Insert elements at specific positions (`insertAt`)

- **Deletion Operations**
  - Remove elements from front (`popFront`)
  - Remove elements from back (`popBack`)
  - Remove elements at specific positions (`removeAt`)

- **Search & Access**
  - Search for elements (`search`)
  - Access elements by position (`at`)
  - Get list size (`getSize`)

- **Utility Operations**
  - Display list contents (`display`)
  - Reverse the list (`reverse`)
  - Clear the list (`clear`)
  - Check if empty (`isEmpty`)

- **Advanced Features**
  - Template-based implementation (works with any data type)
  - Proper memory management with RAII
  - Copy constructor and assignment operator
  - Exception handling for bounds checking
  - Interactive console interface

## 🏗️ Project Structure

```
LinkedList/
├── LinkedList.h          # Header file with LinkedList class template
├── main.cpp             # Interactive console application
├── test.cpp             # Automated test program
├── CMakeLists.txt       # CMake build configuration
├── Makefile             # Alternative build option
├── build_vs2022.bat     # Visual Studio 2022 build script
├── find_vs.bat          # Visual Studio detection script
├── .gitignore           # Git ignore rules for C++ projects
└── README.md            # This file
```

## 📋 Requirements

- **Operating System**: Windows 10/11
- **C++ Compiler**: Visual Studio 2022 Community (or Professional/Enterprise)
- **C++ Standard**: C++17 or later
- **Build Tools**: Visual Studio Build Tools or full Visual Studio installation

## 🛠️ Setup Instructions

### Prerequisites

1. **Install Visual Studio 2022 Community** (Free)
   - Download from: [Visual Studio Downloads](https://visualstudio.microsoft.com/downloads/)
   - During installation, select **"Desktop development with C++"** workload
   - This includes the MSVC compiler, standard libraries, and build tools

2. **Verify Installation**
   - Open Start Menu and search for "Developer Command Prompt for VS 2022"
   - If found, the installation is complete

### Project Setup

1. **Clone or Download the Project**
   ```bash
   git clone <repository-url>
   cd LinkedList
   ```

2. **Verify Project Files**
   - Ensure `main.cpp` and `LinkedList.h` are present
   - Check that `build_vs2022.bat` exists

## 🔨 Building the Project

### Option 1: Using the Build Script (Recommended)

The easiest way to build the project is using the provided batch file:

```bash
# From Command Prompt or PowerShell
cmd /c build_vs2022.bat
```

This script will:
- Automatically set up the Visual Studio 2022 environment
- Compile the project with proper flags
- Create `LinkedList.exe` executable

### Option 2: Using Developer Command Prompt

1. **Open Developer Command Prompt for VS 2022**
   - Press Windows key and search for "Developer Command Prompt for VS 2022"
   - Click to open

2. **Navigate to Project Directory**
   ```bash
   cd C:\Users\brian-admin\Desktop\LinkedList
   ```

3. **Build the Project**
   ```bash
   cl /std:c++17 /EHsc /W4 /Fe:LinkedList.exe main.cpp
   ```

### Option 3: Using CMake

If you prefer CMake-based builds:

1. **Create Build Directory**
   ```bash
   mkdir build
   cd build
   ```

2. **Configure and Build**
   ```bash
   cmake ..
   cmake --build .
   ```

3. **Find Executable**
   - The executable will be in `build\bin\LinkedList.exe`

### Option 4: Using Makefile

For Unix-like environments or MinGW:

```bash
make
# or
make run
```

## 🚀 Running the Program

### Main Interactive Program

```bash
# Run the interactive linked list demonstration
.\LinkedList.exe
```

**Features:**
- Interactive menu with 12 operations
- Real-time list visualization
- Input validation and error handling
- Comprehensive operation demonstrations

### Test Program

```bash
# Build the test program
cl /std:c++17 /EHsc /W4 /Fe:test.exe test.cpp

# Run automated tests
.\test.exe
```

**Features:**
- Automated testing of all linked list operations
- No user interaction required
- Comprehensive operation coverage
- Performance demonstration

## 🎮 Using the Program

### Interactive Menu Options

1. **Add element to front** - Insert at beginning
2. **Add element to back** - Append at end  
3. **Insert element at position** - Insert at specific index
4. **Remove element from front** - Delete first element
5. **Remove element from back** - Delete last element
6. **Remove element at position** - Delete at specific index
7. **Search for element** - Check if value exists
8. **Get element at position** - Retrieve value at index
9. **Reverse the list** - Reverse element order
10. **Clear the list** - Remove all elements
11. **Display the list** - Show current contents
12. **Show list size** - Display element count
0. **Exit** - Quit program

### Example Session

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

## 🔧 Build Configuration

### Compiler Flags Used

- **`/std:c++17`** - Enable C++17 standard features
- **`/EHsc`** - Enable C++ exception handling
- **`/W4`** - Enable high warning level
- **`/Fe:LinkedList.exe`** - Specify output executable name

### CMake Configuration

- **Minimum Version**: CMake 3.10
- **C++ Standard**: C++17
- **Build Type**: Release (configurable)
- **Output Directory**: `build/bin/`

## 🧪 Testing

### Automated Tests

The `test.cpp` file provides comprehensive testing:

- **Basic Operations**: push, pop, insert, remove
- **Edge Cases**: empty list, single element, bounds checking
- **Advanced Features**: reverse, copy constructor, assignment
- **Memory Management**: proper cleanup verification

### Manual Testing

Use the interactive program to:
- Test various input combinations
- Verify error handling
- Explore edge cases
- Understand algorithm behavior

## 📚 Learning Objectives

This project demonstrates:

- **Data Structures**: Complete linked list implementation
- **Memory Management**: RAII, smart pointers, cleanup
- **Template Programming**: Generic data structure design
- **Modern C++**: C++17 features and best practices
- **Error Handling**: Exception safety and bounds checking
- **User Interface**: Console-based interactive programs
- **Testing**: Automated and manual testing approaches

## 🐛 Troubleshooting

### Common Issues

1. **"cl is not recognized"**
   - Use Developer Command Prompt for VS 2022
   - Or run `build_vs2022.bat`

2. **"iostream: no include path set"**
   - Visual Studio environment not configured
   - Run `build_vs2022.bat` or use Developer Command Prompt

3. **Build failures**
   - Ensure C++17 support is enabled
   - Check Visual Studio installation includes C++ workload

4. **CMake errors**
   - Verify CMake version (3.10+)
   - Use Developer Command Prompt for proper environment

### Getting Help

- Check Visual Studio installation includes "Desktop development with C++"
- Verify `build_vs2022.bat` can find your Visual Studio installation
- Use Developer Command Prompt for VS 2022 as alternative

## 🤝 Contributing

Feel free to extend this project with:

- **Additional Data Structures**: Doubly linked list, circular list
- **Algorithms**: Sorting, merging, partitioning
- **Performance Optimizations**: Memory pools, cache-friendly design
- **Unit Tests**: Comprehensive test coverage
- **Documentation**: Code comments, design documents
- **Features**: GUI interface, file I/O, networking

## 📄 License

This project is open source and available under the MIT License.

## 🙏 Acknowledgments

- Microsoft Visual Studio team for excellent C++ tools
- C++ community for best practices and standards
- Data structure and algorithm resources

---

**Happy Coding! 🎉**

For questions or issues, please check the troubleshooting section or open an issue in the project repository.
