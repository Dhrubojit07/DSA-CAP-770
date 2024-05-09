#include <iostream>
#include <stack>
using namespace std ;

const int MAX_SIZE = 10; // Adjust this for the maximum number of readings

class Temperature{
public:
  stack<float> stack;
  // Push a temperature reading onto the stack
  void push(float temperature) {
    if (isFull()) {
      cout<< "Error: Stack overflow!" <<endl;
      return;
    }
    stack.push(temperature);
  }

  // Pop a temperature reading from the stack
  float pop() {
    if (isEmpty()) {
      cout<< "Error: Stack underflow!" <<endl;
      return -1.0f; // Indicate error (replace with appropriate value)
    }
    float temp = stack.top();
    stack.pop();
    return temp;
  }

  // Check if the stack is empty
  bool isEmpty() const {
    return stack.empty();
  }

  // Check if the stack is full
  bool isFull() const {
    return stack.size() == MAX_SIZE;
  }

  // Print the top element (without popping)
  void peek() const {
    if (isEmpty()) {
      cout<< "Error: Stack is empty!" <<endl;
      return;
    }
    cout << "Top temperature: " << stack.top() << " degrees" << endl;
  }
};

int main() {
  Temperature tempStack;

  tempStack.push(25.5f);
  tempStack.push(18.2f);
  tempStack.push(30.1f);

  cout << "Popped temperature: " << tempStack.pop() << " degrees" <<endl;
  tempStack.peek();

  return 0;
}
