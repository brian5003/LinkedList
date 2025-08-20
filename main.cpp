#include <iostream>
#include <limits>
#include "LinkedList.h"

void displayMenu() {
    std::cout << "\n=== Linked List Demonstration ===\n";
    std::cout << "1. Add element to front\n";
    std::cout << "2. Add element to back\n";
    std::cout << "3. Insert element at position\n";
    std::cout << "4. Remove element from front\n";
    std::cout << "5. Remove element from back\n";
    std::cout << "6. Remove element at position\n";
    std::cout << "7. Search for element\n";
    std::cout << "8. Get element at position\n";
    std::cout << "9. Reverse the list\n";
    std::cout << "10. Clear the list\n";
    std::cout << "11. Display the list\n";
    std::cout << "12. Show list size\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getIntInput() {
    int value;
    while (!(std::cin >> value)) {
        std::cout << "Invalid input! Please enter a number: ";
        clearInputBuffer();
    }
    return value;
}

int main() {
    LinkedList<int> list;
    int choice, value, position;
    
    std::cout << "Welcome to the Linked List Demonstration!\n";
    std::cout << "This program demonstrates various operations on a linked list.\n";
    
    do {
        displayMenu();
        choice = getIntInput();
        
        switch (choice) {
            case 1:
                std::cout << "Enter value to add to front: ";
                value = getIntInput();
                list.pushFront(value);
                std::cout << "Added " << value << " to front of list.\n";
                break;
                
            case 2:
                std::cout << "Enter value to add to back: ";
                value = getIntInput();
                list.pushBack(value);
                std::cout << "Added " << value << " to back of list.\n";
                break;
                
            case 3:
                std::cout << "Enter position (0-" << list.getSize() << "): ";
                position = getIntInput();
                std::cout << "Enter value to insert: ";
                value = getIntInput();
                list.insertAt(position, value);
                break;
                
            case 4:
                list.popFront();
                std::cout << "Removed element from front.\n";
                break;
                
            case 5:
                list.popBack();
                std::cout << "Removed element from back.\n";
                break;
                
            case 6:
                if (list.isEmpty()) {
                    std::cout << "List is empty!\n";
                } else {
                    std::cout << "Enter position (0-" << (list.getSize() - 1) << "): ";
                    position = getIntInput();
                    list.removeAt(position);
                }
                break;
                
            case 7:
                std::cout << "Enter value to search for: ";
                value = getIntInput();
                if (list.search(value)) {
                    std::cout << "Element " << value << " found in the list.\n";
                } else {
                    std::cout << "Element " << value << " not found in the list.\n";
                }
                break;
                
            case 8:
                if (list.isEmpty()) {
                    std::cout << "List is empty!\n";
                } else {
                    std::cout << "Enter position (0-" << (list.getSize() - 1) << "): ";
                    position = getIntInput();
                    try {
                        value = list.at(position);
                        std::cout << "Element at position " << position << " is: " << value << "\n";
                    } catch (const std::out_of_range& e) {
                        std::cout << "Error: " << e.what() << "\n";
                    }
                }
                break;
                
            case 9:
                list.reverse();
                std::cout << "List has been reversed.\n";
                break;
                
            case 10:
                list.clear();
                std::cout << "List has been cleared.\n";
                break;
                
            case 11:
                list.display();
                break;
                
            case 12:
                std::cout << "List size: " << list.getSize() << "\n";
                break;
                
            case 0:
                std::cout << "Thank you for using the Linked List Demonstration!\n";
                break;
                
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
        
        if (choice != 0) {
            std::cout << "\nCurrent list: ";
            list.display();
        }
        
    } while (choice != 0);
    
    return 0;
}
