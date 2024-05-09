// error .....

#include <iostream>
#include <stack>
#include <string>
#include <stdexcept> // For invalid expression handling

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

// Function to convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
  stack<char> s;
  string postfix;

  for (char ch : infix) {
    if (isOperand(ch)) {
      postfix += ch;
    } else if (ch == '(') {
      s.push(ch);
    } else if (ch == ')') {
      while (!s.empty() && s.top() != '(') {
        postfix += s.top();
        s.pop();
      }
      if (s.empty()) {
        throw invalid_argument("Unmatched closing parenthesis!");
      }
      s.pop(); // Remove the opening parenthesis
    } else { // Operator
      while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
        postfix += s.top();
        s.pop();
      }
      s.push(ch);
    }
  }

  while (!s.empty()) {
    postfix += s.top();
    s.pop();
  }

  return postfix;
}

// Function to define operator precedence (higher value for higher precedence)
int precedence(char op) {
  switch (op) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    default:
      return 0; // Not an operator
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
  string infixExpression;
  cout << "Enter an infix expression: ";
  getline(cin, infixExpression);

  try {
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;
    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;
  } catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
  }

  return 0;
}
