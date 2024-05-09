#include <iostream>
#include <stack>

using namespace std;

void solveTowerOfHanoi(int n, char source, char auxiliary, char destination) {
  stack<int> sourceStack;

  // Push disks onto the source stack in descending order
  for (int i = n; i >= 1; --i) {
    sourceStack.push(i);
  }

  // Number of moves required (2^n - 1)
  int moves = pow(2, n) - 1;

  // Perform the moves iteratively
  for (int i = 1; i <= moves; ++i) {
    // Handle even moves (move from source to auxiliary or destination)
    if (i % 2 == 0) {
      if (sourceStack.empty()) {
        cout << "Move disk " << auxiliary << " to " << source << endl;
      } else if (auxiliaryStack.empty()) {
        cout << "Move disk " << source << " to " << auxiliary << endl;
      } else {
        int disk = sourceStack.top();
        sourceStack.pop();
        if (disk > auxiliaryStack.top()) {
          cout << "Move disk " << disk << " from " << source << " to " << auxiliary << endl;
        } else {
          cout << "Move disk " << auxiliaryStack.top() << " from " << auxiliary << " to " << source << endl;
          auxiliaryStack.pop();
        }
      }
    } else { // Handle odd moves (move from source to destination or auxiliary)
      if (sourceStack.empty()) {
        cout << "Move disk " << destination << " to " << source << endl;
      } else if (destinationStack.empty()) {
        cout << "Move disk " << source << " to " << destination << endl;
      } else {
        int disk = sourceStack.top();
        sourceStack.pop();
        if (disk > destinationStack.top()) {
          cout << "Move disk " << disk << " from " << source << " to " << destination << endl;
        } else {
          cout << "Move disk " << destinationStack.top() << " from " << destination << " to " << source << endl;
          destinationStack.pop();
        }
      }
    }
  }
}

int main() {
  int numDisks;
  cout << "Enter the number of disks: ";
  cin >> numDisks;

  solveTowerOfHanoi(numDisks, 'A', 'B', 'C');

  return 0;
}
