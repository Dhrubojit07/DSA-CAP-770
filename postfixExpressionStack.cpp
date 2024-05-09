#include <iostream>
#include <stack>
#include <string>
#include <cctype> // For isdigit

using namespace std;

// Function to check if a character is an operand (digit)
bool isOperand(char ch) {
  return isdigit(ch);
}

// Function to perform the operation based on operators
int calculate(int a, int b, char op) {
  switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      if (b == 0) {
        throw invalid_argument("Division by zero!");
      }
      return a / b;
    default:
      throw invalid_argument("Invalid operator encountered!");
  }
}

// Function to evaluate the postfix expression
int evaluatePostfix(const string& postfix) {
  stack<int> operands;

  for (char ch : postfix) {
    if (isOperand(ch)) {
      operands.push(ch - '0'); // Convert digit character to integer
    } else {
      if (operands.size() < 2) {
        throw invalid_argument("Insufficient operands!");
      }
      int b = operands.top();
      operands.pop();
      int a = operands.top();
      operands.pop();
      int result = calculate(a, b, ch);
      operands.push(result);
    }
  }

  if (operands.size() != 1) {
    throw invalid_argument("Invalid postfix expression!");
  }

  return operands.top();
}

int main() {
  string postfixExpression;
  cout << "Enter a postfix expression: ";
  getline(cin, postfixExpression);

  try {
    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;
  } catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
  }

  return 0;
}
