#include <iostream>
#include <string>

const int MAX_SIZE = 10; // Adjust this for the maximum number of kids

class KidQueue {
public:
  KidQueue() : front(-1), rear(-1) {}

  // Check if the queue is empty
  bool isEmpty() const {
    return front == -1;
  }

  // Check if the queue is full
  bool isFull() const {
    return (rear + 1) % MAX_SIZE == front;
  }

  // Add a kid's name to the end of the queue
  void enqueue(const std::string& name) {
    if (isFull()) {
      std::cerr << "Error: Queue overflow!" << std::endl;
      return;
    }

    if (isEmpty()) {
      front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue_[rear] = name;
  }

  // Remove and return the kid's name at the front of the queue
  std::string dequeue() {
    if (isEmpty()) {
      std::cerr << "Error: Queue underflow!" << std::endl;
      return ""; // Or throw an exception
    }

    std::string name = queue_[front];
    if (front == rear) {
      front = rear = -1; // Reset if only one element remains
    } else {
      front = (front + 1) % MAX_SIZE;
    }

    return name;
  }

private:
  std::string queue_[MAX_SIZE]; // Array to store kid names
  int front;                // Index of the front element
  int rear;                 // Index of the rear element
};

int main() {
  KidQueue kidQueue;

  kidQueue.enqueue("Alice");
  kidQueue.enqueue("Bob");
  kidQueue.enqueue("Charlie");

  std::cout << "Dequeued kid: " << kidQueue.dequeue() << std::endl;

  // Print all remaining kids in the queue (modify for specific needs)
  while (!kidQueue.isEmpty()) {
    std::cout << kidQueue.dequeue() << " ";
  }
  std::cout << std::endl;

  return 0;
}
