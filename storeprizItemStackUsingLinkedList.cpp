#include <iostream>

// Node structure for the linked list
struct Node {
  float price;
  Node* next;

  Node(float price) : price(price), next(NULL) {}
};

// Stack class using linked list
class PriceStack {
public:
  PriceStack() : head(NULL) {}

  // Add a price to the top of the stack
  void push(float price) {
    Node* newNode = new Node(price);
    newNode->next = head;
    head = newNode;
  }

  // Remove and return the price at the top of the stack
  float pop() {
    if (isEmpty()) {
      std::cerr << "Error: Stack is empty!" << std::endl;
      return -1.0f; // Indicate error (replace with appropriate value)
    }
    Node* temp = head;
    float price = temp->price;
    head = head->next;
    delete temp;
    return price;
  }

  // Check if the stack is empty
  bool isEmpty() const {
    return head == NULL;
  }

  // Print the top price without popping (optional)
  void peek() const {
    if (isEmpty()) {
      std::cerr << "Error: Stack is empty!" << std::endl;
      return;
    }
    std::cout << "Top price: " << head->price << std::endl;
  }

private:
  Node* head; // Pointer to the head node
};

int main() {
  PriceStack priceStack;

  priceStack.push(10.50f);
  priceStack.push(15.75f);
  priceStack.push(8.25f);

  std::cout << "Popped price: " << priceStack.pop() << std::endl;
  priceStack.peek(); // Optional: Print the top price without removing it

  return 0;
}
