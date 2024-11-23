#include <iostream>
#include <string>

using namespace std;

class TrieNode {
private:
  TrieNode *children[26];
  bool endOfword;
  int weight;

public:
  TrieNode() {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
    endOfword = false;
  }

  void Trie_insert(TrieNode *node, string word) {
    TrieNode *root = this;

    for (int i = 0; i < word.length(); i++) {
      int index = word[i] - 'a';
      if (!root->children[index]) {
        root->children[index] = new TrieNode();
      }
      root = root->children[index];
    }
    root->endOfword = true;
  }

  bool startwith(string word) {
    TrieNode *current = this;

    for (int i = 0; i < word.length(); i++) {
      int index = word[i] - 'a';
      if (!current->children[index])
        return false;
      current = current->children[index];
    }

    return true;
  }

  bool search(string word) {
    TrieNode *current = this;

    for (char c : word) {
      int index = c - 'a';
      if (!current->children[index])
        return false;
      current = current->children[index];
    }
    return current->endOfword;
  }
};

int main() {
  string a = "apple";
  TrieNode *root = new TrieNode();
  root->Trie_insert(root, a);

  cout << "startwith 'app': "
       << (root->startwith("app") ? "Found!" : "not Found!") << endl
       << "search 'appl': " << (root->search("appl") ? "Found!" : "not Found!");

  return 0;
}
