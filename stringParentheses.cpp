#include <iostream>
#include <stack>
#include <string>

bool isBalancedParenthesis(const std::string& expression) {
  std::stack<char> s;

  for (char ch : expression) {
    if (ch == '(' || ch == '{' || ch == '[') {
      s.push(ch);
    } else if (ch == ')' || ch == '}' || ch == ']') {
      if (s.empty()) {
        return false; // Closing bracket without opening bracket
      }
      char openingBracket = s.top();
      s.pop();

      if ((openingBracket == '(' && ch != ')') ||
          (openingBracket == '{' && ch != '}') ||
          (openingBracket == '[' && ch != ']')) {
        return false; // Mismatched brackets
      }
    }
  }

  // Check if all opening brackets have a closing counterpart
  return s.empty();
}

int main() {
  std::string expression;
  std::cout << "Enter an expression with parentheses: ";
  std::getline(std::cin, expression);

  if (isBalancedParenthesis(expression)) {
    std::cout << "The expression has balanced parentheses." << std::endl;
  } else {
    std::cout << "The expression has unbalanced parentheses." << std::endl;
  }

  return 0;
}
