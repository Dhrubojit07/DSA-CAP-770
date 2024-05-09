// error..

#include <iostream>
#include <vector>
#include <string>
#include <functional> // For std::hash

const int TABLE_SIZE = 10; // Adjust table size as needed

// Hash function (simple example using string length)
int hashFunction(const std::string& key) {
  return key.length() % TABLE_SIZE;
}

// Node structure for storing key-value pairs
struct Node {
  std::string key;
  std::string value;

  Node(const std::string& key, const std::string& value) : key(key), value(value) {}
};

// Hash table class using separate chaining
class HashTable {
public:
  HashTable() {
    table.resize(TABLE_SIZE);
  }

  // Insert a key-value pair into the hash table
  void insert(const std::string& key, const std::string& value) {
    int index = hashFunction(key);
    table[index].push_back(Node(key, value));
  }

  // Search for a value associated with a key
  std::string search(const std::string& key) const {
    int index = hashFunction(key);
    for (const Node& node : table[index]) {
      if (node.key == key) {
        return node.value;
      }
    }
    return ""; // Not found
  }

private:
  std::vector<std::vector<Node>> ta ble;
};

int main() {
  HashTable hashTable;

  hashTable.insert("apple", "A delicious fruit");
  hashTable.insert("banana", "Another tasty fruit");
  hashTable.insert("orange", "A citrus fruit");

  std::string value = hashTable.search("apple");
  if (!value.empty()) {
    std::cout << "Value for 'apple': " << value << std::endl;
  } else {
    std::cout << "'apple' not found in the hash table." << std::endl;
  }

  value = hashTable.search("grape"); // Not inserted
  if (!value.empty()) {
    std::cout << "Value for 'grape': " << value << std::endl;
  } else {
    std::cout << "'grape' not found in the hash table." << std::endl;
  }

  return 0;
}
