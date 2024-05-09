#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// Function to determine the precedence of operators
int precedence(char op) {
  unordered_map<char, int> prec = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
  return prec[op];
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
  stack<char> s;
  string postfix;

  for (char ch : infix) {
    if (isalnum(ch)) { // Operand
      postfix += ch;
    } else if (ch == '(') {
      s.push(ch);
    } else if (ch == ')') {
      while (!s.empty() && s.top() != '(') {
        postfix += s.top();
        s.pop();
      }
      if (s.empty()) {
        return "Invalid Expression"; // Mismatched parentheses
      }
      s.pop(); // Pop the '('
    } else { // Operator
      while (!s.empty() && precedence(ch) <= precedence(s.top())) {
        postfix += s.top();
        s.pop();
      }
      s.push(ch);
    }
  }

  // Pop remaining operators from the stack
  while (!s.empty()) {
    postfix += s.top();
    s.pop();
  }

  return postfix;
}

int main() {
  string infixExpression;
  cout << "Enter an infix expression: ";
  getline(cin, infixExpression);

  string postfixExpression = infixToPostfix(infixExpression);

  if (postfixExpression != "Invalid Expression") {
    cout << "Postfix expression: " << postfixExpression << endl;
  } else {
    cout << postfixExpression << endl;
  }

  return 0;
}
