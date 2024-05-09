#include <iostream>

const int MAX_SIZE = 10; // Adjust this for the maximum number of items

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

  // Enqueue (insert) an item price into the queue
  void enqueue(float price) {
    if (isFull()) {
      std::cerr << "Error: Queue overflow!" << std::endl;
      return;
    }

    if (isEmpty()) {
      front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue_[rear] = price;
  }

  // Dequeue (remove) an item price from the queue
  float dequeue() {
    if (isEmpty()) {
      std::cerr << "Error: Queue underflow!" << std::endl;
      return -1.0f; // Indicate error (replace with appropriate value)
    }

    float price = queue_[front];

    if (front == rear) {
      front = rear = -1; // Reset if only one element remains
    } else {
      front = (front + 1) % MAX_SIZE;
    }

    return price;
  }

private:
  int front; // Index of the front element
  int rear;  // Index of the rear element
  float queue_[MAX_SIZE]; // Array to store item prices
};

int main() {
  CircularQueue priceQueue;

  priceQueue.enqueue(10.50f);
  priceQueue.enqueue(15.75f);
  priceQueue.enqueue(8.25f);

  std::cout << "Dequeued price: " << priceQueue.dequeue() << std::endl;
  priceQueue.enqueue(22.99f);

  // Print all prices in the queue (modify for specific needs)
  while (!priceQueue.isEmpty()) {
    std::cout << priceQueue.dequeue() << " ";
  }
  std::cout << std::endl;

  return 0;
}
