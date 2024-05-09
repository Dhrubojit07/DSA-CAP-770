// error ...

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isBalanced(const string& expression) {
  unordered_map<char, char> openingToClosing = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
  stack<char> s;

  for (char ch : expression) {
    if (openingToClosing.count(ch)) {
      // Push opening brackets onto the stack
      s.push(ch);
    } else if (closingToOpening.count(ch)) {
      // Check if the closing bracket matches the top element (opening bracket)
      if (s.empty() || s.top() != openingToClosing[ch]) {
        return false;
      }
      // Pop the matching opening bracket
      s.pop();
    }
  }

  // Check if all opening brackets have a closing counterpart
  return s.empty();
}

int main() {
  string expression;
  cout << "Enter an expression with parentheses, brackets, and braces: ";
  getline(cin, expression);

  if (isBalanced(expression)) {
    cout << "The expression has balanced symbols." << endl;
  } else {
    cout << "The expression has unbalanced symbols." << endl;
  }

  return 0;
}
