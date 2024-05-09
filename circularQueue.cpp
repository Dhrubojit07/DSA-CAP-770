#include <iostream>

const int MAX_SIZE = 10; // Adjust this for the desired maximum number of elements

class CircularQueue {
public:
  CircularQueue() : front(-1), rear(-1) {}

  // Check if the queue is empty
  bool isEmpty() const {
    return front == -1;
  }

  // Check if the queue is full
  bool isFull() const {
    return (rear + 1) % MAX_SIZE == front;
  }

  // Add an element to the end of the queue (circular fashion)
  void enqueue(int value) {
    if (isFull()) {
      std::cerr << "Error: Queue overflow!" << std::endl;
      return;
    }

    if (isEmpty()) {
      front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue_[rear] = value;
  }

  // Remove and return the element at the front of the queue
  int dequeue() {
    if (isEmpty()) {
      std::cerr << "Error: Queue underflow!" << std::endl;
      return -1; // Or throw an exception
    }

    int value = queue_[front];
    if (front == rear) {
      front = rear = -1; // Reset if only one element remains
    } else {
      front = (front + 1) % MAX_SIZE;
    }

    return value;
  }

  // Print all elements in the queue (useful for debugging)
  void printQueue() const {
    if (isEmpty()) {
      std::cout << "Queue is empty." << std::endl;
      return;
    }

    std::cout << "Queue elements: ";
    int i = front;
    while (i != rear) {
      std::cout << queue_[i] << " ";
      i = (i + 1) % MAX_SIZE;
    }
    std::cout << queue_[rear] << std::endl;
  }

private:
  int queue_[MAX_SIZE]; // Array to store queue elements
  int front;                // Index of the front element
  int rear;                 // Index of the rear element
};

int main() {
  CircularQueue queue;

  queue.enqueue(10);
  queue.enqueue(20);
  queue.enqueue(30);

  std::cout << "Dequeued element: " << queue.dequeue() << std::endl;

  queue.enqueue(40);

  queue.printQueue(); // Print all elements in the queue

  return 0;
}
