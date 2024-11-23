#include <iostream>
#include <map>
#include <string>

using namespace std;

class TrieNode {
public:
  bool isEndOfWord; // 是否是單字結尾
  map<char, TrieNode *> children;

  TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
  TrieNode *root;

  void preorderHelper(TrieNode *node, int level) {
    if (node == nullptr)
      return;

    // 遍歷每個子節點
    for (auto &[ch, childNode] : node->children) {
      cout << string(level * 2, ' ') << ch << endl; // 根據層級輸出空格
      preorderHelper(childNode, level + 1);         // 遞迴處理下一層
    }
  }

public:
  Trie() { root = new TrieNode(); }

  bool search(const string &key) {
    TrieNode *current = root;
    for (char ch : key) {
      if (current->children.find(ch) == current->children.end()) {
        return false;
      }
      current = current->children[ch];
    }
    return current->isEndOfWord;
  }

  void insert(const string &value) {
    TrieNode *current = root;
    for (char ch : value) {
      if (current->children.find(ch) == current->children.end()) {
        current->children[ch] = new TrieNode();
      }
      current = current->children[ch];
    }
    current->isEndOfWord = true;
  }

  void preorder() {
    preorderHelper(root, 0); // 從根節點開始，層級為 0
    cout << "[]" << endl;    // 空行表示輸出結束
  }
};

int main() {
  Trie *trie = new Trie();
  string command, key, value;

  while (true) {
    cin >> command;
    if (command == "insert") {
      cin >> value;
      trie->insert(value);
    } else if (command == "search") {
      cin >> key;
      if (trie->search(key))
        cout << "exist" << endl;
      else
        cout << "not exist" << endl;
    } else if (command == "print") {
      trie->preorder();
    } else if (command == "exit") {
      break;
    }
  }

  delete trie;
  return 0;
}
