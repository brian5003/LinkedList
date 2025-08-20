#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    size_t size;
    
public:
    // Constructor
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    // Destructor
    ~LinkedList() {
        clear();
    }
    
    // Copy constructor
    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), size(0) {
        Node* current = other.head;
        while (current != nullptr) {
            pushBack(current->data);
            current = current->next;
        }
    }
    
    // Assignment operator
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current != nullptr) {
                pushBack(current->data);
                current = current->next;
            }
        }
        return *this;
    }
    
    // Check if list is empty
    bool isEmpty() const {
        return head == nullptr;
    }
    
    // Get size of list
    size_t getSize() const {
        return size;
    }
    
    // Add element to front of list
    void pushFront(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    
    // Add element to back of list
    void pushBack(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    // Insert element at specific position
    void insertAt(size_t position, const T& value) {
        if (position > size) {
            std::cout << "Position out of bounds!" << std::endl;
            return;
        }
        
        if (position == 0) {
            pushFront(value);
            return;
        }
        
        if (position == size) {
            pushBack(value);
            return;
        }
        
        Node* newNode = new Node(value);
        Node* current = head;
        for (size_t i = 0; i < position - 1; i++) {
            current = current->next;
        }
        
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
    
    // Remove element from front
    void popFront() {
        if (isEmpty()) {
            std::cout << "List is empty!" << std::endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        
        if (head == nullptr) {
            tail = nullptr;
        }
    }
    
    // Remove element from back
    void popBack() {
        if (isEmpty()) {
            std::cout << "List is empty!" << std::endl;
            return;
        }
        
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            size = 0;
            return;
        }
        
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        
        delete tail;
        tail = current;
        tail->next = nullptr;
        size--;
    }
    
    // Remove element at specific position
    void removeAt(size_t position) {
        if (position >= size) {
            std::cout << "Position out of bounds!" << std::endl;
            return;
        }
        
        if (position == 0) {
            popFront();
            return;
        }
        
        if (position == size - 1) {
            popBack();
            return;
        }
        
        Node* current = head;
        for (size_t i = 0; i < position - 1; i++) {
            current = current->next;
        }
        
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
    }
    
    // Search for element
    bool search(const T& value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    // Get element at specific position
    T& at(size_t position) {
        if (position >= size) {
            throw std::out_of_range("Position out of bounds!");
        }
        
        Node* current = head;
        for (size_t i = 0; i < position; i++) {
            current = current->next;
        }
        return current->data;
    }
    
    // Clear the list
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }
    
    // Display the list
    void display() const {
        if (isEmpty()) {
            std::cout << "List is empty!" << std::endl;
            return;
        }
        
        Node* current = head;
        std::cout << "List contents: ";
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << " -> ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    // Reverse the list
    void reverse() {
        if (isEmpty() || head == tail) {
            return;
        }
        
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        tail = head;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

#endif // LINKEDLIST_H
