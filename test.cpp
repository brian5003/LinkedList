#include <iostream>
#include "LinkedList.h"

int main() {
    std::cout << "=== Linked List Test Program ===\n\n";
    
    // Create a linked list
    LinkedList<int> list;
    
    std::cout << "Initial list: ";
    list.display();
    std::cout << "Size: " << list.getSize() << "\n\n";
    
    // Test push operations
    std::cout << "Adding elements...\n";
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);
    list.pushFront(5);
    list.pushFront(1);
    
    std::cout << "After adding elements: ";
    list.display();
    std::cout << "Size: " << list.getSize() << "\n\n";
    
    // Test insert at position
    std::cout << "Inserting 15 at position 2...\n";
    list.insertAt(2, 15);
    list.display();
    std::cout << "Size: " << list.getSize() << "\n\n";
    
    // Test search
    std::cout << "Searching for 20: ";
    if (list.search(20)) {
        std::cout << "Found!\n";
    } else {
        std::cout << "Not found!\n";
    }
    
    std::cout << "Searching for 99: ";
    if (list.search(99)) {
        std::cout << "Found!\n";
    } else {
        std::cout << "Not found!\n";
    }
    std::cout << "\n";
    
    // Test access at position
    try {
        std::cout << "Element at position 3: " << list.at(3) << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    std::cout << "\n";
    
    // Test reverse
    std::cout << "Reversing the list...\n";
    list.reverse();
    list.display();
    std::cout << "\n";
    
    // Test removal operations
    std::cout << "Removing from front...\n";
    list.popFront();
    list.display();
    std::cout << "Size: " << list.getSize() << "\n\n";
    
    std::cout << "Removing from back...\n";
    list.popBack();
    list.display();
    std::cout << "Size: " << list.getSize() << "\n\n";
    
    std::cout << "Removing at position 1...\n";
    list.removeAt(1);
    list.display();
    std::cout << "Size: " << list.getSize() << "\n\n";
    
    // Test copy constructor
    std::cout << "Creating a copy of the list...\n";
    LinkedList<int> listCopy = list;
    std::cout << "Original list: ";
    list.display();
    std::cout << "Copied list: ";
    listCopy.display();
    std::cout << "\n";
    
    // Test clear
    std::cout << "Clearing the original list...\n";
    list.clear();
    std::cout << "Original list: ";
    list.display();
    std::cout << "Copied list: ";
    listCopy.display();
    std::cout << "\n";
    
    std::cout << "Test completed successfully!\n";
    return 0;
}
