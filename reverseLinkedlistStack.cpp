#include <iostream>
#include <stack>

struct Node {
  int data;
  Node* next;
  Node(int data) : data(data), next(nullptr) {}
};

// Function to reverse a linked list using a stack
Node* reverseLinkedList(Node* head) {
  if (head == nullptr || head->next == nullptr) {
    return head; // Empty list or single node, no need to reverse
  }

  std::stack<Node*> s;
  Node* current = head;

  // Push all nodes onto the stack
  while (current != nullptr) {
    s.push(current);
    current = current->next;
  }

  // Create the new reversed linked list
  head = s.top();
  current = head;
  s.pop();

  while (!s.empty()) {
    current->next = s.top();
    current = current->next;
    s.pop();
  }

  current->next = nullptr; // Set the last node's next to nullptr

  return head;
}

// Function to print the linked list
void printLinkedList(Node* head) {
  while (head != nullptr) {
    std::cout << head->data << " -> ";
    head = head->next;
  }
  std::cout << "NULL" << std::endl;
}

int main() {
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);

  std::cout << "Original list: ";
  printLinkedList(head);

  head = reverseLinkedList(head);

  std::cout << "Reversed list: ";
  printLinkedList(head);

  return 0;
}
