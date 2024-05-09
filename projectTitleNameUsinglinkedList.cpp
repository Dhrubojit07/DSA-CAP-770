#include <iostream>
#include <string>

// Node structure for the linked list
struct Node {
  std::string title;
  Node* next;

  Node(const std::string& title) : title(title), next(NULL) {}
};

// Queue class using linked list
class ProjectQueue {
public:
  ProjectQueue() : head(NULL), tail(NULL) {}

  // Add a project title to the end of the queue
  void enqueue(const std::string& title) {
    Node* newNode = new Node(title);
    if (isEmpty()) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  // Remove and return the project title at the front of the queue
  std::string dequeue() {
    if (isEmpty()) {
      std::cerr << "Error: Queue is empty!" << std::endl;
      return ""; // Or throw an exception
    }
    Node* temp = head;
    std::string title = temp->title;
    head = head->next;
    if (head == NULL) {
      tail = NULL; // Queue becomes empty
    }
    delete temp;
    return title;
  }

  // Check if the queue is empty
  bool isEmpty() const {
    return head == NULL;
  }

private:
  Node* head; // Pointer to the head node
  Node* tail; // Pointer to the tail node
};

int main() {
  ProjectQueue projectQueue;

  projectQueue.enqueue("Project A");
  projectQueue.enqueue("Project B");
  projectQueue.enqueue("Project C");

  std::cout << "Dequeued project: " << projectQueue.dequeue() << std::endl;

  // Print all remaining projects in the queue (modify for specific needs)
  while (!projectQueue.isEmpty()) {
    std::cout << projectQueue.dequeue() << " ";
  }
  std::cout << std::endl;

  return 0;
}
