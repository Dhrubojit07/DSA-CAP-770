#include <iostream>

const int MAX_SIZE = 100; // Adjust this for the desired maximum number of elements

class Stack {
public:
    Stack() : top(-1) {} // Initialize top index to -1 (empty stack)

    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    // Add an element to the end of the stack (push)
    void push(int value) {
        if (isFull()) {
            std::cerr << "Error: Stack overflow!" << std::endl;
            return;
        }

        top++;
        data[top] = value;
    }

    // Remove and return the element at the top of the stack (pop)
    int pop() {
        if (isEmpty()) {
            std::cerr << "Error: Stack underflow!" << std::endl;
            return -1; // Or throw an exception
        }

        int value = data[top];
        top--;
        return value;
    }

private:
    int data[MAX_SIZE]; // Array to store stack elements
    int top;                // Index of the top element in the stack
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Dequeued element: " << stack.pop() << std::endl;

    // Print all remaining elements in the stack (modify for specific needs)
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}
