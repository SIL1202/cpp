#include <iostream>
#include <string>

using namespace std;

class Trie {
private:
  Trie *children[26]; // 26個字母的子節點
  bool endOfWord;     // 是否是單字結尾

public:
  // 建構函數，初始化節點
  Trie() {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
    endOfWord = false;
  }

  /*
  搜尋字串是否存在於Trie中，若存在返回true，否則返回false。
  */
  bool search(string key) {
    Trie *current = this; // 從根節點開始
    for (char ch : key) {
      int index = ch - 'a';
      if (!current->children[index]) {
        return false;
      }
      current = current->children[index];
    }
    return current->endOfWord; // 判斷是否為單字結尾
  }

  /*
  插入字串到Trie中。
  */
  void insert(string value) {
    Trie *current = this; // 從根節點開始
    for (char ch : value) {
      int index = ch - 'a';
      if (!current->children[index]) {
        current->children[index] = new Trie();
      }
      current = current->children[index];
    }
    current->endOfWord = true; // 標記為單字結尾
  }

  /*
  前序遍歷Trie並輸出，每層用對應的空格縮排。
  */
  void preorder(int level = 0) {
    for (int i = 0; i < 26; i++) {
      if (children[i]) {
        // 輸出當前字母（加上縮排）
        cout << string(level * 2, ' ') << char(i + 'a');
        // 遞迴輸出子節點
        children[i]->preorder(level + 1);
      }
    }
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
