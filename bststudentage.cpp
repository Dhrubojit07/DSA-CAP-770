//ERROR...


#include <iostream>
#include <random>

struct Node {
  int age;
  Node* left;
  Node* right;

  Node(int age) : age(age), left(NULL), right(NULL) {}
};

class BinarySearchTree {
public:
  BinarySearchTree() : root(NULL) {}

  void insert(int age) {
    Node* newNode = new Node(age);
    insertHelper(root, newNode);
  }

  // Helper function for recursive insertion
  void insertHelper(Node*& current, Node* newNode) {
    if (current == NULL) {
      current = newNode;
      return;
    }

    if (age < current->age) {
      insertHelper(current->left, newNode);
    } else {
      insertHelper(current->right, newNode);
    }
  }

  // In-order traversal (prints students' ages in ascending order)
  void inOrderTraversal() const {
    inOrderTraversalHelper(root);
  }

  // Helper function for in-order traversal
  void inOrderTraversalHelper(const Node* current) const {
    if (current != NULL) {
      inOrderTraversalHelper(current->left);
      std::cout << current->age << " ";
      inOrderTraversalHelper(current->right);
    }
  }

private:
  Node* root;
};

int main() {
  std::random_device rd; // Seed for random number generation
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> ageDist(10, 25); // Adjust age range as needed

  int numStudents;
  std::cout << "Enter the number of students: ";
  std::cin >> numStudents;

  BinarySearchTree bst;

  for (int i = 0; i < numStudents; ++i) {
    int age = ageDist(generator);
    bst.insert(age);
  }

  std::cout << "Students' ages in the BST (ascending order): ";
  bst.inOrderTraversal();
  std::cout << std::endl;

  return 0;
}
